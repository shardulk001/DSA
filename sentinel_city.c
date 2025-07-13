#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char city_names[101][51]; 
    char std_codes[101][11];  
    char search_name[51];
    int num_cities = 0;
    char file_name[] = "city.txt";

    
    file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    while (fscanf(file, "%50s %10s", city_names[num_cities], std_codes[num_cities]) == 2) {
        num_cities++;
        if (num_cities >= 100) break; // Avoid exceeding the array limit
    }
    fclose(file);

    
    printf("Enter the name of the city to search: ");
    scanf("%50s", search_name);

    
    strcpy(city_names[num_cities], search_name); // Sentinel value
    strcpy(std_codes[num_cities], ""); // Sentinel STD code

    
    int i = 0;
    while (strcmp(city_names[i], search_name) != 0) {
        i++;
    }

    // Output the result
    if (i < num_cities) {
        printf("City: %s, STD Code: %s\n", city_names[i], std_codes[i]);
    } else {
        printf("City not in the list.\n");
    }

    return 0;
}
