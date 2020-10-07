#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <fstream>

using namespace std; 

class List
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int invalidCount = 0;

public:
	List();
	~List();

	int getInvalidCount();
	void setInvalidCount(int);

	Node* getHead();
	Node* getTail();

	void setHead(Node*); //sets a new head
	void setTail(Node*); //sets a new tail

	void adder(string); //adds a node to the linked list
	int length(); //gets the present lenght of the list
	int length(Node*);
	
	void removeByPos(int); //for removing the node at the index of invalidCount

	void bubbleSort();
	void insert(Node*&, Node*&); //inserts the second parameter before the first in the linked list

	void removeNegs(List&);
	void getNegs(stack<int>&, stack<int>&); //this, with the help of gNh, creates two stacks for removeNegs to use to remove negative values
	void gNh(Node*, stack<int>&, stack<int>&); //helps getNegs
	void removeByVal(List& second, stack<int>&);
	void rBvH1(Node*, stack<int>&); //remove by value helper 1, removes from the native list
	void rBvH2(List&, stack<int>&); //remove by value helper 2, removes from the second list
	void rBvH2_1(Node*, stack<int>&, List&); //helps rBvH2 to perform the functionality recursively



	void printLinkedList(ofstream&, Node*); //requires output obj and the head node.
	void printTreasureCode(ofstream&, Node*); //requires ouput obj and head node of merged linked list(LL).
	void printActualCode(ofstream&, Node*);
	void comparePasscode(ofstream&, string, Node*, int passPosition = 0); //Compares the merged with the last line in the input file. Requires the last line and the head node of the merged LL.

};
#endif

