#include "Fruit.h"
Fruit::Fruit(float radius, int initialRow, int initialColoumn, string fileName) {
	texture.loadFromFile(fileName);
	circle.setRadius(radius);
	circle.setPosition(55 + (40 * initialColoumn), 105 + (40 * initialRow));
	circle.setTexture(&texture);
}

void Fruit::drawOnWindow(RenderWindow& window) {
		window.draw(circle);
}
CircleShape Fruit::getFruit() {
	return circle;
}

bool Fruit::eaten(int x, int y, int arr[][19]) {
	if (arr[x][y] == 161 && circle.getFillColor() != Color::Black) {
		circle.setFillColor(Color::Black);
		return true;
	}
	return false;
}
void Fruit::erase() {
	circle.setFillColor(Color::Black);
}