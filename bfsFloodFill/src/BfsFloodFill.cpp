//============================================================================
// Name        : BfsFloodFill.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int cursor_row, int cursor_col, vector<vector<char>> &matrix, char target, int rowSize, int colsize) {
	if((cursor_row < 0) || (cursor_row > rowSize) || (cursor_col < 0) || (cursor_col > colsize)) {
		return false;
	}
	if (matrix[cursor_row][cursor_col] != target) {
		return false;
	}
	return true;
}

void floodFill(vector<vector<char>> &matrix, int startRow, int startCol, char replacement, int rowSize, int colsize) {
	queue<pair<int, int>> q;
	pair<int, int> coord;
	char target = matrix[startRow][startCol];
	coord.first = startRow;
	coord.second = startCol;
	q.push(coord);
	while (!q.empty())
	{
		//cout <<  << q.front().first <<
		pair<int, int> cursor_coord = q.front();
		int cursor_row = cursor_coord.first;
		int cursor_col = cursor_coord.second;
		matrix[cursor_row][cursor_col] = replacement;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int adjX = cursor_row + row[i];
			int adjY = cursor_col + col[i];
			if(isValid(adjX, adjY, matrix, target, rowSize, colsize)) {
				q.push({adjX, adjY});
			}
		}
	}

}

int main()
{
	vector<vector<char>> matrix = {
	        { 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
	        { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X', 'G' },
	        { 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X', 'G' },
	        { 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X', 'G' },
	        { 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X', 'G' },
	        { 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X', 'G' },
	        { 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X', 'G' },
	        { 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X', 'G' },
	        { 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X', 'Y' },
	        { 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'Y' }
	};
	int rowsize = matrix.size();
	int colsize = matrix[0].size();
	for (vector<vector<char>>::iterator itx = matrix.begin(); itx != matrix.end(); itx++)
	{
		for (vector<char>::iterator ity = itx->begin(); ity != itx->end(); ity++)
		{
			cout << *ity << " ";
		}
		cout << endl;
	}
	cout << endl;
	floodFill(matrix, 0, 0, 'E', rowsize, colsize);

	for (vector<vector<char>>::iterator itx = matrix.begin(); itx != matrix.end(); itx++)
	{
		for (vector<char>::iterator ity = itx->begin(); ity != itx->end(); ity++)
		{
			cout << *ity << " ";
		}
		cout << endl;
	}

}

