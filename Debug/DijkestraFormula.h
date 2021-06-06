#include <iostream>
#include <vector>
using namespace std;
const int COUNT = 191;
const int INFINITE = 9999;

class DijkestraFormula
{
	
public:
	int Graph[COUNT][COUNT];
	DijkestraFormula(int arr[][19]);
	//int Dijkstra(int startNode, int endnode);
	int Dijkstra(int Graph[COUNT][COUNT], int startNode, int endNode);
};

