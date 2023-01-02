#include <iostream>
using namespace std;
//                                                                Functions declerations
void mergeSorting(int[], int, int);
void mergeing(int[], int, int, int);
void display(int[], int);
//                                                                 Main Function
int main()
{
  int size;
  system("cls");
  cout << "Enter the size for your array \t";
  cin >> size;
  int *array = new int[size];
  system("cls");
  for (int i = 0; i < size; i++)
  {
    cout << "value at index [" << i << "] = ";
    cin >> array[i];
  }
  mergeSorting(array, 0, size - 1);
  display(array, size);
  delete[] array;
}

//                                                                   Functions Decleration

void mergeSorting(int array[], int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;

    mergeSorting(array, left, mid);
    mergeSorting(array, mid + 1, right);

    mergeing(array, left, mid, right);
  }
}

void mergeing(int array[], int left, int mid, int right)
{
  int n1 = mid - left + 1; //    size for left array
  int n2 = right - mid;    //    size for right array
  int *a1 = new int[n1];   //    left array
  int *a2 = new int[n2];   //    right array
  //                                                                    Assigning values to the temporary arrays
  int temp = left;
  for (int i = 0; i < n1; i++)
  {
    a1[i] = array[temp];
    temp++;
  }
  for (int i = 0; i < n2; i++)
  {
    a2[i] = array[temp];
    temp++;
  }
  //                                                                    Sort Values
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (a1[i] < a2[j])
    {
      array[k] = a1[i];
      i++;
    }
    else
    {
      array[k] = a2[j];
      j++;
    }
    k++;
  }
  //                                                                   If one array is out of values
  while (i < n1)
  {
    array[k] = a1[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    array[k] = a2[j];
    j++;
    k++;
  }
  //                                                                   Delete Temporary Arrays
  delete[] a1;
  delete[] a2;
}

void display(int array[], int size)
{
  cout << endl
       << "Your sorted array is " << endl;
  for (int i = 0; i < size; i++)
    cout << array[i] << "\t";
}