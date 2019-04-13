#include <gtest.h>
#include "table.h"
#include <iostream>
using namespace std;
TEST(pol, suka_blyat)
{
	List a,b;
	a.Insert_begin(154, 12);
	b.Insert_begin(154, 2);
	pol b1(b);
	pol b2(a);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(b2.a.head->c, 12);
}
TEST(pol, is_eq)
{
	List a;
	a.Insert_begin(3154, 12);
	pol b1(a);
	pol b2(a);
	EXPECT_EQ(b1, b2);
}
TEST(pol, hash)
{
	List a;
	int key;
	a.Insert_begin(3154, 256);
	a.Insert_begin(3154, 12.2);
	pol b(a);
	key = (int)b.get_key()%256;
	EXPECT_EQ(key, 12);
}
TEST(table1, can_insert)
{
	List a;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	pol b1(a);
	table1 t;
	t.insert(b1,"a");
	t.insert(b1,"b");
	EXPECT_EQ(t.get_vec()[0].p, b1);
}
TEST(table1, can_search)
{
	List a;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	pol b1(a);
	table1 t;
	t.insert(b1,"a");
	t.insert(b1,"a");
	EXPECT_EQ(t.search("a"), b1);
}

TEST(table1, can_Delete)
{
	List a;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	pol b1(a);
	table1 t;
	t.insert(b1,"a");
	t.Delete("a");
	ASSERT_NO_THROW(t.insert(b1,"b"));
}
TEST(table1, can_Delete_2)
{
	List a,b;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	b.Insert_begin(153, 12);
	pol b1(a);
	pol b2(b);
	table1 t;
	t.insert(b1,"a");
	t.insert(b2,"b");
	t.Delete("a");
	EXPECT_EQ(t.search("b"), b2);
}
TEST(table2, can_insert_correct)
{
	List a,b;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	b.Insert_begin(142, 12);
	pol b1(a);
	pol b2(b);
	table2 t;
	t.insert(b1, "b");
	t.insert(b2, "a");
	EXPECT_EQ(t.get_vec()[1].p, b1);
}
TEST(table2, can_insert_correct_2)
{
	List a, b, c;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	b.Insert_begin(142, 12);
	c.Insert_begin(111, 12);
	pol b1(a);
	pol b2(b);
	pol b3(c);
	pol b4(a);
	table2 t;
	t.insert(b1, "aa");
	t.insert(b2, "v");
	t.insert(b3, "va");
	t.insert(b4, "aaa");
	EXPECT_EQ(t.get_vec()[3].p, b3);
}
TEST(table2, can_search_correct)
{
	List a, b, c;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	b.Insert_begin(142, 12);
	c.Insert_begin(111, 12);
	pol b1(a);
	pol b2(b);
	pol b3(c);
	pol b4(a);
	table2 t;
	t.insert(b1, "aa");
	t.insert(b2, "v");
	t.insert(b3, "va");
	t.insert(b4, "aaa");
	EXPECT_EQ(t.search("aaa"), b4);
}
TEST(table2, can_del_correct)
{
	List a, b, c;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	b.Insert_begin(142, 12);
	c.Insert_begin(111, 12);
	pol b1(a);
	pol b2(b);
	pol b3(c);
	pol b4(a);
	table2 t;
	t.insert(b1, "aa");
	t.insert(b2, "v");
	t.insert(b3, "va");
	t.insert(b4, "aaa");
	t.Delete("aaa");
	ASSERT_ANY_THROW(t.search("aaa"));
}
TEST(table3, can_Delete_1)
{
	List a, b;
	a.Insert_begin(154, 12);
	a.Insert_begin(153, 12);
	b.Insert_begin(153, 12);
	pol b1(a);
	pol b2(b);
	table3 t;
	t.insert(b1, "a");
	ASSERT_NO_THROW(t.Delete("a"));
}