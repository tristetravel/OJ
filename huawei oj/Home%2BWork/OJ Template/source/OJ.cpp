
#include "OJ.h"
 
double max(double a, double b)
{
	return a > b ? a : b;
}
/*

输入: nPapers表示试卷的数目(1≤Papers≤20)，nRemain表示剩余的时间(1≤nRemain≤10000)，paper[][2]是一个Papers*2的数组，

每一行的两个元素依次为做完这一份试卷所需的时间、做完这份试卷的价值

输出: *pMaxValue为获得的最大价值
返回:
0:异常
1:计算成功返回


*/
int GetMaxValue(int nPapers, int nRemain, int paper[][2], double* pMaxValue)
{
	if(nPapers < 1 || nPapers > 20)
		return 0;
	if(nRemain < 1 || nRemain > 10000)
		return 0;

	int row = nPapers + 1;
	int column = nRemain + 1;

	double **max_value = new double*[row];
	for(int i = 0; i < row; i++)
	{
		max_value[i] = new double[column];
	}

	for(int i = 0; i < row; i++)
		max_value[i][0] = 0;
	for(int j = 0; j < column; j++)
		max_value[0][j] = 0;

	for(int i = 1; i < row; i++)
		for(int j = 1; j < column; j++)
		{
			if( j >= paper[i - 1][0])
				max_value[i][j] = max(max_value[i - 1][j - paper[i - 1][0]] + paper[i - 1][1], max_value[i - 1][j]);
			else
				max_value[i][j] = max_value[i - 1][j];
		}

		*pMaxValue = max_value[nPapers][nRemain];

	return 1;
}
