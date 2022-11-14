#include <iostream>
using namespace std;

int size;
int searchMenue();
void handleSearchElement(int x);
void deletion();
class telephoneDictionary
{
private:
  string name[50], address[50];
  long long pno[50];
  // string *name;
  // string *address;
  // long long *pno;

public:
  telephoneDictionary()
  {
    // name = new string[size];
    // address = new string[size];
    // pno = new long long[size];
    name[size];
    address[size];
    pno[size];
  }
  void setData()
  {
    for (int i = 0; i < size; i++)
    {
      system("cls");
      cout << "Data entry at = [ " << i << " ] \n";
      cout << "Name = ";
      cin >> name[i];
      cout << "Phone number = ";
      cin >> pno[i];
      cout << "Address = ";
      cin >> address[i];
    }
  }
  void showData()
  {
    cout << endl
         << "Sr. \t"
         << "Name \t \t"
         << "Contact \t"
         << "Address " << endl
         << endl;
    for (int i = 0; i < size; i++)
    {
      cout << i + 1 << "\t" << name[i] << "\t \t" << pno[i] << "\t \t" << address[i] << "\t \t" << endl;
    }
  }
  int insertion()
  {
    system("cls");
    string newname, newadd;
    long long newpn;
    int index;
    char ch;
    cout << "Enter the position where you want to insert \t";
    cin >> index;

    if (size >= index)
    {
      cout << "Enter the name   \t";
      cin >> newname;
      cout << "Enter the number  \t";
      cin >> newpn;
      cout << "Enter the address \t";
      cin >> newadd;
      for (int i = size - 1; i >= index; i--)
      {
        name[i + 1] = name[i];
        address[i + 1] = address[i];
        pno[i + 1] = pno[i];
      }

      name[index] = newname;
      pno[index] = newpn;
      address[index] = newadd;
      size++;
    }
    else
      cout << "Error index not found";
    ch = cin.get();
    ch = cin.get();
    return 0;
  }
  int searching(string value, long long number, int x)
  {
    if (x == 1) // For Name Searching
    {
      for (int i = 0; i < size; i++)
      {
        if (name[i] == value)
          return i;
      }
    }
    else if (x == 2) // For Number Searching
    {
      for (int i = 0; i < size; i++)
      {
        if (pno[i] == number)
          return i;
      }
    }
    else // For Address Searching
    {
      for (int i = 0; i < size; i++)
      {
        if (address[i] == value)
          return i;
      }
    }
    return -1;
  }
  void deletion(int index)
  {
    for (int i = 0; i < size; i++)
    {
      if (index <= i)
      {
        name[i] = name[i + 1];
        pno[i] = pno[i + 1];
        address[i] = address[i + 1];
      }
    }
    size--;
  }
  void updation()
  {
    int index;
    string newname, newadd;
    long long newpn;
    cout << "Enter the name of std you want to update data \t";
    cin >> newname;
    index = searching(newname, 0, 1);
    if (index == (-1))
    {
      cout << "Not found";
    }
    else
    {
      cout << "Enter the new name   \t";
      cin >> newname;
      cout << "Enter the new number  \t";
      cin >> newpn;
      cout << "Enter the new address \t";
      cin >> newadd;

      name[index] = newname;
      pno[index] = newpn;
      address[index] = newadd;
    }
  }
  void showSearch(int index)
  {
    cout << endl
         << "Sr. \t"
         << "Name \t \t"
         << "Contact \t "
         << "Address " << endl
         << endl;
    cout << index + 1 << "\t" << name[index] << "\t \t" << pno[index] << "\t \t" << address[index] << "\t \t" << endl;
  }
};
telephoneDictionary obj;
int main()
{
  cout << "Enter the Size for your array " << endl;
  cin >> size;

  char ch;
  int choice;
  while (1)
  {
    system("cls");
    cout << endl
         << "1. Set array" << endl
         << "2. Insert " << endl
         << "3. Search" << endl
         << "4. Delete" << endl
         << "5. Update" << endl
         << "6. Show" << endl
         << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      obj.setData();
      break;
    case 2:
      obj.insertion();
      break;
    case 3:
      searchMenue();
      break;
    case 4:
      deletion();
      break;
    case 5:
      obj.updation();
      break;
    case 6:
      obj.showData();
      break;
    case 7:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

int searchMenue()
{
  while (1)
  {
    char ch;
    int choice;
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
    index = obj.searching(name, 0, 1);
  }
  else if (x == 2)
  {
    cout << "Enter Phone Number You want to Search \t";
    cin >> number;
    index = obj.searching("nothing", number, 2);
  }
  else
  {
    cout << "Enter address You want to Search \t";
    cin >> name;
    index = obj.searching(name, 0, 3);
  }

  //    Retuen Index print
  if (index == (-1))
  {
    cout << "Not found" << endl;
  }
  else
    obj.showSearch(index);
}

void deletion()
{
  string rmname;
  int index;
  cout << "Enter the name you want to remove. \t";
  cin >> rmname;
  index = obj.searching(rmname, 0, 1);
  if (index == (-1))
  {
    cout << "Item not found";
  }
  else
  {
    obj.deletion(index);
    cout << "Deletion done!";
  }
}

//*******************                                End Code                                 **************************