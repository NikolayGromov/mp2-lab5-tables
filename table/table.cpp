#include "table.h"
using namespace std;
poly::poly(pol b, string s)
{
	p = b;
	name = s;
}
bool poly::operator==(poly b)
{
	if ((p == b.p) && (name == b.name))
		return 1;
	return 0;
}
void table1::insert(pol b, string s)
{
	poly c(b, s);
	counterI = 0;
	counterI++;
	if (counter + 1 > maxsize)
		throw "Not enough space";
	a[counter++]=c;
}
void table1::Delete(string s)
{
	counterD = 0;
	poly c(search(s), s);
	for (int i = 0; i < counter; i++,counterD++)
		if (a[i] == c)
		{
			a[i] = a[counter--];
		}
}
pol table1::search(string s)
{
	counterS = 0;
	for (poly n : a)
	{
		counterS++;
		if (n.name == s)
			return n.p;
	}
	throw "Not found";
}
void table1::Print()
{
	if (!counter)
		throw "table is empty";
	for (int i=0;i<counter;i++)
	{
		cout << a[i].name << "   ";
		a[i].p.Print();
		cout << endl;
	}
}
void table2::insert(pol b, string s)
{
	int min,i,k;
	k = 0;
	counterI = 0;
	counterI++;
	if (counter + 1 > maxsize)
		throw "Not enough space";
	poly c(b, s);
		for (int j = 0; j<counter; j++)
		{
			i = 0;
			min = (s.length() > a[j].name.length()) ? a[j].name.length() : s.length();
			while ((s[i] == a[j].name[i]) && (i < min))
				i++;
			if (i == min)
			{
				counterI++;
				if (s.length() <= a[j].name.length())
				{
					for (int k = counter - 1; k >= j; k--)
						a[k + 1] = a[k];
					a[j]= c;
					counter++;
					counterI++;
					return;
				}
			}
			else
			{
				counterI++;
				if (s[i] < a[j].name[i])
				{
					for (int k = counter - 1; k >= j; k--)
						a[k + 1] = a[k];
					a[j] = c;
					counter++;
					return;
				}
			}
		}
		a[counter++] = c;
}
pol table2::search(string s)
{
	int i,l = 0;
	int r = counter;
	int mid,min;
	counterS = 0;
	while (l <= r) {
		counterS++;
		mid = (l + r) / 2; 
		if (a[mid].name == s)
			return(a[mid].p);
		counterS += 2;
		i = 0;
		min = (s.length() > a[mid].name.length()) ? a[mid].name.length() : s.length();
		while ((s[i] == a[mid].name[i]) && (i < min))
			i++;
		if (i == min)
		{
			if (s.length() < a[mid].name.length())
				r = mid - 1;
			else l = mid + 1;
		}
		else
		{
			if (s[i] < a[mid].name[i])
				r = mid - 1;
			else l = mid + 1;
		}
	}
	throw "is out";
}
int table2::get_i_search(string s)
{
	int i, l = 0;
	int r = counter;
	int mid, min;
	counterD = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		counterD++;
		if (a[mid].name == s)
			return mid;
		counterD += 2;
		i = 0;
		min = (s.length() > a[mid].name.length()) ? a[mid].name.length() : s.length();
		while ((s[i] == a[mid].name[i]) && (i < min))
			i++;
		if (i == min)
		{
			if (s.length() < a[mid].name.length())
				r = mid - 1;
			else l = mid + 1;
		}
		else
		{
			if (s[i] < a[mid].name[i])
				r = mid - 1;
			else l = mid + 1;
		}
	}
}
void table2::Delete(string s)
{
	int k = get_i_search(s);
	for (int i = k; i < counter-1; i++)
		a[i] = a[i+1];
	counter--;
}
table3::table3()
{
	n = 0;
	counterS = 0;
	counterD = 0;
	counterI = 0;
}
void table3::insert(pol b, string s)
{
	int key=0;
	poly c(b, s);
	counterI = 0;
	counterI++;
	if (n + 1 > maxsize)
		throw "Not enough space";
	for (int i = 0; i < s.length(); i++)
		key += int(s[i]);
	key %= 256;
	a[key].push_front(c);
	n++;
}
pol table3::search(string s)
{
	int key = 0;
	counterS = 0;
	for (int i = 0; i < s.length(); i++)
		key += int(s[i]);
	key = key % 256;
	counterS++;
	if (!a[key].empty())
		for (poly n : a[key])
		{
			counterS++;
			if (n.name == s)
				return n.p;
		}
	throw "Not found";
}
void table3::Delete(string s)
{
	int key = 0;
	counterD = 1;
	if (n - 1 < 0)
		throw "Table is empty";
	for (int i = 0; i < s.length(); i++)
		key += int(s[i]);
	key = key % 256;
	counterD++;
	if (!a[key].empty())
		for (poly n : a[key])
		{
			counterD++;
			if (n.name == s)
			{
				poly c(n.p, s);
				a[key].remove(c);
				break;

			}
		}
	n--;
}
void table3::Print()
{
	for(int i=0;i<maxsize;i++)
		if(!a[i].empty())
			for (poly n : a[i])
			{
				cout << n.name << "   ";
				n.p.Print();
				cout << endl;
			}
}