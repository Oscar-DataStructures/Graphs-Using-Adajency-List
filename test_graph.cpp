/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 8
*/


#include <iostream>
#include <string>
#include <cassert>
#include "graph.h"


// ======================= Test Default Constructor Method =====================
void test_defaultConstructor()
{
	graph a("testDirected.txt");
	assert(a.topologicalsort() == "[0, 1, 2, 3, 4]");
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

	graph c("testUndirected.txt");
	// cout << c.display_adjMatrix() << endl;
	// cout << c.display_adjList() << endl;
	// cout << c.display_colors() << endl;
	// assert(c.topologicalsort() == "[0, 1, 2, 3, 4]");
	// assert(c.display_colors() == "[0, 0, 0, 0, 0]");
	// assert(c.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	// assert(c.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

}


// ======================= Test Default Constructor Method =====================
void test_copyConstructor()
{
	graph a("testDirected.txt");
	assert(a.topologicalsort() == "[0, 1, 2, 3, 4]");
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

	cout << "HERE" << endl;
	graph b(a);
	cout << "COPY" << endl;
	assert(b.topologicalsort() == "[0, 1, 2, 3, 4]");
	cout << "COPY" << endl;
	assert(b.display_colors() == "[0, 0, 0, 0, 0]");
	cout << "COPY" << endl;
	assert(b.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	cout << "COPY" << endl;
	assert(b.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");
}


// ======================= Test Default Constructor Method =====================
void test_assignmentOp()
{
	graph a("testDirected.txt");
	// a.display_adjMatrix();
	// a.display_adjList();
	// a.display_colors();

	graph b = a;
	// b.display_adjMatrix();
	// b.display_adjList();
	// b.display_colors();
}


void test_dfs()
{
	graph a("testDirected.txt");
	// a.dfs();
}


void test_sort()
{
	graph a("testDirected.txt");
	// a.topologicalsort();
}

// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	std::cout << "Default Constructor Test	|Passed|" << std::endl;
	test_copyConstructor();
	std::cout << "Copy Constructor Test		|Passed|" << std::endl;
	test_assignmentOp();
	std::cout << "AssignmentOp  Test		|Passed|" << std::endl;
	test_dfs();
	test_sort();
	return 0;
}
