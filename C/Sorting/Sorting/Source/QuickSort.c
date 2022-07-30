//
//  QuickSort.c
//  Sorting
//
//  Created by 오승기 on 2022/07/31.
//

#include "QuickSort.h"
#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int first, int second)
{
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

int Partition(int arr[], int left, int right)
{
  int pivot = arr[left];
  int low = left+1;
  int high = right;

  while(low <= high) {
    while(pivot >= arr[low] && low <= right) {
      low++;
    }

    while(pivot <= arr[high] && high >= (left+1)) {
      high--;
    }

    if(low <= high) {
      Swap(arr, low, high);
    }
  }

  Swap(arr, left, high);
  return high;
}

void QuickSort(int arr[], int left, int right)
{
  if(left<=right) {
    int pivot = Partition(arr, left, right);
    QuickSort(arr, left, pivot - 1);
    QuickSort(arr, pivot + 1, right);
  }
}
