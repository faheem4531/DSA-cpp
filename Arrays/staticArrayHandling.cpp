//         This expanded menue program is just to understand array handling or functions as well- @MUSHAB_FAHEEM
#include <iostream>
using namespace std;

//********************************    Functions Decleration
int insertMenue();
void deletion(int);
void searchHandler();
int binarySearcher(int);
int linearHub();
int binaryHub();
void searcher();
int searchDistributer(int, int);
void sortingMenue();
//********************************    Global variable
int n;
//********************************    Class
class MyArrayManagment
{
private:
  int array[50];

public:
  MyArrayManagment(int n)
  {
    array[n];
  }
  void ArrayIndexSet()
  {
    cout << "Total index you want for an array ?" << endl;
    cin >> n;
    cout << "< " << n << " > size array has been set!" << endl;
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
  int linearSearching(int element)
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
  void bubbleSorting()
  {
    // char ch;

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
    cout << "Your Array has been BUBBLE Sort... \n \t \t \t \t Press ENTER to continue" << endl;
    // ch = cin.get();
    // ch = cin.get();
  }
  void selectionSorting()
  {
    for (int i = 0; i < n - 1; i++)
    {
      int min = i;
      for (int j = i + 1; j < n; j++)
      {
        if (array[min] > array[j])
          min = j;
      }
      swap(array[min], array[i]);
      // int temp = array[min];
      // array[min] = array[i];
      // array[i] = temp;
    }
    cout << "Your Array has been Selection Sort... \n \t \t \t \t Press ENTER to continue" << endl;
  }
  void updation(int x)
  {
    int item, newItem, index;
    cout << "Enter the value you want to replace ";
    cin >> item;
    if (x == 0)
    {
      index = linearSearching(item);
      if (index == (-1))
      {
        cout << item << " not found " << endl;
      }
    }
    else
    {
      index = binarySearcherEmulator(item);
      if (index == (-1))
      {
        cout << item << " not found " << endl;
      }
    }
    if (index != (-1))
    {
      cout << item << " replace with...? ";
      cin >> newItem;
      array[index] = newItem;
      cout << "Value Updated !..." << endl;
    }
  }
  bool sortingArrayChecker()
  {
    bool flag;
    for (int i = 0; i < n - 1; i++)
    {
      if (array[i] <= array[i + 1])
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
  char ch;
  int choice;
  while (1)
  {
    system("cls");
    cout << "which Seaching You want to go for " << endl
         << "1. Linear Search" << endl
         << "2. Binary Searching " << endl
         << "3. Exit " << endl;
    cout << "Enter your choice: ";
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
    ch = cin.get();
    ch = cin.get();
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

void deletion(int x) //                                         Dellete item handler
{
  int value, position;
  cout << "Enter the value you want to remove \t";
  cin >> value;
  position = searchDistributer(x, value);
  if (position == (-1))
  {
    cout << "Item not found" << endl;
  }
  else
  {
    la.deleteIndex(position);
    cout << "< " << value << " >   removed from your array " << endl;
  }
}

void searchHandler() //                                    Linear search handler
{
  int value, temp;
  cout << "Enter value you want to search " << endl;
  cin >> value;
  temp = la.linearSearching(value);
  if (temp == (-1))
    cout << "Value not found" << endl;
  else
    cout << "Your value found at index " << temp << endl;
}

int binarySearcher(int searchItem) //                                    Binary Search Engine
{
  int var, returnBack, itemIndex;
  char ch;
  returnBack = la.sortingArrayChecker();
  if (returnBack == 0) // if cheaker return false
  {
    cout << "ErRoR! \t Your array is not Sorted press enter to arrange ..." << endl;
    ch = cin.get();
    ch = cin.get();
    la.bubbleSorting();
    itemIndex = la.binarySearcherEmulator(searchItem);
    return itemIndex;
  }
  else if (returnBack == 1) // if checker return true
  {
    itemIndex = la.binarySearcherEmulator(searchItem);
    return itemIndex;
  }

  return 0; // to avoid return type error
}

void searcher()
{
  int searchItem, searchedIndex;
  cout << "Enter the value you want to search \t";
  cin >> searchItem;
  searchedIndex = binarySearcher(searchItem);
  if (searchedIndex == (-1))
  {
    cout << "Searched item not found " << endl;
  }
  else
    cout << "Your value found at index " << searchedIndex << endl;
}

int searchDistributer(int x, int value)
{
  int index;
  if (x == 0)
  {
    index = la.linearSearching(value);
  }
  else
  {
    index = binarySearcher(value);
  }

  return index;
}

void sortingMenue()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
    cout << "Which Sorting do you want to go for..." << endl;
    cout << endl
         << "1. Bubble Sorting" << endl
         << "2. Selection Sorting" << endl
         << "3. Return" << endl;
    cout << "\n Enter your choice \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
      la.bubbleSorting();
      break;
    case 2:
      la.selectionSorting();
    case 3:
      return;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

int linearHub()
{
  int choice;
  char ch;
  while (1)
  {
    system("cls");
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
      la.ArrayIndexSet();
      break;
    case 2:
      la.setArray();
      break;
    case 3:
      sortingMenue();
      break;
    case 4:
      insertMenue();
      break;
    case 5:
      searchHandler();
      break;
    case 6:
      deletion(0);
      break;
    case 7:
      la.updation(0);
      break;
    case 8:
      la.showArray();
      break;
    case 9:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

int binaryHub()
{
  int choice, searchItem, searchedIndex;
  char ch;
  while (1)
  {
    system("cls");
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
      la.ArrayIndexSet();
      break;
    case 2:
      la.setArray();
      break;
    case 3:
      sortingMenue();
      break;
    case 4:
      insertMenue();
      break;
    case 5:
      searcher();
      break;
    case 6:
      deletion(1);
      break;
    case 7:
      la.updation(1);
      break;
    case 8:
      la.showArray();
      break;
    case 9:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

//***************************************************             END              ****************************************