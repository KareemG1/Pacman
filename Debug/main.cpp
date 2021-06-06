//SFML: Simpple and Fast Multimedia Library.
#include "Player.h"
#include "Pellet.h"
#include "Fruit.h"
#include "ghosts.h"
#include "DijkestraFormula.h"
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include "bst.h"
int main()
{
	//Setting up all the variables,  
	Clock clock, fruit, ghostC, move, timer;
	Text sc, life, win, lose, enter, title, ready;
	Text scores[10];
	int arr[22][19];
	ifstream inputFile, inScore, print;
	ofstream outputFile, outScore("highscore.txt", std::ios_base::app);
	vector<int> highscore (1);
	SoundBuffer start, eat, frEat;
	Sound st, et, fe;
	int score = -10, i = 0, p = 0, b = 0, c = 0, pEaten = 0, fright = 0, lives = 3, hs = 0;
	bool frozen = false;
	bool invincible = false;
	float iTimer = 0.0;
	srand(time(NULL));

	//readng from from the file to make the maze
	inputFile.open("board.txt");
	if (inputFile.is_open()) {
		for (int i = 0; i < 22; i++)
			for (int j = 0; j < 19; j++)
				if (!inputFile.eof())
					inputFile >> arr[i][j];
		inputFile.close();
	}
	else
		cout << "Error loading board.txt" << endl;

	//Creating the window
	RenderWindow window;
	window.create(VideoMode(780, 950), "Pacman");
	window.setFramerateLimit(30);

	//Various calls to the constructors
	Pellet pel(20, "Pellet.png", arr);
	Fruit fr(15, 11, 8, "Cherry.png");
	Player play(20, 16, 9, "Pacman.png");
	ghosts g(20);
	BinarySearchTree bst;
	DijkestraFormula d(arr);
	//Textures of the board
	Texture wallTexture, floorTexture, homeDoor;
	wallTexture.loadFromFile("wall.png");
	floorTexture.loadFromFile("floor.png");
	homeDoor.loadFromFile("thinLine.png");
	RectangleShape board[22][19];
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 19; j++) {
			board[i][j].setSize(Vector2f(40, 40));
			board[i][j].setPosition(10 + (40 * j), 60 + (40 * i));
			if (arr[i][j] == -1) {
				board[i][j].setTexture(&wallTexture);
			}
			else if (arr[i][j] >= 0 || arr[i][j] < -3) {
				board[i][j].setTexture(&floorTexture);

			}
			else if (arr[i][j] == -3) {
				board[i][j].setSize(Vector2f(40, 5));
				board[i][j].setTexture(&homeDoor);
			}
		}

	//Setting up the text of the stuff on board
	Font font;
	font.loadFromFile("ARCADECLASSIC.ttf");
	
	//Score
	sc.setFont(font);
	sc.setCharacterSize(24);
	sc.setFillColor(Color::White);
	
	//Lives text
	life.setFont(font);
	life.setCharacterSize(24);
	life.setFillColor(Color::White);
	
	//Win text
	win.setFont(font);
	win.setCharacterSize(30);
	win.setFillColor(Color::White);
	win.setPosition(300, 400);
	win.setString("You  have  won!");
	
	//Lose text
	lose.setFont(font);
	lose.setCharacterSize(30);
	lose.setFillColor(Color::White);
	lose.setPosition(300, 400);
	lose.setString("You  have  lost!");
	
	//Close window text
	enter.setFont(font);
	enter.setCharacterSize(30);
	enter.setFillColor(Color::White);
	enter.setPosition(250, 475);
	enter.setString("Press  enter  to  close");
	
	//Name of the game
	title.setFont(font);
	title.setCharacterSize(30);
	title.setFillColor(Color::White);
	title.setPosition(340, 15);
	title.setString("Pacman!");
	
	//Ready text
	ready.setFont(font);
	ready.setPosition(290, 375);
	ready.setCharacterSize(15);
	ready.setFillColor(Color::White);
	ready.setPosition(325, 550);
	ready.setString("Ready! Press space");
	
	
	
	eat.loadFromFile("pacman_chomp.wav");
	frEat.loadFromFile("pacman_eatfruit.wav");
	start.loadFromFile("pacman_beginning.wav");
	
	et.setBuffer(eat);
	fe.setBuffer(frEat);
	st.setBuffer(start);
	
	
	
	//This is for the win/lose screens
	RectangleShape menu;
	menu.setSize(Vector2f(700, 900));
	menu.setPosition(40, 50);
	menu.setFillColor(Color::Black);

	//Loop for while the window is open to make the game workjj
	while (window.isOpen()) {
		Time elapsedTime = timer.restart();
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			frozen = true;
			//play sound
		}
	
		//This set of code is what lets pacman move
		Event e;
		while (window.pollEvent(e) && frozen) {
			if (e.type == Event::Closed)
				window.close();
			else if (e.type == Event::KeyReleased)
				if (clock.getElapsedTime().asSeconds() > .15) {
					play.moveOnWindow(e, arr);
					clock.restart();
				}
		}
		if (clock.getElapsedTime().asSeconds() > .15 && frozen) {
			clock.restart();
			play.moveOnWindow(e, arr);
		}

		window.clear();

		//This is the code for pellet collision and a small snippit of the invincibility code
		if (pel.eaten(play.getY(), play.getX(), arr)) {
			score += 10;
			pEaten += 1;
			if (arr[play.getY()][play.getX()] == 22 || arr[play.getY()][play.getX()] == 27 || arr[play.getY()][play.getX()] == 101 || arr[play.getY()][play.getX()] == 114) {
				score += 40;
				fright = 1;
			}
		}

		//This is the invincibility timer set up
		if (fright == 1) {
			iTimer += elapsedTime.asSeconds();
			if (iTimer > 5.0f) {
				fright = 0;
				iTimer = 0;
			}
		}		

		//Displays the score and updates it
		sc.setString("Score " + to_string(score));
		sc.setPosition(650, 20);
		window.draw(sc);

		//Draws the board with the walls and floor
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 19; j++) {
				window.draw(board[i][j]);
			}
		}
		//These draw the pellets
		window.draw(pel.getPellet());
		pel.drawOnWindow(window);

		//This displays the cherry after 70 pellets have been eaten (just like the regular game)
		if (pEaten >= 70) {
			window.draw(fr.getFruit());
			if (arr[play.getY()][play.getX()] == 161 && fr.eaten(play.getY(), play.getX(), arr)) {
				score += 200;
			
			}
			if (score >= 1700) {//If the player stays too long without eating the pellet it dissapears
				fr.erase();
			}			
		}

		//This draws pacman (his position in the code makes him below the ghosts but above the fruit and pellets
		play.drawOnWindow(window);
		window.draw(play.getPlayer());
		
		//Draws the ghosts
		g.drawOnWindow(window);
		window.draw(g.getBlinky());
		window.draw(g.getPinky());
		window.draw(g.getInky());
		window.draw(g.getClyde());

		//This sets up the life on the screen
		life.setPosition(50, 20);
		window.draw(life);
		window.draw(title);

		//This is the random movement of the ghosts that will be changed to follow Pacman
		if (ghostC.getElapsedTime().asSeconds() > .3 && frozen) {
			int cpath = d.Dijkstra(d.Graph, arr[g.cgetY()][g.cgetX()], arr[play.getY()][play.getX()]);
			g.clydeMoveOnWindow(cpath, arr);
									
			int ipath = d.Dijkstra(d.Graph, arr[g.igetY()][g.igetX()], arr[play.getY()][play.getX()]);
			g.inkyMoveOnWindow(ipath, arr);
			
			int ppath = d.Dijkstra(d.Graph, arr[g.pgetY()][g.pgetX()], arr[play.getY()][play.getX()]);
			g.pinkyMoveOnWindow(ppath, arr);
			
			int bpath = d.Dijkstra(d.Graph, arr[g.bgetY()][g.bgetX()], arr[play.getY()][play.getX()]);
			g.blinkyMoveOnWindow(bpath, arr);
			
			ghostC.restart();
		}
		

		//This is the code that determines collison with the ghosts as well as the invinicibilty
		if (fright == 0 && frozen) {
			if (((arr[play.getY()][play.getX()] == arr[g.igetY()][g.igetX()]) || (arr[play.getY()][play.getX()] == arr[g.bgetY()][g.bgetX()]) || (arr[play.getY()][play.getX()] == arr[g.pgetY()][g.pgetX()]) || (arr[play.getY()][play.getX()] == arr[g.cgetY()][g.cgetX()]))) {
				lives -= 1;
				play.reset();
				//ghosts g(20);
			}
		}
		
		//This is just the code that draws the lives and updates it
		life.setString("Lives " + to_string(lives));

		//Lose condition and lose menu
		if (lives <= 0) {

			outScore << score << endl;
			
			outScore.close();
			print.open("highscore.txt");
			while (print >> hs) {
					bst.insert(hs);
			}
			
			window.draw(menu);
			window.draw(lose);
			window.draw(enter);
			frozen = false;
			
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				window.close();
			}
		}


		//Win condition and win menu
		if (pEaten == 156) {
			window.draw(menu);
			window.draw(win);
			window.draw(enter);
			frozen = false;
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				window.close();
			}
		}
		
		//Ready text
		if (!frozen && lives != 0 && pEaten !=156) {
			window.draw(ready);
		}
		window.display();
		
	}
	cout << "High scores!" << endl;
	bst.printInorder();
	return 0;
}
