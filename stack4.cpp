#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPriority(char ch)
{
    //获取优先级
    if (ch == '(')
        return 1;
    else if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 3;
    else
        return 4;
}

void calculate(stack<double> &num_stack, char operation)
{
    double right, left;
    right = num_stack.top();
    num_stack.pop();
    left = num_stack.top();
    num_stack.pop();
    
    switch (operation)
    {
    case '+':
        num_stack.push(left + right);
        break;
    case '-':
        num_stack.push(left - right);
        break;
    case '*':
        num_stack.push(left * right);
        break;
    case '/':
        num_stack.push(left / right);
        break;
    }
    /*
    if (operation == '+')
    {
        num_stack.push(left + right);
    }
    else if (operation == '-')
    {
        num_stack.push(left - right);
    }
    else if (operation == '*')
    {
        num_stack.push(left * right);
    }
    else if (operation == '/')
    {
        num_stack.push(left / right);
    }
    */
    cout << operation << endl;
}

double calculator(string str)
{
    //计算中缀表达式,默认输入是合法的
    stack<double> num_stack;
    stack<char> char_stack;
    int i;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num_stack.push(str[i] - '0');
        }
        else
        {
            if (str[i] == '(')
            {
                char_stack.push(str[i]);
                cout << char_stack.top() << endl;
            }
            else if (str[i] == ')')
            {
                while (char_stack.top() != '(')
                {
                    calculate(num_stack, char_stack.top());
                    char_stack.pop();
                }
                char_stack.pop();
                //cout << "3" << endl;
            }
            else
            {
                while (char_stack.empty() != true)
                {
                    if (getPriority(char_stack.top()) >= getPriority(str[i]))
                    {
                        calculate(num_stack, char_stack.top());
                        char_stack.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                //cout << "4" << endl;
                char_stack.push(str[i]);
                cout << char_stack.top() << endl;
            }
        }
    }

    while (!char_stack.empty())
    {
        calculate(num_stack, char_stack.top());
        char_stack.pop();
    }

    return num_stack.top();
}

int main()
{
    string str = "1+(2-3)*4+1/2+2*2+2+2/5";
    cout << "中缀表达式为:" << endl
         << str << endl;
    double num_res = calculator(str);
    cout << "计算结果:" << endl
         << num_res << endl;
    return 0;
}