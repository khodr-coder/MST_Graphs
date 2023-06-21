//Program Name: Program 2 Part 1 + 2
//Programmer Name: Khodr Salman
/*
* Description:
* create an undirected graph with weighted edges, create an initial MST for the graph.
* Then update the MST as changes, like inserting / deleting vertices / edges occur.
*/
//Date Created: 03/16/21

#include "Header.h"

//Description:  initializes the weight of the heap array and sets the root to null
//Pre-condition: An object is created in main 
//Post-condition: The weight of the heap is set to sentinal value -1, the root array is set to null 
MSTTree::MSTTree()
{
	for (int i = 0; i < 100; i++)
	{
		heap[i].weight = -1;
		AdjMST[i] = nullptr;
	}
	
}

//i got confused here and didnt know how to work through the logic 
//Description: this was supposed to build the MST
//Pre-condition: a node pointer must be passed in
//Post-condition: the minimum spanning tree is built
void MSTTree::buildTree(Node* vertexBuild)
{
	string node = vertexBuild->vertex;
	VertexNode* temp = nullptr;

	VertexNode* n = new VertexNode;		// creating a new Vertex node
	n->vertexRoot = vertexBuild->vertex;
	n->next = nullptr;

	for (int i = 0; i < 100; i++) {	// finding the first nullptr in roots and making that point to the new Vertex node
		if (AdjMST[i] == nullptr) {
			AdjMST[i] = n;
			temp = n;	// making temp point to the newly created Vertex node
			n = n->next;
		}
	}
}


//Description: doesnt work - prints the MST
//Pre-condition:  function must be called
//Post-condition: depth of the minimum spanning tree is printed for each level
void MSTTree::MSTPrint(VertexNode* node, ofstream& outFile) {
	
	cout << node->vertexRoot << endl;
	outFile << node->vertexRoot << endl;

	if (node->next != nullptr) {	// will print left child of current node
		MSTPrint(node->next, outFile);
	}
}
