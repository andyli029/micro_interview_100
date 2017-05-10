#include <stdio.h>
#include <set>
#include <cassert>

using namespace std;

#define M 100

// O(2^n)
long long fibonacci1(unsigned int n)
{
      int result[2] = {0, 1};

      if(n < 2)
            return result[n];

      return fibonacci1(n - 1) + fibonacci1(n - 2);
}

// O(n)
long long fibonacci2(unsigned int n)
{
	long long fib[M];
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i < n + 1; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		//printf("%d ", fib[i]);
	}

    printf("%ld.\n", fib[n]);
}

// O(log n)

///////////////////////////////////////////////////////////////////////
// A 2 by 2 matrix
///////////////////////////////////////////////////////////////////////
struct Matrix2By2
{
      Matrix2By2
      (
            long long m00 = 0, 
            long long m01 = 0, 
            long long m10 = 0, 
            long long m11 = 0
      )
      :m_00(m00), m_01(m01), m_10(m10), m_11(m11) 
      {
      }

      long long m_00;
      long long m_01;
      long long m_10;
      long long m_11;
};

///////////////////////////////////////////////////////////////////////
// Multiply two matrices
// Input: matrix1 - the first matrix
//        matrix2 - the second matrix
//Output: the production of two matrices
///////////////////////////////////////////////////////////////////////
Matrix2By2 MatrixMultiply
(
      const Matrix2By2& matrix1, 
      const Matrix2By2& matrix2
)
{
      return Matrix2By2(
            matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
            matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
            matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
            matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

///////////////////////////////////////////////////////////////////////
// The nth power of matrix 
// 1  1
// 1  0
///////////////////////////////////////////////////////////////////////
Matrix2By2 MatrixPower(unsigned int n)
{
      assert(n > 0);

      Matrix2By2 matrix;
      if(n == 1)
      {
            matrix = Matrix2By2(1, 1, 1, 0);
      }
      else if(n % 2 == 0)
      {
            matrix = MatrixPower(n / 2);
            matrix = MatrixMultiply(matrix, matrix);
      }
      else if(n % 2 == 1)
      {
            matrix = MatrixPower((n - 1) / 2);
            matrix = MatrixMultiply(matrix, matrix);
            matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
      }

      return matrix;
}

long long fibonacci3(unsigned int n)
{
      int result[2] = {0, 1};
      if(n < 2)
            return result[n];

      Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
      return PowerNMinus2.m_00;
}


int main()
{  
    printf("%ld.\n", fibonacci3(M));    

    fibonacci2(M);

	//printf("%ld.\n", fibonacci1(M));  

}

