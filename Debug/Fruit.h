#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;
class Fruit
{
private:
	CircleShape circle;
	Texture texture;
	Clock clock;
public:
	Fruit(float radius, int initialRow, int initialColoumn, string fileName);
	void drawOnWindow(RenderWindow& window);
	CircleShape getFruit();
	bool eaten(int x, int y, int arr[][19]);
	void erase();
};