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
  void insert_rear(int size)
  {
    int item;
    // if ((f == 0 && r == size - 1) || (f == r + 1))                               can be other posibility
    if (((r + 1) % size) == f)
    {
      cout << "Queue is Full" << endl;
      return;
    }
    cout << "Enter the value you want to insert at the End" << endl;
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
  void insert_front(int size)
  {
    int item;
    int rare;
    if (((r + 1) % size) == f)
    {
      cout << "Queue is Full" << endl;
      return;
    }
    cout << "Enter the value you want to insert at Head" << endl;
    cin >> item;
    if (f == -1)
      f = r = 0;
    else
    {
      if (f == 0)
        f = size - 1;
      else
        f--;
    }
    arr[f] = item;
    display(size);
  }
  void delete_front(int size)
  {
    if (f == -1)
    {
      cout << "Queue is Empty" << endl;
      return;
    }
    cout << "Element deleted from the Front is : " << arr[f] << endl;
    if (f == r)
      f = r = -1;
    else
    {
      if (f == size - 1)
        f = 0;
      else
        f++;
    }
    display(size);
  }
  void delete_rear(int size)
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
    cout << "1. EnQueue from Rear  (End)" << endl
         << "2. EnQueue from Front (Head)" << endl
         << "3. DeQueue from Rear  (End)" << endl
         << "4. DeQueue from Front (Head)" << endl
         << "5. Display" << endl
         << "6. Exit" << endl;
    cout << "\n \t Enter your choice \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
      obj.insert_rear(size);
      break;
    case 2:
      obj.insert_front(size);
      break;
    case 3:
      obj.delete_rear(size);
      break;
    case 4:
      obj.delete_front(size);
      break;
    case 5:
      obj.display(size);
      break;
    case 6:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}
//******************                                      Code End                                       *********************