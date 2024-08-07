//
//  ChronoTimer.h
//  Sudoku_Solver
//
//  Created by Alireza Zahedi on 2021-05-27.
//

#ifndef ChronoTimer_h
#define ChronoTimer_h
#include <chrono>

class ChronoTimer{
public:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration;

    ChronoTimer():start(std::chrono::high_resolution_clock::now()){}

    ~ChronoTimer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << duration.count() << "s\n";
    }
};



#endif /* ChronoTimer_h */
