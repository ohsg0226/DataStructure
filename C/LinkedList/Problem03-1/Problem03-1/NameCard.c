//
//  NameCard.c
//  Problem03-1
//
//  Created by 오승기 on 2022/08/04.
//

#include "NameCard.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NameCard *MakeNameCard(char *name, char *phone)
{
  NameCard *newNameCard = (NameCard *)malloc(sizeof(NameCard));
  strcpy((newNameCard -> name), name);
  strcpy((newNameCard -> phone), phone);
  
  return newNameCard;
}

void ShowNameCardInfo(NameCard *pcard)
{
  printf("이름: %s\n", pcard -> name);
  printf("전화번호: %s\n", pcard -> phone);
}

int NameCompare(NameCard *pcard, char *name)
{
  return strcmp(pcard -> name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone)
{
  strcpy(pcard -> phone, phone);
}
