
#include <iostream>
using namespace std;

//*************Funtion prototype
void deletionHandler(int &);

//**************Class
class Dynamic
{
private:
  int *number;

public:
  Dynamic(int size)
  {
    number = new int[size];
  }
  void setData(int size)
  {
    for (int i = 0; i < size; i++)
    {
      cout << "[ " << i << " ] = ";
      cin >> number[i];
    }
  }
  void show(int size)
  {
    for (int i = 0; i < size; i++)
    {
      cout << "Value at " << i << " =  " << number[i] << endl;
    }
  }
  void insertion(int &size)
  {
    int n;
    int nam;
    cout << "Enter the position at  ";
    cin >> n;
    if (n <= size)
    {
      cout << "Enter the number you want to insert =  ";
      cin >> nam;

      for (int i = size - 1; i >= n; i--)
      {
        number[i + 1] = number[i];
      }
      number[n] = nam;
      size++;
    }
    else
      cout << "index Not found \n";
  }
  int searching(int size)
  {
    int index, num;
    cout << "Enter the number ";
    cin >> num;
    for (int i = 0; i < size; i++)
    {
      if (number[i] == num)
      {
        cout << "value fount at " << i;
        return i;
      }
    }
    cout << "number not found";
    return 0;
  }
  void deletion(int &size)
  {
    int index;
    index = searching(size);
    for (int i = index; i < size; i++)
    {
      number[i] = number[i + 1];
    }
    size--;
  }
};

int main()
{

  int size, choice;
  char ch;
  cout << "Enter the size for your array   ";
  cin >> size;
  Dynamic obj(size);
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Set Array index" << endl
         << "2. Set array" << endl
         << "3. Insert " << endl
         << "4. Search" << endl
         << "5. Delete" << endl
         << "6. Show" << endl
         << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      // cout << "Enter the size for your array   ";
      // cin >> size;
      break;
    case 2:
      obj.setData(size);
      break;
    case 3:
      obj.insertion(size);
      break;
    case 4:
      obj.searching(size);
      break;
    case 5:
      deletionHandler(size);
      break;
    case 6:
      obj.show(size);
      break;
    case 7:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

//*************************Function Defination

void deletionHandler(int &size)
{
  int value;
  cout << "Enter the value you want to delete   ";
  cin >> value;
  // obj.deletion(size,value);
}