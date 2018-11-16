#ifndef BASIC_TEST_CELL_H
#define BASIC_TEST_CELL_H

#include <vector>



class Cell {
public:
    Cell(bool alive = false);
    bool isAlive();

    void survive();

    void nextGeneration();

    void addNeighbor(Cell cell);

    bool operator==(Cell& other) const;


private:
    bool alive;
    std::vector<Cell> neighbors;
    int alive_neighbors;
};


#endif //BASIC_TEST_CELL_H
