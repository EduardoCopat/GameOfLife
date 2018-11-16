#include "gtest/gtest.h"
#include "cell.h"

 Cell createCell(bool alive) {
    return new Cell(alive);
}

/*
// Defines a base TEST_F fixture.
class cellTest_Fs : public ::testing::Test {
protected:

};

TEST_F(cellTest_Fs, canBeBornAlive){
    Cell cell (true);
    EXPECT_EQ(cell.isAlive(), true);
}

TEST_F(cellTest_Fs, canBeBornDead){
    Cell cell (false);
    EXPECT_EQ(cell.isAlive(), false);
}

TEST_F(cellTest_Fs, underpopulation_0neighbors){
    //Any live cell with fewer than two live neighbors dies, as if by underpopulation.
    Cell cell (true);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}

TEST_F(cellTest_Fs, underpopulation_1LiveNeighbor){
    //Any live cell with fewer than two live neighbors dies, as if by underpopulation.
    Cell cell (true);

    cell.addNeighbor(cellFalse);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}

TEST_F(cellTest_Fs, livesToNextGen_2LiveNeighbors) {
    //Any live cell with two or three live neighbors lives on to the next generation.
    Cell cell (true);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), true);
}

TEST_F(cellTest_Fs, livesToNextGen_3LiveNeighbors) {
    //Any live cell with two or three live neighbors lives on to the next generation.
    Cell cell(true);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), true);
}

TEST_F(cellTest_Fs, livesToNextGen_4LiveNeighbors) {
    //Any live cell with more than three live neighbors dies, as if by overpopulation.
    Cell cell(true);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellFalse);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}


TEST_F(cellTest_Fs, livesToNextGen_8LiveNeighbors) {
    //Any live cell with more than three live neighbors dies, as if by overpopulation.
    Cell cell(true);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(cellTrue);
    cell.survive();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}

TEST_F(cellTest_Fs, should_not_be_affected_before_next_generation) {
    //Any live cell with more than three live neighbors dies, as if by overpopulation.
    Cell cell(true);
    Cell anotherCell(false);

    //anotherCell was dead and will be alive
    anotherCell.addNeighbor(cellTrue);
    anotherCell.addNeighbor(cellTrue);
    anotherCell.addNeighbor(cellTrue);
    anotherCell.survive();

    //cell was alive and will be dead
    cell.addNeighbor(cellTrue);
    cell.addNeighbor(anotherCell);
    cell.survive();

    //They are not affected by their initial state
    anotherCell.nextGeneration();
    cell.nextGeneration();
    EXPECT_EQ(cell.isAlive(), false);
}
 */
