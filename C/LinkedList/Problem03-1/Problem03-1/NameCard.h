//
//  NameCard.h
//  Problem03-1
//
//  Created by 오승기 on 2022/08/04.
//

#ifndef NameCard_h
#define NameCard_h

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct _namecard
{
  char name[NAME_LEN];
  char phone[PHONE_LEN];
} NameCard;

NameCard *MakeNameCard(char *name, char *phone);
void ShowNameCardInfo(NameCard *pcard);
int NameCompare(NameCard *pcard, char *name);
void ChangePhoneNum(NameCard *pcard, char *phone);

#endif /* NameCard_h */
