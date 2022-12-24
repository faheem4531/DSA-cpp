#include <iostream>
#include <cstring>
using namespace std;
//                                                     Class
class Expression_Conversion
{
private:
  string stack[30];
  int top;
  string infix_input;

public:
  Expression_Conversion()
  {
    top = -1;
  }
  void input()
  {
    cout << "Enter the value without any space " << endl;
    cin >> infix_input;
  }
  string reverseString()
  {
    string reverse = "";
    for (int i = infix_input.length(); i >= 0; i--)
      reverse += infix_input[i];
    return reverse;
  }
  void reverseBrackets(string expression)
  {
    for (int i = 0; i < expression.length(); i++)
    {
      if (expression[i] == ')')
        expression[i] = '(';
      else if (expression[i] == '(')
        expression[i] = ')';
    }
    cout << expression << endl;
  }
};

//                                                          Main
int main()
{
  Expression_Conversion obj;
  obj.input();
  obj.reverseBrackets(obj.reverseString());
}