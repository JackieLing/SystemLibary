#include <iomanip>
#include "string"
#include"bookmis.h"
#include"status.h"
#include<iostream>
using namespace std;
void Printf(BookList &L);
int InitList(BookList &L)
{
	L.elem = new Book[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}
int GetBook(BookList L, int i, Book &e) 
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int InsertBook(BookList &L, int i) 
{
	int j = 0;
	if ((i<1) || (i > L.length + 1)) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	for (j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];

	std::cout << "请输入书号、书名、作者" << endl;
	std::cin >> L.elem[i].isbn >> L.elem[i].name >> L.elem[i].author;
	++L.length;
	Printf(L);

	return OK;
}




void Update(BookList &L)
{
	Book e;
	int i;
	char n;
	while (1)
	{
		std::cout << "请输入要修改的书的序号 ,输入0返回上一级:";
		std::cin >> i;
		if (i == 0) break;
		else if ((i<1) || (i>L.length)) std::cout << "输入的序号不正确" << endl;
		else
		{
			std::cout << L.elem[i - 1].isbn << "  " << L.elem[i - 1].name << "  " << L.elem[i - 1].author << endl;
			std::cout << "请选择要修改的对象，1：书号，2：书名，3：作者 ,输入#返回上一级" << endl;
			std::cin >> n;
			if (n == '#')
				break;
			switch (n)
			{
			case '1':std::cout << "把其修改为：";
				std::cin >> L.elem[i - 1].isbn;
				std::cout << L.elem[i - 1].isbn << "  " << L.elem[i - 1].name << "  " << L.elem[i - 1].author << endl; break;
			case '2':std::cout << "把其修改为：";
				std::cin >> L.elem[i - 1].name;
				std::cout << L.elem[i - 1].isbn << "  " << L.elem[i - 1].name << "  " << L.elem[i - 1].author << endl; break;
			case '3':std::cout << "把其修改为：";
				std::cin >> L.elem[i - 1].author;
				std::cout << L.elem[i - 1].isbn << "  " << L.elem[i - 1].name << "  " << L.elem[i - 1].author << endl; break;
			default:break;
			}




		}
	}

}


void Create(BookList &L, int n) 
{
	int i;

	for (i = 0; i < n; i++)
	{
		std::cout << "请分别输入第" << i + 1 << "本书的书号、书名、作者" << endl;
		std::cin >> L.elem[i].isbn >> L.elem[i].name >> L.elem[i].author;

		L.length++;
	}
}
void Printf(BookList &L)
{
	int i;
	std::cout << "/---------------------  存在以下图书  ----------------------------------/" << endl;
	std::cout << "   " << setw(10) << left << "序号" << setw(10) << left << "书号" << setw(30) << left << "书名" << setw(10) << left << "作者" << endl << endl;
	for (i = 0; i<L.length; i++)
	{
		std::cout << "   " << setw(10) << left << i + 1 << setw(10) << left << L.elem[i].isbn << setw(30) << left << L.elem[i].name << setw(10) << left << L.elem[i].author << endl;
	}
	std::cout << "/-----------------------------------------------------------------------/" << endl;
}
void main()
{
	BookList L;
	Book B;
	char n[20];
	int m = 0;
	char s = 0;
	InitList(L);
	std::cout << "/------------------------欢迎进入图书管理系统---------------------------/" << endl;
	std::cout << "创建图书信息" << endl;
	std::cout << "请输入书本数目：";
	std::cin >> m;
	Create(L, m);
	Printf(L);
	while (1)
	{
		std::cout << "请选择要进行的操作 :1：查找  2： 插入  3： 删除  4：修改  0: 显示：  ：" << endl;
		std::cin >> s;
		switch (s)
		{
		case '0': Printf(L); break;
		case '1': LocateBook(L); break;
		case '2': InsertBook(L, L.length); break;
		case '4': Update(L); break;
		case '3':Deletebyname(L); break;
		}
	}

	system("pause");
}

