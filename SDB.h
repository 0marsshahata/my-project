#ifndef SDB_H
#define SDB_H

#include <stdio.h>
#include "STD.h"

typedef struct SimpleDb {
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} SimpleDb;

bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint32 id, uint32 year, uint32 course1_id, uint32 course1_grade, uint32 course2_id, uint32 course2_grade, uint32 course3_id, uint32 course3_grade);
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id, SimpleDb* student);
void SDB_GetList(uint8* count, uint32* list);
bool SDB_IsIdExist(uint32 id);

#endif
