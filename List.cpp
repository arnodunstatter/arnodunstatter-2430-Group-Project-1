#include "List.h"

List::List() {};

List::~List()
{
	if (length() > 0) //if our list has elements in it by the end then we deallocate that memory
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* deleteMe = current;
			current = current->next;
			delete deleteMe;
		}
	}
}

int List::getInvalidCount() { return invalidCount; }

void List::setInvalidCount(int x) { invalidCount = x; }

Node* List::getHead() { return head; }

Node* List::getTail() { return tail; }

void List::setHead(Node* newHead) { head = newHead; }

void List::setTail(Node* newTail) { tail = newTail; }

void List::adder(string expression) //adds a node to the linked list
{
	if (expression == "") return; //checks that we're not trying to add a blank line
	

	//else
	Node* toAdd = new Node(expression);

	if (toAdd->expressionIsGood == 1) //checks that the node should be added (that it is valid)
	{
		if (head == nullptr) //we have an empty list
		{
			head = toAdd;
			tail = toAdd;
		}
		else //we are adding to the end;
		{
			tail->next = toAdd;
			toAdd->previous = tail;
			tail = toAdd;
		}
	}
	else
	{
		++invalidCount;
		return;
	}
}

/*
int List::length()
{
	int count = 0;
	
	for (Node* current = head; current != nullptr; current = current->next)
		++count;

	return count;
}
*/

int List::length()
{
	Node* cur = head;
	return length(cur);
}

int List::length(Node* cur) //helper recursive function
{
	if (cur == nullptr) return 0;
	else if (cur->next == nullptr) return 1;
	else return 1 + length(cur->next);
}

void List::removeByPos(int index) 
{
	Node* deleteMe;
	int listLength = length();

	if (index == 0) //we are removing the head
	{
		deleteMe = head;

		head->next->previous = nullptr;
		head = head->next;

		delete deleteMe;
	}

	else if (index == listLength - 1) //we are removing the tail
	{
		deleteMe = tail;

		tail->previous->next = nullptr;
		tail = tail->previous;

		delete deleteMe;
	}

	else //we are removing within the list
	{
		Node* current = head;
		for (int i = 1; i <= index; ++i) //moves current to the right index
			current = current->next;

		deleteMe = current; 

		current->previous->next = current->next;
		current->next->previous = current->previous;

		delete deleteMe;
	}
}

void List::bubbleSort()
{
	for (Node* left = head; left != nullptr; left = left->next)
	{
		for (Node* right = left->next; right != nullptr; right = right->next)
		{
			if (left->evaluated > right->evaluated)
				insert(left, right);
		}
	}
}

void List::insert(Node*& left, Node*& right)
{
	Node* oLp = left->previous;
	Node* oRp = right->previous;
	Node* oLn = left->next;
	Node* oRn = right->next; 

	if (left->previous == nullptr) //left is head, dont need to change left->previous->next;
	{
		right->previous = nullptr;
		head = right;
	}
	else //left isn't head, we do need to change left->previous->next
	{
		right->previous = oLp;
		oLp->next = right;
	}
	if (right->next == nullptr) //right is the tail, don't need to change right->next->previous
	{
		right->previous->next = nullptr;
		tail = oRp;
	}
	else //right isn't the tail, we need to change right->next->previous
	{
		right->next->previous = oRp;
		oRp->next = oRn;
	}

	right->next = left;
	left->previous = right;

	Node* hold = left;
	left = right;
	right = hold;

}

void List::removeNegs(List& second)
{
	//make a stack of negative numbers in first using recursion
	stack<int> negsToRemove, posToRemove;
	getNegs(negsToRemove, posToRemove);
	//recursively try to remove that value's positive
	//remove negative values from host list
	Node* cur = head;
	rBvH1(cur, negsToRemove);
	
	//remove positives from host list
	cur = head;
	rBvH1(cur, posToRemove);

	//if posToRemove is not empty remove values in posToRemove from second
	if (!posToRemove.empty())
		rBvH2(second, posToRemove);
}

void List::getNegs(stack<int>& negsToRemove, stack<int>& posToRemove)
{
	Node* cur = head;
	gNh(head, negsToRemove, posToRemove);
}

void List::gNh(Node* cur, stack<int>& negsToRemove, stack<int>& posToRemove)
{
	if (cur == nullptr) return;
	else
	{
		if (cur->evaluated < 0)
		{
			negsToRemove.push(cur->evaluated);
			posToRemove.push(-1 * (cur->evaluated));
		}
		gNh(cur->next, negsToRemove, posToRemove);
	}
}

