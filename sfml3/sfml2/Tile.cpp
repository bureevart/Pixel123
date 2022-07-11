#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

Tile::Tile(float x, float y) {
	Tile::tile = RectangleShape(Vector2f(30, 30));
	tile.setFillColor(Color::White);
	tile.setOutlineColor(Color::Black);
	tile.setOutlineThickness(2);
	Tile::x = x;
	Tile::y = y;
	tile.setPosition(Vector2f(x, y));
};
Tile::Tile() {
	//code
}