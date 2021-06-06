#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

class ghosts
{
private:
	CircleShape inky, pinky, blinky, clyde;
	Texture itexture, ptexture, btexture, ctexture;
	int sRow = 8;
	int sColoumn = 9;

	int bRow = sRow;
	int	bColoumn = 10;

	int iRow = sRow; 
	int iColoumn = 11;

	int pRow = sRow; 
	int pColoumn = 8;

	int cRow = sRow;
	int cColoumn = 7;

public:
	ghosts(float radius);
	

	void inkyMoveOnWindow(int iMovement, int arr[][19]);
	void pinkyMoveOnWindow(int pMovement, int arr[][19]);
	void blinkyMoveOnWindow(int bMovement, int arr[][19]);
	void clydeMoveOnWindow(int cMovement, int arr[][19]);


	
	int igetX();
	int igetY();
	
	int pgetX();
	int pgetY();
	
	int bgetX();
	int bgetY();
	
	int cgetX();
	int cgetY();

	void drawOnWindow(RenderWindow& window);

	CircleShape getInky();
	CircleShape getPinky();
	CircleShape getBlinky();
	CircleShape getClyde();
};