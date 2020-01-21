#include "pch.h"
#include "libbmp.h"
#include <iostream>

int main()
{
	BmpImg img;
	img.read("pic9.bmp");
	const int width = img.get_width() - 1;
	const int height = img.get_height() - 1;
	char pix[4000];
	char y = 0;
	int pos = 0;
	int k = 0;
	int bit;
	bool isEnd = false;
	for (int i = height; i >= 0; i--)
	{
		for (int j = width; j >= 0; j--)
		{
			bit = img.blue_at(j, i);
			y = y << 1;
			if (bit % 2 == 1) 
				y++;
			k++;
			if (k == 8) {
				pix[pos] = y;
				pos++;
				k = 0;
				if (y == '\0') {
					isEnd = true;
					break;
				}
			}

			bit = img.green_at(j, i);
			y = y << 1;
			if (bit % 2 == 1)
				y++;
			k++;
			if (k == 8) {
				pix[pos] = y;
				pos++;
				k = 0;
				if (y == '\0') {
					isEnd = true;
					break;
				}
			}

			bit = img.red_at(j, i);
			y = y << 1;
			if (bit % 2 == 1) 
				y++;
			k++;
			if (k == 8) {
				pix[pos] = y;
				pos++;
				k = 0;
				if (y == '\0') {
					isEnd = true;
					break;
				}
			}
			
			
		}
		if (isEnd)	
			break;
	}
	std::cout << pix;
}

