#include <iostream>
using namespace std;
//                                                 Class
class Que
{
private:
  int *arr;
  int f, r;

public:
  Que(int n)
  {
    arr = new int[n];
    f = r = -1;
  }
  void display()
  {
    cout << "\n \t \t Data in your Queue " << endl;
    if (f == -1)
      cout << "Queue is Empty" << endl;
    else
    {
      for (int i = f; i <= r; i++)
      {
        cout << arr[i] << "\t";
      }
      cout << endl;
    }
  }
  void insert()
  {
  }
};

//                                                 Main
int main()
{
  int size, choice;
  char ch;
  cout << "Enter the size for your Queues" << endl;
  cin >> size;
  Que obj(size);
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
      // obj.insert(size);
      break;
    case 2:
      // obj.dell();
      break;
    case 3:
      // obj.display();
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}