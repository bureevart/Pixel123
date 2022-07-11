#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;



class Tile
{
public:
	float x;
	float y;
	int side;
	int squareSize;
	RectangleShape tile;
public:
	Tile(float x, float y, int squareSize);
	Tile();
};

