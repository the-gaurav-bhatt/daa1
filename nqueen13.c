#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

int queensInColumn[20];

// Function to determine if a queen can be placed on the board at column col and row row.
int canPlaceQueen(int col, int row) {

    for (int i = 1; i <= col; i++) {
        // Check if there's any queen in the same row or on the diagonals.
        if ((queensInColumn[i] == row) || (abs(queensInColumn[i] - row) == abs(i - col))) {
            return FALSE;
        }
    }   
    return TRUE; // If no queens found in the same row or on the diagonals, return true
}

// Recursive function to solve the N-Queens problem
void solveNQueens(int col, int n) {
    int row, a;
    
    for (row = 1; row <= n; row++) {
        // For a given column (col), we will try all rows (from 1 to n) to place the queen.
        if (canPlaceQueen(col, row)) {
            queensInColumn[col] = row; // Record in the array that a queen is placed at row "row" in column "col".
            
            if (col == n) {
                // If all queens are placed, print the board configuration
                for (a = 1; a <= n; a++) {
                    printf("%d\t", queensInColumn[a]);
                }
                printf("\n");
            } else {
                solveNQueens(col + 1, n); // Try to place the next queen in the next column.
            }
        }
    }
}

int main() {
    int n;

    // Input the number of queens to be placed on an nxn chessboard.
    printf("\nEnter the number of queens:");
    scanf("%d", &n);
    printf("\n Solutions to the N-Queens problem are: \n");

    // Try to find solutions starting from the first column
    solveNQueens(1, n);

    return 0;
}
