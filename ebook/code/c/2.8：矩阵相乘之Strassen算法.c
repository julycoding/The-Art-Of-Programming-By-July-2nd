//解法一
//矩阵乘法，3个for循环搞定    
void Mul(int** matrixA, int** matrixB, int** matrixC)    
{    
	for(int i = 0; i < 2; ++i)     
	{    
		for(int j = 0; j < 2; ++j)     
		{    
			matrixC[i][j] = 0;    
			for(int k = 0; k < 2; ++k)     
			{    
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];    
			}    
		}    
	}    
}  
