//============================================================================
// Name        : BfsGraph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class BfsGraph
{
private:
	int no;
	vector<list<int>> vertices;

public:
	BfsGraph(int no) {
		this->no = no;
		vertices.resize(no);
	}

	~BfsGraph() {

	}

	void addVertices(int vertex, int value) {
		vertices[vertex].push_back(value);
	}

	void Bfs(int vertex) {
		queue<int> q;
		vector<bool> visited;
		visited.resize(no, false);

		visited[vertex] = true;
		q.push(vertex);
		while (!q.empty())
		{
			vertex = q.front();
			cout << vertex << " ";
			q.pop();
			for (auto adjVertex : vertices[vertex])
			{
				if(!visited[adjVertex]) {
					visited[adjVertex] = true;
					q.push(adjVertex);
				}
			}
			
		}
		
	}

};

int main() {
	BfsGraph bfsGraph(4);
	bfsGraph.addVertices(0, 1);
	bfsGraph.addVertices(0, 2);
	bfsGraph.addVertices(1, 2);
	bfsGraph.addVertices(2, 0);
	bfsGraph.addVertices(2, 3);
	bfsGraph.addVertices(3, 3);

	bfsGraph.Bfs(2);

	return 0;
}
