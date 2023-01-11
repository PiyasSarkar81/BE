#include<stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)          
{
    int i;
    for (i = 0; i < n; i++)                
        printf("%d ", arr[i]);
    printf("\n");         
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1; 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
	printArray(arr,n);
    }
    printf("\n");
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    printf("Stapes in selection sort\n");
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
	printArray(arr,n);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    printf("Stapes in Bubble sort\n");
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
	{
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
	    printArray(arr,n);
	}
    }	    
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    int i= (low - 1),j;
    for ( j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
	
    }
    swap(&arr[i + 1], &arr[high]);
    printArray(arr,n);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int n)
{
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

void merge(int arr[], int l, int m, int r, int n)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    printArray(arr,n);
}

void mergeSort(int arr[], int l, int r, int n)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n); 
        merge(arr, l, m, r, n);
    }
}
void heapify(int arr[], int N, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest, n);
    }
    printArray(arr,n);
}

void heapSort(int arr[], int N, int n)
{
    int i;
    for ( i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i, n);
    for ( i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, n);
    }
}

int main(){
    int n,i,choice;
    
    printf("Enter the number of elements.\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements.\n");
    for ( i = 0; i < n; i++)
        {
        	scanf("%d",&arr[i]);
    	}
    while(1)
    {
        printf("\n1.Insertion sort.\n");
        printf("2.Selection sort.\n");
        printf("3.Bubble sort.\n");
        printf("4.Quick sort.\n");
        printf("5.Merge sort.\n");
        printf("6.Heap sort.\n");
        printf("7.Quit.\n");
        printf("\nEnter your choice.\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
	    printf("Stapes :");
            insertionSort(arr,n);
            printf("Insertion sorted array :\n");
            printArray(arr,n);
            break;
        
        case 2:
            selectionSort(arr,n);
	    printf("Selection sorted array :\n");
            printArray(arr,n);
            break;

        case 3:
            bubbleSort(arr, n);
	    printf("Bubble sorted array :\n");
            printArray(arr,n);
            break;

        case 4:
	    printf("stapes in quick sort.\n");
            quickSort(arr, 0, n, n);
	    printf("Quick sorted array :\n");
            printArray(arr,n);
            break;
        
        case 5:
	    printf("stapes of merge sort.\n");
            mergeSort(arr,0,n,n);
	    printf("Merge sorted array :\n");
            printArray(arr,n);
            break;

        case 6:
	    printf("stapes of heap sort.\n");
            heapSort(arr,n,n);
	    printf("Heap sorted array :\n");
            printArray(arr,n);
            break;

        case 7:
            exit(1);
            break;

        default:
            break;
        }
    }
    
    return 0;
}
