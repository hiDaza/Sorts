#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen()
{
    system("cls");
}

int main()
{
    int quit = 0;

    while (!quit)
    {
        int size;
        int *array;

        clearScreen();
        setConsoleColor(10);

        printf("Welcome to the sorting program!\n");
        printf("Please wait while the program loads...\n");
        Sleep(2000);
        clearScreen();

        setConsoleColor(10);

        printf("Choose the size of the array: \n");
        printf("1 - Size 1000\n");
        printf("2 - Size 5000\n");
        printf("3 - Size 10,000\n");
        printf("4 - Size 15,000\n");
        printf("5 - Size 100,000\n");
        printf("6 - Size 500,000\n");

        int sizeOption;
        scanf("%d", &sizeOption);

        switch (sizeOption)
        {
        case 1:
            size = 1000;
            break;
        case 2:
            size = 5000;
            break;
        case 3:
            size = 10000;
            break;
        case 4:
            size = 15000;
            break;
        case 5:
            size = 100000;
            break;
        case 6:
            size = 500000;
            break;
        default:
            printf("Invalid size option!\n");
            return 1;
        }

        printf("Choose the type of array:\n");
        printf("1 - Random\n");
        printf("2 - Ascending Order\n");
        printf("3 - Descending Order\n");

        int arrayTypeOption;
        scanf("%d", &arrayTypeOption);

        switch (arrayTypeOption)
        {
        case 1:
            array = randomArray(size);
            break;
        case 2:
            array = ascendingArray(size);
            break;
        case 3:
            array = descendingArray(size);
            break;
        default:
            printf("Invalid array type option!\n");
            return 1;
        }

        printf("Choose the sorting method: \n");
        printf("1 - Bubble Sort\n");
        printf("2 - Improved Bubble Sort\n");
        printf("3 - Quick Sort\n");
        printf("4 - Insertion Sort\n");
        printf("5 - Shell Sort\n");
        printf("6 - Selection Sort\n");
        printf("7 - Heap Sort\n");
        printf("8 - Merge Sort\n");
        printf("9 - Exit\n");

        int sortOption;
        scanf("%d", &sortOption);

        switch (sortOption)
        {
        case 1:
            printf("\t\t\t\t Loading...\n");
            bubbleSort(array, size);
            break;
        case 2:
            printf("\t\t\t\t Loading...\n");
            improvedBubbleSort(array, size);
            break;
        case 3:
            printf("Choose the pivot position: \n");
            printf("1 - Beginning\n");
            printf("2 - Middle\n");
            int pivotOption;
            scanf("%d", &pivotOption);
            switch (pivotOption)
            {
            case 1:
                printf("\t\t\t\t Loading...\n");
                quickSortStart(array, 0, size - 1);
                break;
            case 2:
                printf("\t\t\t\t Loading...\n");
                quickSortMiddle(array, 0, size - 1);
                break;
            }
            break;
        case 4:
            printf("\t\t\t\t Loading...\n");
            insertionSort(array, size);
            break;
        case 5:
            printf("Choose the increment sequence for Shell Sort: \n");
            printf("1 - Sequence 2^k-1\n");
            int incrementOption;
            scanf("%d", &incrementOption);
            int *increments;
            int numIncrements;

            switch (incrementOption)
            {
            case 1:
                increments = generateIncrement2k1(size, &numIncrements);
                break;
            default:
                printf("Invalid increment sequence option!\n");
                free(array);
                return 1;
            }
            printf("\t\t\t\t Loading...\n");
            shellSort(array, size, increments, numIncrements);
            free(increments);
            break;
        case 6:
            printf("\t\t\t\t Loading...\n");
            selectionSort(array, size);
            break;
        case 7:
            printf("\t\t\t\t Loading...\n");
            heapSort(array, size);
            break;
        case 8:
            printf("\t\t\t\t Loading...\n");
            mergeSort(array, 0, size - 1);
            break;
        case 9:
            quit = 1;
            break;
        default:
            printf("Invalid sorting option!\n");
            free(array);
            return 1;
        }

        setConsoleColor(10);

        /* printf("Sorted array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        */
        setConsoleColor(7);
        system("pause");
        free(array);

        if (!quit)
        {
            printf("\n Press Enter to continue...");
            getchar();
        }
    }
}
