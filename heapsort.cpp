// heap sort
#include <iostream>
using namespace std;
                                                                         // HeapifYMethod
void HeapifY(int *arr, int size, int i)
{
    int Largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    while (left < size - 1)
    {

        if (arr[Largest] < arr[right] || arr[Largest] < arr[left])
        {
            if (arr[left] > arr[right])
            {

                swap(arr[Largest], arr[left]);
                Largest = left;
            }

            else
            {
                swap(arr[Largest], arr[right]);
                Largest = right;
            }
        }
        else
            break;
        left = 2 * Largest + 1;
        right = 2 * Largest + 2;
    }
}

                                                                                                    // build Heap
void BuildHeap(int *arr, int size)
{
    for (int i = (size / 2 - 1); i >= 0; i--)
    {
        HeapifY(arr, size, i);
    }
}

                                                                                           // Heap sort
void HeapSort(int *arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        HeapifY(arr, i, 0);
    }
} 
 ////////                                                   print Heap
void printHeap(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {34, 5, 53, 4, -23, 6, 800, 67, 98, -54, 200};
    BuildHeap(arr, 11);
    HeapSort(arr,11);
    printHeap(arr, 11);
}
