#include "gtest/gtest.h"
#include "cell.h";
#include "Matrix.h";
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multi_array.hpp>

#include <string>

using namespace boost::numeric::ublas;

TEST(matrixTests, shouldCreateMatrixWithSize){



    matrix<Cell*> cells (10,10);
    Cell a(true);

        for (unsigned i = 0; i < cells.size1 (); ++ i)
            for (unsigned j = 0; j < cells.size2 (); ++ j) {
                a = cells(i, j);
                if (a.isAlive())
                    std::cout << "oi"<< std::endl;
                else
                    std::cout << "tcau" << std::endl;
            }


    EXPECT_EQ(1,1);
}