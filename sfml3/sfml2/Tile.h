#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;



class Tile
{
public:
	enum SideOfTile {
		white = 1,
		black = 2,
		neutral = 0
	};

	float x;
	float y;
	int side;
	RectangleShape tile;
public:
	Tile(float x, float y);
	Tile();
};

