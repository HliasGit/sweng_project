# SE4HPCproject - Step 1 Testing

In the first step we have exploited some tests to check if and how many errors the matrix_multiplication_with_errors library contained. In order to do that we first tested some special cases, then we exploied a brute force test to find all the errors that were in the code. Follos a brief recap of what we have done and found:

Tests exploited (The major part of the tests assert the right value by doing the multiplication with the function that works correctly):
- TestMultiplyMatrices: Simple test to assert a generic matrix multiplication
- TestMultiplyMatrices_zeroMatrixRight: Multiply the zero matrix on the right
- TestMultiplyMatrices_zeroMatrixLeft: Multiply the zero matrix on the left
- TestMultiplyMatrices_identityMatrixRight:  Multiply the identity matrix on the right
- TestMultiplyMatrices_identityMatrixLeft:  Multiply the identity matrix on the left
- TestMultiplyMatrices_squaredMatrix: Multiply the matrix for itself
- TestMultiplyMatrices_matrixTimesInverseMatrix: Multiply the matrix for its inverse
- TestMultiplyMatrices_associativity: Exploit associativity between matrices and assert the result is not the same
- TestMultiplyMatrices_withFor: Exploit 4 for nested loops to retrieve all the possible errors. A great part of the errors below have been found using this function 

Errors found:
- Error 1: Element-wise multiplication of ones detected!
- Error 2: Matrix A contains the number 7!
- Error 3: Matrix A contains a negative number!
- Error 4: Matrix B contains the number 3!
- Error 5: Matrix B contains a negative number!
- Error 6: Result matrix contains a number bigger than 100!
- Error 7: Result matrix contains a number between 11 and 20!
- Error 8: Result matrix contains zero!
- Error 9: Result matrix contains the number 99!
- Error 10: A row in matrix A contains more than one '1'!
- Error 11: Every row in matrix B contains at least one '0'!
- Error 12: The number of rows in A is equal to the number of columns in B!
- Error 13: The first element of matrix A is equal to the first element of matrix B!
- Error 14: The result matrix C has an even number of rows!
- Error 15: A row in matrix A is filled entirely with 5s!
- Error 16: Matrix B contains the number 6!
- Error 17: Result matrix C contains the number 17!
- Error 18: Matrix A is a square matrix!
- Error 19: Every row in matrix A contains the number 8!
- Error 20: Number of columns in matrix A is odd!

