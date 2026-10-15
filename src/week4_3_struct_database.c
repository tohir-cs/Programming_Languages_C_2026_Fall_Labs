/*
 * week4_3_struct_database.c
 * Author: Tokhirbek Akramov
 * Student ID: 251ADB079
 * Description:
 *   Demonstrates dynamic memory allocation for an array of structs.
 *   Reads student records from user input, displays them in a formatted
 *   table, and properly frees the allocated memory.
 */

#include <stdio.h>
#include <stdlib.h>

// student's structure
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;

  // asking amount of students
  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  // allocating memory for array of structs
  struct Student* students =
      (struct Student*)malloc((size_t)n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // 3.Reading each student's information
  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);
    if (scanf("%49s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      printf("Invalid input.\n");
      free(students);
      return 1;
    }
  }

  // 4. empty row and table header
  printf("\n");
  printf("%-6s %-11s %s\n", "ID", "Name", "Grade");

  // 5. displaying each row in a table format
  for (int i = 0; i < n; i++) {
    printf("%-6d %-11s %.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  // 6. clear history
  free(students);
  return 0;
}