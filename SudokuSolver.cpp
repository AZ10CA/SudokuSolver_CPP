/// Sudoku Solver Version 2.1

#include "SudokuSolver.h"

void SudokuSolver::search(const int& row, const int& col){
    recursive_calls++;
    if(col == COLUMNS)
        return search(row + 1, 0);

    if(row == ROWS){
        print();
        solutions++;
        return;
    }

    for(int i = MIN; i < MAX + 1; i++){
        // Early pruning
        /// 9 ^ 81 operations without early pruning
        if(matrix[row][col])
            return search(row, col + 1);
        if(rows[row][i] || cols[col][i] || hasSquare(row, col, i))
            continue;

        // Recording initial states
        State initial_row_state = rows[row];
        State initial_col_state = cols[col];
        State initial_square_state = squares[row / SQUARE_ROWS][col / SQUARE_COLUMNS];

        // Changing states
        matrix[row][col] = i;
        rows[row].set(i);
        cols[col].set(i);
        squares[row / SQUARE_ROWS][col / SQUARE_COLUMNS].set(i);

        // Searching with new states
        search(row, col + 1);

        // Restoring previous states
        matrix[row][col] = 0;
        rows[row] = initial_row_state;
        cols[col] = initial_col_state;
        squares[row / SQUARE_ROWS][col / SQUARE_COLUMNS] = initial_square_state;
    }
}

int SudokuSolver::get_recursive_calls() const {
    return recursive_calls;
}

int SudokuSolver::get_number_of_solutions() const {
    return solutions;
}

void SudokuSolver::read_board(){
    std::ifstream reader;
    reader.open(file_name);
    assert(reader.is_open());
    while(reader){
        char space;
        for(int i = 0; i < ROWS; i++)
            for(int j = 0; j < COLUMNS; j++) {
                reader >> matrix[i][j];
                reader.get(space);
            }
    }
}

void SudokuSolver::reset(){
    solutions = 0;
    recursive_calls = 0;
}

void SudokuSolver::solve(){
    reset();
    set_bitmasks_state();
    search(0, 0);
}

void SudokuSolver::set_file_name(const char *f_name) {
    delete[] file_name;
    int length = str_len(f_name);
    file_name = new char[length + 1];
    str_cpy(f_name, file_name);
}
