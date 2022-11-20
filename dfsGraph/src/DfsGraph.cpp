//============================================================================
// Name        : DfsGraph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// DFS algorithm in C++

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

class DfsRecursiveGraph
{
private:
	int totalvertices;
	list<int> *adj;

public:
	DfsRecursiveGraph(int totalvertices) {
		this->totalvertices = totalvertices;
		adj = new list<int>[totalvertices];
	};

	~DfsRecursiveGraph() = default;

	void addEdge(int vertex, int value) {
		adj[vertex].push_back(value);
	}

	void Dfs(int vertex,vector<bool> &visited) {
		cout << vertex << endl;
		visited[vertex] = true;

		for (list<int>::iterator it = adj[vertex].begin(); it != adj[vertex].end(); it++)
		{
			if(!visited[*it]) {
				Dfs(*it, visited);
			}
		}
		
	}

	void DfsInit(int start) {
		vector<bool> visited;
		visited.resize(totalvertices, false);

		Dfs(start, visited);
	}


};

void dfsRecursive() {
	DfsRecursiveGraph dfsRecursiveGraph(6);
	dfsRecursiveGraph.addEdge(0, 1);
	dfsRecursiveGraph.addEdge(0, 2);

	dfsRecursiveGraph.addEdge(1, 0);
	dfsRecursiveGraph.addEdge(1, 3);
	dfsRecursiveGraph.addEdge(1, 4);

	dfsRecursiveGraph.addEdge(2, 0);
	dfsRecursiveGraph.addEdge(2, 4);

	dfsRecursiveGraph.addEdge(3, 1);
	dfsRecursiveGraph.addEdge(3, 4);
	dfsRecursiveGraph.addEdge(3, 5);

	dfsRecursiveGraph.addEdge(4, 1);
	dfsRecursiveGraph.addEdge(4, 2);
	dfsRecursiveGraph.addEdge(4, 3);
	dfsRecursiveGraph.addEdge(4, 5);

	dfsRecursiveGraph.addEdge(5, 3);
	dfsRecursiveGraph.addEdge(5, 4);

	dfsRecursiveGraph.DfsInit(0);
}

class DfsIterativeGraph {
	private:
	int totalvertices;
	list<int> *adj;

	public:
	DfsIterativeGraph(int totalvertices){
		this->totalvertices = totalvertices;
		adj = new list<int>[totalvertices];
	}

	void addEdge(int vertex, int value) {
		adj[vertex].push_back(value);
	}

	void Dfs(int vertex) {
		vector<bool> visited;
		visited.resize(totalvertices, false);
		stack<int> s;
		s.push(vertex);
		
		while(!s.empty()) {
			int value = s.top();
			s.pop();
			if(!visited[value]) {
				cout << value << endl;
				visited[value] = true;
			}

			for(list<int>::iterator it=adj[value].begin(); it != adj[value].end(); it++) {
				if(!visited[*it]) {
					s.push(*it);
				}
			}
		}
	}
};

void dfsIterative() {
    DfsIterativeGraph g(6); // Total 5 vertices in graph
	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 0);
	g.addEdge(2, 4);

	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);

	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	g.addEdge(5, 3);
	g.addEdge(5, 4);
    g.Dfs(0);
}

int main() {
	dfsRecursive();
	cout << "----" << endl;
	dfsIterative();

	return 0;
}

