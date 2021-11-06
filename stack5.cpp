#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPriority(char ch)
{
    //获取优先级
    if (ch == '(')
    {
        return 1;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

string getPostfixExpression(string str)
{
    //将中缀表达式转化为后缀表达式
    //默认输入是合法的
    int i;
    string postfix;
    stack<char> stack;

    cout << (str.size()) << endl;
    for (i = 0; i < str.size(); i++)
    {

        if (str[i] >= '0' && str[i] <= '9')
        {
            postfix.push_back(str[i]);
            cout << "1" << endl;
        }
        else if (str[i] == '(')
        {
            stack.push(str[i]);
            cout << "2" << endl;
        }
        else if (str[i] == ')')
        {
            while (stack.top() != '(')
            {
                postfix.append(1, stack.top());
                stack.pop();
            }
            stack.pop();
            cout << "3" << endl;
        }
        else
        {
            while (stack.empty() != true)
            {
                if (getPriority(stack.top()) >= getPriority(str[i]))
                {
                    postfix.append(1, stack.top());
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            cout << "4" << endl;
            stack.push(str[i]);
        }
    }

    while (stack.empty() != true)
    {
        postfix.append(1, stack.top());
        stack.pop();
        cout << "5" << endl;
    }

    return postfix;
}

int calculator(string str)
{
    //计算后缀表达式的值，默认中缀表达式所有数字都是一位的，在0-9之间
    stack<int> num;
    int i;
    int left, right;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num.push(str[i]-'0');//！！记得减'0'
        }
        else if (str[i] == '+')
        {
            right = num.top();
            num.pop();
            left = num.top();
            num.pop();
            num.push(left + right);
        }
        else if (str[i] == '-')
        {
            right = num.top();
            num.pop();
            left = num.top();
            num.pop();
            num.push(left - right);
        }
        else if (str[i] == '*')
        {
            right = num.top();
            num.pop();
            left = num.top();
            num.pop();
            num.push(left * right);
        }
        else if (str[i] == '/')
        {
            right = num.top();
            num.pop();
            left = num.top();
            num.pop();
            num.push(left / right);
        }
        cout << num.top() << endl;
    }

    return num.top();
}

int main()
{
    string str = "1+(2-3)*4+4/2";
    cout << "中缀表达式为:" << endl
         << str << endl;
    string res = getPostfixExpression(str);
    cout << "后缀表达式为:" << endl
         << res << endl;
    int num_res = calculator(res);
    cout << "计算结果:" << endl
         << num_res << endl;
    system("pause");
    return 0;
}