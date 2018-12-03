#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
 //one reason employeers object to employees using personal smartphones
 //do you agree to mandatory liscensing to software professionals
using namespace std;

int main(int argc, char* argv[])
{
  string fileName = argv[1];
  int numElements;
  ifstream fileIn;

  fileIn.open(fileName);
  if(!fileIn)
  {
    exit(1);
  }

  fileIn >> numElements;
  double qArr[numElements];
  double iArr[numElements];
  double bArr[numElements];

  for(int i = 0; i < numElements - 1; i++)
  {
    fileIn >> qArr[i];
    fileIn >> iArr[i];
    fileIn>> bArr[i];
  }

  auto start = std::chrono::high_resolution_clock::now();
  int low = 0;
  int high = numElements - 1;
  QuickSort(qArr, low, high);
  auto stop = std::chrono::high high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<milliseconds>(stop - start);
  cout << "Time taken by Quicksort algorithm: " << duration.count() << "milliseconds." << endl;

  start = std::chrono::high_resolution_clock::now();
  InsertionSort(iArr);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<milliseconds>(stop - start);
  cout << "Time taken by Insertion Sort algorithm: " << duration.count() << "milliseconds." << endl;

  start = std::chrono::high_resolution_clock::now();
  BubbleSort(bArr);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<milliseconds>(stop - start);
  cout << "Time taken by Bubble Sort algorithm: " << duration.count() << "milliseconds." << endl;
}

int divide(double arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++)
  {
    if(arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i], arr[j]);
  return(i + 1);
}

void swap(int i, int j)
{
  int temp = i;
  i = j;
  j = temp;
}

void QuickSort(double arr[], int low, int high) //O(n^2)
{
  if(low < high)
  {
    int i = divide(arr, low, high);

    QuickSort(arr, low, high);
    QuickSort(arr, low, high);
  }
}

void  InsertionSort(double arr[]) //avg O(n) worst (reverse sorted) O(n^2)
{
  int i, j, k, n;
  n = double(sizeof(arr) / sizeof(arr[0]));

  for(i = 1; i < n; i++)
  {
    k = arr[i];
    k = i - 1;

    while(j >= 0 && arr[j] > k)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = k;
  }
}

void  BubbleSort(double arr[]) //O(n^2)
{
  int n = sizeof(arr) / sizeof(arr[0]);

  for(int i = 0; i < n - 1; i++)
  {
    for(int j = 0; j < n - i - 1; j++)
    {
      if(arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}
