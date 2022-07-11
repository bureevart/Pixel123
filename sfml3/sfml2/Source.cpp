#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Grid.h"

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

int main()
{
	int size = 19;
	int squareSize = 30;
	RenderWindow window(VideoMode(size * squareSize, size * squareSize), "SFML d Works!");

	Grid grd(size);

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

			for (size_t i = 0; i < size; i++)
			{
				for (size_t j = 0; j < size; j++)
				{
					if (isMousePressedOnTile(event, vecMouse, grd.grid[i][j].tile, i * squareSize, j * squareSize)) {
						grd.grid[i][j].tile.setFillColor(Color::Red);
					}
				}
			}
		}


		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				RectangleShape rec = grd.grid[i][j].tile;
				window.draw(rec);
			}
		}
		

		// Отрисовка окна	
		window.display();
	}

	return 0;
}