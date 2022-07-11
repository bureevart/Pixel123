#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Grid.h"
#include <ctime>
#include <random>

using namespace std;
using namespace sf;

bool isInSquareCollision(Vector2f vecMouse, RectangleShape square, int x1, int y1) {
	if ((vecMouse.x >= x1 && vecMouse.x <= (x1 + square.getSize().x)) && (vecMouse.y >= y1 && vecMouse.y <= (y1 + square.getSize().y)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isMousePressedOnTile(Event event, Vector2f vecMouse, RectangleShape square, int x1, int y1) {
	Tile tempTile;
	if (event.type == Event::MouseButtonPressed && (isInSquareCollision(vecMouse, square, x1, y1)))
	{
		if (event.key.code == Mouse::Left)
		{
			return true;
		}
	}
	return false;

}

int randomGenerator(int first, int last) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(first, last);
	srand(dist(gen));
	return (rand() % last) + first;
}

int main()
{
	Color currentColor = Color::Red;

	int sizeX = 25;
	int sizeY = 25;
	int sizeOfPaletteX = 5;
	int sizeOfPaletteY = 10;
	int squareSize = 20;
	int palleteMoveX = (sizeX + 1) * squareSize + 150;
	int palleteMoveY = 200;
	RenderWindow window(VideoMode(sizeX * squareSize + 350, sizeY * squareSize + 100), "SFML d Works!");
	int** colorNumbers = new int*[sizeOfPaletteX * sizeOfPaletteY];

	Grid grd(sizeX, sizeY, 100, 50, squareSize);
	Grid palette(sizeOfPaletteX, sizeOfPaletteY, palleteMoveX, palleteMoveY, 30);

	for (size_t i = 0; i < sizeOfPaletteX * sizeOfPaletteY; i++)
	{
		int* tempIntArr = new int[3];
		for (size_t j = 0; j < 3; j++)
		{
			tempIntArr[j] = randomGenerator(0, 255);
		}
		colorNumbers[i] = tempIntArr;
	}

	while (window.isOpen())
	{
		window.clear(Color(250, 220, 100, 0));

		Vector2i positionMouse = Mouse::getPosition(window);
		int MouseX = positionMouse.x;
		int MouseY = positionMouse.y;
		Vector2f vecMouse;
		vecMouse.x = MouseX;
		vecMouse.y = MouseY;


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}

			for (size_t i = 0; i < sizeX; i++)
			{
				for (size_t j = 0; j < sizeY; j++)
				{
					if (isMousePressedOnTile(event, vecMouse, grd.grid[i][j].tile, grd.grid[i][j].x + grd.moveX, grd.grid[i][j].y + grd.moveY)) {
						grd.grid[i][j].tile.setFillColor(currentColor);
					}
				}
			}

			for (size_t i = 0; i < sizeOfPaletteX; i++)
			{
				for (size_t j = 0; j < sizeOfPaletteY; j++)
				{
					if (isMousePressedOnTile(event, vecMouse, palette.grid[i][j].tile, palette.grid[i][j].x + palette.moveX, palette.grid[i][j].y + palette.moveY)) {
						currentColor = palette.grid[i][j].tile.getFillColor();
					}
				}
			}

		}


		for (size_t i = 0; i < sizeX; i++)
		{
			for (size_t j = 0; j < sizeY; j++)
			{
				window.draw(grd.grid[i][j].tile);
			}
		}

		int tempCount = 0;
		for (size_t i = 0; i < sizeOfPaletteX; i++)
		{
			for (size_t j = 0; j < sizeOfPaletteY; j++)
			{
				palette.grid[i][j].tile.setFillColor(Color::Color(colorNumbers[tempCount][0], colorNumbers[tempCount][1], colorNumbers[tempCount][2]));
				window.draw(palette.grid[i][j].tile);
				tempCount++;
			}
		}
		

		// Отрисовка окна	
		window.display();
	}

	return 0;
}