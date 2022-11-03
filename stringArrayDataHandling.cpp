#include <iostream>
using namespace std;

//*****************************************************************Functions Decleration
int handleSetArray();
int handleInsertion();
void handleInsertionSub(int);
int handleSearch();
void handleSearchElement(int);
int handleDelation();
//*****************************************************************Global Variables
int n, sizeN, sizeP, sizeA;
//*****************************************************************Class
class DataOperator
{
private:
  long long phone[50];
  string name[50], address[50];

public:
  DataOperator(int sizeN, int sizeP, int sizeA)
  {
    phone[sizeP];
    name[sizeN];
    address[sizeA];
  }
  void setData(int x)
  {
    if (x == 1)
    {
      for (int i = 0; i < sizeN; i++)
      {
        cout << "Enter name at [ " << i << " ] = \t ";
        cin >> name[i];
        cout << "\t" << phone[i] << "\t" << address[i] << endl;
      }
    }
    else if (x == 2)
    {
      for (int i = 0; i < sizeP; i++)
      {
        cout << "Enter phone at [ " << i << " ] = \t" << name[i] << "\t ";
        cin >> phone[i];
        cout << "\t" << address[i] << endl;
      }
    }
    else
    {
      for (int i = 0; i < sizeA; i++)
      {
        cout << "Enter address at [ " << i << " ] = \t " << name[i] << "\t \t" << phone[i] << "\t \t";
        cin >> address[i];
        cout << endl;
      }
    }
  }
  void showData()
  {
    cout << "Name : \t";
    for (int i = 0; i < sizeN; i++)
    {
      cout << "\t \t" << name[i];
    }
    cout << endl
         << endl
         << "Phone : ";
    for (int i = 0; i < sizeP; i++)
    {
      cout << "\t \t" << phone[i];
    }
    cout << endl
         << endl
         << "Address : ";
    for (int i = 0; i < sizeA; i++)
    {
      cout << "\t \t" << address[i];
    }
    cout << endl;
  }
  void insertion(string newname, int x, long long newnumber, int index)
  {
    if (x == 1) // if user wants to insert name
    {
      if (sizeN >= index)
      {
        for (int i = sizeN - 1; i >= index; i--)
        {
          name[i + 1] = name[i];
        }
        name[index] = newname;
        sizeN++;
      }
      else
        cout << "Error  index not Found";
    }
    else if (x == 2) // if user wants to insert phone number
    {
      if (sizeP >= index)
      {
        for (int i = sizeP - 1; i >= index; i--)
        {
          phone[i + 1] = phone[i];
        }
        phone[index] = newnumber;
        sizeP++;
      }
      else
        cout << "Error index not Found";
    }
    else // if user wants to insert  address
    {
      if (sizeA >= index)
      {
        for (int i = sizeA - 1; i >= index; i--)
        {
          address[i + 1] = address[i];
        }
        address[index] = newname;
        sizeA++;
      }
      else
        cout << "Error index not Found";
    }
  }
  int search(string value, long long number, int x)
  {
    if (x == 1) // For Name Searching
    {
      for (int i = 0; i < sizeN; i++)
      {
        if (name[i] == value)
          return i;
      }
    }
    else if (x == 2)
    {
      for (int i = 0; i < sizeN; i++)
      {
        if (phone[i] == number)
          return i;
      }
    }
    else
    {
      for (int i = 0; i < sizeA; i++)
      {
        if (address[i] == value)
          return i;
      }
    }
    return -1;
  }
};

//*****************************************************************Main function
DataOperator obj(sizeN, sizeP, sizeA);
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
      cout << "Total index you want for Data Entry" << endl;
      cin >> n;
      sizeA = n;
      sizeN = n;
      sizeP = n;
      break;
    case 2:
      handleSetArray();
      break;
    case 3:
      handleInsertion();
      break;
    case 4:
      handleSearch();
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

int handleInsertion()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Insert Name" << endl
         << "2. Insert Phone Number" << endl
         << "3. Insert Address" << endl
         << "4. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      handleInsertionSub(1);
      break;
    case 2:
      handleInsertionSub(2);
      break;
    case 3:
      handleInsertionSub(3);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

void handleInsertionSub(int x)
{
  string name;
  long long number;
  int index;
  cout << "Enter index where you want to insert  ";
  cin >> index;
  if (x == 1)
  {
    cout << "Enter Name You want to insert \t";
    cin >> name;
    obj.insertion(name, 1, 0, index);
  }
  else if (x == 2)
  {
    cout << "Enter Phone Number You want to insert \t";
    cin >> number;
    obj.insertion("no item", 2, number, index);
  }
  else
  {
    cout << "Enter Name You want to insert \t";
    cin >> name;
    obj.insertion(name, 3, 0, index);
  }
}

int handleSearch()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Search Name" << endl
         << "2. Search Phone Number" << endl
         << "3. Search Address" << endl
         << "4. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      handleSearchElement(1);
      break;
    case 2:
      handleSearchElement(2);
      break;
    case 3:
      handleSearchElement(3);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

void handleSearchElement(int x)
{
  string name;
  long long number;
  int index;
  if (x == 1)
  {
    cout << "Enter Name You want to Search \t";
    cin >> name;
    index = obj.search(name, 0, 1);
  }
  else if (x == 2)
  {
    cout << "Enter Phone Number You want to Search \t";
    cin >> number;
    index = obj.search("nothing", number, 2);
  }
  else
  {
    cout << "Enter Name You want to Search \t";
    cin >> name;
    index = obj.search(name, 0, 3);
  }

  //    Retuen Index print
  if (index == (-1))
  {
    cout << "Not found" << endl;
  }
  else
    cout << "You Data fount at index = " << index << endl;
}

int handleDelation()
{
}