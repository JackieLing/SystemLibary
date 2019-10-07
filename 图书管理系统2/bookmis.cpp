#include"bookmis.h"
#include<iostream>
using namespace std;
void LocateBook(BookList L)
{
	Book e;
	int i;
	char n = 0;
	while (1)
	{
		std::cout << "输入1按书号查找，输入2按书名查找，输入3按作者名查找，输入4按序号查找,输入#返回上一级：" << endl;
		std::cin >> n;
		if (n == '#')
			break;
		if (n == '1')
		{
			std::cout << "请输入要查找的书号：";
			std::cin >> e.isbn;
			for (i = 0; i < L.length; i++)
			{
				if (strcmp(L.elem[i].isbn, e.isbn) == 0)
				{
					std::cout << L.elem[i].isbn << "  " << L.elem[i].name << "  " << L.elem[i].author << endl;
					break;
				}

			}
			if (i >= L.length)
				std::cout << "查无此书！请查看输入是否正确" << endl;


		}
		if (n == '2')
		{
			std::cout << "请输入要查找的书名：";
			std::cin >> e.name;
			for (i = 0; i < L.length; i++)
			{
				if (strcmp(L.elem[i].name, e.name) == 0)
				{
					std::cout << L.elem[i].isbn << "  " << L.elem[i].name << "  " << L.elem[i].author << endl;
					break;
				}


			}
			if (i >= L.length)
				std::cout << "查无此书！请查看输入是否正确" << endl;
		}
		if (n == '3')
		{
			std::cout << "请输入要查找的作者：";
			std::cin >> e.author;
			for (i = 0; i < L.length; i++)
			{
				if (strcmp(L.elem[i].author, e.author) == 0)
				{
					std::cout << L.elem[i].isbn << "  " << L.elem[i].name << "  " << L.elem[i].author << endl;
					break;
				}


			}
			if (i >= L.length)
				std::cout << "查无此书！请查看输入是否正确" << endl;
		}
		if (n == '4')
		{
			std::cout << "请输入要查找的序号：";
			std::cin >> i;
			if (i <= L.length)
			{
				std::cout << L.elem[i - 1].isbn << "  " << L.elem[i - 1].name << "  " << L.elem[i - 1].author << endl;


			}
			if (i > L.length)
				std::cout << "查无此书！请查看输入是否正确" << endl;
		}



	}

}

void Deletebyname(BookList &L)
{
	Book e;
	int i, j;
	char n = 0;
	while (1)
	{


		std::cout << "请输入要删除的书名：";
		std::cin >> e.name;
		for (i = 0; i < L.length; i++)
		{
			if (strcmp(L.elem[i].name, e.name) == 0)
			{
				for (j = i + 1; j <= L.length - 1; j++)
					L.elem[j - 1] = L.elem[j];
				--L.length;
				Printf(L);

			}


		}
	}

}