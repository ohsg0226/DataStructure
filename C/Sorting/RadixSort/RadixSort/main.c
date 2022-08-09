//
//  main.c
//  RadixSort
//
//  Created by 오승기 on 2022/08/09.
//

#include <stdio.h>
#include "LSD.h"

int main(int argc, const char * argv[]) {
  int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

  int len = sizeof(arr) / sizeof(int);
  int i;

  RadixSort(arr, len, 5);

  for(i=0; i<len; i++)
    printf("%d ", arr[i]);

  printf("\n");
  return 0;
}
