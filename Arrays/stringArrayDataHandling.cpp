#include <iostream>
using namespace std;

//*****************************************************************Functions Decleration
int showArrayIndexes();
int setArrayIndexes();
int handleSetArray();
int handleInsertion();
void handleInsertionSub(int);
int handleSearch();
void handleSearchElement(int);
int handleDelationMenue();
int handleDaleteByIndex();
void handleDeleteIndexSub(int);
int handleDeletion();
void handleDeletionElement(int);
int handleUpdation();
void handleUpdationElement(int);
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
    cout << endl
         << endl;
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
      cout << "\t \t " << phone[i];
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
        cout << "Value Added...";
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
        cout << "Value Added...";
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
        cout << "Value Added...";
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
    else if (x == 2) // For Number Searching
    {
      for (int i = 0; i < sizeN; i++)
      {
        if (phone[i] == number)
          return i;
      }
    }
    else // For Address Searching
    {
      for (int i = 0; i < sizeA; i++)
      {
        if (address[i] == value)
          return i;
      }
    }
    return -1;
  }
  void deletion(int x, int index)
  {
    if (x == 1)
    {
      for (int i = 0; i < sizeN; i++)
      {
        if (index <= i)
          name[i] = name[i + 1];
      }
      sizeN--;
    }
    else if (x == 2)
    {
      for (int i = 0; i < sizeP; i++)
      {
        if (index <= i)
          phone[i] = phone[i + 1];
      }
      sizeP--;
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        if (index <= i)
          address[i] = address[i + 1];
      }
      sizeA--;
    }
  }
  void Updation(int x, int index, string names, long long newNumber)
  {
    if (x == 1)
      name[index] = names;

    else if (x == 2)
      phone[index] = newNumber;

    else
      address[index] = names;
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
    cout << "NOTE:" << endl
         << "    Inscribing strings should not contain spaces." << endl;
    cout << endl
         << "1. Check current size of arrays" << endl
         << "2. Set Arrays indexes" << endl
         << "3. Set Array's Data" << endl
         << "4. Insert" << endl
         << "5. Search" << endl
         << "6. Delete" << endl
         << "7. Update" << endl
         << "8. Show Current Data" << endl
         << "9. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      showArrayIndexes();
      break;
    case 2:
      setArrayIndexes();
      break;
    case 3:
      handleSetArray();
      break;
    case 4:
      handleInsertion();
      break;
    case 5:
      handleSearch();
      break;
    case 6:
      handleDelationMenue();
      break;
    case 7:
      handleUpdation();
      break;
    case 8:
      obj.showData();
      break;
    case 9:
      ch = cin.get();
      ch = cin.get();
      cout << "... by  ==>  Mushab Faheem  <==" << endl;
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

//*****************************************************************Function Definations

int showArrayIndexes()
{
  char ch;
  system("cls");
  cout << "Size of Name's    Array :  \t" << sizeN << endl;
  cout << "Size of Phone's   Array :  \t" << sizeP << endl;
  cout << "Size of Address's Array :  \t" << sizeA << endl;
  ch = cin.get();
  // ch = cin.get();
  return 0;
}

int setArrayIndexes()
{
  char ch;
  system("cls");
  cout << "Total index you want for Data Entry" << endl;
  cin >> n;
  sizeA = n;
  sizeN = n;
  sizeP = n;
  ch = cin.get();
  // ch = cin.get();
  return 0;
}

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
    // cout << "Value Added...";
  }
  else if (x == 2)
  {
    cout << "Enter Phone Number You want to insert \t";
    cin >> number;
    obj.insertion("no item", 2, number, index);
    // cout << "Value Added...";
  }
  else
  {
    cout << "Enter Name You want to insert \t";
    cin >> name;
    obj.insertion(name, 3, 0, index);
    // cout << "Value Added...";
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
    cout << "You Data found at index = " << index << endl;
}

int handleDelationMenue()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Delete by Index" << endl
         << "2. Delete by Value" << endl
         << "3. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      handleDaleteByIndex();
      break;
    case 2:
      handleDeletion();
      break;
    case 3:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

