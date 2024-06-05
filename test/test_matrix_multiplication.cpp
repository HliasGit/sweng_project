#include "matrix_multiplication.h"
#include "matrix_mulitplication_exact.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult
// ERRORS FOUND:
// Error 1: Element-wise multiplication of ones detected!
// Error 2: Matrix A contains the number 7!
// Error 3: Matrix A contains a negative number!
// Error 4: Matrix B contains the number 3!
// Error 5: Matrix B contains a negative number!
// Error 6: Result matrix contains a number bigger than 100!
// Error 7: Result matrix contains a number between 11 and 20!
// Error 8: Result matrix contains zero!
// Error 9: Result matrix contains the number 99!
// Error 10: A row in matrix A contains more than one 1!
// Error 11: Every row in matrix B contains at least one 0!
// Error 12: The number of rows in A is equal to the number of columns in B!
// Error 13: The first element of matrix A is equal to the first element of  matrix B!
// Error 14: The result matrix C has an even number of rows!
// Error 15: A row in matrix A is filled entirely with 5s!
// Error 16: Matrix B contains the number 6!
// Error 17: Result matrix C contains the number 17!
// Error 18: Matrix A is a square matrix!
// Error 19: Every row in matrix A contains the number 8!
// Error 20: Number of columns in matrix A is odd!

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));


    multiplyMatrices(A, B, C, 2, 3, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 3, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication test failed! :(((()";
}


/*
When multiplying a matrix times a matrix with all entries to zero we expect a zero matrix
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_zeroMatrixRight) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {0, 0},
        {0, 0},
        {0, 0}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 3, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication for zero on the right test failed! :(((()";
}

/*
When multiplying a zero matrix times a generic matrix we expect a zero matrix.
It's different from the previuous test case since the matrix multiplication is not commutative
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_zeroMatrixLeft) {
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> B = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 3, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication for zero on the left test failed! :(((()";
}

/*
A generic matrix times its identity matrix gives back the original generic matrix
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_identityMatrixRight) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {4, 5}
    };
    std::vector<std::vector<int>> B = {
        {1, 0},
        {0, 1}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 2, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication for the identity on the right test failed! :(((()";
}

/*
The identity matrix times a generic matrix gives back the original generic matrix
It's different from the previuous test case since the matrix multiplication is not commutative
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_identityMatrixLeft) {
    std::vector<std::vector<int>> A = {
        {1, 0},
        {0, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 2},
        {4, 5}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 2, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication for the identity on the left test failed! :(((()";
}

/*
The test mean to see if the matrix times itself gives the right answer
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_squaredMatrix) {
    std::vector<std::vector<int>> A = {
        {5, 0},
        {0, 5}
    };
    std::vector<std::vector<int>> B = {
        {5, 0},
        {0, 5}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 2, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication for itself test failed! :(((()";
}

/*
Test that the matrix times its inverse gives the identity
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_matrixTimesInverseMatrix) {
    std::vector<std::vector<int>> A = {
        {2, 1},
        {1, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, -1},
        {-1, 2}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);
    multiplyMatricesWithoutErrors(A, B, C2, 2, 2, 2);

    ASSERT_EQ(C, C2) << "Matrix multiplication for its inverse test failed! :(((()";
}

/*
Test associativity property:
A(BC)=(AB)C

First muliply B and C, store it in D_one after multiplying it with A.
Do the same for A and B, then in D_two after multiplying with C
Assert that they are the same
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_associativity) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<int>> B = {
        {5, 6},
        {7, 8}
    };
    std::vector<std::vector<int>> C = {
        {9, 10},
        {11,12}
    };
    std::vector<std::vector<int>> temp(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> D_one(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> D_two(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, temp, 2, 2, 2);
    multiplyMatrices(temp, C, D_one, 2, 2, 2);

    multiplyMatrices(B, C, temp, 2, 2, 2);
    multiplyMatrices(A, temp, D_two, 2, 2, 2);

    ASSERT_EQ(D_one, D_two) << "Matrix multiplication for zero test failed! :(((()";
}


/*
Iterate brute force. This is seen as only one test. We exploited this brute force method just to retrieve
all the 20 errors we had to find.
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_withFor) {
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> C2(2, std::vector<int>(2, 0));

    for(int a=-1; a<100; a++){
        for(int b=0; b<50; b++){
            for(int c=0; c<50; c++){
                for(int d=0; d<50; d++){
                    std::vector<std::vector<int>> A = {
                        {a, b},
                        {c, d}
                    };
                    std::vector<std::vector<int>> B = {
                        {1, 0},
                        {0, 1}
                    };
                    multiplyMatrices(A, B, C, 2, 2, 2);
                    multiplyMatricesWithoutErrors(A, B, C2, 2, 2, 2);
                    EXPECT_EQ(C, C2) << "Matrix multiplication test with brute force failed! :(((()";               
                }
            }
        }
    }
}


// We should also test that the dimensions of the matrices are compatible, i.e. that the number of columns of the first
// matrix are the same as the number of rows of the second matrix. Though the program doesn't perform this check, so it doesn't
// make sense. Same reasoning for a test checking that the matrix dimensions are not negative.

// an implementation of the aformeentioned test about dimension compatibility is the one below, though it should expect a custom
// error (i.e. invalid matrix dimensions, which is not implemented in the multiplyMatrices method) and not a segmentation fault
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_invalidDimensionsSegfault)
{
    std::vector<std::vector<int>> A = {
        {5, 0, 1},
        {0, 5, 0}};

    std::vector<std::vector<int>> B = {
        {5, 0},
        {0, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    ASSERT_EXIT((multiplyMatrices(A, B, C, 2, 3, 2), exit(0)), ::testing::KilledBySignal(SIGSEGV), ".*");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
