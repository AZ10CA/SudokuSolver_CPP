//
// Created by Alireza Zahedi on 2021-05-29.
//

#ifndef SUDOKUCPP_SUDOKU_H
#define SUDOKUCPP_SUDOKU_H
#include <bitset>
#include <cassert>


class Sudoku {
protected:
    /// Static Variables
    constexpr static int ROWS{9};
    constexpr static int COLUMNS{9};
    constexpr static int SQUARE_ROWS{3};
    constexpr static int SQUARE_COLUMNS{3};

    constexpr static int MIN{1};
    constexpr static int MAX{9};

    typedef std::bitset<MAX + 1> State;
    /// Bitmasks
    State* rows{nullptr}; // in rows
    State* cols{nullptr}; // in columns
    State** squares{nullptr}; // in squares (3 * 3) default

    /// Sudoku Board
    int** matrix{nullptr};

public:
    Sudoku();

    ~Sudoku();

    void print() const;

protected:
    void set_squares_state();

    void set_rows_state();

    void set_columns_state();

    void set_bitmasks_state();

    void clear_rows_state();

    void clear_columns_state();

    void clear_squares_state();

    void clear_matrix();


    bool hasSquare(const int& row, const int& col, const int& val);
};


#endif //SUDOKUCPP_SUDOKU_H
