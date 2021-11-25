#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    insertion_sort(int *array, int numb_elements)
{
    int i;
    int    value;
    int hole;
    int num_operations;

    i = 0;
    num_operations = 0;
    for (i = 0; i < numb_elements; i++)
    {
        value = array[i];
        hole = i;
        while (hole > 0 && array[hole - 1] > value)
        {
            array[hole] = array[hole - 1];
            hole -= 1;
            num_operations++;
        }
        array[hole] = value;
    }
    printf("Number operations = %d\n", num_operations);
}

int    main(void)
{
    int array[] = {7, 5, 4, 3, 2, 1};
    int i;

    i = 0;    
    for (i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    insertion_sort(array, 6);

    i = 0;
    for (i = 0; i < 6; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}