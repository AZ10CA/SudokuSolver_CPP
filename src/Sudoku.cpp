//
// Created by Alireza Zahedi on 2021-05-29.
//

#include <iostream>
#include "../include/Sudoku.h"

void Sudoku::set_squares_state(){
    for(int d = 0; d < ROWS / SQUARE_ROWS; d++)
        for(int r = 0; r < COLUMNS / SQUARE_COLUMNS; r++){
            State state;
            for(int i = 0; i < SQUARE_ROWS; i++)
                for(int j = 0; j < SQUARE_COLUMNS; j++)
                    state.set(matrix[i + d * SQUARE_ROWS][j + r * SQUARE_COLUMNS]);

            squares[d][r] = state;
        }
}

void Sudoku::set_columns_state(){
    for(int i = 0; i < ROWS; i++){
        State col_state;
        for(int j = 0; j < COLUMNS; j++)
            col_state.set(matrix[j][i]);
        col_state[0] = false;
        cols[i] = col_state;
    }
}

void Sudoku::set_rows_state(){
    for(int i = 0; i < ROWS; i++){
        State row_state;
        for(int j = 0; j < COLUMNS; j++)
            row_state.set(matrix[i][j]);
        row_state[0] = false;
        rows[i] = row_state;
    }
}

void Sudoku::set_bitmasks_state(){
    set_columns_state();
    set_rows_state();
    set_squares_state();
}

bool Sudoku::hasSquare(const int& row, const int& col, const int& val){
    return squares[row / SQUARE_ROWS][col / SQUARE_COLUMNS][val];
}

void Sudoku::print() const {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << '\n';
    }
}

Sudoku::~Sudoku(){
    delete[] rows;
    delete[] cols;

    for(int i = 0; i < SQUARE_ROWS; i++)
        delete[] squares[i];
    delete[] squares;

    for(int i = 0; i < ROWS; i++)
        delete[] matrix[i];
    delete[] matrix;
}

Sudoku::Sudoku(){
    rows = new State[ROWS];
    cols = new State[COLUMNS];

    squares = new State*[SQUARE_ROWS];
    for(int i = 0; i < SQUARE_ROWS; i++)
        squares[i] = new State[SQUARE_COLUMNS];

    matrix = new int*[ROWS];
    for(int i = 0; i < ROWS; i++)
        matrix[i] = new int[COLUMNS];

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMNS; j++)
            matrix[i][j] = 0;
}

void Sudoku::clear_rows_state() {
    delete[] rows;
    rows = new State[ROWS];
}

void Sudoku::clear_columns_state() {
    delete[] cols;
    cols = new State[COLUMNS];
}

void Sudoku::clear_matrix() {
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMNS; j++)
            matrix[i][j] = 0;
}

void Sudoku::clear_squares_state() {
    for(int i = 0; i < SQUARE_ROWS; i++)
        for(int j = 0; j < SQUARE_COLUMNS; j++)
            squares[i][j] = 0;
}


