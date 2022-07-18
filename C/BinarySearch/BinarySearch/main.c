//
//  main.c
//  BinarySearch
//
//  Created by 오승기 on 2022/07/18.
//

#include <stdio.h>

int BinarySearch(int arr[], int len, int target);

int main(int argc, const char * argv[]) {
  int arr[] = {1, 3, 5, 7, 9};
  int idx;
  
  //찾고자하는 값이 있는 경우
  idx = BinarySearch(arr, sizeof(arr) / sizeof(int), 7);
  if(idx == -1) {
    printf("실패");
  } else {
    printf("index = %d, value = %d\n", idx, arr[idx]);
  }
  
  //찾고자하는 값이 없는 경우
  idx = BinarySearch(arr, sizeof(arr) / sizeof(int), 4);
  if(idx == -1) {
    printf("실패");
  } else {
    printf("index = %d, value = %d\n", idx, arr[idx]);
  }
  
  return 0;
}

int BinarySearch(int arr[], int len, int target)
{
  int start = 0;
  int last = len - 1;
  int mid;
  
  while(start<=last) {
    mid = (start + last) / 2;
    
    if(target == arr[mid]) {
      return mid;
    } else {
      if(target < arr[mid]) {
        last = mid - 1;
      } else {
        start = mid + 1;
      }
    }
  }
  return -1;
}

