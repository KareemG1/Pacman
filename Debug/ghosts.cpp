#include "ghosts.h"
ghosts::ghosts(float radius) {
	inky.setRadius(radius);
	inky.setPosition(10 + (40 * iColoumn), 60 + (40 * iRow));
	itexture.loadFromFile("inky.png");
	inky.setTexture(&itexture);

	pinky.setRadius(radius);
	pinky.setPosition(10 + (40 * pColoumn), 60 + (40 * pRow));
	ptexture.loadFromFile("pinky.png");
	pinky.setTexture(&ptexture);

	blinky.setRadius(radius);
	blinky.setPosition(10 + (40 * bColoumn), 60 + (40 * bRow));
	btexture.loadFromFile("blinky.png");
	blinky.setTexture(&btexture);

	clyde.setRadius(radius);
	clyde.setPosition(10 + (40 * cColoumn), 60 + (40 * cRow));
	ctexture.loadFromFile("clyde.png");
	clyde.setTexture(&ctexture);

}



void ghosts::inkyMoveOnWindow(int iMovement, int arr[][19]){
		if ((arr[iRow - 1][iColoumn] >= 0 || arr[iRow - 1][iColoumn] <-3) && arr[iRow - 1][iColoumn] == iMovement) {
				inky.move(0, -40);
				iRow--;
		}else if ((arr[iRow + 1][iColoumn] >= 0 || arr[iRow + 1][iColoumn] < -3) && arr[iRow + 1][iColoumn] == iMovement) {
				inky.move(0, 40);
				iRow++;
		}else if ((arr[iRow][iColoumn - 1] >= 0 || arr[iRow][iColoumn - 1] < -3) && arr[iRow][iColoumn - 1] == iMovement) {
				inky.move(-40, 0);
				iColoumn--;
		}else if ((arr[iRow][iColoumn + 1] >= 0 || arr[iRow][iColoumn + 1] < -3) && arr[iRow][iColoumn + 1] == iMovement){
				inky.move(40, 0);
				iColoumn++;
		}
}

void ghosts::pinkyMoveOnWindow(int pMovement, int arr[][19]) {

		if ((arr[pRow - 1][pColoumn] >= 0 || arr[pRow - 1][pColoumn] < -3) && arr[pRow - 1][pColoumn] == pMovement) {
			pinky.move(0, -40);
			pRow--;
		}else if ((arr[pRow + 1][pColoumn] >= 0 || arr[pRow + 1][pColoumn] < -3) && arr[pRow + 1][pColoumn] == pMovement) {
			pinky.move(0, 40);
			pRow++;
		}else if ((arr[pRow][pColoumn - 1] >= 0 || arr[pRow][pColoumn - 1] < -3) && arr[pRow][pColoumn - 1] == pMovement) {
			pinky.move(-40, 0);
			pColoumn--;
		}else if ((arr[pRow][pColoumn + 1] >= 0 || arr[pRow][pColoumn + 1] < -3) && arr[pRow][pColoumn + 1] == pMovement) {
			pinky.move(40, 0);
			pColoumn++;
		}

	
}

void ghosts::blinkyMoveOnWindow(int bMovement, int arr[][19]){

		if ((arr[bRow - 1][bColoumn] >= 0 || arr[bRow - 1][bColoumn] <-3) && arr[bRow - 1][bColoumn] == bMovement) {
				blinky.move(0, -40);
				bRow--;
		}else if ((arr[bRow + 1][bColoumn] >= 0 || arr[bRow + 1][bColoumn] < -3) && arr[bRow + 1][bColoumn] == bMovement) {
				blinky.move(0, 40);
				bRow++;
		}else if ((arr[bRow][bColoumn - 1] >= 0 || arr[bRow][bColoumn - 1] < -3) && arr[bRow][bColoumn - 1] == bMovement) {
			blinky.move(-40, 0);
			bColoumn--;
		}else if ((arr[bRow][bColoumn + 1] >= 0 || arr[bRow][bColoumn + 1] < -3) && arr[bRow][bColoumn + 1]  == bMovement) {
				blinky.move(40, 0);
				bColoumn++;
		}

}

void ghosts::clydeMoveOnWindow(int cMovement, int arr[][19]){
		if ((arr[cRow - 1][cColoumn] >= 0 || arr[cRow - 1][cColoumn] <-3) && arr[cRow - 1][cColoumn] == cMovement) {
				clyde.move(0, -40);
				cRow--;
		}else if ((arr[cRow + 1][cColoumn] >= 0 || arr[cRow + 1][cColoumn] < -3) && arr[cRow + 1][cColoumn] == cMovement) {
				clyde.move(0, 40);
				cRow++;
		}else if ((arr[cRow][cColoumn - 1] >= 0 || arr[cRow][cColoumn - 1] < -3) && arr[cRow][cColoumn - 1] == cMovement) {
				clyde.move(-40, 0);
				cColoumn--;	
		}else if ((arr[cRow][cColoumn + 1] >= 0 || arr[cRow][cColoumn + 1] < -3) && arr[cRow][cColoumn + 1] == cMovement) {
				clyde.move(40, 0);
				cColoumn++;
		}

}

int ghosts::igetX() {
	return iColoumn;
}
int ghosts::igetY(){
	return iRow;
}

int ghosts::pgetX(){
	return pColoumn;
}
int ghosts::pgetY(){
	return pRow;
}

int ghosts::bgetX(){
	return bColoumn;
}
int ghosts::bgetY(){
	return bRow;
}

int ghosts::cgetX(){
	return cColoumn;
}
int ghosts::cgetY(){
	return cRow;
}

void ghosts::drawOnWindow(RenderWindow& window){
	window.draw(inky);
	window.draw(pinky);
	window.draw(blinky);
	window.draw(clyde);
}

CircleShape ghosts::getInky(){
	return inky;
}

CircleShape ghosts::getPinky(){
	return pinky;
}

CircleShape ghosts::getBlinky(){
	return blinky;
}

CircleShape ghosts::getClyde(){
	return clyde;
}