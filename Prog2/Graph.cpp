//Program Name: Program 2 Part 1 + 2
//Programmer Name: Khodr Salman
/*
* Description:
* create an undirected graph with weighted edges, create an initial MST for the graph.
* Then update the MST as changes, like inserting / deleting vertices / edges occur.
*/
//Date Created: 03/16/21

#include "Header.h"

//Description: constructor
//Pre-condition:  object must be created
//Post-condition: the visited and list arrays are set to empty/null
Graph::Graph()
{
	for (int i = 0; i < 100; i++)
	{
		adjList[i] = nullptr;
	}
}

//Description: insert new vertex to adjacency list array
//Pre-condition: function called with string passed
//Post-condition: a new vertex added to the list array
void Graph::addVertex(string v, ofstream& outFile) {
	Node* n = new Node;
	n->vertex = v;
	n->next = nullptr;

	for (int i = 0; i < 100; i++) {		// finding an empty spot in the list array to insert new vertex
		if (adjList[i] == nullptr) {
			adjList[i] = n;
			cout << "the vertex " << v << " has been inserted \n";
			outFile << "the vertex " << v << " has been inserted \n";
			break;
		}
		else if (adjList[i]->vertex == v) {	// checking if the vertex already exists
			cout << "error: the vertex " << v << " already exists\n";
			outFile << "error: the vertex " << v << " already exists\n";
			break;
		}
	}
}

//Description: insert an edge between two vertices
//Pre-condition: function called with two string variables + int passed in
//Post-condition: new edge added between two vertices
void Graph::addEdge(string v1, string v2, float w, ofstream& outFile) {
	int confirmed = 0;
	Node* temp = nullptr;

	for (int i = 0; i < 100; i++) {		// making sure the vertex exist in adj
		if (adjList[i] == nullptr) {		
			break;
		}
		if (adjList[i]->vertex == v1) {	//check if exists
			confirmed++;
			temp = adjList[i]->next;
			while (temp != nullptr) {
				if (temp->vertex == v2) {
					cout << "error: the edge between " << v1 << " and " << v2 << " already exists\n";
					outFile << "error: the edge between " << v1 << " and " << v2 << " already exists\n";
					return;
				}
				temp = temp->next;
			}
		} 
		if (adjList[i]->vertex == v2) {
			confirmed++;
			temp = adjList[i]->next;
			while (temp != nullptr) {
				if (temp->vertex == v1) {
					cout << "error: the edge between " << v1 << " and " << v2 << " already exists\n";
					outFile << "error: the edge between " << v1 << " and " << v2 << " already exists!" << endl;
					return;
				}
				temp = temp->next;
			}
		}
		if (confirmed == 2) {	// both vertices exist
			break;
		}
	}
	if (confirmed != 2) {
		cout << "error: one or more vertex not valid\n";
		outFile << "error: one or more vertex not valid\n";
		return;
	}

	for (int i = 0; i < 100; i++) {		// adding the edge to vertices in adj list
		if (adjList[i] != nullptr) {
			if (adjList[i]->vertex == v1) {
				Node* n = new Node;		// creating a new node to add to the end of v1
				n->vertex = v2;
				n->weight = w;
				n->next = nullptr;
				temp = adjList[i];
				while (temp->next != nullptr) {	// moving to the end of v1  NOTE: try looping while temp is null?
					temp = temp->next;
				}
				temp->next = n;
				confirmed++;
			}
			else if (adjList[i]->vertex == v2) {
				Node* n = new Node;		// creating a new node to add to the end of v1
				n->vertex = v1;
				n->weight = w;
				n->next = nullptr;
				temp = adjList[i];
				while (temp->next != nullptr) {
					temp = temp->next;
				}
				temp->next = n;
				confirmed++;
			}
			if (confirmed == 4) {	// both vertices were confirmed
				cout << "edge between " << v1 << " and " << v2 << " added \n";
				outFile << " edge between " << v1 << " and " << v2 << " added \n";
				break;
			}
		}
	}
}

//Description: prints the adjacency list
//Pre-condition: must be called
//Post-condition:  list of verticies and edges is printed to console 
void Graph::printGraph(ofstream& outFile)
{
	Node* t = nullptr;
	cout << "printing the graph:\n";
	outFile << "printing the graph:\n";

	for (int i = 0; i < 100; i++)
	{
		if (adjList[i] == nullptr) {break;}//stops if the list is empty

		cout << adjList[i]->vertex;
		outFile << adjList[i]->vertex;

		t = adjList[i]->next;
		while (t != nullptr)
		{
			//format this how he had it in that one slide 
			cout << "->[ " << t->vertex << " | " << t->weight << " ]"; 
			outFile << "->[ " << t->vertex << " | " << t->weight << " ]"; 

			t = t->next;
		}

		cout << endl;
		outFile << endl;

	}
}

//Description: deletes the vertex passed in
//Pre-condition: must be called and vertex to be deleted passed in
//Post-condition: vertex to be deleted is deleted
void Graph::deleteVertex(string v, ofstream& outFile) {
	for (int i = 0; i < 100; i++) {
		if (adjList[i] == nullptr) {
			cout << "error: the vertex " << v << " does not exist\n";
			outFile << "error: the vertex " << v << " does not exist\n";
			return;
		}
		if (adjList[i]->vertex == v) {
			while (adjList[i]->next != nullptr) {
				deleteEdge(v, adjList[i]->next->vertex, outFile);
			}
			delete adjList[i];
			adjList[i] = nullptr;
			for (int j = i; j < 100; j++) {
				adjList[j] = adjList[j + 1];
			}
			cout << "the vertex " << v << " deleted sucessfully \n";
			outFile << "the vertex " << v << " deleted sucessfully \n";
			break;
		}
	}
}

//Description: delete edge from the adjacency list
//Pre-condition: must be called with two string parameters passed in
//Post-condition: edge is deleted from the ajacency list
void Graph::deleteEdge(string v1, string v2, ofstream& outFile) {
	Node* temp = nullptr;
	Node* prev = nullptr;
	int confirmedDel = 0;

	for (int i = 0; i < 100; i++) {
		if (adjList[i] == nullptr) {
			cout << "error: the edge between " << v1 << " and " << v2 << " does not exist\n";
			outFile << "error: the edge between " << v1 << " and " << v2 << " does not exist\n";
			return;
		}
		if (adjList[i]->vertex == v1) {
			temp = adjList[i]->next;
			prev = adjList[i];
			while (temp != nullptr) {
				if (temp->vertex == v2) {
					prev->next = temp->next;
					delete temp;
					temp = nullptr;
					confirmedDel++;
					break;
				}
				prev = temp;
				temp = temp->next;
			}
		}
		if (adjList[i]->vertex == v2) {
			temp = adjList[i]->next;
			prev = adjList[i];
			while (temp != nullptr) {
				if (temp->vertex == v1) {
					prev->next = temp->next;
					delete temp;
					temp = nullptr;
					confirmedDel++;
					break;
				}
				prev = temp;
				temp = temp->next;
			}
		}
		if (confirmedDel == 2) {
			cout << " edge between " << v1 << " and " << v2 << " deleted\n";
			outFile << " edge between " << v1 << " and " << v2 << " deleted\n";
			return;
		}
	}
	cout << "error: the edge between " << v1 << " and " << v2 << " does not exist\n";
	outFile << "error: the edge between " << v1 << " and " << v2 << " does not exist\n";
}
