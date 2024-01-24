#include "Graph.h"
#include <string>
#include<iostream>
#include<set>
#include<queue>
#include<climits>

Graph::Graph()
{
	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		for (int j = 0; j < MAX_VERTECIES; j++)
		{
			matrix[i][j] = INT_MAX; // row X column
		}
	}
	numVerticies = 0;
}

void Graph::AddEdge(std::string source, std::string target, int weight)
{
	int from = GetIndex(source);
	int to = GetIndex(target);

	matrix[from][to] = weight;
	return;
}

void Graph::AddVertex(std::string label)
{
	if (numVerticies >= MAX_VERTECIES)
		return;
	labels[numVerticies++] = label;
	return;
}

int Graph::GetIndex(std::string label) const
{
	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		if (label == labels[i])
			return i;
	}
	return -1;
}

bool Graph::IsEdge(int sourceIndex, int targetIndex) const
{
	if (matrix[sourceIndex][targetIndex] != 0)
	{
		return true;
	}
	return false;
}

int Graph::GetWeight(int sourceIndex, int targetIndex) const
{
	return matrix[sourceIndex][targetIndex];
}

void Graph::BreadthFirstSearch(std::string startingVertex) const
{
	int visited[MAX_VERTECIES];
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		visited[i] = -1;
	}

	BreadthFirstSearch(startingVertex, visited);

	std::cout << "starting BFS with vertex " << startingVertex << std::endl;

	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		if (visited[i] == -1)
			break;
		std::cout << "\t visited " << labels[visited[i]] << std::endl;
	}

	std::cout << std::endl;

}

void Graph::BreadthFirstSearch(std::string startingVertex, int visited[]) const
{
	std::queue<int> frontier;
	std::queue<int> visitedQ;
	int currentV;
	frontier.push(GetIndex(startingVertex));
	visitedQ.push(GetIndex(startingVertex));
	visited[GetIndex(startingVertex)] = 0;

	while (!frontier.empty())
	{
		currentV = frontier.front();
		frontier.pop();

		for (size_t i = 0; i < MAX_VERTECIES; i++)
		{
			if (matrix[currentV][i] < INT_MAX && visited[i] == -1)
			{
				frontier.push(i);
				visited[i] = i;
				visitedQ.push(i);
			}
		}
	}
	// reinitialize the visited array to all negetive ones
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		visited[i] = -1;
	}
	/// the visited array with the appropriate vertexes
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		if (visitedQ.empty())
			return;
		visited[i] = visitedQ.front();
		visitedQ.pop();
	}
}

void Graph::DijkstraShortestPath(std::string startingVertex) const
{
	
	int distance[MAX_VERTECIES];
	int prevVertex[MAX_VERTECIES];

	//initialize the distance to infinity and initialize the distance from the starting vertex to the previous vertex to -1;
	/*for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		distance[i] = INT_MAX;
		PrevVertex[i] = -1;

	}*/

	DijkstraShortestPath(startingVertex, distance, prevVertex);

	// using the distance array display shortest paths and lengths
	std::cout << "Shortest Distance starting from vertex " << startingVertex << std::endl;

	for (size_t i = 0; i < numVerticies; i++)
	{
		std::cout << "\tto: " << labels[i] << "\t";
		if (distance[i] == INT_MAX)
			std::cout << "no path\n";
		else
		{
			std::cout << distance[i] << "\tPath: ";
			int path = i;
			while (path != -1)
			{
				if (prevVertex[path] == -1)
				{
					std::cout << labels[path] << "\n";
					break;
				}
				std::cout << labels[path] << ", " ;
				path = prevVertex[path];
			}
			//std::cout << "\n";
			//std::cout << labels[i] << "\n";
		}
	}
	std::cout << "\n";
}

bool Empty(int unVisit[])
{
	int sum = 0;
	for (size_t i = 0; i < 6; i++)
		sum += unVisit[i];
	if (sum < 0)
		return true;
	return false;
}
int findMin(int unVisit[], int distance[]) //this needs to return the index of the lowest distance in the array
{
	int min = INT_MAX;
	for (size_t i = 0; i < 6; i++)
	{
		if (distance[unVisit[i]] < min && unVisit[i] != -1)
			min = distance[unVisit[i]];
	}
	for (size_t i = 0; i < 6; i++)
	{
		if (distance[unVisit[i]] == min)
		{
			unVisit[i] = -1;
			return i;
		}
	}
    return min;
}

void Graph::DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const
{
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		distance[i] = INT_MAX;
		prevVertex[i] = -1;

	}
	
	int startV = GetIndex(startingVertex);
	int currentV;
	int weight;
	int APD;
	distance[startV] = 0;
	int unVisit[6];

	for (size_t i = 0; i < 6; i++)
		unVisit[i] = i;
	
	while (Empty(unVisit) == false)
	{
		currentV = findMin(unVisit, distance);
		if (distance[currentV] == INT_MAX)
			return;
		for (size_t i = 0; i < MAX_VERTECIES; i++)
		{
			if (matrix[currentV][i] < INT_MAX)
			{
				weight = matrix[currentV][i];
				APD = distance[currentV] + weight;
				if (APD < distance[i])
				{
					distance[i] = APD;
					prevVertex[i] = currentV;
				}
			}
		}
	}




	
}
// the distance array tells you how far a vertex is form the starting vertex
	/*
		for example: if we start at B then our distance array should look like this
read B to: A    B   C   D   E   F
		| inf | 0 | 8 | 9 | 9 | 6 |
	index: 0    1   2   3   4   5
	inf means there is no path from B to A;
	0 means that is where we start
	*/

void Graph::PrintGraph() const
{
	/*
	this method of printing is garbage i need to use a nested for loop instead fix this before you submit!!!!!!!
	*/
	// first line
	std::cout << "numVerticies: " << numVerticies << std::endl;
	std::cout << "\tA\tB\tC\tD\tE\tF\n";
	char mark = 'A';
	int row = 0;
	int column = 0;
	while (mark <= 70)
	{
		std::cout << mark;
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << '\t';// << matrix[row][i];
			if (matrix[row][i] == INT_MAX)
				std::cout << "";
			else
				std::cout << matrix[row][i];
		}
		std::cout << std::endl;
		row++;
		mark++;
	}
}