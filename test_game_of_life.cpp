#include "gtest/gtest.h"
#include "cell.h";

TEST(cellTests, canBeBornAlive){
    Cell cell (true);
    EXPECT_EQ(cell.isAlive(), true);
}

TEST(cellTests, canBeBornDead){
    Cell cell (false);
    EXPECT_EQ(cell.isAlive(), false);
}

TEST(cellTests, underpopulation_0neighbors){
    //Any live cell with fewer than two live neighbors dies, as if by underpopulation.
    Cell cell (true);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}

TEST(cellTests, underpopulation_1LiveNeighbor){
    //Any live cell with fewer than two live neighbors dies, as if by underpopulation.
    Cell cell (true);
    cell.addNeighbor(Cell(false));
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}

TEST(cellTests, livesToNextGen_2LiveNeighbors) {
    //Any live cell with two or three live neighbors lives on to the next generation.
    Cell cell (true);
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), true);
}

TEST(cellTests, livesToNextGen_3LiveNeighbors) {
    //Any live cell with two or three live neighbors lives on to the next generation.
    Cell cell(true);
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), true);
}

TEST(cellTests, livesToNextGen_4LiveNeighbors) {
    //Any live cell with more than three live neighbors dies, as if by overpopulation.
    Cell cell(true);
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(false));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}


TEST(cellTests, livesToNextGen_8LiveNeighbors) {
    //Any live cell with more than three live neighbors dies, as if by overpopulation.
    Cell cell(true);
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(Cell(true));
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}

TEST(cellTests, should_not_be_affected_before_next_generation) {
    //Any live cell with more than three live neighbors dies, as if by overpopulation.
    Cell cell(true);
    Cell anotherCell(false);

    //anotherCell was dead and will be alive
    anotherCell.addNeighbor(Cell(true));
    anotherCell.addNeighbor(Cell(true));
    anotherCell.addNeighbor(Cell(true));
    anotherCell.survive();

    //cell was alive and will be dead
    cell.addNeighbor(Cell(true));
    cell.addNeighbor(anotherCell);
    cell.survive();

    //They are not affected by their initial state
    anotherCell.nextGeneration();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}
