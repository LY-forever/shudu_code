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
	srand(unsigned(time(nullptr)) + rand());
	x = rand() % 9+1;
	y = (x + s[1][3]) % 9+1;
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
void changex(int s[9][9])   //增大随机性
{
	int m=s[0][2];
	int n=s[4][4];
	int i;
	int j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (s[i][j] == m)
			{
				s[i][j] = n;
				continue;
			}

			if (s[i][j] == n)
			{
				s[i][j] = m;
				continue;
			}
			else continue;
		}
	}
};
void first_num(int s[9][9])   //显示首个为2 学号19 （1+9）% 9 + 1 = 2
{
	int x=2;
	int y=s[0][0];
	int i;
	int j;
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
void shengcheng(int s[9][9])   //生成一个新数独
{
	int i = 0;
	int m[9];
	change9(s);               //随机交换两个数字，增大随机性
	changex(s);				 //随机交换两个数字，增大随机性
	for (i = 0; i < 9; i++)   //记录对角线数字
	{
		m[i] = s[i][i];
	}
	for (i = 0;i < 9; i++)   //根据对角线数字进行变化
	{
		if (m[i] == 1)
		{
			change1(s);
			continue;
		}
		if (m[i] == 2)
		{
			change2(s);
			continue;
		}
		if (m[i] == 3)
		{
			change3(s);
			continue;
		}
		if (m[i] == 4)
		{
			change4(s);
			continue;
		}
		if (m[i] == 5)
		{
			change5(s);
			continue;
		}
		if (m[i] == 6)
		{
			change6(s);
			continue;
		}
		if (m[i] == 7)
		{
			change7(s);
			continue;
		}
		if (m[i] == 8)
		{
			change8(s);
			continue;
		}
		if (m[i] == 9)
		{
			change9(s);
			continue;
		}
		else continue;
	}
	changex(s);
	first_num(s);
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
	int i;
	cin >> n;
	if (n > 1000000 || n < 0)
	{
		cout << "输入错误！" << endl;
	}

	ofstream outfile;
	outfile.open("sudoku.txt"); 
	for (i = 0; i < n; i++)          
	{
		
		shengcheng(shudu);
		int m = 0;
		int n = 0;
		for (m = 0; m < 9; m++) {
			for (n = 0; n < 9; n++) {
				outfile << shudu[m][n] << ' ';
			}
			outfile << endl;
		}
		outfile << endl;
		
	}
	outfile.close();

	system("pause");
	return 0;
}