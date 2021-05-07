#include <iostream>
#include "engine.cpp"

int main() {
  int grid[gridSize][gridSize];

/*
example:
0 0 7 9 0 0 6 3 1
0 0 0 1 0 3 0 4 0
1 0 0 0 0 5 0 0 9
6 0 4 8 3 0 0 0 5
0 0 9 0 0 0 1 0 0
2 0 0 0 1 7 9 0 4
5 0 0 3 0 0 0 0 8
0 9 0 4 0 2 0 0 0
8 4 6 0 0 1 3 0 0
*/

  std::cout << "Enter the Sudoku grid (Use 0 for empty cells): " << std::endl;
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      std::cin >> grid[i][j];
    }
  }

  std::cout << std::endl;
 
  if (solveSudoku(grid) == true) {
    std::cout << "Solution: " << std::endl;
    displayGrid(grid);
  } else {
    std::cout << "No solution exists. " << std::endl;
    std::cout << "Are you sure you entered it correctly?" << std::endl;
  }
  return 0;
}