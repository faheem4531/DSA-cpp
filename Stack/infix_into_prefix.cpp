#include <iostream>
#include "math.h"
using namespace std;
//                                                                Global Expression
string prefix_solution = "";
//                                                     Class
class Expression_Conversion
{
private:
  char stack[30];
  int top;
  string infix_input;
  string prefix;
  char ch;

public:
  Expression_Conversion()
  {
    top = -1;
    prefix = "";
  }
  bool isEmpty()
  {
    if (top == -1)
      return true;
    return false;
  }
  bool isOperator(char ch)
  {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
      return true;
    return false;
  }
  int presedence(char opr)
  {
    if (opr == '+' || opr == '-')
      return 1;
    if (opr == '*' || opr == '/')
      return 2;
    if (opr == '^')
      return 3;
    return 0;
  }
  void input()
  {
    cout << "Enter the value without any space " << endl;
    cin >> infix_input;
  }
  string reverseString(string expression)
  {
    string reverse = "";
    for (int i = expression.length(); i >= 0; i--)
      reverse += expression[i];
    return reverse;
  }
  string reverseBrackets(string expression)
  {
    for (int i = 0; i < expression.length(); i++)
    {
      if (expression[i] == ')')
        expression[i] = '(';
      else if (expression[i] == '(')
        expression[i] = ')';
    }
    return expression;
  }
  string Scaning()
  {
    infix_input = reverseBrackets(reverseString(infix_input));
    // cout << "Infix reversed Expression  " << infix_input << endl;
    for (int i = 0; i < infix_input.length(); i++)
    {
      ch = infix_input[i];
      if (ch == '(')
        push(ch);
      else if (ch == ')')
      {
        char chh;
        while ((chh = pop()) != '(')
          prefix += chh;
      }
      else if (isOperator(ch))
      {
        while (!isEmpty() && presedence(stack[top]) > presedence(ch))
          prefix += pop();
        push(ch);
      }
      else
        prefix += ch;
    }
    while (!isEmpty())
      prefix += pop();
    // cout << "postfix of inputed (infix) expression " << prefix << endl;
    return reverseString(prefix); //         Returned the prefix expression  (as prefix is the reverse of postfix)
  }
  void push(char ch)
  {
    if (top == 30 - 1) // 30 is the size of your stack
    {
      return;
    }
    top = top + 1;
    stack[top] = ch;
  }
  char pop()
  {
    char c;
    if (top == -1)
    {
      return false;
    }
    c = stack[top];
    top = top - 1;
    return c;
  }
  void display()
  {
    string prefix_expre = Scaning();
    cout << "\n \t \t \t Your Prefix Expression is = " << prefix_expre << endl;
    prefix_solution = prefix_expre;
  }
};

//                                                                Class 2nd
class expression_Solution
{
private:
  int top;
  int stack[30];
  string prefix;

public:
  expression_Solution()
  {
    top = -1;
    prefix = prefix_solution;
  }
  int post_evaluation()
  {
    for (int i = prefix.length(); i > 0; i--)
    {
      if (prefix[i] >= '0' && prefix[i] <= '9')
      {
        push(prefix[i] - '0');
      }
      else
      {
        int a, b;
        a = pop();
        b = pop();
        switch (prefix[i])
        {
        case '+':
          push(b + a);
          break;
        case '-':
          push(b - a);
          break;
        case '*':
          push(b * a);
          break;
        case '/':
          push(b / a);
          break;
        case '^':
          push(pow(b, a));
          break;
        }
      }
    }
    return pop();
  }
  void push(int ch)
  {
    if (top == 30 - 1) // 30 is the size of your stack
    {
      return;
    }
    top = top + 1;
    stack[top] = ch;
  }
  char pop()
  {
    int c;
    if (top == -1)
    {
      return false;
    }
    c = stack[top];
    top = top - 1;
    return c;
  }
};
//                                                          Main
int main()
{
  Expression_Conversion obj;
  obj.input();
  obj.display();
  expression_Solution obj2;
  cout << "\n \t \t \t Expression Solution is = " << obj2.post_evaluation() << endl;
}