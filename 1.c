#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int calibrate(char * line)
{
    int number = 0;
    int arr[] = {0, 0};
    char * index = NULL;
    bool isFirst = false;
    int count = 0;
    for (index = line; *index != '\n'; index++)
    {
        if (isdigit(*index) && isFirst == false)
        {
            arr[0] = *index - '0';  // ascii trick?
            isFirst = true;
            count++;
            continue;
        }
        if (isdigit(*index))
        {
            arr[1] = *index - '0';  // ascii trick?
            count++;
        }
    }
    printf("There were %d numbers in %s\n", count, line);
    if(count == 1)
    {
        arr[1] = arr[0];
    }
    number = arr[0] * 10 + arr[1];
    return number;
}
int main(int argc, char * argv[])
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int summation = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        summation += calibrate(line);
    }
    printf("Total: %d\n", summation);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}