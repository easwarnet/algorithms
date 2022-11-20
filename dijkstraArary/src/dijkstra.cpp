//============================================================================
// Name        : dijkstra.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits.h>
using namespace std;

#define V 9

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

int minDistance(int distance[], bool visited[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < V; i++)
	{
		if(!visited[i] && distance[i] <= min) {
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

void dijkstra(int matrix[V][V], int src) {
	bool visited[V];
	int distance[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		distance[i] = INT_MAX;
	}

	distance[src] = 0;

	for (int i = 0; i < V-1; i++)
	{
		int u = minDistance(distance, visited);
		visited[u] = true;
		for (int v = 0; v < V; v++)
		{
			if(!visited[v] && matrix[u][v] && (distance[u] != INT_MAX) && (distance[u] + matrix[u][v] < distance[v])) {
				distance[v] = distance[u] + matrix[u][v];
			}
		}
		
	}
	
	printSolution(distance);

}

int main() {
						//0, 1, 2, 3,  4, 5, 6,  7, 8
	int graph[V][V] = { { 0, 4, 0, 0,  0, 0, 0,  8, 0 },//0
						{ 4, 0, 8, 0,  0, 0, 0,  8, 0 },//1
						{ 0, 8, 0, 7,  0, 4, 0,  0, 2 },//2
						{ 0, 0, 7, 0,  9, 14, 0, 0, 0 },//3
						{ 0, 0, 0, 9,  0, 10, 0, 0, 0 },//4
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },//5
						{ 0, 0, 0, 0,  0,  2, 0, 1, 6 },//6
						{ 8, 11, 0, 0, 0,  0, 1, 0, 7 },//7
						{ 0, 0,  2, 0, 0,  0, 6, 7, 0 } //8
					};

	dijkstra(graph, 0);
}
