#include <iostream>
using namespace std;
//*********************************  Functions Handler
void checkAdding(int **, int **, int **, int, int, int, int);
int menueSubtract(int **, int **, int **, int, int, int, int);
void multiplyhandler(int **, int **, int **, int, int, int, int);
//*********************************   Logical Functions Controler
void SetMatrix(int **, int, int);
void ShowMatrix(int **, int, int);
void add(int **, int **, int, int, int, int);
void subtract(int **, int **, int **, int, int, int, int);
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

  //   2D array Decleratfon in hype memory
  int **matrix1 = new int *[r1];
  int **matrix2 = new int *[r2];
  int **apply = new int *[r2];
  //   Memory Allocation for 2 matrixes
  for (int i = 0; i < r1; i++)
  {
    matrix1[i] = new int[c1];
  }
  for (int i = 0; i < r2; i++)
  {
    matrix2[i] = new int[c2];
    apply[i] = new int[c1];
  }

  while (1)
  {
    system("cls");

    cout << "1. Set Matrix-1" << endl
         << "2. Set Matrix-2" << endl
         << "3. Show Matrix-1" << endl
         << "4. Show Matrix-2" << endl
         << "5. Adding" << endl
         << "6. Subtraction" << endl
         << "7. Multiplication" << endl
         << "8. Exit" << endl;
    cout << "\nEnter Choice \t";
    cin >> hit;
    cout << endl;
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
      break;
    case (4):
      ShowMatrix(matrix2, r2, c2);
      break;
    case (5):
      checkAdding(matrix1, matrix2, apply, r1, r2, c1, c2);
      break;
    case (6):
      menueSubtract(matrix1, matrix2, apply, r1, r2, c1, c2);
      break;
    case (7):
      multiplyhandler(matrix1, matrix2, apply, r1, r2, c1, c2);
      break;
    case (8):
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

void checkAdding(int **array1, int **array2, int **add, int r1, int r2, int c1, int c2)
{
  system("cls");
  if (r1 == r2 && c1 == c2)
  {
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        add[i][j] = array1[i][j] + array2[i][j];
      }
    }
    cout << "\t \t \t Sum of 2 Matrixes \n"
         << endl;
    cout << endl
         << "\t \t Matrix 1" << endl;
    ShowMatrix(array1, r1, c1);
    cout << endl
         << "\t \t Matrix 2" << endl;
    ShowMatrix(array2, r1, c1);
    cout << endl
         << "\t \t Sum of Both Matrices " << endl;
    ShowMatrix(add, r1, c1);
  }
  else
    cout << "Matrix Addition Rule Error" << endl;
}

int menueSubtract(int **array1, int **array2, int **sub, int r1, int r2, int c1, int c2)
{
  char ch;
  int choice;
  while (1)
  {
    system("cls");
    cout << "Subtracting Matrices" << endl;
    cout << "1. Subtract Matrix 1 from 2 " << endl
         << "2. Subtract Matrix 2 from 1 " << endl
         << "3. return" << endl;
    cout << "Enter your Choice \t";
    cin >> choice;
    switch (choice)
    {
    case (1):
      subtract(array1, array2, sub, r1, r2, c1, c2);
      break;
    case (2):
      subtract(array2, array1, sub, r1, r2, c1, c2);
      break;
    case (3):
      return 0;
    }
    ch = cin.get();
    ch = cin.get();
  }
}

void subtract(int **array1, int **array2, int **sub, int r1, int r2, int c1, int c2)
{
  system("cls");
  if (r1 == r2 && c1 == c2)
  {
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sub[i][j] = array1[i][j] - array2[i][j];
      }
    }
    cout << "\t \t \t Subtraction of Matrices\n"
         << endl;
    cout << endl
         << "\t \t Matrix 1" << endl;
    ShowMatrix(array1, r1, c1);
    cout << endl
         << "\t \t Matrix 2" << endl;
    ShowMatrix(array2, r1, c1);
    cout << endl
         << "\t \t Subtrected Matrix " << endl;
    ShowMatrix(sub, r1, c1);
  }
  else
    cout << "Matrix Subtraction Rule Error" << endl;
}

void multiplyhandler(int **m1, int **m2, int **product, int r1, int r2, int c1, int c2)
{
  system("cls");
  if (c1 == r2)
  {
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c2; j++)
      {
        product[i][j] = 0;
        for (int k = 0; k < r2; k++) // c1==r2......k<c1
        {
          product[i][j] = product[i][j] + m1[i][k] * m2[k][j];
        }
      }
    }
    cout << "\t \t \t Multiplication of Matrices" << endl
         << endl;
    cout << endl
         << "\t \t Matrix 1 " << endl;
    ShowMatrix(m1, r1, c1);

    cout << endl
         << "\t \t Matrix 2 " << endl;
    ShowMatrix(m2, r2, c2);
    cout << endl
         << "\t \t Product " << endl;
    ShowMatrix(product, r2, c2);
  }
  else
    cout << "Condition unsatisfied" << endl;
}

//**************                             Code End                                    ************