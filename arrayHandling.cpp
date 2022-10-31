#include <iostream>
using namespace std;

//********************************    Functions Decleration
int insertMenue();
void deletion();
void searchHandler();
int binarySearcher();
int linearHub();
int binaryHub();
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
  int binarySearcherEmulator(int value)
  {
    int start, end;
    start = 0;
    end = n - 1;
    while (start <= end)
    {
      int mid = end;
      if (array[mid] == value)
      {
        return mid;
      }
      else if (array[mid] > value)
      {
        end = mid - 1;
      }
      else
        start = mid + 1;
    }
    return -1;
  }
};

//********************************************************Main Function
MyArrayManagment la(n);
int main()
{
  // char ch;
  int backup;
  int choice, value;
  while (1)
  {
    // system("cls");
    cout << "which Seaching You want to go for " << endl
         << "1. Linear Search" << endl
         << "2. Binary Searching " << endl
         << "3 Exit " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      linearHub();
      break;
    case 2:
      binaryHub();
      break;
    case 3:
      return 0;
    }
    // ch = cin.get();
    // ch = cin.get();
  }
}

//******************************************************************* Functions Definations
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

void deletion() //                                         Dellete item handler
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

void searchHandler() //                                    Linear search handler
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

int binarySearcher() //                                    Binary Search Engine
{
  int var, returnBack, searchItem, itemIndex;
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
    cout << "Enter the item you want to deal with " << endl;
    cin >> searchItem;
    itemIndex = la.binarySearcherEmulator(searchItem);
    if (itemIndex == (-1))
    {
      cout << "Item not found " << endl;
    }
    else
      cout << "Searching index is " << itemIndex << endl;
  }
  return 1;
}

int linearHub()
{
  int choice;
  // char ch;
  while (1)
  {
    // system("cls");
    cout << endl
         << "1. Set Array index" << endl
         << "2. Set array" << endl
         << "3. Sorting Array" << endl
         << "4. Insert " << endl
         << "5. Search" << endl
         << "6. Delete" << endl
         << "7. Update" << endl
         << "8. Show" << endl
         << "9. Return Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Total index you want for an array" << endl;
      cin >> n;
      break;
    case 2:
      la.setArray();
      break;
    case 3:
      la.sortingArray();
      break;
    case 4:
      insertMenue();
      break;
    case 5:
      searchHandler();
      break;
    case 6:
      deletion();
      break;
    case 7:
      la.updation();
      break;
    case 8:
      la.showArray();
      break;
    case 9:
      return 0;
    }
    // ch = cin.get();
    // ch = cin.get();
  }
}

int binaryHub()
{
  int choice;
  // char ch;
  while (1)
  {
    // system("cls");
    cout << endl
         << "1. Set Array index" << endl
         << "2. Set array" << endl
         << "3. Sorting Array" << endl
         << "4. Insert " << endl
         << "5. Search" << endl
         << "6. Delete" << endl
         << "7. Update" << endl
         << "8. Show" << endl
         << "9. Return Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Total index you want for an array" << endl;
      cin >> n;
      break;
    case 2:
      la.setArray();
      break;
    case 3:
      la.sortingArray();
      break;
    case 4:
      insertMenue();
      break;
    case 5:
      binarySearcher();
      break;
    case 6:
      deletion();
      break;
    case 7:
      la.updation();
      break;
    case 8:
      la.showArray();
      break;
    case 9:
      return 0;
    }
    // ch = cin.get();
    // ch = cin.get();
  }
}