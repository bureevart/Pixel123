#include "Grid.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

Grid::Grid(int countX, int countY, int moveX, int moveY, int squareSize) {
	Grid::countX = countX;
	Grid::countY = countY;
	grid = new Tile*[countX];
	for (size_t i = 0; i < countX; i++)
	{
		Tile* tempTile = new Tile[countY];
		for (size_t j = 0; j < countY; j++)
		{
			tempTile[j] = (Tile(squareSize * i + moveX, squareSize * j + moveY, squareSize));
		}
		grid[i] = tempTile;
	}
};