#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void capture();
int get_month();
int get_day();
int get_year();
int day_of_week(int day, int month, int year);
void print_result(int n);
bool continue_calculations();

int main()
{
    // Initial data

    int day = 0;
    int month = 0;
    int year = 0;

    // Title and author

    capture();

    // Get initial data

    do
    {
        do
        {
            day = get_day();
        } 
        while (day == -1);

        do
        {
            month = get_month();
        } 
        while (month == -1);

        do
        {
            year = get_year();
        } 
        while (year == -1);

        // Get day of week

        int n  = day_of_week(day, month, year);

        print_result(n);
    } 
    while (continue_calculations());

    return 0;
}

void capture()
{
    // Author

    printf("\nNadiia Rybak 2023\n");

    // Title

    printf("\nDAY OF WEEK\n");

    // Decription

    printf("\nGet day of week by date.\n\n");
}

int get_day()
{
    char input[3];

    int day = 0;

    printf("\nDay: ");

    scanf("%s", input);

    // Check input

    // Check is that a number

    for (int i = 0; input[i] != '\0'; i++)
    {
        if ((isdigit(input[i]) == 0))
        {
            printf("\nYour input is invalid.\n");
            return -1;
        }
    }

    day = atof(input);

    if (day > 31 || day < 1)
    {
        printf("\nYour input is invalid.\n");
        return -1;
    }

    return day;
}

int get_month()
{
    char input[3];

    int month = 0;

    printf("\nMonth: ");

    scanf("%s", input);

    // Check input

    // Check is that a number

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            printf("\nYour input is invalid.\n");
            return -1;
        }
    }

    month = atof(input);

    if (month > 12 || month < 1)
    {
        printf("\nYour input is invalid.\n");
        return -1; 
    }

    return month;
}

int get_year()
{
    char input[5];

    int year = 0;

    printf("\nYear: ");

    scanf("%s", input);

    // Check input

    // Check is that a number

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            printf("\nYour input is invalid.\n");
            return -1;
        }
    }
    
    year = atof(input);

    return year;
}

int day_of_week(int day, int month, int year)
{
    // If month is January or Febraury treat them as 13th or 14th months of the previous year 

    if (month < 3)
    {
        month += 12;
        --year;
    }

    int century = year / 100;

    int year_of_century = year % 100;

    // Use Zaller'sformula to calculate the day of the week

    int result = (day + (13 * (month + 1) / 5) + year_of_century + (year_of_century / 4) + (century / 4) - 2 * century) % 7;

    return result;
}

void print_result(int n)
{
    switch (n)
    {
    case 0:
        printf("\nSaturday\n");
        break;
    case 1:
        printf("\nSunday\n");
        break;
    case 2:
        printf("\nMonday\n");
        break;
    case 3:
        printf("\nTuesday\n");
        break;
    case 4:
        printf("\nWednesday\n");
        break;
    case 5:
        printf("\nThursday\n");
        break;
    case 6:
        printf("\nFriday\n");
        break;
    }

}

bool continue_calculations()
{
    printf("\nDo you want to enter your date one more time? (enter/esc) \n");

    while(1)
    {
        char response = getch(); 

        if (response == 13)  
        {
            return true;
        }
        else if (response == 27)  
        {
            return false;
        }
    }
}











































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































// lublu Nadiu