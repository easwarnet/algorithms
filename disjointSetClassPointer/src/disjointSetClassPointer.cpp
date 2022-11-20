//============================================================================
// Name        : disjointSetClassPointer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		int weight;
		Node *parent;
		Node(int data): data(data),
						weight(0), 
						parent(this) 
		{
			
		};
		~Node() = default;
};

class DisjointSets {
	public:
	int nodesListSize;
	vector<Node *> nodesList;

	DisjointSets(int size): nodesListSize(size), nodesList(size, 0) {

	}

	void addToList(int val) {
		
		if (val < nodesListSize) {
			nodesList[val] = new Node(val);
		} else {
			cout << "Value not in range" << endl;
		}
	}

	void mergeNodes(int val1, int val2) {
		if((val1 < nodesListSize) && (val2 < nodesListSize)) {
			merge(nodesList[val1], nodesList[val2]);
		}
	}

	void printUnion() {
		for (int i = 0; i < nodesListSize; i++) {
			cout << "Parent: " << nodesList[i]->parent->data << " Child: " << nodesList[i]->data << endl;
		}
	}

	private:
	Node *find(Node *node) {
		if(node != node->parent) {
			node = find(node->parent);
		}
		return node->parent;
	}

	void merge(Node *node1, Node *node2) {
		node1 = find(node1);
		node2 = find(node2);

		if(node1->weight > node2->weight) {
			node2->parent = node1;
		} else {
			node1->parent = node2;
			if (node1->parent == node2->parent) {
				(node2->weight)++;
			}
		}
	}
};

int main() {
	DisjointSets disjointSets(10);

	for(int i=0; i<10;i++) {
		disjointSets.addToList(i);
	}
	disjointSets.printUnion();

	disjointSets.mergeNodes(3,1);
	disjointSets.mergeNodes(1,2);
	disjointSets.mergeNodes(2,4);
	disjointSets.mergeNodes(0,7);
	disjointSets.mergeNodes(8,9);
	disjointSets.printUnion();

	return 0;
}

/***********************************
Expect Output:
7 0
1 1
1 2
1 3
1 4
5 5
6 6
7 7
9 8
9 9

Tree:
  7     1       5    6   9
 /    / | \              |
0    2  3  4             8
***********************************/
