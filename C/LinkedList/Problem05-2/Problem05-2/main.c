//
//  main.c
//  Problem05-2
//
//  Created by 오승기 on 2022/08/05.
//

#include <stdio.h>
#include "DoublyLinkedList.h"

int main(void)
{
  List list;
  int data;
  ListInit(&list);

  // 8∞≥¿« µ•¿Ã≈Õ ¿˙¿Â ///////
  LInsert(&list, 1);  LInsert(&list, 2);
  LInsert(&list, 3);  LInsert(&list, 4);
  LInsert(&list, 5);  LInsert(&list, 6);
  LInsert(&list, 7);  LInsert(&list, 8);

  // ¿˙¿Âµ» µ•¿Ã≈Õ¿« ¡∂»∏ ///////
  if(LFirst(&list, &data))
  {
    printf("%d ", data);

    while(LNext(&list, &data))
      printf("%d ", data);
    
    printf("\n");
  }

  // 2¿« πËºˆ ¿¸∫Œ ªË¡¶ ///////
  if(LFirst(&list, &data))
  {
    if(data%2 == 0)
      LRemove(&list);

    while(LNext(&list, &data))
    {
      if(data%2 == 0)
        LRemove(&list);
    }
  }

  // ¿˙¿Âµ» µ•¿Ã≈Õ¿« ¿Á ¡∂»∏ ///////
  if(LFirst(&list, &data))
  {
    printf("%d ", data);

    while(LNext(&list, &data))
      printf("%d ", data);
    
    printf("\n\n");
  }

  return 0;
}
