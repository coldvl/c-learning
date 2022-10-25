#include <stdio.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main() {
    int i, j, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    //enter array elements
    for(i=0; i < n; i++) {
        printf("Enter element #%d: ",i+1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printArray(arr, n);
    printf("Alone has been found:");
    for(i=0; i < (n/2); i++) {
        if (arr[2*i]!=arr[2*i+1])
        printf("%d\n", arr[2*i]);
        break;
    }
    

    if (arr[n-1]!=arr[n-2]) {
        printf("%d\n", arr[n-1]);
    }
    


    
    
}