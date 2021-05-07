#include <iostream>

const int emptyCell = 0; 
const int gridSize = 9;
 
bool usedInRow(int grid[gridSize][gridSize], int row, int number) {
  for (int col = 0; col < gridSize; col++)
    if (grid[row][col] == number) {
      return true;
    }
  return false;
}
 
bool usedInCol(int grid[gridSize][gridSize], int col, int number) {
  for (int row = 0; row < gridSize; row++)
    if (grid[row][col] == number)
      return true;
  return false;
}
 
bool usedInBox(int grid[gridSize][gridSize], int row, int col, int number) {
  int boxStartRow = row - row % 3;
  int boxStartCol = col - col % 3;
  for (int ii = 0; ii < 3; ii++)
    for (int jj = 0; jj < 3; jj++)
      if (grid[boxStartRow + ii][boxStartCol + jj] == number)
        return true;
  return false;
}
 
bool isValid(int grid[gridSize][gridSize], int row, int col, int number) {
  return !usedInRow(grid, row, number) &&
       !usedInCol(grid, col, number) &&
       !usedInBox(grid, row, col, number);
}
 
bool findemptyCellLocation(int grid[gridSize][gridSize], int &row, int &col) {
  for (row = 0; row < gridSize; row++)
    for (col = 0; col < gridSize; col++)
      if (grid[row][col] == emptyCell)
        return true;
  return false;
}
 
bool solveSudoku(int grid[gridSize][gridSize]) {
  int row, col;
 
  if (!findemptyCellLocation(grid, row, col)) {
    return true;
  }
 
  for (int number = 1; number <= 9; number++) {
    if (isValid(grid, row, col, number)) {
      grid[row][col] = number;
 
      if (solveSudoku(grid)) {
        return true;
      }
 
      grid[row][col] = emptyCell;
    }
  }
  return false; // Start backtracking
}
 
void displayGrid(int grid[gridSize][gridSize]) {
  for (int row = 0; row < gridSize; row++) {
    for (int col = 0; col < gridSize; col++)
      std::cout << grid[row][col] << " ";
    std::cout << std::endl;
  }
}