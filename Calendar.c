#include <stdio.h>

// Function to get the number of days in a month
int get_days_in_month(int month, int year) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check if the year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_in_month[1] = 29; // February has 29 days in a leap year
    }
    
    return days_in_month[month - 1];
}

// Function to get the first day of the week for a given month and year
int get_first_day_of_week(int month, int year) {
    // January 1, 1900 was a Monday
    int days_since_1900 = (year - 1900) * 365 + (year - 1901) / 4;
    int days_since_jan_1 = 0;
    
    for (int i = 1; i < month; i++) {
        days_since_jan_1 += get_days_in_month(i, year);
    }
    
    days_since_1900 += days_since_jan_1;
    
    if (month > 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_since_1900++; // Add an extra day for the leap year
    }
    
    return (days_since_1900 % 7);
}

// Function to print the calendar for a given month and year
void print_calendar(int month, int year) {
    int days_in_month = get_days_in_month(month, year);
    int first_day_of_week = get_first_day_of_week(month, year);
    
    printf("      %d/%d\n", month, year);
    printf(" Su Mo Tu We Th Fr Sa\n");
    
    // Print spaces for the days before the first day of the month
    for (int i = 0; i < first_day_of_week; i++) {
        printf("   ");
    }
    
    // Print the days of the month
    for (int i = 1; i <= days_in_month; i++) {
        printf("%3d", i);
        if ((first_day_of_week + i - 1) % 7 == 6) { // Sunday is the 7th day
            printf("\n");
        }
    }
    
    // Print a newline character if the last week is not full
    if ((first_day_of_week + days_in_month) % 7 != 0) {
        printf("\n");
    }
}

int main() {
    int month, year;
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    
    print_calendar(month, year);
    
    return 0;
}
