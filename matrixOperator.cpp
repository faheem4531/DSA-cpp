#include <iostream>
using namespace std;
//*********************************  Menue Functions Handler

//********************************   Logical Functions Controler
void SetMatrix(int **, int, int);
void ShowMatrix(int **, int, int);
//*******************************   Main
int main()
{
  char ch;
  int hit, r1, r2, c1, c2;
  system("cls");
  cout << "Enter Rows for 1st Matrix \t";
  cin >> r1;
  cout << "Enter Column for 1st Matrix \t";
  cin >> c1;
  cout << "Enter Rows for 2nd Matrix \t";
  cin >> r2;
  cout << "Enter Column for 2nd Matrix \t";
  cin >> c2;

  //   2D array Decleration in hype memory
  int **matrix1 = new int *[r1];
  int **matrix2 = new int *[r2];
  //   Memory Allocation for 2 matrixes
  for (int i = 0; i < r1; i++)
  {
    matrix1[i] = new int[c1];
  }
  for (int i = 0; i < r2; i++)
  {
    matrix2[i] = new int[c2];
  }

  while (1)
  {
    system("cls");
    cout << "1. Set Matrix-1" << endl
         << "2. Set Matrix-2" << endl
         << "3. Show Matrix-1" << endl
         << "4. Show Matrix-2" << endl
         << "5. Exit" << endl;
    cout << "\nEnter Choice \t";
    cin >> hit;
    switch (hit)
    {
    case (1):
      SetMatrix(matrix1, r1, c1);
      break;
    case (2):
      SetMatrix(matrix2, r2, c2);
      break;
    case (3):
      ShowMatrix(matrix1, r1, c1);
    case (4):
      ShowMatrix(matrix2, r2, c2);
      break;
    case (5):
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

//********************************  Definations

void SetMatrix(int **array, int r, int c) //       Set Values in Matrix
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << "[ " << i << " ][ " << j << " ] =   ";
      cin >> array[i][j];
    }
    cout << endl;
  }
}

void ShowMatrix(int **array, int r, int c) //       Show Matrix
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << array[i][j] << "\t";
    }
    cout << endl;
  }
}