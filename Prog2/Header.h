//Program Name: Program 2 Part 1 + 2
//Programmer Name: Khodr Salman
/*
* Description:
* create an undirected graph with weighted edges, create an initial MST for the graph.
* Then update the MST as changes, like inserting / deleting vertices / edges occur.
*/
//Date Created: 03/16/21

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Graph {
protected:
	struct Node {
		string vertex;
		float weight;
		Node* next;
	};
	
	Node* adjList[100];

public:
	void addVertex(string, ofstream&);
	void addEdge(string, string, float, ofstream&);
	void printGraph(ofstream&);
	void deleteVertex(string, ofstream&);
	void deleteEdge(string, string, ofstream&);
	Graph();
};

class MSTTree : public Graph {
protected:
	
	struct Data { //this will be the heap 
		string vertex1;
		string vertex2;
		float weight;
	};

	struct VertexNode { //this will be the adjacency list for the MST
		string vertexRoot;
		float weight;
		VertexNode* next;
	};
	
	Data heap[100];
	VertexNode* AdjMST[100];
public:
	void buildTree(Node*);
	void MSTPrint(VertexNode*, ofstream&);
	MSTTree();
};

#endif
