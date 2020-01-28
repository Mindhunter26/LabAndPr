#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

enum ItemType {
	SWORD,
	BOW,
	SPELL
};

enum Element {
	FIRE,
	WATER,
	AIR,
	EARTH
};

struct Sword {
	int damage;
};

struct Bow {
	int damage;
	int charge_time;
	double distance;
};

struct Spell {
	int damage;
	Element element;
	double distance;
};

struct Item {
	ItemType itemType;
	union {
		Sword sword;
		Bow bow;
		Spell spell;
	};
};

Item getRandomItem() {
	Item loot;

	loot.itemType = static_cast<ItemType>(rand() % 3);
	
	if (loot.itemType == SWORD) {
	     loot.sword.damage = rand() % 1000;
	}
	else if (loot.itemType == BOW) {
		loot.bow.damage = rand() % 500;
		loot.bow.charge_time = 5 + rand() % 10;
		loot.bow.distance = rand() % 100;
	}
	else if (loot.itemType == SPELL) {
		loot.spell.damage = 300 + rand() % 5000;
		loot.spell.distance = rand() % 1000;
		loot.spell.element = static_cast<Element>(rand() % 4);
	}
	return loot;
}
void printItem(Item loot) {
	if (loot.itemType == SWORD) {
		cout << "---SWORD---" << endl;
		cout << "Damage: " << loot.sword.damage << endl;
		cout << endl;
	} else
		if (loot.itemType == SPELL) {
			cout << "---SPELL---" << endl;
			cout << "Damage: " << loot.spell.damage << endl;
			cout << "Element: " << loot.spell.element << endl;
			cout << "Distance: " << loot.spell.distance << endl;
			cout << endl;
	} else
		if (loot.itemType == BOW) {
			cout << "---BOW---" << endl;
			cout << "Damage: " << loot.bow.damage << endl;
			cout << "Distance: " << loot.bow.distance << endl;
			cout << "Charge time: " << loot.bow.charge_time << endl;
			cout << endl;
	}
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
		printItem(getRandomItem());
}
