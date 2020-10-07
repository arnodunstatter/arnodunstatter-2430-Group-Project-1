#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node
{
public:
	Node* previous = nullptr;
	Node* next = nullptr;

	string expression = "";
	int evaluated = -9999999;

	bool expressionIsGood = 0;

	Node(string);
	Node(Node*);
	void evaluator(string);
};
#endif
