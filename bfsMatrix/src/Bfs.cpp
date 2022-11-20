//============================================================================
// Name        : Bfs.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

bool isValid(int cursor_row, int cursor_col, vector<vector<bool>> &visited,int xsize, int ysize) {
	if((cursor_row < 0) || (cursor_row >= xsize) || (cursor_col < 0) || (cursor_col >= ysize) || (visited[cursor_row][cursor_col])) {
		return false;
	}
	return true;
}

void bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col, int xsize, int ysize) {
	queue<pair<int, int>> q;
	q.push({row, col});
	visited[row][col] = true;
	while (!q.empty())
	{
		int cursor_row = q.front().first;
		int cursor_col = q.front().second;
		cout << matrix[cursor_row][cursor_col] << endl;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int adjX = cursor_row + dRow[i];
			int adjY = cursor_col + dCol[i];
			if(isValid(adjX, adjY, visited, xsize, ysize)) {
				q.push({adjX, adjY});
				visited[adjX][adjY] = true;
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

	int xsize = matrix.size();
	int ysize = matrix[0].size();

	vector<vector<bool>> visited;

	visited.resize(xsize, vector<bool>(ysize));

	bfs(matrix, visited, 0, 0, xsize, ysize);
}













# if 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 4

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
//  1
// 4 0 2
//  3

bool isValid(bool visited[][COL], int row, int col)
{
	if ((row < 0) || (row >= ROW) || (col < 0) || (col >= COL))
	{
		return false;
	}

	if (visited[row][col])
	{
		return false;
	}

	return true;
}

void bfs(int grid[][COL], bool visited[][COL], int row, int col)
{
	queue<pair<int, int>> q;
	q.push({row, col});
	visited[row][col] = true;

	while (!q.empty())
	{
		pair<int, int> top = q.front();
		int row = top.first;
		int col = top.second;
		q.pop();
		cout << grid[row][col] << " ";

		for (int i = 0; i < 4; i++)
		{
			int adjX = row + dRow[i];
			int adjY = col + dCol[i];
			if (isValid(visited, adjX, adjY))
			{
				q.push({adjX, adjY});
				visited[adjX][adjY] = true;
			}
		}
	}
}

int main()
{
	int grid[ROW][COL] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}};

	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));
	bfs(grid, visited, 0, 0);
}
#endif
