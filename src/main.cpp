// SudokuSolver solver version 2.1
#include <iostream>
#include "../include/SudokuSolver.h"
#include "../include/ChronoTimer.h"

using namespace std;

int main(){
    ChronoTimer timer;
    SudokuSolver solver("board.txt");
    solver.print();
    cout << endl;
    solver.solve();

    return 0;
}
