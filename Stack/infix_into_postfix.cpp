#include <iostream>
#include "math.h"
using namespace std;
//                                                                Global Expression
string postfix_Expression = "";
//                                                                Class
class infix_To_Postfix
{
private:
  int top;
  char stack[30], ch;
  string expresion;
  string postfix;

public:
  infix_To_Postfix()
  {
    top = -1;
    postfix = "";
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
  bool isOpearand(char ch) // This function is not used in the program
  {
    if (ch >= 'A' && ch <= 'Z')
      return true;
    if (ch >= 'a' && ch <= 'z')
      return true;
    if (ch >= 0 && ch <= 9)
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
  void inputExpression()
  {
    cout << "Enter Expression without any space" << endl;
    cin >> expresion;
  }
  void handling()
  {
    for (int i = 0; i < expresion.length(); i++)
    {
      ch = expresion[i];
      if (ch == '(')
        push(ch);
      else if (ch == ')')
      {
        char chh;
        while ((chh = pop()) != '(')
          postfix += chh;
      }
      else if (isOperator(ch))
      {
        while (!isEmpty() && presedence(stack[top]) > presedence(ch)) // DOUBT--CAN BE EQUAL OR NOT BE
          postfix += pop();
        push(ch);
      }
      else
        postfix += ch;
    }
    while (!isEmpty())
      postfix += pop();
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
  void print()
  {
    cout << "\n \t \t \t Your Postfix Expression is = " << postfix << endl;
    postfix_Expression = postfix;
  }
};

//                                                                Class 2nd
class expression_Solution
{
private:
  int top;
  int stack[30];
  string postfix;

public:
  expression_Solution()
  {
    top = -1;
    postfix = postfix_Expression;
  }
  int post_evaluation()
  {
    for (int i = 0; i < postfix.length(); i++)
    {
      if (postfix[i] >= '0' && postfix[i] <= '9')
      {
        push(postfix[i] - '0');
      }
      else
      {
        int a, b;
        a = pop();
        b = pop();
        switch (postfix[i])
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
    char c;
    if (top == -1)
    {
      return false;
    }
    c = stack[top];
    top = top - 1;
    return c;
  }
};

//                                                                Main Function

int main()
{
  infix_To_Postfix obj;
  obj.inputExpression();
  obj.handling();
  obj.print();
  expression_Solution obj2;
  cout << "\n \t \t \t Expression Solution is = " << obj2.post_evaluation() << endl;
}
//********************                  Code End                    ***************************8