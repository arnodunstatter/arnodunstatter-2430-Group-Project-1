#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "ArgumentManager.h"

using namespace std;


int main(int argc, char** argv) 
{
	ArgumentManager am(argc, argv);

	string inputFile = am.get("input");
	string outputFile = am.get("output");

	List Travis;
	List Scarlet;
	string passcode = "";

	ifstream read(inputFile.c_str());
	if (!read.is_open()) cout << "Input file did not open properly.\n";
	else
	{
		string line;
		while (line.empty())
		{
			getline(read, line);
		}
		//getline(read, line);
		while (passcode == "")
		{
			if (line == "Scarlet") //we are working on Scarlet's linked list
			{
				while (line != "Travis" && line[0] != 'P')
				{
					getline(read, line);

					if (line != "Travis" && line[0] != 'P')
						Scarlet.adder(line);
				}
			}
			if (line == "Travis") //we are working on Travis' linked list
			{
				while (line != "Scarlet" && line[0] != 'P')
				{
					getline(read, line);

					if (line != "Scarlet" && line[0] != 'P')
						Travis.adder(line);
				}
			}
			else //we must be on the last line
			{
				passcode = line.substr(9, line.length() - 9);

				/*
				string garb;
				getline(read, garb, ':');
				read >> passcode;
				*/
			}

		}

		//make a linked list out of passcode
		List Passcode;
		for (int i = 0; i < passcode.length(); ++i)
		{
			if (isdigit(passcode[i]))
			{
				string num = "";
				num += passcode[i];
				Passcode.adder(num);
			}
		}

		//print original
		{
			cout << "Original lists are as follows:\n";
			cout << "Travis' original:\n";
			for (Node* cur = Travis.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";

			cout << endl;

			cout << "Scarlet's original:\n";
			for (Node* cur = Scarlet.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";

			cout << endl;
		}

		//remove negatives and their corresponding positive values and reprint to check
		Travis.removeNegs(Scarlet);
		Scarlet.removeNegs(Travis);
		{
			cout << endl;
			cout << "After remvoing negatives the lists are as follows:\n";
			cout << "Travis':\n";
			for (Node* cur = Travis.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";

			cout << endl;

			cout << "Scarlet's:\n";
			for (Node* cur = Scarlet.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";
			cout << endl;
		}

		//merge the two linked lists
		List Combined;

		//get all nodes from the host list
		for (Node* cur = Travis.getHead(); cur != nullptr; cur = cur->next)
			Combined.adder(cur->expression);

		//get all nodes from the second list
		for (Node* cur = Scarlet.getHead(); cur != nullptr; cur = cur->next)
			Combined.adder(cur->expression);

		Combined.setInvalidCount(Travis.getInvalidCount() + Scarlet.getInvalidCount());

		{
			cout << endl;
			cout << "The combined list:\n";
			for (Node* cur = Combined.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";
			cout << endl;
		}

		//sort
		Combined.bubbleSort();
		{
			cout << endl;
			cout << "The sorted combined list:\n";
			for (Node* cur = Combined.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";
			cout << endl;
		}

		//remove the node a the position of invalid count
		if (Combined.getInvalidCount() > 0)
			Combined.removeByPos(Combined.getInvalidCount());
		{
			cout << endl;
			cout << "We've removed the node at position invalidCount:\n";
			for (Node* cur = Combined.getHead(); cur != nullptr; cur = cur->next)
				cout << cur->evaluated << " ";
			cout << endl;
		}

		ofstream write(outputFile.c_str());
		if (!write.is_open()) cout << "Output file did not open properly.\n";
		else
		{
			write << "Scarlet: ";
			Scarlet.printLinkedList(write, Scarlet.getHead());
			write << "Travis: ";
			Travis.printLinkedList(write, Travis.getHead());

			Combined.printTreasureCode(write, Combined.getHead());
			Passcode.printActualCode(write, Passcode.getHead());
			Combined.comparePasscode(write, passcode, Combined.getHead());

		}
	}

	/////////////////////////////Do we need to actually verify that the passcode in Combined is equal to the passcode from input?
}

