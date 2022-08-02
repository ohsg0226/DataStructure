//
//  Person.h
//  Table
//
//  Created by 오승기 on 2022/08/02.
//

#ifndef Person_h
#define Person_h

#define STR_LEN 50

typedef struct _person
{
  int ssn;
  char name[STR_LEN];
  char addr[STR_LEN];
} Person;

int GetSSN(Person *p);
void ShowPersonInfo(Person *p);
Person *MakePersonData(int ssn, char *name, char *addr);

#endif /* Person_h */
