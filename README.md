# Sudoku-Solver
A C++ Sudoku solver that takes an unsolved Sudoku puzzle as input and uses an recursive backtracking algorithm to solve the puzzle

The program have the following features:

Input: The program take input in the form of a 9x9 grid, where each cell can contain a number from 1 to 9 or be left blank.

Algorithm: The program use a backtracking algorithm to solve the puzzle. The algorithm works by trying to fill in each cell with a number from 1 to 9. If a number is found that violates the rules of Sudoku, the algorithm backtracks to the previous cell and tries a different number.

rules of sudoku: 
 -> Each row must contain all numbers from 1 to 9 exactly once.
 -> Each column must contain all numbers from 1 to 9 exactly once.
 -> Each of the 9 sub-grids (3x3) must contain all numbers from 1 to 9 exactly once.

Output: Once the puzzle is solved, the program output the solved puzzle in the same format as the input.
