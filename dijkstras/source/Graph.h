#ifndef __GRAPH__
#define __GRAPH__

#include<string>


class Graph
{
public:
	Graph();
	~Graph() = default;

	void AddEdge(std::string source, std::string target, int weight);
	void AddVertex(std::string label);
	int GetIndex(std::string label) const; // -1 if label is not found
	bool IsEdge(int sourceIndex, int targetIndex) const;
	int GetWeight(int sourceIndex, int targetIndex) const;
	void BreadthFirstSearch(std::string startingVertex) const;
	void BreadthFirstSearch(std::string startingVertex, int visited[]) const;
	void DijkstraShortestPath(std::string startingVertex) const;
	void DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const;
	void PrintGraph() const;

//private:
	static const int MAX_VERTECIES = 10;

	int matrix[MAX_VERTECIES][MAX_VERTECIES];
	int numVerticies;
	std::string labels[MAX_VERTECIES];
};
#endif