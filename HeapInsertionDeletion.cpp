#include <iostream>

using namespace std;
class MaxHeap
{
    int *arr;
    int currSize;
    int totalSize;

public:
    // *****************************consustructor *****************************************
    MaxHeap(int n) // n is total size
    {
        arr = new int[totalSize];
        totalSize = n;
        currSize = 0;
    }
    // **************************************code for deletion **************************************************

    // insert into max heap
    void insert(int value)
    {
        if (currSize == totalSize)
            cout << "Heap overflow\n";
        else
        {
            arr[currSize] = value;
            int index = currSize;
            currSize++;
            // code for swap
            while ((arr[index] > arr[(index - 1) / 2]) && index > 0)
            {

                swap(arr[index], arr[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
    }

    // **************************************code for deletion **************************************************
    void DeleteElement()
    {

        if (currSize == 0)
        {
            cout << "there is no element to delete\n"
                 << endl;
            return;
        }
        // delete element  replecement
        arr[0] = arr[currSize - 1];
        --currSize;
        if (currSize == 0)
            return;

        // heapify
        int index = 0;
        while (((2 * index + 2) <= currSize || (2 * index + 1) <= currSize)) // for checking size condition 
        {

            if (arr[2 * index + 1] > arr[2 * index + 2])
            { // swap greater element
                swap(arr[index], arr[2 * index + 1]);
                index = 2 * index + 1;
            }

            else
            {
                // swap greater element
                swap(arr[index], arr[2 * index + 2]);
                index = 2 * index + 2;
            }
        }
    }
    // print element
    void print()
    {
        for (int i = 0; i < currSize; i++)
            cout << arr[i] << endl;
    }
};
int main()
{
    MaxHeap H(9);
    // insert element
    H.insert(30);
    H.insert(40);
    H.insert(50);
    H.insert(60);
    H.insert(70);
    H.insert(70);
    H.insert(70);
    H.insert(20);
    // delete
    H.DeleteElement();
    H.DeleteElement();
    H.print(); // print element
}
