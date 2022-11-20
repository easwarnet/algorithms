//============================================================================
// Name        : Dfs.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 4

int dRow[] = {0, 1, 0, -1};
int dCol[] = {-1, 0, 1, 0};

//  4
// 1   3
//  2
bool isValid(vector<vector<bool>> &visited, int row, int col, int rowsize, int colsize) {
	if((row < 0) || (row >= rowsize) || (col < 0) || (col >= colsize)) {
		return false;
	}
	if ((visited[row][col] == true)) {
		return false;
	}
	return true;
}

void dfsRecursive(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col, int rowsize, int colsize) {
	visited[row][col] = true;
	cout << matrix[row][col] << " ";
	for(int i=0;i<4;i++) {
		int rowAdj = row + dRow[i];
		int colAdj = col + dCol[i];
		if(isValid(visited, rowAdj, colAdj, rowsize, colsize)) {
			dfsRecursive(matrix, visited, rowAdj, colAdj, rowsize, colsize);
		}
	}
}

void dfsIterative(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col, int rowsize, int colsize) {
	stack<pair<int, int>> s;
	s.push({row, col});
	visited[row][col] = true;
	while (!s.empty()) {
		row = s.top().first;
		col = s.top().second;
		cout << matrix[row][col] << " ";
		s.pop();
		for (int i = 0; i < 4; i++)
		{
			int adjRow = row + dRow[i];
			int adjCol = col + dCol[i];
			if(isValid(visited, adjRow, adjCol, rowsize, colsize)) {
				s.push({adjRow, adjCol});
				visited[adjRow][adjCol] = true;
			}
		}
	}
}

int main()
{
	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	vector<vector<bool>> visited;
	visited.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
	vector<vector<bool>> visitedIterative;
	visitedIterative.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
	cout << matrix.size() << " " << matrix[0].size() << endl;
	cout << "Dfs Recursive" << endl;
	dfsRecursive(matrix, visited, 0, 0, matrix.size(), matrix[0].size());
	cout << endl << "Dfs Iterative" << endl;
	dfsIterative(matrix, visitedIterative, 0, 0, matrix.size(), matrix[0].size());

}

