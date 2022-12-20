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
    f = -1;
    r = -1;
  }
  void display(int size)
  {
    if (f == -1)
      cout << "Queue is Empty" << endl;
    else
    {
      cout << "\n \t \t Data in your Queue " << endl;
      if (f <= r)
      {
        for (int i = f; i <= r; i++)
          cout << arr[i] << "\t";
        cout << endl;
      }
      else // f > r
      {
        for (int i = f; i < size; i++)
          cout << arr[i] << "\t";
        for (int i = 0; i <= r; i++)
          cout << arr[i] << "\t";
        cout << endl;
      }
    }
  }
  void insert(int size)
  {
    int item;
    // if ((f == 0 && r == size - 1) || (f == r + 1))                               can be
    if (((r + 1) % size) == f)
    {
      cout << "Queue is Full" << endl;
      return;
    }
    cout << "Enter the value you want to insert" << endl;
    cin >> item;
    if (f == -1)
      f = r = 0;
    else
    {
      if (r == size - 1)
        r = 0;
      else
        r++;
    }
    arr[r] = item;
    display(size);
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
      obj.insert(size);
      break;
    case 2:
      // obj.dell();
      break;
    case 3:
      obj.display(size);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}