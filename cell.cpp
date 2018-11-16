#include <cstdlib>
#include "cell.h"

Cell::Cell(bool alive) {
    this->id = rand() % 1000 + 1;
    this->alive = alive;
    alive_neighbors = 0;
    index = 0;
}

bool Cell::isAlive() {
    return this->alive;
}

void Cell::survive() {
    alive_neighbors = 0;

    for (int i = 0; i < 8; i++){
        if(neighbors[i].isAlive())
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

void Cell::addNeighbor(Cell &cell) {
    if(index == 0)
        neighbors = new Cell[8];

    neighbors[index] = cell;
    index++;
}

bool Cell::operator==(Cell &other) const {
    if(this == &other) return true; //This is the pointer for
    else return false;
}

void Cell::live() {
    this->alive = true;
}

void Cell::die() {
    this->alive = false;
}
