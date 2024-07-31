#include <iostream>
#include <stack>
#include <string>

using namespace std;
int ss(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	return 0;
}
stack <char> postfix(string infix)
{
	stack<char> pf;
	stack<char> st;
	for (int i = 0; i < infix.length(); i++)
	{
		if (isdigit(infix[i]))
		{
			pf.push(infix[i]);
		}
		else if (infix[i] == '(')
		{
			st.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				pf.push(st.top());
				st.pop();
			}
			if (!st.empty() && st.top() == '(')
			{
				st.pop();
			}
		}
		else
		{
			while (!st.empty() && ss(st.top()) >= ss(infix[i])) 
			{
				pf.push(st.top());
				st.pop();
			}

			st.push(infix[i]);
		}
	}
	while (!st.empty())
	{
		pf.push(st.top());
		st.pop();
	}

	return pf;
}
double res(string op)
{
	stack<double>st;
	for (int i = 0; i < op.length(); i++)
	{
		if (isdigit(op[i]))
		{
			st.push(op[i] - '0');
		}
		else
		{
			double t1 = st.top(); st.pop();
			double t2 = st.top(); st.pop();
			if (op[i] == '*') st.push(t2 * t1);
			else if (op[i] == '/') st.push(t2 / t1);
			else if (op[i] == '+') st.push(t2 + t1);
			else st.push(t2 - t1);
		}
	}
	return st.top();
}
int main()
{
	string infix;
	cin >> infix;
	stack<char> pf = postfix(infix);
	string op;
	while (!pf.empty())
	{
		op = pf.top() + op;
		pf.pop();
	}
	cout << op << endl;
	cout << res(op) << endl;
}
