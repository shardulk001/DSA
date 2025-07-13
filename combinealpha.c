#include <stdio.h>
#include <string.h>

struct Employee {
    char name[100];
    int age;
};

void bubbleSort(struct Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void insertionSort(struct Employee employees[], int count) {
    for (int i = 1; i < count; i++) {
        struct Employee key = employees[i];
        int j = i - 1;
        while (j >= 0 && strcmp(employees[j].name, key.name) > 0) {
            employees[j + 1] = employees[j];
            j--;
        }
        employees[j + 1] = key;
    }
}

void selectionSort(struct Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(employees[j].name, employees[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        struct Employee temp = employees[i];
        employees[i] = employees[minIndex];
        employees[minIndex] = temp;
    }
}

int main() {
    struct Employee employees[10];
    int count = 0;

    FILE *file = fopen("emp.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(file, "%s %d", employees[count].name, &employees[count].age) == 2) 
    {
        count++;
    }

    fclose(file);

    printf("Before sorting:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", employees[i].name, employees[i].age);
    }

    bubbleSort(employees, count);
    printf("After Bubble Sort:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", employees[i].name, employees[i].age);
    }

    // Reset employees array
    file = fopen("emp.txt", "r");
    count = 0;
    while (fscanf(file, "%s %d", employees[count].name, &employees[count].age) == 2) {
        count++;
    }
    fclose(file);

    insertionSort(employees, count);
    printf("After Insertion Sort:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", employees[i].name, employees[i].age);
    }

    // Reset employees array
    file = fopen("emp.txt", "r");
    count = 0;
    while (fscanf(file, "%s %d", employees[count].name, &employees[count].age) == 2) {
        count++;
    }
    fclose(file);

    selectionSort(employees, count);
    printf("After Selection Sort:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", employees[i].name, employees[i].age);
    }

    return 0;
}

