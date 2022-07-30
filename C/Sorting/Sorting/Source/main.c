//
//  main.c
//  Sorting
//
//  Created by 오승기 on 2022/07/31.
//

#include <stdio.h>
#include "MergeSort.h"
#include "QuickSort.h"

void BubbleSort(int arr[], int n)
{
  int i, j;
  int temp;
  
  for(i=0;i<n-1;i++) {
    for(j=0;j<(n-i)-1;j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void SelectSort(int arr[], int n)
{
  int i, j;
  int maxIdx;
  int temp;
  
  for(i = 0; i<n-1; i++) {
    maxIdx = i;
    
    for(j=i+1; j<n; j++) {
      if(arr[j] < arr[maxIdx]) {
        maxIdx = j;
      }
    }
    
    temp = arr[i];
    arr[i] = arr[maxIdx];
    arr[maxIdx] = temp;
  }
}

void InsertSort(int arr[], int n)
{
  int i, j;
  int insertData;
  
  for(i = 1; i<n; i++) {
    insertData = arr[i];
    for(j=i-1; j>=0; j--) {
      if(arr[j] > insertData) {
        arr[j+1] = arr[j];
      } else {
        break;
      }
      
    }
    arr[j+1] = insertData;
  }
}

int main(int argc, const char * argv[]) {
  int arr[4] = {3,2,4,1};
  int i;
  
//  BubbleSort(arr, sizeof(arr)/sizeof(int));
//  SelectSort(arr, sizeof(arr)/sizeof(int));
//  InsertSort(arr, sizeof(arr)/sizeof(int));
//  MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
  QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
  
  for(i=0;i<4;i++) {
    printf("%d", arr[i]);
  }
  return 0;
}
