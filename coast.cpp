/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 8
*/


#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

enum Color {WHITE, GRAY, BLACK};	//0 = white, 1 = gray, 2 = black


class graph
{
	public:
		graph(int row,int column, vector<int> color)
		{
  			constructAdjList(row,column);   //does error check
			this->colors = color;
		}
		~graph()
		{
			this->colors.clear();
			this->numVertices = 0;
			this->adjList.clear();
		}


		int dfs()
		{
			int result = 0;
			for(int i = 0; i < numVertices; i++)
  			{
    			if (colors[i] == WHITE)
				{
					dfsNonRecursive(i);
					result++;
				}
  			}
			return result;
		}


	private:
		std::vector<int> colors;		//make a std::vector to hold the color of n things
		int numVertices;
		std::map<int, std::vector<int> > adjList;

		void constructAdjList(int rows, int columns)
		{
			std::string vertices;
  			std::string line;
  			numVertices = rows * columns;
  			for(int i = 0; i < numVertices; i++)
  			{
				adjList[i];   //populate keys
    			std::vector<int> result;
				if ((i+columns)>=0 && ((i+columns)<numVertices)) result.push_back((i+columns));
				if ((i-columns)>=0 && ((i-columns)<numVertices)) result.push_back((i-columns));
				if ( (i+1)%columns != 0 ) result.push_back((i+1));
				if ( i%columns !=0 ) result.push_back((i-1));
    			adjList[i] = result;
  			}
		}

		void dfsNonRecursive(int vertex)
		{
			stack<int> processStack;
  			colors[vertex] = GRAY;
  			processStack.push(vertex);
  			while(processStack.empty() != true)   //while stack is not empty
  			{
    			int u = processStack.top();       //returns top element
    			processStack.pop();   //pops top element
    			int vecLen = adjList.at(u).size();    //gets size of vector at key j
    			for(int i = 0; i < vecLen; i++)
    			{
      				int v = adjList.at(u)[i];   //get the vertex at u
    				if(colors[v] == WHITE)    //if vertex is white
      				{
				        processStack.push(v);   //add vertex to stack
        				colors[v] = GRAY;   //color vertex gray
      				}
    			}
				colors[u] = BLACK;    //once no more neighbors we color black
  			}
		}


};


// int count(vector<vector<char>>& v, int i, int j) {
//     int total = 0;
//     if(v[i+1][j] == 's') {
//         total++;
//     }
//     if(v[i-1][j] == 's') {
//         total++;
//     }
//     if(v[i][j+1] == 's') {
//         total++;
//     }
//     if(v[i][j-1] == 's') {
//         total++;
//     }
//     return total;
// }
//
// bool untouched(vector<vector<char>>& v, int i, int j, int m, int n) {
//     if(i < 0 || j < 0 || i >= m+2 || j >= n+2) {
//         return false;
//     }
//     if(v[i][j] != '0') {
//         return false;
//     }
//     return true;
// }

int main()
{
    // int m, n;
    // cin >> m >> n;
		//
    // vector<vector<char>> v;
    // v.resize(m+2, vector<char>(n+2, '0'));
		//
    // // Read in data
    // for(int i = 1; i <= m; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cin >> v[i][j];
    //     }
    // }
		//
    // queue<pair<int, int>> q;
    // q.push({0,0});
		//
    // while(!q.empty()) {
    //     int i = q.front().first;
    //     int j = q.front().second;
    //     q.pop();
		//
    //     if(v[i][j] != '0') {
    //         continue;
    //     }
		//
    //     v[i][j] = 's';
		//
    //     if(untouched(v, i+1, j, m, n)) {
    //         q.push({i+1, j});
    //     }
    //     if(untouched(v, i-1, j, m, n)) {
    //         q.push({i-1, j});
    //     }
    //     if(untouched(v, i, j+1, m, n)) {
    //         q.push({i, j+1});
    //     }
    //     if(untouched(v, i, j-1, m, n)) {
    //         q.push({i, j-1});
    //     }
    // }
		//
    // // Count the edges
    // int total = 0;
    // for(int i = 1; i <= m; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         if(v[i][j] == '1') {
    //             total += count(v, i, j);
    //         }
    //     }
    // }
    // cout << total << endl;
}
