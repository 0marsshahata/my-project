#include "SDB.h"
#include "STD.h"

#define MAX_STUDENTS 10

SimpleDb array_s[MAX_STUDENTS];
int num_st = 0;

bool SDB_IsFull() {
    return num_st == MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() {
    return num_st;
}
bool SDB_AddEntry(uint32 id, uint32 year,
uint32 course1_id, uint32 course1_grade,
uint32 course2_id, uint32 course2_grade,
uint32 course3_id, uint32 course3_grade)
{array_s [num_st].Student_ID=id;

array_s [num_st].Student_year=year;

array_s [num_st].Course1_grade=course1_grade;
array_s [num_st].Course1_ID=course1_id;

array_s[num_st].Course2_grade=course2_grade;
array_s [num_st].Course2_ID=course2_id;

array_s [num_st].Course3_grade=course3_grade;
array_s [num_st].Course2_ID=course2_id;
num_st++;
return true;
}
void SDB_DeletEntry (uint32 id)
{
for (uint8 i = 0; i < num_st; i++) {
if (array_s[i].Student_ID == id) {
for (uint8 j = i; j < num_st - 1; j++) {
array_s[j] = array_s[j + 1];
}
num_st--;
break;
        }
    }
return true;
}
bool SDB_ReadEntry(uint32 id, SimpleDb* student) {
    for (uint8 i = 0; i < num_st; i++) {


        if (array_s[i].Student_ID == id) {
*student = array_s[i];
return true;
}
}

return false;
}

void SDB_GetList (uint8 * count, uint32 * list)
{
*count = num_st;
for (uint8 i = 0; i < num_st; i++) {
list[i] = array_s[i].Student_ID;
}
}
bool SDB_IsIdExist (uint32 id)
{
for (uint8 i = 0; i < num_st; i++) {
if (array_s[i].Student_ID == id) {
return true;
}
}
return false;
}


void SDB_APP() {
    uint8 choice;
    SDB_action(choice);
}
