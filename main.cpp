// SudokuSolver solver version 2.1
#include <iostream>
#include "SudokuSolver.h"
#include "ChronoTimer.h"

using namespace std;

int main(){
    ChronoTimer timer;
    SudokuSolver solver("Board.txt");
    solver.print();
    cout << endl;
    solver.solve();

    return 0;
}
