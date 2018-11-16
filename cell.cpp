#include "cell.h"

Cell::Cell(bool alive) {
    this->alive = alive;
    alive_neighbors = 0;
    neighbors.reserve(8);
}

bool Cell::isAlive() {
    return this->alive;
}

void Cell::survive() {
    alive_neighbors = 0;

    for (Cell &neighbor : neighbors) {
        if(neighbor.isAlive())
            alive_neighbors++;
    }
}

void Cell::nextGeneration() {
    if(alive_neighbors <= 1){
        this->alive = false;
    } else if (alive_neighbors >= 2 && alive_neighbors <= 3) {
        this->alive = true;
    } else {
        this->alive = false;
    }
}

void Cell::addNeighbor(Cell cell) {
    neighbors.push_back(cell);
}

bool Cell::operator==(Cell &other) const {
    if(this == &other) return true; //This is the pointer for
    else return false;
}
