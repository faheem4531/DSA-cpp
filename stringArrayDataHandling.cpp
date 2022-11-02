#include <iostream>
using namespace std;

//*****************************************************************Functions Decleration
int handleSetArray();
//*****************************************************************Global Variables
int n;
//*****************************************************************Class
class DataOperator
{
private:
  long long phone[50];
  string name[50], address[50];

public:
  DataOperator(int n)
  {
    phone[n];
    name[n];
    address[n];
  }
  void setData(int x)
  {
    if (x == 1)
    {
      for (int i = 0; i < n; i++)
      {
        cout << "Enter name at [ " << i << " ] = ";
        cin >> name[i];
        cout << "\t" << phone[i] << "\t" << address[i] << endl;
      }
    }
    else if (x == 2)
    {
      for (int i = 0; i < n; i++)
      {
        cout << "Enter phone at [ " << i << " ] = " << name[i] << "\t";
        cin >> phone[i];
        cout << "\t" << address[i] << endl;
      }
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        cout << "Enter address at [ " << i << " ] = " << name[i] << "\t" << phone[i] << "\t";
        cin >> address[i];
      }
    }
  }
  void showData()
  {
    for (int i = 0; i < n; i++)
    {
      cout << name[i] << "\t" << phone[i] << "\t" << address[i] << "\t" << endl;
    }
  }
};

//*****************************************************************Main function
DataOperator obj(n);
int main()
{

  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Set Array index" << endl
         << "2. Set array" << endl
         << "3. Insert " << endl
         << "4. Search" << endl
         << "5. Delete" << endl
         << "6. Update" << endl
         << "7. Show" << endl
         << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Total index you want for an array" << endl;
      cin >> n;
      break;
    case 2:
      handleSetArray();
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      obj.showData();
      break;
    case 8:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

//*****************************************************************Function Definations
int handleSetArray()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Set Name" << endl
         << "2. Set Phone Number" << endl
         << "3. Set Address" << endl
         << "4. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      obj.setData(1);
      break;
    case 2:
      obj.setData(2);
      break;
    case 3:
      obj.setData(3);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}
