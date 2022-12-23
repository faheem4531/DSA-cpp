#include <iostream>
using namespace std;
//                                                                Class
class Expr
{
private:
  int top, j;
  char stack[30], ch;
  string expresion;
  string postfix;

public:
  Expr()
  {
    top = -1;
    postfix = "";
    j = 0;
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
        while (!isEmpty() && presedence(stack[top]) >= presedence(ch))
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
      cout << "Stack overflow" << endl;
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
      cout << "Stack Empty" << endl;
      return false;
    }
    c = stack[top];
    top = top - 1;
    return c;
  }
  void print()
  {
    cout << "\n \t \t \t Your Postfix Expression is = " << postfix << endl;
    cout << endl;
  }
};

//                                                                Main Function

int main()
{
  Expr obj;
  obj.inputExpression();
  obj.handling();
  obj.print();
}
//********************                  Code End                    ***************************8