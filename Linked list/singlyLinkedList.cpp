#include <iostream>
using namespace std;
//******************  Node class
class Node
{
  int data;
  Node *next;

public:
  Node(int dta, Node *nxt)
  {
    this->data = dta;
    this->next = nxt;
  }

  friend class List; // giving acess of private node data member to List class
};

// ***********                                                                 List class
class List
{
  Node *head;

public:
  List() //                                                                     set head
  {
    head = NULL;
  }
  bool isEmpty() //                                                             Check head
  {
    return !head;
  }
  void traversing()
  {
    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      Node *currNode = head;
      cout << "\n \t \t Your List Data is: " << endl;
      do
      {
        cout << currNode->data << "\t";
        currNode = currNode->next;
      } while (currNode != NULL);
      cout << endl;
    }
  }
  void checkValue(int value) // To check searched value exist or not
  {
    Node *testNode = head;
    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      do
      {
        if (value == testNode->data)
        {
          cout << "Value Found" << endl;
          return;
        }
        else
        {
          testNode = testNode->next;
        }

      } while (testNode != NULL);
      cout << "Value not found" << endl;
    }
  }
  void insertAtHead(int data)
  {
    Node *newNode = new Node(data, NULL);
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }
  Node *searching(int value) // this searching function is for insert-delete for specific node
  {
    if (head == NULL)
    {
      cout << "Your list is Empty" << endl;
    }
    else
    {
      Node *nextNode = head;
      do
      {
        if (value == nextNode->data)
        {
          return nextNode;
        }
        else
        {
          nextNode = nextNode->next;
        }
      } while (nextNode != NULL);

      cout << "value not found" << endl;
    }
  }
  void insertAtMid()
  {
    int value, item;
    cout << "Enter the value you want to insert " << endl;
    cin >> value;
    Node *newNode = new Node(value, NULL);
    Node *store;
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      cout << "Enter the value you want to insert above of it" << endl;
      cin >> item;
      store = searching(item);
      // cout << "store data \t" << store->data << "\t" << store->next << endl;
      newNode->next = store->next;
      store->next = newNode;
      // cout << "newNode data \t" << newNode->data << "\t" << newNode->next << endl;
      // cout << "store data \t" << store->data << "\t" << store->next << endl;
      traversing();
    }
  }
  void instertAtPosition(int data)
  {
    Node *newNode = new Node(data, NULL);
    Node *posNode = head;
    int i = 1, pos;
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      cout << "Your list contain " << counter() << " items " << endl;
      cout << "Enter the position where you want to insert" << endl;
      cin >> pos;
      while (i < pos)
      {
        posNode = posNode->next;
        i++;
      }
      newNode->next = posNode->next;
      posNode->next = newNode;
    }

    traversing();
  }
  void insertLast(int data) //                                                  Insert at last
  {
    Node *newNode = new Node(data, NULL);
    if (head == NULL)
    {
      head = newNode;
      return;
    }
    else
    {
      Node *currentNode = head;
      while (currentNode->next != NULL)
      {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
    }
  }
  void deleteAtFirst()
  {
    Node *newnode = head;
    if (head == NULL)
    {
      cout << "List is empty" << endl;
    }
    else
    {
      head = head->next;
      delete newnode;
    }
  }
  void deleteAtLast()
  {
    if (head == NULL)
    {
      cout << "List is empty" << endl;
    }
    else
    {
      if (head->next == NULL)
      {
        delete head;
        head = NULL;
      }
      else
      {
        Node *preNode = head;
        Node *nextNode = head;
        while (nextNode->next != NULL)
        {
          preNode = nextNode;
          nextNode = nextNode->next;
        }
        delete nextNode;
        preNode->next = NULL;
      }
    }
  }
  int counter()
  {
    Node *currNode = head;
    int count = 0;
    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      do
      {
        count++;
        currNode = currNode->next;

      } while (currNode != NULL);
    }
    return count;
  }
  int sum()
  {
    int sum = 0;
    Node *currNode = head;
    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      while (currNode != NULL)
      {
        sum = sum + currNode->data;
        currNode = currNode->next;
      }
    }
    return sum;
  }
  void average()
  {
    int add, n;
    float avg;
    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      system("cls");
      add = sum();
      n = counter();
      avg = add / n;
      cout << "Sum  = " << add << "\t Nodes  = " << n << "\t  Average  =  " << avg << endl;
    }
  }
};

int main()
{
  List la;
  int choice, insert, search, i, sum = 0;
  char ch;
  while (1)
  {
    system("cls");
    cout << "1.  Insert At First" << endl
         << "2.  Insert Above any value" << endl
         << "3.  Insert At Last" << endl
         << "4.  Insert At position" << endl
         << "5.  Delete First" << endl
         << "6.  Delete Last" << endl
         << "7.  Delete by Value" << endl
         << "8.  Searching" << endl
         << "9.  Sum of All list" << endl
         << "10. Average of list" << endl
         << "11. Count Values" << endl
         << "12. Show" << endl
         << "13. Exit" << endl;
    cout << "\n Enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      la.insertAtHead(insert);
      break;
    case 2:
      la.insertAtMid();
      break;
    case 3:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      la.insertLast(insert);
      break;
    case 4:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      la.instertAtPosition(insert);
      break;
    case 5:
      la.deleteAtFirst();
      break;
    case 6:
      la.deleteAtLast();
      break;
    case 7:
      cout << "Enter searched value" << endl;
      cin >> search;
      la.searching(search);
      break;
    case 8:
      cout << "Enter the value you want to Check Availiblity" << endl;
      cin >> search;
      la.checkValue(search);
      break;
    case 9:
      sum = la.sum();
      if (sum != 0)
        cout << "Sum of Linked list data is " << sum << endl;
      break;
    case 10:
      la.average();
      break;
    case 11:
      i = la.counter();
      if (i != 0)
        cout << "your List contain  " << i << " Nodes/Values" << endl;
      break;
    case 12:
      la.traversing();
      break;
    case 13:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}