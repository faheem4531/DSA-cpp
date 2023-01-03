#include <iostream>
using namespace std;
//                                           Functions declerations
void quick_sort(int[], int, int);
int partition(int[], int, int);
void display(int[], int);

//                                            Main Function
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
  quick_sort(array, 0, size - 1);
  display(array, size);
  delete[] array;
}

//                                            Functions Defination

void quick_sort(int array[], int left, int right)
{
  if (left < right)
  {
    int pivot = partition(array, left, right);

    quick_sort(array, left, pivot - 1);
    quick_sort(array, pivot + 1, right);
  }
}

int partition(int array[], int l, int r)
{
  int pi = array[r];
  int i = l - 1;
  for (int j = l; j < r; j++)
  {
    if (array[j] < array[r])
    {
      i++;
      swap(array[i], array[j]);
    }
  }
  swap(array[i + 1], array[r]);
  return i + 1;
}

void display(int array[], int size)
{
  cout << endl
       << "Your sorted array is " << endl;
  for (int i = 0; i < size; i++)
    cout << array[i] << "\t";
}