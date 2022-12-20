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
  void displayCQ(int size)
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
  void insertCQ(int size)
  {
    int item;
    // if ((f == 0 && r == size - 1) || (f == r + 1))                               can be other posibility
    if (((r + 1) % size) == f)
    {
      cout << "Queue is Full" << endl;
      return;
    }
    cout << "Enter the value you want to   insert" << endl;
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
    displayCQ(size);
  }
  void dellCQ(int size)
  {
    if (f == -1)
    {
      cout << "Queue is Empty" << endl;
      return;
    }
    cout << "Element deleted from queue is : " << arr[f] << endl;
    if (f == r)
      f = r = -1;
    else
    {
      if (f == size - 1)
        f = 0;
      else
        f++;
    }
    displayCQ(size);
  }
  void searchingCQ(int size)
  {
    int value;
    if (f == -1)
      cout << "Queue is Empty" << endl;
    else
    {
      cout << "Enter the value you want to Search " << endl;
      cin >> value;
      if (f <= r)
      {
        for (int i = f; i <= r; i++)
        {
          if (arr[i] == value)
          {
            cout << "Your Seacrhed value found at " << i << endl;
            return;
          }
        }
        cout << "Value not Found" << endl;
      }
      else if (f > r)
      {
        for (int i = f; i < size; i++)
        {
          if (arr[i] == value)
          {
            cout << "Your Searched value found at " << i << endl;
            return;
          }
        }
        for (int i = 0; i <= r; i++)
        {
          if (arr[i] == value)
          {
            cout << "Your Seacrhed value found at " << i << endl;
            return;
          }
        }
        cout << "Value not Found" << endl;
      }
    }
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
         << "4. Searching" << endl
         << "5. Exit" << endl;
    cout << "\n \t Enter your choice \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
      obj.insertCQ(size);
      break;
    case 2:
      obj.dellCQ(size);
      break;
    case 3:
      obj.displayCQ(size);
      break;
    case 4:
      obj.searchingCQ(size);
      break;
    case 5:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}