/// Sudoku Solver Version 2.1

#ifndef SUDOKUCPP_SUDOKUSOLVER_H
#define SUDOKUCPP_SUDOKUSOLVER_H

#include <iostream>
#include <fstream>
#include <bitset>
#include "Sudoku.h"


class SudokuSolver : public Sudoku {
private:
    /// Source Filename
    char* file_name{nullptr};

    /// Statistics Properties
    int solutions;
    int recursive_calls;

public:
    explicit SudokuSolver(const char* f_name) : Sudoku(){
        assert(f_name);
        set_file_name(f_name);

        recursive_calls = 0;
        solutions = 0;

        read_board();
    }

    ~SudokuSolver(){
        delete[] file_name;
    }


public:
    [[nodiscard]] int get_recursive_calls() const;

    [[nodiscard]] int get_number_of_solutions() const;

    void solve();

    void set_file_name(const char* f_name);


private:
    void search(const int& row, const int& col);

    void reset();

    void read_board();

private:
    int static str_len(const char* _str){
        int length = 0;
        while(_str[length] != '\0')
            length++;
        return length;
    };

    void static str_cpy(const char* _str, char* _new){
        int length = str_len(_str);
        for(int i = 0; i < length + 1; i++)
            _new[i] = _str[i];
    };

};

#endif //SUDOKUCPP_SUDOKUSOLVER_H