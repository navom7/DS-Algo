#include<iostream>

using namespace std;

void printBoard(int board[][20], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << board[i][j] << "| ";
		}
		cout << endl;
	}
}

bool isSafe(int sz, int i, int j, int board[][20]) {
	int k = i;
	while(k >= 0) {
		if(board[k][j] == 1) {
			return false;
		}
		k--;
	}
	int m = i;
	int n = j;
	while(m-- >= 0 && n-- >= 0) {
		if(board[m][n] == 1) {
			return false;
		}
	}
	m = i;
	n = j;
	while(m-- >= 0 && n++ < sz) {
		if(board[m][n] == 1) {
			return false;
		}
	}
	return true;
}

bool solveNQueen(int n, int board[][20], int i) {
	//base case
	if(i == n) {
		printBoard(board, n);
		return true;
	}
	for(int j = 0; j < n; j++) {
		if(isSafe(n, i, j, board)) {
			board[i][j] = 1;
			bool success = solveNQueen(n, board, i+1);
			if(success) {
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}


int main() {
	

	int board[20][20] = {0};
	solveNQueen(8, board, 0);

	return 0;
}