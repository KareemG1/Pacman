#include "DijkestraFormula.h"
DijkestraFormula::DijkestraFormula(int arr[][19]) {

	for (int i = 0; i < COUNT; i++)
		for (int j = 0; j < COUNT; j++) {
			Graph[i][j] = 0;
		}

	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 19; j++) {
			if (arr[i][j] >= 0) { // Vertex: 0
				if (i < 22 && arr[i + 1][j] >= 0) {
					Graph[arr[i][j]][arr[i + 1][j]] = 1;
				}
				if (i >= 0 && arr[i - 1][j] >= 0) {
					Graph[arr[i][j]][arr[i - 1][j]] = 1;
				}
				if (j >= 0 && arr[i][j - 1] >= 0) {
					Graph[arr[i][j]][arr[i][j - 1]] = 1;
				}
				if (j < 19 && arr[i][j + 1] >= 0) {
					Graph[arr[i][j]][arr[i][j + 1]] = 1;
				}
			}
		}


}
int DijkestraFormula::Dijkstra(int Graph[COUNT][COUNT], int startNode, int endnode)
{

	int temp[COUNT][COUNT], costs[COUNT], previous[COUNT];
	bool visited[COUNT];
	// temp
	for (int i = 0; i < COUNT; i++)
		for (int j = 0; j < COUNT; j++)
			if (Graph[i][j] == 0)
				temp[i][j] = INFINITE;
			else
				temp[i][j] = Graph[i][j];
	// costs, previous, and visited
	for (int i = 0; i < COUNT; i++)
	{
		costs[i] = temp[startNode][i];
		previous[i] = startNode;
		visited[i] = false;
	}
	// startNode
	costs[startNode] = 0;
	visited[startNode] = true;

	int count = 1, nextNode, minimumCost;
	while (count < COUNT)
	{
		// Find the minimum cost in order to visit a node.
		minimumCost = INFINITE;
		for (int i = 0; i < COUNT; i++)
			if ((costs[i] < minimumCost) && (visited[i] == false))
			{
				minimumCost = costs[i];
				nextNode = i;
			}
		// Visit the node.
		visited[nextNode] = true;
		// Update the costs of the children of the visited node.
		for (int i = 0; i < COUNT; i++)
			if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
			{
				costs[i] = minimumCost + temp[nextNode][i];
				previous[i] = nextNode;
			}
		count++;
	}

	int jMany;
	int j;
	vector<vector<int>> pathsMany;
	pathsMany.resize(COUNT);
	for (int i = 0; i < COUNT; i++)
	{
		pathsMany[i].push_back(i);
		if (i != startNode)
		{
			j = endnode;
			do
			{
				j = previous[j];
				//cout << j << endl;
				pathsMany[i].insert(pathsMany[i].begin(), j);
			} while (j != startNode);
		}
	}
	int firstMovement = pathsMany[endnode][1];
	return firstMovement;
}