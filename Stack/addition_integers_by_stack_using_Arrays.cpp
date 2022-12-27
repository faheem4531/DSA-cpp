#include <iostream>
using namespace std;
class Adding
{
private:
  int stack1[30], stack2[30], resultStack[30];
  int top1, top2, top3;
  int carry;
  int size;
  int operand1, operand2;

public:
  Adding()
  {
    carry = 0;
    top1 = top2 = top3 = -1;
    size = 30;
  }
  void input()
  {
    system("cls");
    cout << endl
         << "Enter the First  operand  ";
    cin >> operand1;
    setStack(stack1, top1, operand1);
    cout << endl
         << "Enter the Second operand  ";
    cin >> operand2;
    setStack(stack2, top2, operand2);
  }
  void setStack(int stack[], int &top, int operand)
  {
    int digit;
    while (operand > 0)
    {
      digit = operand % 10;
      top++;
      stack[top] = digit;
      operand = operand / 10;
    }
  }
  void display(int stackshow[], int top)
  {
    for (int i = 0; i <= top; i++)
      cout << stackshow[i] << "\t";
    cout << endl;
  }
  void adding()
  {
    int sum = 0;
    while (top1 != -1 || top2 != -1)
    {
      if (top1 != -1 && top2 != -1)
      {
        sum = stack1[top1] + stack2[top2] + carry;
        top1--;
        top2--;
      }
      else if (top1 == -1)
      {
        sum = stack2[top2] + carry;
        top2--;
      }
      else if (top2 == -1)
      {
        sum = stack1[top1] + carry;
        top1--;
      }
      top3++;
      resultStack[top3] = sum;
      sum = sum / 10;
      carry = sum;
      sum = 0;
    }
    cout << "\n+  \n";
    cout << "_________________________________" << endl;
    display(resultStack, top3);
  }
};

int main()
{
  Adding obj;
  obj.input();
  obj.adding();
}
