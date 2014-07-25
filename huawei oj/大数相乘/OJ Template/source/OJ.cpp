
#include "oj.h"


/*****************************************************************************
 Prototype    : multiply
 Description  : 两个任意长度的长整数相乘, 输出结果
 Input Param  : 
                const std::string strMultiplierA  乘数A
                const std::string strMultiplierB  乘数B
 Output       : 
                std::string strRst            乘法结果
 Return Value : 
                int                       0  正确  
                                         -1  异常
*****************************************************************************/
int multiply (const std::string strMultiplierA,const std::string strMultiplierB, std::string &strRst) 
{

    /* 在这里实现功能 */
    if(strMultiplierA.empty() || strMultiplierB.empty())
		return -1;

	std::string strTemp;
	std::string strResult;

	int pos1 = strMultiplierA.size() - 1;
	int pos2 = strMultiplierB.size() - 1;
	std::string tempA = strMultiplierA;
	std::string tempB = strMultiplierB; 

	int negativeA = 0;
	int negativeB = 0;
	for(int i = 0; i <= pos1; ++i)
	{
		if(i == 0 && strMultiplierA[0] == '-')
		{
			++negativeA;
			tempA = tempA.substr(1, tempA.size() - 1);
			continue;
		}
		if(strMultiplierA[i] < '0' || strMultiplierA[i] > '9')
		{
			return -1;
		}
	}

	if(negativeA)
	{
		--pos1;
	}

	for(int i = 0; i <= pos2; ++i)
	{
		if(i == 0 && strMultiplierB[0] == '-')
		{
			++negativeB;
			tempB = tempB.substr(1, tempB.size() - 1);
			continue;
		}
		if(strMultiplierB[i] < '0' || strMultiplierB[i] > '9')
		{
			return -1;
		}
	}

	if(negativeB)
	{
		--pos2;
	}

	int incre = 0;//每次乘法的结果末尾添加0的个数
	int carry_multi = 0;
	int temp_multi = 0;
	int carry_add = 0;
	int temp_add = 0;
	std::string stemp_multi;
	std::string stemp_add;
	for(int i = pos2; i >= 0; --i)
	{
		for(int addzero = incre; addzero > 0; --addzero)
		{
			stemp_multi = stemp_multi + '0';
		}

		for(int j = pos1; j >= 0; --j)
		{
			temp_multi = (tempA[j] - '0') * (tempB[i] - '0') + carry_multi;
			carry_multi = temp_multi / 10;
			temp_multi = temp_multi % 10;
			stemp_multi = (char)(temp_multi + '0') + stemp_multi;
		}

		if(carry_multi > 0)
		{
			stemp_multi = (char)(carry_multi + '0') + stemp_multi;
		}

		int index = stemp_multi.size() > strTemp.size() ? strTemp.size() : stemp_multi.size();

		for(int i = stemp_multi.size() - 1, j = strTemp.size() - 1, k = index; k > 0; --k, --i, --j)
		{
			temp_add = stemp_multi[i] - '0' + strTemp[j] - '0' + carry_add;
			carry_add = temp_add / 10;
			temp_add = temp_add % 10;
			stemp_add = (char)(temp_add + '0') + stemp_add;
		}
		if(index == strTemp.size())
		{
			for(int i = stemp_multi.size() - strTemp.size() - 1; i >= 0; --i)
			{
				temp_add = stemp_multi[i] - '0' + carry_add;
				carry_add = temp_add / 10;
				temp_add = temp_add % 10;
				stemp_add = (char)(temp_add + '0') + stemp_add;
			}
		}
		else if(index == stemp_multi.size())
		{
			for(int i = strTemp.size() - stemp_multi.size() - 1; i >= 0; --i)
			{
				temp_add = strTemp[i] - '0' + carry_add;
				carry_add = temp_add / 10;
				temp_add = temp_add % 10;
				stemp_add = (char)(temp_add + '0') + stemp_add;
			}
		}

		if(carry_add > 0)
		{
			stemp_add = (char)(carry_add + '0') + stemp_add;
		}

		strTemp = stemp_add;

		incre++;
		stemp_add.clear();
		stemp_multi.clear();
	}

	while(strTemp[0] == '0' && strTemp.size() > 1)
	{
		strTemp = strTemp.substr(1, strTemp.size() - 1);
	}

	if((negativeA^negativeB) == 1)
	{
		strTemp = '-' + strTemp;
	}

	strRst = strTemp;

    return 0;
}