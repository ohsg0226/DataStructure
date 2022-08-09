//
//  LSD.c
//  RadixSort
//
//  Created by 오승기 on 2022/08/09.
//

#include <stdio.h>
#include "LSD.h"

void RadixSort(int arr[], int num, int maxLen)
{
  int  divfac = 1;
  int radix;
  
  Queue buckets[BUCKET_NUM];
  
  for(int bi=0; bi<BUCKET_NUM; bi++) {
    QueueInit(&buckets[bi]);
  }
  
  for(int pos=0; pos<maxLen; pos++) {
    for(int di=0; di<num; di++) {
      radix = (arr[di] / divfac) % 10;
      
      Enqueue(&buckets[radix], arr[di]);
    }
    
    for(int bi=0, di=0; bi<BUCKET_NUM; bi++) {
      while(!QIsEmpty(&buckets[bi])) {
        arr[di++] = Dequeue(&buckets[bi]);
      }
    }

    divfac *= 10;
  }
}

