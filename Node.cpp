#include "Node.h"

Node::Node(string expression) //parameter constructor
	:expression(expression)
{
	evaluator(expression);
}

Node::Node(Node* copyMe) //copy constructor
{
    previous = copyMe->previous;
    next = copyMe->previous;
    expression = copyMe->expression;
    evaluated = copyMe->evaluated;
    expressionIsGood = copyMe->expressionIsGood;
}

void Node::evaluator(string expression)
{
    int toReturn = 0; //we'll use this to set the value in our program, but here we'll just print it
    string postFix = "";

    stack<char> eval;

    stack<bool> parenthesisAreOpen; // '(' has already been encountered if true
    stack<bool> bracketsAreOpen; // '[' has already been encountered if true
    stack<bool> bracesAreOpen; // '{' has already been encountered if true

    //this for loop creates our postFix expression
    for (int i = 0; i < expression.length(); ++i)
    {
        if (isdigit(expression[i]))
        {
            postFix += expression[i];
        }

        else if (expression[i] == '{')
        {
            eval.push(expression[i]);
            bracesAreOpen.push(1);
        }

        else if (expression[i] == '[')
        {
            eval.push(expression[i]);
            bracketsAreOpen.push(1);
        }

        else if (expression[i] == '(')
        {
            eval.push(expression[i]);
            parenthesisAreOpen.push(1);
        }

        else if (expression[i] == '+')
        {
            if (!eval.empty() && (eval.top() == '+' || eval.top() == '-'))
            {
                postFix += eval.top();
                eval.pop();
            }

            eval.push(expression[i]);
        }

        else if (expression[i] == '-')
        {

            if (!eval.empty() && (eval.top() == '+' || eval.top() == '-'))
            {
                postFix += eval.top();
                eval.pop();
            }


            eval.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            if (parenthesisAreOpen.empty())
            {
                cout << "Error: Encountered a close " << expression[i] << " before an open\n";
                return;
            }
            while (eval.top() != '(')
            {
                if (eval.top() == '[')
                {
                    cout << "Error: mismatched " << expression[i] << endl;
                    return;
                }
                else if (eval.top() == '{')
                {
                    cout << "Error: mismatched " << expression[i] << endl;
                    return;
                }
                else if (eval.top() == '+' || eval.top() == '-')
                {
                    postFix += eval.top();
                    eval.pop();
                }
            }
            eval.pop();
            parenthesisAreOpen.pop();
        }

        else if (expression[i] == '}')
        {
            if (bracesAreOpen.empty())
            {
                cout << "Error: Encountered a close " << expression[i] <<" before an open\n";
                return;
            }
            while (eval.top() != '{')
            {
                if (eval.top() == '[')
                {
                    cout << "Error: mismatched " << expression[i] << endl;
                    return;
                }
                else if (eval.top() == '(')
                {
                    cout << "Error: mismatched " << expression[i] << endl;
                    return;
                }
                else if (eval.top() == '+' || eval.top() == '-')
                {
                    postFix += eval.top();
                    eval.pop();
                }
            }
            eval.pop();
            bracesAreOpen.pop();
        }

        else if (expression[i] == ']')
        {
            if (bracketsAreOpen.empty())
            {
                cout << "Error: Encountered a close " << expression[i] << " before an open\n";
                return;
            }
            while (eval.top() != '[')
            {
                if (eval.top() == '(')
                {
                    cout << "Error: mismatched " << expression[i] << endl;
                    return;
                }
                else if (eval.top() == '{')
                {
                    cout << "Error: mismatched " << expression[i] << endl;
                    return;
                }
                else if (eval.top() == '+' || eval.top() == '-')
                {
                    postFix += eval.top();
                    eval.pop();
                }
            }
            eval.pop();
            bracketsAreOpen.pop();
        }

        if (i == expression.length() - 1 && !eval.empty())
        {
            postFix += eval.top();
            eval.pop();
        }
    }

    //checks that we closed all opened enclosing Glyphs
    if (!parenthesisAreOpen.empty() || !bracketsAreOpen.empty() || !bracesAreOpen.empty())
    {
        cout << "Didn't close a set of glyphs. Invalid input\n";
        return;
    }

    //if we get to this next line without returning then our input was valid
    expressionIsGood = 1;

    //now we need to evaluate the postfix expression
    stack<int> answer;
    for (int i = 0; i < postFix.length(); ++i)
    {
        if (isdigit(postFix[i]))
            answer.push(static_cast<int>(postFix[i]) - 48);

        else if (postFix[i] == '+')
        {
            int temp = answer.top();
            answer.pop();
            temp += answer.top();
            answer.pop();
            answer.push(temp);
        }

        else if (postFix[i] == '-')
        {
            int temp = -answer.top();
            answer.pop();
            temp += answer.top();
            answer.pop();
            answer.push(temp);
        }

        if (i == postFix.length() - 1)
        {
            toReturn = answer.top();
            answer.pop();
        }

    }
    evaluated = toReturn;
}