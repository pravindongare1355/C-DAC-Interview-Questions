#include "Header.h"

int main(int argc, const char * argv[]) {

    int arr[] = { 40, 12, 56, 43, 23, 67, 8, 55, 91, 25, 12   };
    
    //bubbleSort( arr, 10 );
    //selectionSort(arr, 10);
    //insertionSort( arr, 11 );
    //quickSort(arr, 0, 10);
    
    mergeSort(arr, 0, 10);
    
    for( int i = 0; i < 11; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
