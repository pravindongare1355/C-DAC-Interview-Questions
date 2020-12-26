#include <iostream>
using namespace std;

void bubbleSort( int * arr, int size ) {
    
    if( size <= 1 ) {
        return;
    }
    
    int passes = size  - 1;
    int comps = size  - 1;
 
    for( int i = 0; i < passes; i++ ) {
        
        int count = 0;
        
        for( int j = 0; j < (comps - i); j++  ) {
            
            if( arr[j] > arr[j+1] ) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                count++;
            }
            
        }
        
        if( count == 0 ) {
            cout<<"passes = "<<i+1<<endl;
            return;
        }
        
    }
    
}

void selectionSort( int * arr, int size ) {
    if( size <= 1 ) {
        return;
    }
    
    for( int i = 0; i < size; i++ ) {
        
        int min = i;
        
        for( int  j = min+1; j < size; j++ ) {
            if( arr[j] < arr[min]) {
                min = j;
            }
        }
        
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        
    }
}

void insertionSort( int * arr, int size ) {
    
    for( int i = 0; i < size; i++ ) {
        
        for( int j = 0; j < i ; j++) {
            
            if( arr[i] < arr[j] ) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
    }
    
}

void quickSort( int * arr, int left, int right ) {
    
    if( left >= right ) {
        return;
    }
    
    int oldLeft = left, oldRight = right;
    
    int pivot = arr[left];
    
    while ( left != right ) {
        
        while( arr[right] > pivot && left != right ) {
            right--;
        }
    
        if( left != right ) {
            arr[left] = arr[right];
            left++;
        }
    
        while( arr[left] < pivot && left != right ) {
            left++;
        }
    
        if( left != right ) {
            arr[right] = arr[left];
            right--;
        }
    }
    
    arr[left] = pivot;
    
    quickSort(arr, oldLeft , right-1 ); // left part
    quickSort(arr, left+1, oldRight ); // right part
}

int temp[100];

void merge( int * arr, int leftStart, int leftEnd, int rightStart, int rightEnd ) {
    
    int tempPos = leftStart;
    int numEle = rightEnd - leftStart + 1;
    
    while( leftStart <= leftEnd && rightStart <= rightEnd ) {
        if( arr[leftStart] < arr[rightStart] ) {
            temp[tempPos] = arr[leftStart];
            leftStart++;
            tempPos++;
        }
        else {
            temp[tempPos] = arr[rightStart];
            rightStart++;
            tempPos++;
        }
    }
    
    while( leftStart <= leftEnd ) {
        temp[tempPos] = arr[leftStart];
        leftStart++;
        tempPos++;
    }
    
    while( rightStart <= rightEnd ) {
        temp[tempPos] = arr[rightStart];
        rightStart++;
        tempPos++;
    }
    
    
    for( int i = 1; i <= numEle; i++ ) {
        arr[rightEnd] = temp[rightEnd];
        rightEnd--;
    }
}

void mergeSort( int * arr, int left, int right ) {
    
    if( left == right ) {
        return;
    }
    
    int mid = ( left + right ) / 2;
    mergeSort( arr, left, mid );
    mergeSort( arr, mid + 1, right );
    
    merge( arr, left, mid, mid+1, right );
    
}





































