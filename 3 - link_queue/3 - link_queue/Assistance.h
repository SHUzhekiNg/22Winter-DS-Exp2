#ifndef __ASSISTANCE_H__
#define __ASSISTANCE_H__
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cstdarg>
#include <cassert>
#include<algorithm>
using namespace std;

enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

constexpr auto DEFAULT_SIZE = 1000;
constexpr auto DEFAULT_INFINITY = 1000000;


char GetChar(istream &inStream = cin);

template <class ElemType >
void Swap(ElemType &e1, ElemType &e2);

template<class ElemType>
void Display(ElemType elem[], int n);

template <class ElemType>
void Write(const ElemType &e);

class Error;

char GetChar(istream &inStream)
{
	char ch;
	while ((ch = (inStream).peek()) != EOF
		&& ((ch = (inStream).get()) == ' '
		|| ch == '\t'));
	return ch;
}

constexpr auto MAX_ERROR_MESSAGE_LEN = 100;

class Error
{
public:
	Error(const char *mes = "一般性异常!");
	~Error(void) {};
	void Show() const;
private:
	char message[MAX_ERROR_MESSAGE_LEN];
};

Error::Error(const char *mes)
{
	strcpy(message, mes);
}

void Error::Show()const
{
	cout << message << endl;
}


template <class ElemType >
void Swap(ElemType &e1, ElemType &e2)
{
	ElemType temp;
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
{
	for (int i = 0; i < n; i++)
		cout << elem[i] << "  ";
	cout << endl; 
}

template <class ElemType>
void Write(const ElemType &e)
{
	cout << "飞机号: " << e.Id << endl << "起飞时间：" << e.ayear << "年" << e.amonth << "月" << e.aday << "日" << e.ahour << "时" << e.aminute << "分" << e.asecond << "秒";
	cout << " 起飞地点：" << e.aplace << endl << "降落时间：" << e.byear << "年" << e.bmonth << "月" << e.bday << "日" << e.bhour << "时" << e.bminute << "分" << e.bsecond << "秒";
	cout << " 降落地点：" << e.bplace << endl << "票价：" << e.price << " 总座位数：" << e.SeatNum << " 剩余座位数：" << e.EmptyNum << endl;
}

#endif
