#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Tile.h"
#include <array>

using namespace std;
using namespace sf;

class Grid
{
public:
	int countX;
	int countY;
	int moveX;
	int moveY;
	int squareSize;
	Tile** grid;

	Grid(int countX, int countY, int moveX, int moveY, int squareSize);
};