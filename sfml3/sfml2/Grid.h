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
	int size;
	Tile** grid;

	Grid(int size);
};