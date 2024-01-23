#include<iostream>
#include<string>
#include<stack>
#include<fstream>
using namespace std;

bool isleft(char x)
{
	if (x == '(') { return true; }
	else { return false; }
}
bool isright(char x)
{
	if (x == ')') { return true; }
	else { return false; }
}

bool isop(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/') { return true; }
	else { return false; }
}
// if top is <  or > current char precedence
int precedence(char x)
{
	if (x == '(') { return 0; }
	if (x == '+' || x == '-') { return 1; }
	if (x == '*' || x == '/') { return 2; }
	if (x == ')') { return 3; }
    return 0;
}

double calculate(char x, char left, char right)
{
	/*left -= '0';
	right -= '0';*/
	static_cast<double>(left);
	static_cast<double> (right);
	enum operaotrs {Plus = '+' , Minus = '-', Multiply = '*', Divide = '/'};

	switch (x)
	{
	case Plus:
		return (left + right);
		break;
	case Minus:
		return (left - right);
		break;
	case Multiply:
		return (left * right);
		break;
	case Divide:
		return left / right;
		break;
	}

    return 0;
}

string InToPostfix(const string& infix)
{
	stack<char> op;
	string post;
	for (int i = 0; i < infix.length(); i++)
	{
		do
		{
			if (isleft(infix.at(i)))
			{
				//always put a left parenthesis on the atack
				op.push(infix.at(i));
			}


			else if (isspace(infix.at(i)))
			{
				continue;
			}


			else if (isdigit(infix.at(i)))
			{
				// push onto string.
				post.push_back(infix.at(i));
			}


			/*
			while (  stack is not empty AND
						stack's top is not left parenthesis AND
						stack's top is an operation with  equal or higher precedence
								 than the next input symbol)
			*/


			else if (isop(infix.at(i)))
			{
				while (!op.empty() && op.top() != '(' && (precedence(op.top()) >= precedence(infix.at(i))))
				{
					post.push_back(op.top());
					op.pop();
				}
				//if (!op.empty() && op.top() == '(') { op.pop(); }
				op.push(infix.at(i));
			}


			else
			{
				//read and discard the next input symbol (should be a right parenthesis)
				op.push(infix.at(i)); // read in right parententhesis
				op.pop(); // pop right parenthesis;
				if (!op.empty() && op.top() == '(') { op.pop(); }
				post.push_back(op.top());
				op.pop();
				/*
				while ( stack's top is not a left parenthesis )
                   print next symbol on stack and pop stack
				*/
				while (!op.empty() && op.top() != '(')
				{
					if (!op.empty() && op.top() == '(') { op.pop(); }
					post.push_back(op.top());
					op.pop();
				}
			}
		} while (i == infix.length());

		
	}
	while (!op.empty() )
		{
			if (!op.empty() && op.top() == '(') { op.pop(); }
			if (!op.empty() && op.top() != '(') { post.push_back(op.top()); }
			if (!op.empty()) { op.pop(); }
		}
	return post;
}

double EvaluatePostfix(const string& postFixEquation)
{
	stack<double> post;
	double left;
	double right;
	for (int i = 0; i < postFixEquation.length(); i++)
	{

		do
		{
			if (isdigit(postFixEquation.at(i)))
			{
				post.push(postFixEquation.at(i) -'0');
			}
			else
			{
				right = post.top();
				post.pop();
				left = post.top();
				post.pop();
				post.push(calculate(postFixEquation.at(i), left, right));
			}
		} while (i == postFixEquation.length());
	}
	if (!post.empty() && postFixEquation.size() == 1)
		return post.top();
	if (!post.empty())
		return post.top();

    return 0;
}

int main()
{
	string instr;
	ifstream dataFile;
	
	dataFile.open("stack/data.txt");
	if (!dataFile.good())
	{
		cout << "Could not open file..." << endl;
	}
	while (!dataFile.eof())
	{
		getline(dataFile, instr);
		//cout << InToPostfix(instr) << endl;
		cout << "infix: " << instr << endl;
		string s = InToPostfix(instr);
		cout << "PostFix: ";
		for(int i = 0; i < s.length(); i++)
		{
		     cout << s.at(i) << ' ';
		}
		cout << endl;
		cout << "answer: " << EvaluatePostfix(InToPostfix(instr)) << endl << endl;
		dataFile.peek();
	}
	
}