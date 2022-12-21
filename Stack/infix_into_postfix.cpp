#include <iostream>
using namespace std;
//                                                                Class
class Expr
{
private:
  int top;
  char stack[10], ch;
  string expresion;

public:
  Expr()
  {
    top = -1;
  }
  void inputExpression()
  {
    cout << "Enter your Expression without any space" << endl;
    cin >> expresion;
  }
};

//                                                                Main Function

int main()
{
  Expr obj;
  obj.inputExpression();
}