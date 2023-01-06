#include <iostream>
using namespace std;
class Stack
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node(int value, Node *adress)
    {
      this->data = value;
      this->next = adress;
    }
  };
  Node *head;

public:
  Stack()
  {
    head = NULL;
  }
  void display()
  {
    if (head == NULL)
      cout << "List is Empty";
    else
    {
      Node *currNode = head;
      cout << "__________________________________________" << endl
           << endl
           << "Data in Your list is.. " << endl
           << endl;
      do
      {
        cout << currNode->data << "\t";
        currNode = currNode->next;
      } while (currNode != NULL);
    }
    cout << endl;
  }
  void push(int value)
  {
    Node *newNode = new Node(value, NULL);
    if (head == NULL)
      head = newNode;
    else
    {
      newNode->next = head;
      head = newNode;
    }
    display();
  }
  void pop()
  {
    if (head == NULL)
      cout << "List is Empty" << endl;
    else
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      display();
    }
  }
};

int main()
{
  int choice, value;
  char ch;
  Stack obj;
  while (1)
  {
    system("cls");
    cout << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Display" << endl
         << "4. Exit" << endl;
    cout << "\n \t Enter your choice \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter the value you want to push \t";
      cin >> value;
      obj.push(value);
      break;
    case 2:
      obj.pop();
      break;
    case 3:
      obj.display();
      break;
    case 4:
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}