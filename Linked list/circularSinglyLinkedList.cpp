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
      cout << "Your Data in List " << endl;
      do
      {
        cout << currNode->data << "\t";
        currNode = currNode->link;
      } while (currNode != head);
      cout << endl;
    }
  }
  void insertAtHead(int value)
  {
    Node *currNode = head;
    Node *newNode = new Node(value, NULL);
    if (head == NULL)
    {
      head = newNode;
      newNode->link = head;
    }
    else
    {
      do
      {
        currNode = currNode->link;
      } while (currNode->link != head);
      newNode->link = head;
      currNode->link = newNode;
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
      Node *currNode = head;
      do
      {
        currNode = currNode->link;
      } while (currNode->link != head);
      currNode->link = newNode;
      newNode->link = head;
    }
    traversing();
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
      cout << "Enter the value you want to Delete" << endl;
      cin >> insert;
      break;
    case 4:
      cout << "Enter the value you want to Delete" << endl;
      cin >> insert;
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