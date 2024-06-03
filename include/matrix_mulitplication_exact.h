#ifndef MAT_MULT_EXACT
#define MAT_MULT_EXACT

#include <vector>
#include <algorithm>
#include <iostream>

void multiplyMatricesWithoutErrors(const std::vector<std::vector<int>> &A,
                      const std::vector<std::vector<int>> &B,
                      std::vector<std::vector<int>> &C, int rowsA, int colsA,
                      int colsB);

#endif