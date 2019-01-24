#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValid(int row, int col, vector<string> board)
{
	for (int i = 0; i < row; i++){
		for (int j = 0; j < board[i].size(); j++){
			if (board[i][j] == 'Q')	{
				if (abs(row - i) == abs(col - j) || j == col)
					return false;
			}
		}
	}
	return true;
}

void dfs(int row, vector<string> &board, vector<vector<string>> &res)
{
	if (row == board.size())
	{
		res.push_back(board);
		return;
	}
	for (int i = 0; i < board.size(); i++)
	{
		if (isValid(row, i, board))
		{
			board[row][i] = 'Q';
			dfs(row + 1, board, res);
			board[row][i] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<string> board(n, string(n, '.'));
	vector<vector<string>> res;
	dfs(0, board, res);
	return res;
}

int main()
{
	solveNQueens(4);
	getchar();
	return 0;
}