#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int *randomArray(int n)
{
    int *array = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }

    return array;
}

int *ascendingArray(int n)
{
    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        array[i] = i;
    }

    return array;
}

int *descendingArray(int n)
{
    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        array[i] = n - i - 1;
    }

    return array;
}

void bubbleSort(int array[], int n)
{
    clock_t start_time = clock();
    int temp;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Bubble Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

void improvedBubbleSort(int array[], int n)
{
    clock_t start_time = clock();
    int temp, swapped = 1;
    for (int j = 0; (j < n - 1) && swapped; j++)
    {
        swapped = 0;
        for (int i = 0; i < n - j - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swapped = 1;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Improved Bubble Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

int partitionStart(int array[], int start, int end)
{
    int pivot = array[start];
    int low = start + 1;
    int high = end;

    while (1)
    {
        while (low <= high && array[low] <= pivot)
        {
            low++;
        }
        while (low <= high && array[high] > pivot)
        {
            high--;
        }
        if (low <= high)
        {
            int temp = array[low];
            array[low] = array[high];
            array[high] = temp;
        }
        else
        {
            break;
        }
    }

    int temp = array[start];
    array[start] = array[high];
    array[high] = temp;
    return high;
}

void quickSortStart(int array[], int start, int end)
{
    while (start < end)
    {
        int pivot = partitionStart(array, start, end);

        if (pivot - start < end - pivot)
        {
            quickSortStart(array, start, pivot - 1);
            start = pivot + 1;
        }
        else
        {
            quickSortStart(array, pivot + 1, end);
            end = pivot - 1;
        }
    }
}

void quickSortStartWithTime(int array[], int start, int end)
{
    clock_t start_time = clock();
    quickSortStart(array, start, end);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Quick Sort with start pivot: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

int partitionMiddle(int array[], int start, int end)
{
    int pivot = array[(start + end) / 2];
    int i = start - 1;
    int j = end + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void quickSortMiddle(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = partitionMiddle(array, start, end);
        quickSortMiddle(array, start, pivot);
        quickSortMiddle(array, pivot + 1, end);
    }
}

void quickSortMiddleWithTime(int array[], int start, int end)
{
    clock_t start_time = clock();
    quickSortMiddle(array, start, end);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Quick Sort with middle pivot: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

void insertionSort(int array[], int n)
{
    clock_t start_time = clock();
    int temp, i;
    for (int k = 1; k < n; k++)
    {
        temp = array[k];
        for (i = k - 1; i >= 0 && array[i] > temp; i--)
        {
            array[i + 1] = array[i];
        }
        array[i + 1] = temp;
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Insertion Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

int *generateIncrement2k1(int n, int *numIncrements)
{
    int maxIncrement = 1;
    int numIncrementsValue = 0;

    while (maxIncrement < n)
    {
        maxIncrement = 2 * maxIncrement + 1;
        numIncrementsValue++;
    }

    int *increments = (int *)malloc(numIncrementsValue * sizeof(int));

    maxIncrement = (maxIncrement - 1) / 2;
    for (int i = 0; i < numIncrementsValue; i++)
    {
        increments[i] = maxIncrement;
        maxIncrement = (maxIncrement - 1) / 2;
    }

    *numIncrements = numIncrementsValue;
    return increments;
}

void shellSort(int array[], int n, int increments[], int numIncrements)
{
    clock_t start_time = clock();
    int span, temp, k;
    for (int inc = 0; inc < numIncrements; inc++)
    {
        span = increments[inc];
        for (int j = span; j < n; j++)
        {
            temp = array[j];
            for (k = j - span; k >= 0 && array[k] > temp; k -= span)
            {
                array[k + span] = array[k];
            }
            array[k + span] = temp;
        }
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Shell Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

void selectionSort(int array[], int n)
{
    clock_t start_time = clock();
    int i, j, min, index;
    for (i = 0; i < n - 1; i++)
    {
        min = array[i];
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                index = j;
            }
        }
        int temp = array[i];
        array[i] = min;
        array[index] = temp;
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Selection Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

void heapify(int array[], int n, int index)
{
    int largest, left, right;
    largest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{
    clock_t start_time = clock();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Heap Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}

void merge(int *array, int start, int middle, int end)
{
    int size1 = middle - start + 1;
    int size2 = end - middle;

    int left[size1], right[size2];

    for (int i = 0; i < size1; i++)
    {
        left[i] = array[start + i];
    }
    for (int j = 0; j < size2; j++)
    {
        right[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, k = start;

    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int start, int end)
{
    int middle;
    if (start < end)
    {
        middle = (start + end) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

void mergeSortWithTime(int *array, int start, int end)
{
    clock_t start_time = clock();
    mergeSort(array, start, end);
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\t\t\t\tTime elapsed for Merge Sort: %lf seconds\n", elapsed_time);
    printf("Clocks per second: %d\n", CLOCKS_PER_SEC);
}
