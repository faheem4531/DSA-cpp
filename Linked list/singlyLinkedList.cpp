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
      cout << "Your List Data is: " << endl;
      do
      {
        cout << currNode->data << "\t";
        currNode = currNode->next;
      } while (currNode != NULL);
      cout << endl;
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
};

int main()
{
  List la;
  int choice, insert;
  char ch;
  while (1)
  {
    system("cls");
    cout << "1. Insert At First" << endl
         << "2. Insert At Last" << endl
         << "3. Delate First" << endl
         << "4. Delete Last" << endl
         << "5. Show" << endl
         << "6. Exit" << endl;
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
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      la.insertLast(insert);
      break;
    case 3:
      la.deleteAtFirst();
      break;
    case 4:
      la.deleteAtLast();
      break;
    case 5:
      la.traversing();
      break;
    case 6:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }

  // la.insertAtHead(10);
  // la.traversing();
  // cout << "\t first time\n \n";
  // la.traversing();
  // la.insertLast(22);
  // la.insertLast(21);
  // la.insertAtHead(30);
  // la.insertLast(20);
  // la.insertLast(19);
  // cout << "\t second time\n \n";
  // la.traversing();
  // la.insertAtHead(1);
  // cout << "\t third time\n \n";
  // la.traversing();
}