/*
Oscar Martinez
CS 271
Dr. Lall
Project 8
*/

#ifndef _graph_h
#define _graph_h

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

template <class KeyType>
class graph
{
	public:
		graph(string filename);
		graph(const graph<KeyType>& g);
		~graph();


		void dfs();
		void topologicalsort();

		graph& operator=(const graph<KeyType>& g);   //sets this table equal to the assigned h's table

};


#include "graph.cpp"

#endif
