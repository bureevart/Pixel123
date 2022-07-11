#include "Grid.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

Grid::Grid(int size) {
	Grid::size = size;
	grid = new Tile*[size];
	for (size_t i = 0; i < size; i++)
	{
		Tile* tempTile = new Tile[size];
		for (size_t j = 0; j < size; j++)
		{
			tempTile[j] = (Tile(30 * i, 30 * j));
		}
		grid[i] = tempTile;
	}
};