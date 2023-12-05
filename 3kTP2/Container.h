#pragma once
#include "Train.h"

class Container
{
	Train* data;
	int size;
public:
	Container();
	~Container();
	void add();
	void del();
	void sort();
	void red();
	void print();
	void search();
};