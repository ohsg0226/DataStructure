//
//  main.c
//  Recursion
//
//  Created by 오승기 on 2022/07/18.
//

#include <stdio.h>

int BinarySearchRecursion(int arr[], int start, int last, int target);

int main(int argc, const char * argv[]) {
  int arr[] = {1, 3, 5, 7 ,9};
  int idx;
  
  //탐색 성공
  idx = BinarySearchRecursion(arr, 0, sizeof(arr)/sizeof(int) - 1, 7);
  
  if(idx == -1) {
    printf("탐색 실패");
  } else {
    printf("Index = %d, Value = %d", idx, arr[idx]);
  }
  
  //탐색 실패
  idx = BinarySearchRecursion(arr, 0, sizeof(arr)/sizeof(int) -1, 8);

  if(idx == -1) {
    printf("탐색 실패");
  } else {
    printf("Index = %d, Value = %d", idx, arr[idx]);
  }
  
  return 0;
}

int BinarySearchRecursion(int arr[], int start, int last, int target)
{
  int mid;
  
  if(start > last) { return -1; }
  
  mid = (start + last) / 2;
  
  if(arr[mid] == target) { return mid;
  } else if(target < arr[mid]) {
    return BinarySearchRecursion(arr, start, mid - 1 , target);
  } else {
    return  BinarySearchRecursion(arr, mid + 1, last, target);
  }
}
