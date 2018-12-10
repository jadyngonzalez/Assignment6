#include <iostream>
#include <fstream>
#include <chrono>
#include "Sorter.h"

using namespace std;
using namespace std::chrono;

Sorter::Sorter()
{
  cout << "Default." << endl;
}

Sorter::~Sorter()
{

}

Sorter::Sorter(string file)
{
  this->fileName = file;
  if(!ifstream(fileName))
  {
    cout << "Error opening file." << endl;
    exit(0);
  }

  sort();
}

void Sorter::sort()
{
  ifstream inFile(fileName);
  inFile >> numElements;

  bArr = new double[numElements];
  iArr = new double[numElements];
  qArr = new double[numElements];
  rArr = new double[numElements];

  for(int i = 0; i < numElements; ++i)
  {
    inFile >> bArr[i];
    iArr[i] = bArr[i];
    qArr[i] = bArr[i];
    rArr[i] = bArr[i];
  }

  auto start = high_resolution_clock::now();
  bubbleSort(bArr, numElements);
  auto end = high_resolution_clock::now();
  cout << "Time taken for bubblesort: " << duration_cast<milliseconds>(end-start).count() << "ms." << endl;

  start = high_resolution_clock::now();
  insertionSort(iArr, numElements);
  end = high_resolution_clock::now();
  cout << "Time taken for insertionsort: " << duration_cast<milliseconds>(end-start).count() << "ms." << endl;

  start = high_resolution_clock::now();
  quickSort(qArr, 0, numElements - 1);
  //print(qArr, numElements);
  end = high_resolution_clock::now();
  cout << "Time taken for quicksort: " << duration_cast<milliseconds>(end-start).count() << "ms." << endl;

  start = high_resolution_clock::now();
  combSort(rArr, numElements);
  //print(rArr, numElements);
  end = high_resolution_clock::now();
  cout << "Time taken for combSort: " << duration_cast<milliseconds>(end-start).count() << "ms." << endl;
}

void Sorter::swap(double *x, double *y)
{
  double temp = *x;
  *x = *y;
  *y = temp;
}

void Sorter::print(double arr[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    cout << arr[i] << endl;
  }
}

int Sorter::getGap(int gap)
{
  gap = (gap*10)/13;
  if(gap < 1)
  {
    return 1;
  }
  return gap;
}

int Sorter::pivot(double arr[], int l, int h)
{
  double val = arr[l];
  int position = l;

  for(int i = l+1; i <= h; ++i)
  {
    if(arr[i] < val)
    {
      swap(&arr[position + 1], &arr[i]);
      swap(&arr[position], &arr[position + 1]);
      ++position;
    }
  }
  return position;
}

void Sorter::bubbleSort(double arr[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    for(int j = 0; j < (size - 1); ++j)
    {
      if(arr[j] > arr[j+1]) //compare current with element afetr
      {
        swap(&arr[j], &arr[j+1]);//if greater swap
      }
    }
  }
}

void Sorter::insertionSort(double arr[], int size)
{
  for(int i = 1; i < numElements; ++i)//start at arr[1]
  {
    double temp = arr[i]; //mark
    int k = i;
    while(k > 0 && arr[k-1] >= temp)
    {
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp; //insert temp into arr[k]
  }
}

void Sorter::quickSort(double arr[], int l, int h)
{
  int p;

if(l < h)
{
  p = pivot(arr, l, h);
  quickSort(arr, l, p - 1);
  quickSort(arr, p + 1, h);
}
  return;
}

void Sorter::combSort(double arr[], int size)
{
  int gap = size;
  bool swapped = true;

  while(gap != 1 || swapped == true)
  {
    gap = getGap(gap);
    swapped = false;
    for(int i = 0; i < size - gap; i++)
    {
      if(arr[i] > arr[i+gap])
      {
        swap(&arr[i], &arr[i+gap]);
        swapped = true;
      }
    }
  }
}
