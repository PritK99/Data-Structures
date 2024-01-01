#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int ans = -1;
    string input;
    cin >> input;

    stack <char> st;
    stack <int> index;

    for (int i = 0 ; i < input.size(); i++)
    {
        
        if(input[i] != '[' && input[i] != '(' && input[i] != '{' && input[i] != ']' && input[i] != ')' && input[i] != '}')
        {
            continue;
        }
        else if (st.empty())
        {
            st.push(input[i]);
            index.push(i);
        }
        else if (input[i] == '[' || input[i] == '(' || input[i] == '{')
        {
            st.push(input[i]);
            index.push(i);
        }
        else if (input[i] == ']' && st.top() == '[')
        {
            st.pop();
            index.pop();
        }
        else if (input[i] == ')' && st.top() == '(')
        {
            st.pop();
            index.pop();
        }
        else if (input[i] == '}' && st.top() == '{')
        {
            st.pop();
            index.pop();
        }
        else
        {
            ans = i;
            st.push(input[i]);
            index.push(i);
        }
    }

    if (!st.empty())
    {
        int x = index.top();
        while(!st.empty())
        {
            st.pop();
            x = index.top();
            index.pop();   
        }
        cout << x + 1 ;
    }
    else
    {
        cout << "Success" ;
    }

    return 0;
}