/*                                                               Circular Linked List
In circular linked list there is no null cz last node is linked with the head of the list.
and the previous node of head is connected with the last node.
So The only change of circular is insert/delete at head or last
rest of all the functions will be same
*/
#include <iostream>
using namespace std;
class List
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node *pre;
  };
  Node *head;
  Node *tail;

public:
  List()
  {
    head = NULL;
  }
  Node *get_tail()
  {
    if (head->next != head)
    {
      Node *temp = head;
      while (temp->next != head)
        temp = temp->next;
      return temp;
    }
    return NULL;
  }
  void traversing()
  {
    Node *currNode = head;
    if (head == NULL)
      cout << "List is Empty" << endl;
    else
    {
      cout << "-------------------------------------------------------------------" << endl;
      cout << "\t \t Your Data in List " << endl;
      do
      {
        cout << currNode->data << "\t";
        currNode = currNode->next;
      } while (currNode != head);
      cout << endl;
    }
  }
  void insert_at_head(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    if (head == NULL)
    {
      newNode->next = newNode;
      newNode->pre = newNode;
      head = newNode;
    }
    else
    {
      head->pre->next = newNode;
      newNode->pre = head->pre;
      newNode->next = head;
      head->pre = newNode;
      head = newNode;
    }
    traversing();
  }
  void insert_at_last(int value)
  {
    Node *newNode = new Node;
    newNode->data = value;
    if (head == NULL)
    {
      newNode->next = head;
      newNode->pre = head;
      head = newNode;
    }
    else
    {
      head->pre->next = newNode;
      newNode->pre = head->pre;
      newNode->next = head;
      head->pre = newNode;
    }
    traversing();
  }
  void delete_from_head()
  {
    if (head == NULL)
      cout << "List is Empty" << endl;
    else
    {
      Node *temp = head;
      if (head->next == head)
      {
        delete head;
        head = NULL;
      }
      else
      {
        head->pre->next = head->next;
        head->next->pre = head->pre;
        head = head->next;
        delete temp;
        temp = NULL;
      }
      traversing();
    }
  }
  void delete_frem_last()
  {
    if (head == NULL)
      cout << "List is Empty" << endl;
    else
    {
      if (head->next == head)
      {
        delete head;
        head = NULL;
      }
      else
      {
        tail = get_tail();
        Node *lastNode = tail;
        tail->pre->next = head;
        head->pre = tail->pre;
        tail = tail->pre;
        delete lastNode;
        lastNode = NULL;
        // {  Node *temp = head;     // Alternative method
        // head->pre->pre->next = head;
        // head->pre = head->pre->pre;
        // delete temp;}
      }
      traversing();
    }
  }
};

int main()
{
  List obj;
  int choice, insert, search;
  char ch;
  while (1)
  {
    system("cls");
    cout << "1.  Insert At First" << endl
         << "2.  Insert At Last" << endl
         << "3.  Delete From First" << endl
         << "4.  Delete From Last" << endl
         << "5.  Display" << endl
         << "6.  Exit" << endl;
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
      cout << "Enter the value you want to insert" << endl;
      cin >> insert;
      obj.insert_at_last(insert);
      break;
    case 3:
      obj.delete_from_head();
      break;
    case 4:
      obj.delete_frem_last();
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
