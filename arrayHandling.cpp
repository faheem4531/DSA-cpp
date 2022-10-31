#include <iostream>
using namespace std;

//********************************    Functions Decleration
int insertMenue();
void deletion();
void searchHandler();
int binarySearcher();
//********************************    Global variable
int n;
//********************************    Class
class MyArrayManagment
{
private:
  int array[0];

public:
  MyArrayManagment(int n)
  {
    array[0] = array[n];
  }
  void showArray()
  {
    if (n <= 0)
    {
      cout << "Sorry! No item found " << endl;
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        cout << array[i] << '\t';
      }
    }
  }
  void setArray()
  {
    for (int i = 0; i < n; i++)
    {
      cout << "Enter value at index = [ " << i << " ] \t";
      cin >> array[i];
    }
    cout << "Your Array has been set!" << endl;
  }
  void Insertion(int index, int item)
  {
    if (n < index)
    {
      cout << "Error ";
    }
    else
    {
      for (int i = n - 1; i >= index; i--)
      {
        array[i + 1] = array[i];
      }
      array[index] = item;
      n++;
    }
  }
  int searching(int element)
  {
    for (int i = 0; i < n; i++)
    {
      if (array[i] == element)
        return i;
    }
    return -1;
  }
  void deleteIndex(int index)
  {
    for (int i = 0; i < n; i++)
    {
      if (index <= i)
        array[i] = array[i + 1];
    }
    n--;
  }
  void sortingArray()
  {
    char ch;
    for (int counter = 1; counter < n; counter++)
    {
      for (int i = 0; i < n - counter; i++)
      {
        if (array[i] > array[i + 1])
        {
          int temp;
          temp = array[i];
          array[i] = array[i + 1];
          array[i + 1] = temp;
        }
      }
    }
    cout << "Your Array has been sorted press ENTER to continue" << endl;
    ch = cin.get();
    ch = cin.get();
  }
  void updation()
  {
    int item, newItem, index;
    cout << "Enter the value you want to replace ";
    cin >> item;
    cout << "replace with...? ";
    cin >> newItem;
    index = searching(item);
    array[index] = newItem;
  }
  bool sortingArrayChecker()
  {
    bool flag;
    for (int i = 0; i < n - 1; i++)
    {
      if (array[i] < array[i + 1])
      {
        flag = true;
      }
      else
      {
        flag = false;
        break;
      }
    }
    return flag;
  }
};

//********************************************************Main Function
MyArrayManagment la(n);
int main()
{
  cout << "Total index you want for an array" << endl;
  cin >> n;
  int backup;
  // la.setArray();
  // backup = la.sortingArrayChecker();
  // cout << "Your return value is " << backup << endl;
  // la.showArray();
  int choice, value;
  // char ch;
  while (1)
  {
    // system("cls");
    cout << endl
         << "1. Set array" << endl
         << "2. Insert " << endl
         << "3. Delete" << endl
         << "4. Search" << endl
         << "5. Update" << endl
         << "6. Show" << endl
         << "7. Sorting Array" << endl
         << "8. Binary Search" << endl
         << "9. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      la.setArray();
      break;
    case 2:
      insertMenue();
      break;
    case 3:
      deletion();
      break;
    case 4:
      searchHandler();
      break;
    case 5:
      la.updation();
      break;
    case 6:
      la.showArray();
      break;
    case 7:
      la.sortingArray();
      break;
    case 8:
      binarySearcher();
      break;
    case 9:
      return 0;
    }
    // ch = cin.get();
    // ch = cin.get();
  }
}

//******************************************** Functions Definations
int insertMenue() //                                       Insert item handler
{
  int position, value;
  cout << "Enter the index where you want to insert \t";
  cin >> position;
  cout << "Enter the item you want to insert \t";
  cin >> value;
  la.Insertion(position, value);
  return 0;
}

void deletion() //                                          Dellete item handler
{
  int value, position;
  cout << "Enter the value you want to remove \t";
  cin >> value;
  position = la.searching(value);
  if (position == (-1))
  {
    cout << "Item not found" << endl;
  }
  else
    la.deleteIndex(position);
}

void searchHandler() //                                     Linear search handler
{
  int value, temp;
  cout << "Enter value you want to search " << endl;
  cin >> value;
  temp = la.searching(value);
  if (temp == (-1))
    cout << "Value not found" << endl;
  else
    cout << "Your value found at index " << temp << endl;
}

int binarySearcher() //                                     Binary Search Engine
{
  int var, returnBack;
  char ch;
  returnBack = la.sortingArrayChecker();
  if (returnBack == 0)
  {
    cout << "ErRoR!  Your array is not arranged press enter to continue..." << endl;
    ch = cin.get();
    ch = cin.get();
    cout << "Do you want to arrange you array ? " << endl
         << "1. To Arrange your array" << endl
         << "2. to move back" << endl;
    cin >> var;

    if (var == 1)
    {
      la.sortingArray();
    }
    else if (var == 2)
    {
      return 0;
    }
  }
  else
  {
    cout << "under processs"s;
  }
  return 1;
}