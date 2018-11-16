#include "gtest/gtest.h"
#include "cell.h"
#include "game_matrix.h"
#include <boost/numeric/ublas/matrix.hpp>



#include <string>

using namespace boost::numeric::ublas;

TEST(gameMatrixTests, shouldCreateWithSize){

    GameMatrix gameMatrix(3);
    gameMatrix.initialize(42, 25);
    gameMatrix.run();


}