void List::rBvH1(Node* cur, stack<int>& removables)
{
	if (cur == nullptr || removables.empty()) return;

	Node* deleteMe;
	int val = removables.top();
	if (cur->evaluated == val)
	{
		if (cur->previous == nullptr && cur->next == nullptr) //we are removing the only node
		{
			deleteMe = head;
			head = nullptr;
			tail = nullptr;
			delete deleteMe;
		}
		else if (cur->previous == nullptr) //we are removing the head
		{
			deleteMe = head;

			head->next->previous = nullptr;
			head = head->next;

			delete deleteMe;
		}
		else if (cur->next == nullptr) //we are removing the tail
		{
			deleteMe = tail;

			tail->previous->next = nullptr;
			tail = tail->previous;

			delete deleteMe;
		}
		else //we are removing within the list
		{
			deleteMe = cur;

			cur->previous->next = cur->next;
			cur->next->previous = cur->previous;

			delete deleteMe;
		}
		removables.pop(); //removes the item in removables if cur->evaluted is the same as removeables.top();
		cur = head;
		rBvH1(cur, removables);
	}
	rBvH1(cur->next, removables);
}

void List::rBvH2(List& second, stack<int>& removables)
{
	Node* head = second.getHead();
	Node* cur = head;
	rBvH2_1(cur, removables, second);	
}

void List::rBvH2_1(Node* cur, stack<int>& removables, List& second)
{
	if (cur == nullptr || removables.empty()) return;
	
	//else
	Node* deleteMe;
	Node* sHead = second.getHead();
	Node* sTail = second.getTail();

	int val = removables.top();
	if (cur->evaluated == val)
	{
		if (cur->previous == nullptr && cur->next == nullptr) //we are removing the only node
		{
			deleteMe = sHead;
			second.setHead(nullptr);
			second.setTail(nullptr);
			delete deleteMe;
		}
		else if (cur->previous == nullptr) //we are removing the head
		{
			deleteMe = sHead;

			sHead->next->previous = nullptr;
			second.setHead(sHead->next);
			cur = second.getHead();

			delete deleteMe;
		}
		else if (cur->next == nullptr) //we are removing the tail
		{
			deleteMe = sTail;

			sTail->previous->next = nullptr;
			second.setTail(sTail->previous);
			cur = second.getTail();

			delete deleteMe;
		}
		else //we are removing within the list
		{
			deleteMe = cur;

			cur->previous->next = cur->next;
			cur->next->previous = cur->previous;
			cur = cur->previous;
			delete deleteMe;
		}
		removables.pop(); //removes the item in removables if cur->evaluted is the same as removeables.top();
	}
	rBvH2_1(cur->next, removables, second);
}

void List::printLinkedList(ofstream& obj, Node* curr)
{
	if (curr == nullptr && curr == head) //we have an empty linked list
	{
		obj << "[]\n";
		return;
	}
	else if (curr == head)
	{
		obj << "[" << curr->evaluated;
		printLinkedList(obj, curr->next);
	}
	else if (curr == NULL)
	{
		obj << "]\n";
		return;
	}	
	else
	{
		obj << ", " << curr->evaluated;
		printLinkedList(obj, curr->next);
	}	
}

void List::printTreasureCode(ofstream& obj, Node* curr)
{
	if (curr == NULL)
	{
		obj << "\n";
		return;
	}

	if (curr == head)
	{
		obj << "Decoded passcode: ";
	}

	obj << "| " << curr->evaluated << " ";

	if (curr->next == NULL)
	{
		obj << "|";
	}

	printTreasureCode(obj, curr->next);
}

void List::printActualCode(ofstream& obj, Node* curr)
{
	if (curr == NULL)
	{
		obj << "\n";
		return;
	}

	if (curr == head)
	{
		obj << "Actual passcode: ";
	}

	obj << "| " << curr->evaluated << " ";

	if (curr->next == NULL)
	{
		obj << "|";
	}

	printTreasureCode(obj, curr->next);
}

//Make sure you have a funtion that outputs the Actual Passcode similar to the our Decoded one.
//Didn't include it here since I felt like it could be done in the main since it's just a string.

void List::comparePasscode(ofstream& obj, string actualPasscode, Node* curr, int passPosition)
{
	bool invalid = 0;

	if (curr == NULL && invalid != 1)
	{
		obj << "Treasure unlocked!" << "\n";
		return;
	}

	if (actualPasscode[passPosition] - 48 != curr->evaluated)
	{
		cout << "Passcode invalid!" << "\n";
		invalid = 1;
		return;
	}

	comparePasscode(obj, actualPasscode, curr->next, ++passPosition);
}
