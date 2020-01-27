#include<iostream>
using namespace std;

/*其中加注释语句均为测试代码使用，无需去注释化*/
class Truthtable  //建立真值表类
{
private:
	int length; //指变元个数
	int width; //指真值表的高度
	int** tt; //创造二维数组储存并输出真值表内容
	int* content; //记录真值表最终的布尔值
	char* cht; //一维数组记录变元名称
public:
	Truthtable() { length = 1; width = 1; tt = NULL; content = NULL; cht = NULL; }
	void output();
	void outPDNF()
	{
		int f = 0;
		cout << "该式的主析取范式为：Σ(";
		for (int i = 0; i < width; i++)
		{
			if (content[i] == 1) 
			{
				if(f) cout << "," << i;
				else {
					cout << i;
					f = 1;
				}
			}
		}
		cout << ")" << endl;
		f = 0;
		cout << "该式的主合取范式为：Π(";
		for (int i = 0; i < width; i++)
		{
			if (content[i] == 0)
			{
				if (f) cout << "," << i;
				else {
					cout << i;
					f = 1;
				}
			}
		}
		cout << ")" << endl;

	}
	void create(int n);
	void charcreate(int n);
	void readinput(int c)
	{
		int* temnum = new int[c];
		int* q = new int[length - 1];
		for (int i = 0; i < c; i++)	temnum[i] = -1;
		char* str = new char[100];
		cout << "请输入一个式子，命题中所有变元用大写字母代替，合取用+代替，析取用*代替（注：析取优先级高于合取。），然后回车结束。" << endl;
		cin >> str;
		for (int i = 0; i < strlen(str)+1; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				for (int j = 0; j < length; j++)
				{
					if (str[i] == cht[j])
					{
						if (str[i - 1] == '!')		temnum[j] = 0;
						else temnum[j] = 1;
					}
				}
			}
			else
			{
				if (str[i] == '+' || str[i] == '\0')
				{
					//cout << "*" << str[i] << endl;
					int m = 0;
					int flag = 1;
					for (int k = 0; k < width; k++)
					{
						flag = 1;
						for (int l = 0; l < length; l++)
							if (temnum[l] != tt[l][k] && temnum[l] != -1) flag = 0;
						if (flag)		content[k] = 1;
					}
					for (int A = 0; A < c; A++)
					{
						temnum[A] = -1;
					}
				}
			}
		}
	}
};
int main()
{
	int c;
	Truthtable tb;
		cout << "请输入变元的总个数。" << endl;
		cin >> c;
		tb.create(c);	
		tb.readinput(c);
		tb.output();
}
void Truthtable::create(int n)
{
	length = n;
	width = pow(2, n);
	//cout << "length=" << length << " width=" << width << endl;
	tt = new int* [length];
	for (int i = 0; i < length; i++)
		tt[i] = new int[width];
	for (int i = 0; i < width; i++)
	{
		int k = i % 2;
		int el = i / 2;
		for (int j = length - 1; j >= 0; j--)
		{
			tt[j][i] = k;
			k = el % 2;
			el = el / 2;
		}
	}
	content = new int[width];
	for (int i = 0; i < width; i++)
		content[i] = 0;

	charcreate(n);
}
void Truthtable::charcreate(int n) 
{
	char temp;
	cht = new char[n];
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个变元的名称，最大长度为1：";
		cin >> temp;
		cht[i] = temp;
	}
	cout << "输入完毕，" << n << "个变元分别为";
	for (int i = 0; i < n; i++)
	{
		cout << cht[i] << " ";
	}
	cout << "。" << endl;
}
void Truthtable::output()
{
	for (int i = 0; i < length; i++)
		cout << cht[i] << ' ';
	cout << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
			cout << tt[j][i] << " ";
		cout << "		" << content[i];
		cout << endl;
	}
	outPDNF();
}

/*for (int k = length - 1; k >= 0; k--)
{
	if (temnum[k]==1)	m = m + pow(2, k);
	else if (temnum[k] == -1)
	{
		for (int p = 0; p < length - 1; p++)
		{
			if(q[p]==NULL)		q[p] = k; //将所有未提及的变元存在一个数组中，记录其位置
		}
		flag = 0;
	}
}
if(flag)	content[m] = 1;
else
{
	for (int k = 0; k < length; k++)
	{
		if()
	}
}
for (int k = 0; k < length; k++)
{
	temnum[k] = -1;
//	cout << "*";
}*/
