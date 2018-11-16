#include "cell.h"
#include <boost/numeric/ublas/matrix.hpp>

class GameMatrix{
public:
    GameMatrix(int size): cells(size,size) {};
    void initialize(int seed, int populationChance);
    void run();

private:
    boost::numeric::ublas::matrix<Cell> cells;

    void set_south_neighbor( int row,  int column, Cell &cell);

    void set_north_neighbor( int row,  int column, Cell &cell);

    void set_northeast_neighbor( int row,  int column, Cell &cell);

    void set_east_neighbor( int row,  int column, Cell &cell);

    void set_southeast_neighbor( int row,  int column, Cell &cell);

    void set_southwest_neighbor( int row,  int column, Cell &cell);

    void set_west_neighbor( int row,  int column, Cell &cell);

    void set_northwest_neighbor( int row,  int column, Cell &cell);

    void set_neighbors( int row,  int column, Cell &cell);

    bool hasSouth(int row) const;

    bool hasNorth(int row) const;

    bool hasEast(int column) const;

    bool hasWest(int column) const;

    int random();
};
