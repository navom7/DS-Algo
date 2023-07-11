#include<iostream>

using namespace std;

void printBoard(int board[][9], int n) {
    cout << "--------> " << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}

bool isSafe(int n, int i, int j, int board[][9], int num) {
	for(int k = 0; k < n; k++) {
		if(board[i][k] == num || board[k][j] == num)
			return false;
	}

	int sx = (i/3)*3;
	int sy = (j/3)*3;
	for(int x = 0; x < 3; x++) {
		for(int y = 0; y < 3; y++) {
			if(board[sx+x][sy+y] == num)
				return false;
		}
	}
	
	return true;

}

bool sudokuSolver(int board[][9], int i, int j, int n) {
	if(i == n) {
		printBoard(board, n);
		return true;
	}
	if(j == n) {
		return sudokuSolver(board, i+1, 0, n);
	}
	if(board[i][j] != 0) {
		return sudokuSolver(board, i, j+1, n);
	}

	for(int num = 1; num < 10; num++) {
		if(isSafe(n, i, j, board, num)) {
			board[i][j] = num;
			bool solveSubProblem = sudokuSolver(board, i, j+1, n);
			if(solveSubProblem) {
				return true;
			}
		}
	}
	
	board[i][j] = 0;
	return false;

}


int main() {
	

	int board[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0} };
	sudokuSolver(board, 0, 0, 9);

	return 0;
}