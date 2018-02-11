static const char* student_id = "0211261";


// do not edit prototype
void LCS(int *, int*, int*);
int max(int, int);
int print_LCS(int**, int*, int*, int *, int, int, int);
// X,Y are input strings, C is answer string
//
// data structure :  
// length of array X is m+1, length of array Y is n+1, length of array C is m+n
// X[0] = m+1, Y[0] = n+1, 
// all element of C are "-1"
// other datas are in [0,255] means the symble in ASCII or ANSI table


// you only allow declare a table with size (m+1)*(n+1)
//
// do your homework here
//
int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int print_LCS(int** c, int*X, int*Y, int *C, int m, int n, int k,int sum)
{

	if (m == 0 || n == 0)
	{
		for (int i = k; i <sum ; i++)
		{
			*(C + i) = -1;

		}
		return k - 1;
	}
	else if (*(X + m) == *(Y + n))
	{
		*(C + k) = *(X + m);
		return print_LCS(c, X, Y, C, m - 1, n - 1, k + 1,sum);

	}
	else if (c[m - 1][n] >= c[m][n - 1])
	{
		return print_LCS(c, X, Y, C, m - 1, n, k,sum);
	}
	else
	{
		return print_LCS(c, X, Y, C, m, n - 1, k,sum);
	}
}
void LCS(int* X, int* Y, int* C) {

	int m = *X - 1;
	int n = *Y - 1;
	int** c;
	c = new int*[m + 1];
	for (int i = 0; i<m + 1; i++)
	{
		c[i] = new int[n + 1];
	}


	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				c[i][j] = 0;

			}

			else if (*(X + i) == *(Y + j))
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	int sum = print_LCS(c, X, Y, C, m, n, 0,m+n);
	int o = 0;
	int p = sum;
	while (o<p)
	{
		int temp = *(C + o);
		*(C + o) = *(C + p);
		*(C + p) = temp;

		o++;
		p--;
	}
}
