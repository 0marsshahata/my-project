#include <stdio.h>
#include "STD.h"
#include "SDB.h"
#define  MAX_STUDENTS 10



void SDB_APP() {
    uint8 choice;
    SDB_action(choice);
}
void SDB_APP();
void SDB_action(uint8 choice);
void SUB_APP ()
{


  printf("To add entry, enter 1\n");
   printf("To get used size in database, enter 2\n");
    printf("To read student data, enter 3\n");
      printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
          printf("To delete student data, enter 6\n");
            printf("To check is database is full, enter 7\n");
              printf("To exit enter 0\n ");

do {
        scanf("%d", &choice);
        SDB_action(choice);
    } while (choice != 0);

}

void SDB_action(uint8 choice)
{
     uint32 id, year, course1_id, course1_grade, course2_id, course2_grade, course3_id, course3_grade;
    uint8 count;
    uint32 list[MAX_STUDENTS];
    SimpleDb student;

switch (choice) {

case 1:
printf("Enter student ID, year, course1 ID, course1 grade, course2 ID, course2 grade, course3 ID, course3 grade:\n");
scanf("%d %d %d %d %d %d %d %d", &id, &year, &course1_id, &course1_grade, &course2_id, &course2_grade, &course3_id, &course3_grade);

if (SDB_AddEntry(id, year, course1_id, course1_grade, course2_id, course2_grade, course3_id, course3_grade)) {
printf("Entry added successfully.\n");
}
 else {
printf("Failed to add entry. Database might be full or data is incorrect.\n");
}
break;

case 2:
printf("Used size in database: %u\n", SDB_GetUsedSize());
break;

case 3:
printf("Enter student ID to read data:\n");
scanf("%u", &id);

if (SDB_ReadEntry(id, &student)) {
printf("Student ID: %d\n", student.Student_ID);
printf("Student year: %d\n", student.Student_year);
printf("Course1 ID: %d, Course1 grade: %u\n", student.Course1_ID, student.Course1_grade);
printf("Course2 ID: %d, Course2 grade: %u\n", student.Course2_ID, student.Course2_grade);
printf("Course3 ID: %d, Course3 grade: %u\n", student.Course3_ID, student.Course3_grade);
}
 else {
        printf("Student ID not found.\n");
}
break;

case 4:
SDB_GetList(&count, list);
printf("List of student IDs:\n");

for (uint8 i = 0; i < count; i++) {
printf("%d", list[i]);
}
printf("\n");
break;

case 5:
printf("Enter student ID to check existence:\n");
scanf("%d", &id);

if (SDB_IsIdExist(id)) {
printf("Student ID exists.\n");
}
 else {
printf("Student ID not found.\n");
}
break;

case 6:
printf("Enter student ID to delete:\n");
scanf("%d", &id);
SDB_DeletEntry (id);
printf("Student data deleted if ID existed.\n");
break;

case 7:
if (SDB_IsFull())
{
printf("Database is full.\n");
}
 else {
printf("Database is not full.\n");
}
break;

case 0:
printf("Exiting...\n");
break;

default:
printf("Invalid choice. Please try again.\n");
break;
}
    return 0;


}



