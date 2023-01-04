#include <iostream>
using namespace std;
class List
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node *prev;
  };
  Node *head;

public:
  List()
  {
    head = NULL;
  }
  void traversing()
  {
    if (head == NULL)
    {
      cout << " List is Empty" << endl;
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
  void insert_at_head(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    traversing();
  }
  void insert_at_end(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      Node *currNode = head;
      while (currNode->next != NULL)
      {
        currNode = currNode->next;
      }
      currNode->next = newNode;
      newNode->prev = currNode;
    }
    traversing();
  }
  void insert_at_mid()
  {
    int value, item;
    cout << "Enter the value you want to insert." << endl;
    cin >> item;
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
      head = newNode;
      cout << "List is Empty, Value inserted at head." << endl;
    }
    else
    {
      cout << "\n Enter the value you want to insert above of it." << endl;
      cin >> value;
      Node *search = Searching(value);
      newNode->next = search->next;
      newNode->prev = search;
      search->next = newNode;
    }
    traversing();
  }
  Node *Searching(int value)
  {
    if (head == NULL)
    {
      cout << "List is Empty " << endl;
    }
    else
    {
      Node *currNode = head;
      do
      {
        if (currNode->data == value)
          return currNode;
        else
          currNode = currNode->next;
      } while (currNode != NULL);
      cout << "value not found" << endl;
    }
  }
  void delete_head()
  {

    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      traversing();
    }
  }
  void delete_last()
  {
    Node *currNode = head;
    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      if (head->next == NULL)
      {
        head = head->next;
        delete currNode;
      }
      else
      {
        while (currNode->next != NULL)
        {
          currNode = currNode->next;
        }
        currNode->prev->next = NULL;
        delete currNode;
      }
      traversing();
    }
  }
  void delete_by_value()
  {
    int value;
    if (head == NULL)
    {
      cout << "List is empty" << endl;
    }
    else
    {
      if (head->next == NULL)
      {
        Node *temp = head;
        delete temp;
        head = NULL;
      }
      else
      {
        cout << "Enter the value you want to delete" << endl;
        cin >> value;
        Node *search = Searching(value);
        search->prev->next = search->next;
        delete search;
      }
      traversing();
    }
  }
};

int main()
{
  List obj;
  int choice, insert, search, i, sum = 0;
  char ch;
  while (1)
  {
    system("cls");
    cout << "1.  Insert At First" << endl
         << "2.  Insert At Mid" << endl
         << "3.  Insert At Last" << endl
         << "4.  Delete First" << endl
         << "5.  Delete Last" << endl
         << "6.  Delete by Value" << endl
         << "7.  Sum of All list values" << endl
         //  << "10. Average of list" << endl
         //  << "11. Count Nodes" << endl
         << "12. Show" << endl
         << "13. Exit" << endl;
    cout << "\n Enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      obj.insert_at_head(insert);
      break;
    case 2:
      obj.insert_at_mid();
      break;
    case 3:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      obj.insert_at_end(insert);
      break;
    case 4:
      obj.delete_head();
      break;
    case 5:
      obj.delete_last();
      break;
    case 6:
      obj.delete_by_value();
      break;
    case 7:
      // sum = la.sum();
      if (sum != 0)
        cout << "Sum of Linked list data is " << sum << endl;
      break;
    // case 10:
    //   la.average();
    //   break;
    // case 11:
    //   i = la.counter();
    //   if (i != 0)
    //     cout << "your List contain  " << i << " Nodes/Values" << endl;
    //   break;
    case 12:
      obj.traversing();
      break;
    case 13:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}