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
	//a.dfs();
	// a.display_adjMatrix();
	// a.display_adjList();
	// a.display_colors();

	graph b(a);
}


// ======================= Test Default Constructor Method =====================
void test_copyConstructor()
{
	graph a("test.txt");
	// a.display_adjMatrix();
	// a.display_adjList();
	// a.display_colors();

	graph b(a);
	// b.display_adjMatrix();
	// b.display_adjList();
	// b.display_colors();
}


// ======================= Test Default Constructor Method =====================
void test_assignmentOp()
{
	graph a("test.txt");
	// a.display_adjMatrix();
	// a.display_adjList();
	// a.display_colors();

	graph b = a;
	// b.display_adjMatrix();
	// b.display_adjList();
	// b.display_colors();
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

	return 0;
}
