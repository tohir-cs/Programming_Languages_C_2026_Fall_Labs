// week5_task1_file_io.c
// Name: Tokhirbek  Surname: Akramov  Student ID: 251ADB079
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) 
{
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    // BONUS: if a file name was given on the command line (argc > 1), use argv[1] instead.
    if (argc > 1) 
    {
        filename = argv[1];
    }

    // 1. Print "Writing lines to <filename>..." and open the file for writing (mode "w")
    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");

    // 2. Check that fp is not NULL. If it is: perror(filename); return EXIT_FAILURE;
    if (fp == NULL) 
    {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 3. Write 2–3 lines of text to the file using fprintf()
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    // 4. Close the file with fclose()
    fclose(fp);

    // 5. Open the file again for reading (mode "r") and check for NULL again
    fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 6. Print "Reading contents:" and use fgets() in a loop to print each line
    printf("Reading contents:\n");
    while (fgets(line, sizeof(line), fp) != NULL) 
    {
        printf("%s", line);
        line_count++;
    }

    // 7. Close the file
    fclose(fp);

    // BONUS: print total lines read
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}