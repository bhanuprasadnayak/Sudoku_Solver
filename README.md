# Sudoku Solver 🧩

A console-based Sudoku Solver written in **C++** using the **Backtracking Algorithm**.

The program supports both **6 × 6** and **9 × 9** Sudoku puzzles. Users can enter a Sudoku puzzle, and the program automatically finds and displays a valid solution if one exists.

## ✨ Features

* 🔢 Supports **6 × 6 Sudoku**
* 🔢 Supports **9 × 9 Sudoku**
* 🧠 Uses **recursive backtracking** to solve the puzzle
* ✅ Checks whether a number can safely be placed in a cell
* 📥 Accepts Sudoku input row-by-row
* 🖨️ Displays the original and solved Sudoku boards
* ❌ Detects Sudoku puzzles with no possible solution
* 💻 Simple command-line interface

## 🛠️ Technologies Used

* **C++**
* Object-Oriented Programming
* Recursion
* Backtracking
* 2D Arrays
* Dynamic Memory Allocation

## 📋 How It Works

The program first asks the user to select the Sudoku size:

```text
1. 6 x 6 Sudoku
2. 9 x 9 Sudoku
```

The user then enters each row as a sequence of digits.

Use:

```text
0
```

for an empty cell.

For example, a 9 × 9 Sudoku row can be entered as:

```text
000900042
```

The program validates the input size and then attempts to solve the puzzle.

## 🧠 Solving Algorithm

The solver uses **recursive backtracking**.

For every empty cell:

1. Try numbers from `1` to the Sudoku size.
2. Check whether the number is valid in the current row.
3. Check whether the number is valid in the current column.
4. Check whether the number is valid in the corresponding sub-grid.
5. Place the number if it is valid.
6. Recursively continue solving.
7. If the choice leads to an invalid state, undo the placement and try another number.

This process continues until the Sudoku is completely solved or all possibilities have been exhausted.

## 📐 Sudoku Rules

### 9 × 9 Sudoku

The board is divided into **3 × 3 boxes**.

A number cannot be repeated in:

* The same row
* The same column
* The same 3 × 3 box

### 6 × 6 Sudoku

The board is divided into **2 × 3 boxes**.

A number cannot be repeated in:

* The same row
* The same column
* The same 2 × 3 box

The program automatically adjusts these rules depending on the selected Sudoku size.

## ▶️ Compilation and Execution

### Compile

```bash
g++ sudoku_solver.cpp -o sudoku_solver
```

### Run

```bash
./sudoku_solver
```

## 🎮 Example

```text
=========================
      SUDOKU SOLVER
=========================

1. 6 x 6 Sudoku
2. 9 x 9 Sudoku

Enter your choice: 2
```

Then enter the Sudoku row by row:

```text
000900042
000006001
009407060
093048600
045000010
081560394
367004005
050200406
020070000
```

The program displays the original Sudoku and then the solved Sudoku.

## 📂 Project Structure

```text
Sudoku-Solver/
│
├── sudoku_solver.cpp
└── README.md
```

## 📚 Concepts Practiced

This project was built to practice:

* Classes and Objects
* Arrays
* Conditional Statements
* Loops
* Functions
* Recursion
* Backtracking
* Dynamic Memory Allocation
* Problem Solving

## 🚀 Future Improvements

Possible improvements for future versions:

* Add a graphical user interface
* Add support for more Sudoku sizes
* Add puzzle generation
* Add difficulty levels
* Add input validation for invalid characters
* Add a step-by-step solving mode
* Improve the solving algorithm using heuristics such as **Minimum Remaining Values (MRV)**

A C++ project created to explore recursion, backtracking, and algorithmic problem solving.
