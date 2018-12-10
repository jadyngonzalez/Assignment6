#ifndef SORTER_H
#define SORTER_H

class Sorter
{
  public:
    Sorter();
    ~Sorter();
    Sorter(std::string file);
    void sort();
  private:
    int numElements;
    std::string fileName;
    double *bArr;
    double *iArr;
    double *qArr;
    double *rArr;

    void swap(double *x, double *y);
    void print(double arr[], int size);

    void bubbleSort(double arr[], int size);
    void insertionSort(double arr[], int size);

    int pivot(double arr[], int l, int h);
    void quickSort(double arr[], int l, int h);

    int getGap(int gap);
    void combSort(double arr[], int size);
};
#endif
