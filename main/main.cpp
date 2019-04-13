#include "table.h"
#include <iostream>
#include <fstream>
using namespace std;
void main()
{
	int r, j, k, p,ci,cd,cs;
	double c;
	List a;
	string s;
	table1 t1;
	table2 t2;
	table3 t3;
	ofstream out;          // поток дл€ записи
	out.open("\Log.txt"); // окрываем файл дл€ записи
		out << "Ћогирование" << endl;
	cout << "Enter number of polynomials" << endl;
	cin >> r;
	for (int i = 0; i < r; i++)
	{
		cout << "Enter name for polynomial" << endl;
		cin >> s;
		cout << "Entering polynomial" << endl;
		cout << "Enter number of monomials" << endl;
		cin >> k; cout << endl;
		for (int j = 0; j < k; j++)
		{
			cout << "Enter power of monom" << " " << j + 1 << endl;
			cin >> p; cout << endl;
			while (p > 999)
			{
				cout << "Incorrect power, try again" << endl;
				cin >> p; cout << endl;
			}
			cout << "Enter coefficient of monom" << " " << j + 1 << endl;
			cin >> c; cout << endl;
			a.Insert_end(p, c);
		}
		pol b(a);
		a.clear();
		t1.insert(b, s);
		t2.insert(b, s);
		t3.insert(b, s);
		out << " оличество операций во вставке в первую таблицы:  " <<t1.counterI<< endl;
		out << " оличество операций во вставке во вторую таблицы: " <<t2.counterI<< endl;
		out << " оличество операций во вставке в третью таблицы:  " <<t3.counterI<< endl;
	}
	cout << "Tables:" << endl;
	t1.Print();
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
	t2.Print();
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
	t3.Print();
	cout << endl;
	cout << "==================================================================" << endl;
	cout << endl;
	while (k)
	{
		cout << "1.Delete" << endl;
		cout << "2.Search" << endl;
		cout << "3.Change" << endl;
		cout << "4.Show tables" << endl;
		cout << "0.Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "Enter his name" << endl;
			cin >> s;
			t1.Delete(s);
			t2.Delete(s);
			t3.Delete(s);
			out << " оличество операций в удалении в первой таблице:  " << t1.counterD << endl;
			out << " оличество операций в удалении во второй таблице: " << t2.counterD << endl;
			out << " оличество операций в удалении в третьей таблице: " << t3.counterD << endl;
			cout << "He is dead" << endl;
			break;
		}
		case 2:
		{
			cout << "Enter his name" << endl;
			cin >> s;
			pol b = t1.search(s);
			t2.search(s);
			t3.search(s);
			out << " оличество операций в поиске в первой таблице:    " << t1.counterS << endl;
			out << " оличество операций в поиске во второй таблице:   " << t2.counterS << endl;
			out << " оличество операций в поиске в третьей таблице:   " << t3.counterS << endl;
			cout << endl;
			b.Print();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Enter his name" << endl;
			cin >> s;
				pol b1 = t1.search(s);
				b1.Print();
				pol b2;
				cout << endl;
				cout << "If you want to perform the operations witn new polynomial enter 1, with table polynomial enter 0" << endl;
				cin >> k;
				if (k) {
					cout << "Entering 2-nd polynomial" << endl;
					cout << "Enter number of monomials" << endl;
					cin >> k; cout << endl;
					for (int i = 0; i < k; i++)
					{
						cout << "Enter power of monom" << " " << i + 1 << endl;
						cin >> p; cout << endl;
						while (p > 999)
						{
							cout << "Incorrect power, try again" << endl;
							cin >> p; cout << endl;
						}
						cout << "Enter coefficient of monom" << " " << i + 1 << endl;
						cin >> c; cout << endl;
						a.Insert_end(p, c);
					}
					cout << "Entering of polynomials is complited";
					pol b(a);
					b2 = b;
				}
				else
				{
					string s1;
					cout << "Enter his name" << endl;
					cin >> s1;
					pol b = t1.search(s1);
					b2 = b;
				}
					cout << endl;
					cout << "Choose operation" << endl;
					cout << "1.Add polynomials" << endl;
					cout << "2.Subtract polynomials" << endl;
					cout << "3.Multiply polynomials" << endl;
					cout << "4.Multiply 1-st polynomial on const" << endl;
					pol b3;
					cin >> k; cout << endl;
					switch (k)
					{
					case 1:
					{
						b3 = b1 + b2;
						t1.Delete(s);
						t2.Delete(s);
						t3.Delete(s);
						t1.insert(b3, s);
						t2.insert(b3, s);
						t3.insert(b3, s);
						break;
					}
					case 2:
					{
						b3 = b1 - b2;
						t1.Delete(s);
						t2.Delete(s);
						t3.Delete(s);
						t1.insert(b3, s);
						t2.insert(b3, s);
						t3.insert(b3, s);
						break;
					}
					case 3:
					{
						b3 = b1 * b2;
						t1.Delete(s);
						t2.Delete(s);
						t3.Delete(s);
						t1.insert(b3, s);
						t2.insert(b3, s);
						t3.insert(b3, s);
						break;
					}
					case 4:
					{
						cout << "Enter constant" << endl;
						cin >> c; cout << endl;
						b3 = b1.Mull(c);
						t1.Delete(s);
						t2.Delete(s);
						t3.Delete(s);
						t1.insert(b3, s);
						t2.insert(b3, s);
						t3.insert(b3, s);
						break;
					}
					default:
						break;
					}
				
			

			break;
		}

		case 4:
		{
			cout << "Tables:" << endl;
			t1.Print();
			cout << endl;
			cout << "==================================================================" << endl;
			cout << endl;
			t2.Print();
			cout << endl;
			cout << "==================================================================" << endl;
			cout << endl;
			t3.Print();
			cout << endl;
			cout << "==================================================================" << endl;
			cout << endl;
			break;

		}
		default:
			break;
		}
	}
}