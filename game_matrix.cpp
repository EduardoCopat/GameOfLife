#include "game_matrix.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <random>
#include <ctime>

void GameMatrix::initialize(int seed, int populationChance) {
    srand(time(NULL));

    for (int row = 0; row < cells.size1 (); ++ row){
        for (int column = 0; column < cells.size2 (); ++ column) {
            Cell &cell = cells(row,column);
            if(populationChance > random())
                cell.live();
            else
                cell.die();

            set_neighbors(row,column, cell);
        }
    }
    return;
}

void GameMatrix::set_south_neighbor(int row, int column, Cell &cell) {

    if(hasSouth(row)) {
        Cell &southCell = cells(row+1,column);
        cell.addNeighbor(southCell);

    }
}

bool GameMatrix::hasSouth(int row) const { return cells.size1() > row + 1; }

void GameMatrix::set_north_neighbor(int row, int column, Cell &cell) {
    if(hasNorth(row))
        cell.addNeighbor(cells(row-1, column));
}

bool GameMatrix::hasNorth(int row) const { return row - 1 >= 0; }

void GameMatrix::set_east_neighbor(int row, int column, Cell &cell) {
    if(hasEast(column))
        cell.addNeighbor(cells(row, column+1));
}

bool GameMatrix::hasEast(int column) const {
    return cells.size2() > column + 1;
}

void GameMatrix::set_west_neighbor(int row, int column, Cell &cell) {
    if(hasWest(column)) {
        Cell &westCell = cells(row, column - 1);
        cell.addNeighbor(westCell);
    }
}

bool GameMatrix::hasWest(int column) const {
    if((column - 1) >= 0){
        return true;
    }
    else
        return false;
}

void GameMatrix::set_northeast_neighbor(int row, int column, Cell &cell) {
    if(hasNorth(row) && hasEast(column))
        cell.addNeighbor(cells(row-1, column+1));
}

void GameMatrix::set_southeast_neighbor(int row, int column, Cell &cell) {
    if(hasSouth(row) && hasEast(column))
            cell.addNeighbor(cells(row+1, column+1));
}

void GameMatrix::set_southwest_neighbor(int row, int column, Cell &cell) {
    if(hasSouth(row) && hasWest(column))
        cell.addNeighbor(cells(row + 1, column - 1));

}

void GameMatrix::set_northwest_neighbor(int row, int column, Cell &cell) {
    if(hasNorth(row) && hasWest(column))
            cell.addNeighbor(cells(row-1, column-1));
}

void GameMatrix::set_neighbors(int row, int column, Cell &cell) {
    set_north_neighbor(row, column, cell);
    set_northeast_neighbor(row, column, cell);
    set_east_neighbor(row, column, cell);
    set_southeast_neighbor(row, column, cell);
    set_south_neighbor(row, column, cell);
    set_southwest_neighbor(row, column, cell);
    set_west_neighbor(row, column, cell);
    set_northwest_neighbor(row, column, cell);
}

void GameMatrix::run() {

    std::string text;
    int k = 0;
    while(k != 3) {
        text = "";
        for (int row = 0; row < cells.size1(); ++row) {
            text = text + "\n";
            for (int column = 0; column < cells.size2(); ++column) {
                Cell &cell = cells(row, column);
                if (cell.isAlive())
                    text = text + "*";
                else
                    text = text + ".";
                cell.survive();
            }
        }
        text = text + "\n";
        std::cout << text << std::endl;
        k++;

        for (int row = 0; row < cells.size1(); ++row) {
            for (int column = 0; column < cells.size2(); ++column) {
                Cell &cell = cells(row, column);
                cell.nextGeneration();
            }
        }
    }
}

int GameMatrix::random() {
    return rand() % 100 + 1;
}
