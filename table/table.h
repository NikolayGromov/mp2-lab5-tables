#ifndef _TABLE_H_
#define _TABLE_H_
#include "pol.h"
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
const int maxsize = 256;
struct poly
{
	pol p;
	string name;
public:
	poly() {};
	poly(pol b, string s);
	bool operator==(poly b);
};
class table1
{
protected:
	poly a[maxsize];
	int counter;
public:
	int counterS;
	int counterI;
	int counterD;
	table1() { counter = 0; counterS = 0; counterD = 0;
	counterI = 0;
	};
	void insert(pol b, string s);
	pol search(string b);
	void Delete(string b);
	void Print();
	poly* get_vec() { return a; }
};
class table2:public table1
{
public:
	void insert(pol b, string s);
	pol search(string b);
	int get_i_search(string s);
	void Delete(string b);
};
class table3
{
	list<poly> a[maxsize];
	int n;
public:
	int counterS;
	int counterD;
	int counterI;
	table3();
	void insert(pol b, string s);
	pol search(string b);
	void Delete(string b);
	void Print();
};

#endif