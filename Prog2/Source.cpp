//Program Name: Program 2 Part 1 + 2
//Programmer Name: Khodr Salman
/*
* Description: 
* create an undirected graph with weighted edges, create an initial MST for the graph.
* Then update the MST as changes, like inserting / deleting vertices / edges occur.
*/
//Date Created: 03/16/21

#include "Header.h"

int main()
{

	int NumberofVertex, edgeAmount, userint;
	float edgeWeight;
	char yn, kF, choice;
	string filename, vertexID, v1, v2, outputFile;
	outputFile = "output.txt";

	ifstream inFile;
	ofstream outFile;

	outFile.open(outputFile);
	if (!outFile.is_open())
	{
		cout << "\nerror opening " << outputFile;
		exit(1);
	}
	else
		cout << outputFile << " opened with no issues ";

	Graph graphOB;
	MSTTree treeOB;

	cout << endl << "would you like to enter your data through a file or keyboard. enter F for file and K for keyboard -> "; 
	cin >> kF;

	if (toupper(kF) == 'F') {	//if user chooses file F
		cout << "\n enter the name of your input file -> ";
		cin >> filename;


		inFile.open(filename); 
		if (!inFile.is_open())
		{
			cout << "\nerror opening " << filename;
			exit(1);
		}
		else
		{
			inFile >> NumberofVertex;
			for (int i = 0; i < NumberofVertex; i++)
			{
				inFile >> vertexID; //takes in one vertex 
				treeOB.addVertex(vertexID, outFile);
				graphOB.addVertex(vertexID, outFile);

			}

			inFile >> edgeAmount; 
			for (int i = 0; i < edgeAmount; i++) 
			{
				inFile >> v1 >> v2 >> edgeWeight;
				if (edgeWeight < 0)
				{
					cout << "\nerror: edge must be poitive";
				}
				else {
					treeOB.addEdge(v1, v2, edgeWeight, outFile);
					graphOB.addEdge(v1, v2, edgeWeight, outFile);
					cout << "\n graph is now: ";
					graphOB.printGraph(outFile);
				}
			}
		}
	}
	else if (toupper(kF) == 'K')	//if user chooses keyboard 
	{
		cout << "\nwhat is the amount of verticies you will be entering -> ";
		cin >> NumberofVertex;
		for (int i = 0; i < NumberofVertex; i++)	//loops amount of vertecies 
		{
			cout << "\nenter a vertex -> ";
			cin >> vertexID;
			treeOB.addVertex(vertexID, outFile);
			graphOB.addVertex(vertexID, outFile);
		}
		cout << "\nwhat is the number of edges you will be entering -> ";
		cin >> edgeAmount;
		for (int i = 0; i < edgeAmount; i++)	//loops amount of edges
		{
			cout << "\nenter vertex 1, vertex 2 and the weight of the edge -> ";
			cin >> v1 >> v2 >> edgeWeight;
			if (edgeWeight < 0)
			{
				cout << "\nerror: edge cannot be less than 0";
			}
			else {
				treeOB.addEdge(v1, v2, edgeWeight, outFile);
				graphOB.addEdge(v1, v2, edgeWeight, outFile);
				cout << "\n graph is now: ";
				graphOB.printGraph(outFile);
				cout << endl;
			}
		}
	}
	do {
			//prints the menu to the user until Q is entered
			cout << "\n D) Delete Vertex OR Delete Edge \n I) Insert Vertex OR Insert Edge \n P) Print Graph OR Print MST \n Q) Quit\n";
			cout << "\n  Choose an option -> ";

			outFile << "\n D) Delete Vertex OR Delete Edge \n I) Insert Vertex OR Insert Edge \n P) Print Graph OR Print MST \n Q) Quit\n";
			outFile << "\n  Choose an option -> ";
			cin >> choice;

			switch (toupper(choice))
			{
			case 'D': 
				cout << "\n would you like to delete an edge or a vertex - 1 for vertex, 2 for edge ";
				cin >> userint;
				if (userint == 1) {
					cout << "\nenter the vertex name -> ";
					cin >> v1;
					graphOB.deleteVertex(v1, outFile);
					cout << "\n graph is now: ";
					graphOB.printGraph(outFile);
				}
				else if (userint == 2) {
					cout << "\nenter the two verticies of the edge -> ";
					cin >> v1 >> v2;
					graphOB.deleteEdge(v1, v2, outFile);
					cout << "\n graph is now: ";
					graphOB.printGraph(outFile);
					
				}
				else {
					cout << "\n invalid entry - 1 for graph or 2 for MST ";
				}
				break;
			case 'I':
				cout << "\n would you like to insert an edge or a vertex - 1 for vertex, 2 for edge -> ";
				cin >> userint;
				if (userint == 1) {
					cout << "\nenter your vertex -> ";
					cin >> v1;
					outFile << "\nvertex entered for insertion -> " << v1;
					cout << "\nvertex entered for insertion -> " << v1;
					graphOB.addVertex(v1, outFile);
					cout << "\n graph is now: ";
					graphOB.printGraph(outFile);
				}
				else if (userint == 2) {
					cout << "\n enter the name of the 2 verticies and the edge weight -> ";
					cin >> v1 >> v2 >> edgeWeight;
					outFile << "\nverticies entered -> " << v1 << ", " << v2 << "\nweight entered -> " << edgeWeight;
					cout << "\nverticies entered -> " << v1 << ", " << v2 << "\nweight entered -> " << edgeWeight;
					graphOB.addEdge(v1, v2, edgeWeight, outFile);
					cout << "\n graph is now: ";
					graphOB.printGraph(outFile);
					
				}
				else {
					cout << "\n invalid entry - 1 for graph or 2 for MST ";
				}
				
				break;
			case 'P':

				cout << "\n would you like to print the graph or the MST ? 1 for graph or 2 for mst -> ";
				cin >> userint;
				if (userint == 1) {
					cout << endl;
					graphOB.printGraph(outFile); 
				}
				else if (userint == 2) {
					
					treeOB.printGraph(outFile); 
				}
				else {
					cout << "\n invalid entry - 1 for graph or 2 for MST ";
				}
				
				break;
			case 'Q':
				cout << "You are now quitting the program" << endl; //program ends 
				outFile << "You are now quitting the program" << endl; 

				break;
			default:
				cout << "\n invalid entry";
			}
			
	} while (toupper(choice) != 'Q');

		inFile.close();
		outFile.close();
	
	return 0;
}