/*                                                               Circular Linked List
In circular linked list there is no null cz last node is linked with the head of the list.
So The only change of circular is insert/delete at head or last
rest of all the functions will be same
*/
#include <iostream>
using namespace std;
//                                                            Node Class
class Node
{
private:
  int data;
  Node *link;

public:
  Node(int item, Node *address)
  {
    this->data = item;
    this->link = address;
  }
  friend class List;
};

//                                                            Link Class
class List
{
private:
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
  void traversing() //                                                        Show list Data
  {
    if (head == NULL)
      cout << "List is Empty" << endl;
    else
    {
      Node *currNode = head;
      cout << "-------------------------------------------------------------------" << endl;
      cout << "\t \t Your Data in List " << endl;
      do
      {
        cout << currNode->data << "\t";
        currNode = currNode->link;
      } while (currNode != head);
      cout << endl;
    }
  }
  Node *tailFind()
  {
    Node *tailNode = head;
    while (tailNode->link != head)
    {
      tailNode = tailNode->link;
    }
    return tailNode;
  }
  void insertAtHead(int value)
  {
    Node *lastNode;
    Node *newNode = new Node(value, head);
    if (head == NULL)
    {
      head = newNode;
      newNode->link = head;
    }
    else
    {
      lastNode = tailFind(); //  return the last node from the list
      lastNode->link = newNode;
      newNode->link = head;
      head = newNode;
    }
    traversing();
  }
  void insertAtLast(int value)
  {
    Node *newNode = new Node(value, head);
    if (head == NULL)
    {
      head = newNode;
      newNode->link = head;
    }
    else
    {
      Node *lastNode = tailFind();
      lastNode->link = newNode;
      newNode->link = head;
    }
    traversing();
  }
  void deleteHead()
  {
    Node *temp = head;

    if (head == NULL)
    {
      cout << "List is Empty" << endl;
    }
    else
    {
      if (head->link == head)
      {
        head = NULL;
        delete head;
      }
      else
      {
        Node *lastNode = tailFind();
        lastNode->link = head->link;
        head = head->link;
        temp = NULL;
        delete temp;
      }
      traversing();
    }
  }
  void deleteLast()
  {
    Node *nextNode = head;
    Node *preNode = head;
    if (head == NULL)
      cout << "List is Empty" << endl;
    else
    {
      if (head->link == head)
      {
        head = NULL;
        delete head;
      }
      else
      {
        while (nextNode->link != head)
        {
          preNode = nextNode;
          nextNode = nextNode->link;
        }
        preNode->link = head;
        nextNode = NULL;
        delete nextNode;
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
         << "2.  Insert At Last" << endl
         << "3.  Delete From First" << endl
         << "4.  Delete From Last" << endl
         << "5.  Show" << endl
         << "6.  Exit" << endl;
    cout << "\n Enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      obj.insertAtHead(insert);
      break;
    case 2:
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      obj.insertAtLast(insert);
      break;
    case 3:
      obj.deleteHead();
      break;
    case 4:
      obj.deleteLast();
      break;
    case 5:
      obj.traversing();
      break;
    case 6:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}
//*************************            Code End               *************************