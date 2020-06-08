#include "pch.h"
#include <iostream>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>

//5a2bc8ce375de838a8213fb00c024b4a - API
//693805 - SIMF
void gen_resp(const httplib::Request& req, httplib::Response& resp)
{
	httplib::Client cli("api.openweathermap.org", 80); //80 - стандартный порт для http-страниц 

	auto responce = cli.Get("/data/2.5/forecast?id=693805&APPID=5a2bc8ce375de838a8213fb00c024b4a&units=metric");
	if (responce && responce->status == 200) //Проверка, удалось ли заргузить страницу
	{
		nlohmann::json res = nlohmann::json::parse(responce->body);
		//std::cout << result["cod"];
		std::ifstream fin("Weather.html");
		std::string output = "Could't load template";

		if (!fin.is_open()) 
		{
			std::cout << "Could't load template" << std::endl;
			fin.close();
		}
		else 
		{
			output = "";
			char ch;
			while (fin.get(ch)) 
			{
				output += ch;
			}

			std::string name = "{city.name}";
			std::string date = "{list.dt}";
			std::string temp = "{list.main.temp}";
			std::string icon = "{list.weather.icon}";
			std::string date_check = "";

			output.replace(output.find(name), name.length(), res["city"]["name"]);

			for (int i = 0; i < res["list"].size(); i++)
			{
				if (output.find(date) != std::string::npos)
				{
					if (res["list"][i]["dt_txt"].dump().substr(1, 11) != date_check) 
					{
						output.replace(output.find(date), date.length(), res["list"][i]["dt_txt"].dump().substr(1, 11));

						if (output.find(temp) != std::string::npos) 
						{
							output.replace(output.find(temp), temp.length() + 1, res["list"][i]["main"]["temp"].dump());
						}

						if (output.find(icon) != std::string::npos) 
						{
							std::string iconid = res["list"][i]["weather"][0]["icon"].dump();
							std::string url = "http://openweathermap.org/img/wn/" + (iconid.substr(1, iconid.size() - 2) + ".png");
							output.replace(output.find(icon), icon.length(), url);
						}

						date_check = res["list"][i]["dt_txt"].dump().substr(1, 11);
						//std::cout << " " << i << std::endl;
					}
				}
			}

		}

		resp.set_content(output, "text/html");
	}
	else 
	{
		resp.set_content("Couldn't load page", "text/text");
	}
}

int main()
{
	httplib::Server svr;				//Создаём сервер (пока-что не запущен)
	svr.Get("/", gen_resp);				//Вызвать функцию gen_response если кто-то обратиться к корню "сайта"
	svr.listen("localhost", 1234);      //Запускаем сервер на localhost и порту 1234
}