#ifndef BASIC_TEST_CELL_H
#define BASIC_TEST_CELL_H

#include <vector>
#include <boost/ptr_container/ptr_vector.hpp>

class Cell {
public:
    Cell(bool alive = false);
    bool isAlive();

    bool live();

    bool die();

    void survive();

    void nextGeneration();

    void addNeighbor(Cell &cell);

    bool operator==(Cell& other) const;


private:
    int id;
    bool alive;
    Cell *neighbors;
    int index;
    int alive_neighbors;

};


#endif //BASIC_TEST_CELL_H
