#include <iostream>
using namespace std;
//                                                       Class
class Stack
{
private:
  int *arr;
  int top;
  int size;

public:
  Stack(int n)
  {
    size = n;
    arr = new int[size];
    top = -1;
  }
  bool isEmpty()
  {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull()
  {
    if (top == size - 1)
      return true;
    else
      return false;
  }
  void push()
  {
    if (isFull() == 1) //           top == size - 1
      cout << "Stack is Full " << endl;
    else
    {
      int value;
      cout << "Enter the value you want to Push \t";
      cin >> value;
      top = top + 1;
      arr[top] = value;
      display();
    }
  }
  void pop()
  {
    if (isEmpty() == 1)
      cout << "Stack is Empty" << endl;
    else
    {
      int temp;
      temp = arr[top];
      top = top - 1;
      cout << temp << "  pop out of stack" << endl;
      display();
    }
  }
  void display()
  {
    if (isEmpty() == 1)
    {
      cout << "stack is Empty" << endl;
      return;
    }
    cout << "\n \t \t Data in your Stack is " << endl;
    for (int i = 0; i <= top; i++)
    {
      cout << arr[i] << "\t";
    }
    cout << endl;
  }
};
//                                                        Main
int main()
{
  int size, choice;
  char ch;
  cout << "Enter the size for your Stack" << endl;
  cin >> size;
  Stack obj(size);
  while (1)
  {
    system("cls");
    cout << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Display" << endl
         << "4. Exit" << endl;
    cout << "\n \t Enter your choice \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
      obj.push();
      break;
    case 2:
      obj.pop();
      break;
    case 3:
      obj.display();
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}
//***************                             Code End                        *************************