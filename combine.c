#include <stdio.h>


#define MAX_EMPLOYEES 100


typedef struct {
    int age;
    char name[20];
} Employee;


void countingSort(Employee arr[], int n) {
    int maxAge = 0;
   
    for (int i = 0; i < n; i++) {
        if (arr[i].age > maxAge) {
            maxAge = arr[i].age;
        }
    }
   
   
    int count[MAX_EMPLOYEES] = {0};
   
   
    for (int i = 0; i < n; i++) {
        count[arr[i].age]++;
    }
   
   
    int j = 0;
    for (int i = 0; i <= maxAge; i++) {
        while (count[i] > 0) {
            for (int k = 0; k < n; k++) {
                if (arr[k].age == i) {
                    arr[j++] = arr[k];
                }
            }
            count[i]--;
        }
    }
}


void merge(Employee arr[], int left, int mid, int right) {
    Employee temp[MAX_EMPLOYEES];
    int n1 = mid - left + 1;
    int n2 = right - mid;
   
   
    for (int i = 0; i < n1; i++)
        temp[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        temp[n1 + j] = arr[mid + 1 + j];
   
   
    int i = 0, j = n1, k = left;
    while (i < n1 && j < n1 + n2) {
        if (temp[i].age <= temp[j].age) {
            arr[k++] = temp[i++];
        } else {
            arr[k++] = temp[j++];
        }
    }
   
   
    while (i < n1) {
        arr[k++] = temp[i++];
    }
   
 
    while (j < n1 + n2) {
        arr[k++] = temp[j++];
    }
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void quickSort(Employee arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right].age;
        int i = left - 1;
       
        for (int j = left; j < right; j++) {
            if (arr[j].age <= pivot) {
                i++;
                Employee temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
       
        Employee temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
       
        int pi = i + 1;
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main() {
    FILE *file = fopen("emp.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
   
    int n;
    fscanf(file, "%d", &n);
   
   
    Employee arr[MAX_EMPLOYEES];
   
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %s", &arr[i].age, arr[i].name);
    }
    fclose(file);
   
   
    int sortMethod;
    printf("Choose sorting method:\n");
    printf("1. Counting Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Quick Sort\n");
    scanf("%d", &sortMethod);
   
   
    switch (sortMethod) {
        case 1:
            countingSort(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        case 3:
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
   
   
    file = fopen("sort9.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
   
    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s\n", arr[i].age, arr[i].name);
    }
    fclose(file);
   
    return 0;
}

























