#include <iostream>
#include <algorithm>
using namespace std;

const int COLS = 80;

void printArray(const int a[], int size);

int main() {
  int a[] = {1, 3, 1, 4, 1, 5};
  
  int arr[] = {1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5,
    1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5,
    1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5, 1, 3, 1, 4, 1, 5};
  printArray(arr, 120);
  
  printArray(a, 6);
  sort(a, a + 6);
  printArray(a, 6);
  cout << unique(a, a + 6) - a << endl;
  printArray(a, 6);
}

void printArray(const int a[], int size) {
  int i = 0, lim = 7;
  
  cout << "a[] = {";
  while(i < size - 1){
    lim += 3;
    cout << a[i++] << ", ";
    if(lim > COLS){
      cout << endl << "       ";
      lim = 7;
    }
  }
  cout << a[size - 1] << '}' << endl;
}
