//
//  MergeSort.c
//  Sorting
//
//  Created by 오승기 on 2022/07/31.
//

#include "MergeSort.h"
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
  int frontIdx = left;
  int rearIdx = mid + 1;
  int i;
  
  int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
  int idx = left;

  while(frontIdx <= mid && rearIdx <= right) {
    if(arr[frontIdx] <= arr[rearIdx]) {
      sortArr[idx] = arr[frontIdx];
      frontIdx++;
    } else {
      sortArr[idx] = arr[rearIdx];
      rearIdx++;
    }
    idx++;
  }
  
  if(frontIdx > mid) {
    for(i = rearIdx; i<=right; i++) {
      sortArr[idx] = arr[i];
      idx++;
    }
  } else {
    for(i = frontIdx; i<=mid; i++) {
      sortArr[idx] = arr[i];
      idx++;
    }
  }
  
  for(i=left; i<=right; i++) {
    arr[i] = sortArr[i];
  }
  
  free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
  int mid;
  
  if(left < right) {
    mid = (left + right) / 2;
    
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    
    MergeTwoArea(arr, left, mid, right);
  }
}