int handleDaleteByIndex()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Delete Name's index" << endl
         << "2. Delete P-Number's index" << endl
         << "3. Delete Address's index" << endl
         << "4. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      handleDeleteIndexSub(1);
      break;
    case 2:
      handleDeleteIndexSub(2);
      break;
    case 3:
      handleDeleteIndexSub(3);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

void handleDeleteIndexSub(int x)
{
  int index;
  cout << "Enter the index you want to delete " << endl;
  cin >> index;
  if (x == 1)
  {
    if (index < sizeN)
    {
      obj.deletion(1, index);
      cout << "Deletion accomplished ";
    }
    else
      cout << "Error ... Index exceeded";
  }
  else if (x == 2)
  {
    if (index < sizeP)
    {
      obj.deletion(2, index);
      cout << "Deletion accomplished ";
    }
    else
      cout << "Error ... Index exceeded";
  }
  else
  {
    if (index < sizeA)
    {
      obj.deletion(3, index);
      cout << "Deletion accomplished ";
    }
    else
      cout << "Error ... Index exceeded";
  }
}

int handleDeletion()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Delete Name" << endl
         << "2. Delete Phone Number" << endl
         << "3. Delete Address" << endl
         << "4. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      handleDeletionElement(1);
      break;
    case 2:
      handleDeletionElement(2);
      break;
    case 3:
      handleDeletionElement(3);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

void handleDeletionElement(int x)
{
  string name;
  long long number;
  int index;
  if (x == 1)
  {
    cout << "Enter Name You want to Delete \t";
    cin >> name;
    index = obj.search(name, 0, 1);
    if (index == (-1))
    {
      cout << "Name not found" << endl;
    }
    else
    {
      obj.deletion(1, index);
      cout << "Deletion accomplished ";
    }
  }
  else if (x == 2)
  {
    cout << "Enter Phone Number You want to Delete \t";
    cin >> number;
    index = obj.search("nothing", number, 2);
    if (index == (-1))
    {
      cout << "Number not found" << endl;
    }
    else
    {
      obj.deletion(2, index);
      cout << "Deletion accomplished ";
    }
  }
  else
  {
    cout << "Enter address You want to Delete \t";
    cin >> name;
    index = obj.search(name, 0, 3);
    if (index == (-1))
    {
      cout << "Address not found" << endl;
    }
    else
    {
      obj.deletion(3, index);
      cout << "Deletion accomplished ";
    }
  }
}

int handleUpdation()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Update Name" << endl
         << "2. Update Phone Number" << endl
         << "3. Update Address" << endl
         << "4. Return" << endl;

    cout << "Enter you Choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      handleUpdationElement(1);
      break;
    case 2:
      handleUpdationElement(2);
      break;
    case 3:
      handleUpdationElement(3);
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

void handleUpdationElement(int x)
{
  string name, newName;
  long long number, newNum;
  int index;
  if (x == 1)
  {
    cout << "Enter Name You want to Update \t";
    cin >> name;
    index = obj.search(name, 0, 1);
    if (index == (-1))
    {
      cout << "Name not found" << endl;
    }
    else
    {
      cout << "Enter New Name \t";
      cin >> newName;
      obj.Updation(1, index, newName, 0);
      cout << "Updation accomplished ";
    }
  }
  else if (x == 2)
  {
    cout << "Enter Phone Number You want to Updation \t";
    cin >> number;
    index = obj.search("nothing", number, 2);
    if (index == (-1))
    {
      cout << "Number not found" << endl;
    }
    else
    {
      cout << "Enter New Number \t";
      cin >> newNum;
      obj.Updation(2, index, "nothing", newNum);
      cout << "Updation accomplished ";
    }
  }
  else
  {
    cout << "Enter address You want to Updation \t";
    cin >> name;

    index = obj.search(name, 0, 3);
    if (index == (-1))
    {
      cout << "Address not found" << endl;
    }
    else
    {
      cout << "Enter New Address \t";
      cin >> newName;
      obj.Updation(3, index, newName, 0);
      cout << "Updation accomplished ";
    }
  }
}

/****************                                        Code - END                                     ****************/