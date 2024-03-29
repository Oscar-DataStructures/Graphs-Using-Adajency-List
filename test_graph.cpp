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
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

	graph c("testUndirected.txt");
	assert(c.display_colors() == "[0, 0, 0, 0, 0]");
	assert(c.display_adjList() == "\n0 : 1, 2\n1 : 0, 2, 3\n2 : 0, 1, 4\n3 : 1, 4\n4 : 2, 3");
	assert(c.display_adjMatrix() == "\n0 1 2 0 0 \n1 0 1 1 0 \n2 1 0 0 3 \n0 1 0 0 1 \n0 0 3 1 0 \n");

}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	graph a("testDirected.txt");
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

	graph b(a);
	assert(b.display_colors() == "[0, 0, 0, 0, 0]");
	assert(b.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(b.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

}


// ========================= Test AssignmentOp Method ==========================
void test_assignmentOp()
{
	graph a("testDirected.txt");
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");

	graph b = a;
	assert(b.display_colors() == "[0, 0, 0, 0, 0]");
	assert(b.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(b.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");
}


// ====================== Test Depth First Search Method =======================
void test_dfs()
{
	graph a("testDirected.txt");
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");
	a.dfs(); // should output 0 2 4 1 3 void function cant return a string
	assert(a.display_colors() == "[2, 2, 2, 2, 2]");

	graph b("testUndirected.txt");
	assert(b.display_colors() == "[0, 0, 0, 0, 0]");
	assert(b.display_adjList() == "\n0 : 1, 2\n1 : 0, 2, 3\n2 : 0, 1, 4\n3 : 1, 4\n4 : 2, 3");
	assert(b.display_adjMatrix() == "\n0 1 2 0 0 \n1 0 1 1 0 \n2 1 0 0 3 \n0 1 0 0 1 \n0 0 3 1 0 \n");
	b.dfs(); // should output 0 2 4 3 1
	assert(b.display_colors() == "[2, 2, 2, 2, 2]");
}


// ============================ Test Sort Method ===============================
void test_topologicalSort()
{
	graph a("testDirected.txt");
	assert(a.display_colors() == "[0, 0, 0, 0, 0]");
	assert(a.display_adjList() == "\n0 : 1, 2\n1 : 2, 3\n2 : 4\n3 : \n4 : ");
	assert(a.display_adjMatrix() == "\n0 1 2 0 0 \n0 0 5 4 0 \n0 0 0 0 3 \n0 0 0 0 0 \n0 0 0 0 0 \n");
	assert(a.topologicalsort() == "[0, 1, 2, 3, 4]");

	graph b("testUndirected.txt");
	assert(b.display_colors() == "[0, 0, 0, 0, 0]");
	assert(b.display_adjList() == "\n0 : 1, 2\n1 : 0, 2, 3\n2 : 0, 1, 4\n3 : 1, 4\n4 : 2, 3");
	assert(b.display_adjMatrix() == "\n0 1 2 0 0 \n1 0 1 1 0 \n2 1 0 0 3 \n0 1 0 0 1 \n0 0 3 1 0 \n");
	assert(b.topologicalsort() == "[cycle detected]");
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
	std::cout << "DFS  Test			|Passed|" << std::endl;
	test_topologicalSort();
	std::cout << "Topological Sort  Test		|Passed|" << std::endl;

	return 0;
}
