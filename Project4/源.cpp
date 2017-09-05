#include<iostream>
#include <cstdlib>
#include<fstream>
#include <time.h>
using namespace std;
void print(int s[9][9])   //打印二维数组
{
	int m = 0;
	int n = 0;
	for (m = 0; m < 9; m++) {
		for (n = 0; n < 9; n++) {
			cout << s[m][n] << ' ';
		}
		cout << endl;
	}
	cout << endl;
};
void change1(int s[9][9])  //第一行和第三行交换
{
	int i = 0;
	int k = 0;
	for (i = 0; i < 9; i++)
	{
		k = s[0][i];
		s[0][i] = s[2][i];
		s[2][i] = k;
	}
};
void change2(int s[9][9])  //第四行和第六行交换
{
	int i = 0;
	int k = 0;
	for (i = 0; i < 9; i++)
	{
		k = s[3][i];
		s[3][i] = s[5][i];
		s[5][i] = k;
	}
};
void change3(int s[9][9])  //第七行和第九行交换
{
	int i = 0;
	int k = 0;
	for (i = 0; i < 9; i++)
	{
		k = s[6][i];
		s[6][i] = s[8][i];
		s[8][i] = k;
	}
};
void change4(int s[9][9])  //第一列和第三列交换
{
	int i = 0;
	int k = 0;
	for (i = 0; i < 9; i++)
	{
		k = s[i][0];
		s[i][0] = s[i][2];
		s[i][2] = k;
	}
};
void change5(int s[9][9])  //第四列和第六列交换
{
	int i = 0;
	int k = 0;
	for (i = 0; i < 9; i++)
	{
		k = s[i][3];
		s[i][3] = s[i][5];
		s[i][5] = k;
	}
};
void change6(int s[9][9])  //第七列和第九列交换
{
	int i = 0;
	int k = 0;
	for (i = 0; i < 9; i++)
	{
		k = s[i][6];
		s[i][6] = s[i][8];
		s[i][8] = k;
	}
};
void change7(int s[9][9])   //头三行和末三行交换
{
	int i;
	int j;
	int k;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
		{
			k = s[i][j];
			s[i][j] = s[i + 6][j];
			s[i + 6][j] = k;
		}
	}
};
void change8(int s[9][9])   //左三列和右三列交换
{
	int i;
	int j;
	int k;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 3; j++)
		{
			k = s[i][j];
			s[i][j] = s[i][j + 6];
			s[i][j + 6] = k;
		}
	}
};
void change9(int s[9][9])   //随机交换两个数字的所有位置
{
	int x;
	int y;
	int i;
	int j;
	srand((unsigned)time(0));
	x = rand() % 9;
	y = (x + 2) % 9;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (s[i][j] == x)
			{
				s[i][j] = y;
				continue;
			}

			if (s[i][j] == y)
			{
				s[i][j] = x;
				continue;
			}
			else continue;
		}
	}
};

int main()
{
	int shudu[9][9] = {
		{ 9,7,8,3,1,2,6,4,5 },
		{ 3,1,2,6,4,5,9,7,8 },
		{ 6,4,5,9,7,8,3,1,2 },
		{ 7,8,9,1,2,3,4,5,6 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 4,5,6,7,8,9,1,2,3 },
		{ 8,9,7,2,3,1,5,6,4 },
		{ 2,3,1,5,6,4,8,9,7 },
		{ 5,6,4,8,9,7,2,3,1 }
	};
	int n;
	cin >> n;
	if (n > 1000000 || n < 0)
	{
		cout << "输入错误！" << endl;
	}

	print(shudu);

	system("pause");
	return 0;
}