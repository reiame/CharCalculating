#include<iostream>
using namespace std;
/*��������ѧ �������ϵ 1892052*/
/*���м�ע������Ϊ���Դ���ʹ�ã�����ȥע�ͻ�*/
class Truthtable  //������ֵ����
{
private:
	int length; //ָ��Ԫ����
	int width; //ָ��ֵ��ĸ߶�
	int** tt; //�����ά���鴢�沢�����ֵ������
	int* content; //��¼��ֵ�����յĲ���ֵ
	char* cht; //һά�����¼��Ԫ����
public:
	Truthtable() { length = 1; width = 1; tt = NULL; content = NULL; cht = NULL; }
	void output();
	void outPDNF()
	{
		int f = 0;
		cout << "��ʽ������ȡ��ʽΪ����(";
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
		cout << "��ʽ������ȡ��ʽΪ����(";
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
		cout << "������һ��ʽ�ӣ����������б�Ԫ�ô�д��ĸ���棬��ȡ��+���棬��ȡ��*���棨ע����ȡ���ȼ����ں�ȡ������Ȼ��س�������" << endl;
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
		cout << "�������Ԫ���ܸ�����" << endl;
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
		cout << "�������" << i + 1 << "����Ԫ�����ƣ���󳤶�Ϊ1��";
		cin >> temp;
		cht[i] = temp;
	}
	cout << "������ϣ�" << n << "����Ԫ�ֱ�Ϊ";
	for (int i = 0; i < n; i++)
	{
		cout << cht[i] << " ";
	}
	cout << "��" << endl;
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
			if(q[p]==NULL)		q[p] = k; //������δ�ἰ�ı�Ԫ����һ�������У���¼��λ��
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
