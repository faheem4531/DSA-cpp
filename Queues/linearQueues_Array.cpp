#include <iostream>
using namespace std;
//                                                    CLASS
class Ques
{
private:
  int *arr;
  int f, r;

public:
  Ques(int n)
  {
    arr = new int[n];
    f = -1;
    r = -1;
  }
  void insert(int size)
  {
    if (r >= size - 1)
    {
      cout << "Overflow" << endl;
      return;
    }
    else
    {
      r = r + 1;
      int item;
      cout << "Enter the value you want to enQueue \t";
      cin >> item;
      arr[r] = item;
      if (f == (-1))
        f = 0;
    }
    display();
  }
  void dell()
  {
    if (f == (-1))
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      int data = arr[f];
      if (f == r)
      {
        f = -1;
        r = -1;
      }
      else
        f++;
      cout << data << "  is deleted " << endl;
      display();
    }
  }
  void display()
  {
    if (f == (-1))
    {
      cout << "Queue is Empty" << endl;
    }
    else
    {
      cout << "\n \t \t Data in your Queue " << endl;
      for (int i = f; i <= r; i++)
        cout << arr[i] << "\t";
      cout << endl;
    }
  }
};
//                                                     MAIN
int main()
{
  int size, choice;
  char ch;
  cout << "Enter the size for your Queue" << endl;
  cin >> size;
  Ques obj(size);
  while (1)
  {
    system("cls");
    cout << "1. EnQueue" << endl
         << "2. DeQueue" << endl
         << "3. Display" << endl
         << "4. Exit" << endl;
    cout << "\n \t Enter your choice \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
      obj.insert(size);
      break;
    case 2:
      obj.dell();
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