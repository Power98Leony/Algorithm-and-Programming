#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 8
#define MAX_CHAR_PER_LINE 1000

typedef struct{
    char location[50];
    char city[50];
    int price;
    int rooms;
    int bathroom;
    int carpark;
    char type[20];
    char furnish[20];
}RealEstate;

RealEstate realEstates[MAX_ROWS];
int numRows = 0;

void readCSV() {
    FILE *file = fopen("realestate.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_CHAR_PER_LINE];
    while (fgets(line, sizeof(line), file)) {
        if (numRows >= MAX_ROWS) {
            break;
        }

        char *token = strtok(line, ",");
        strcpy(realEstates[numRows].location, token);

        token = strtok(NULL, ",");
        strcpy(realEstates[numRows].city, token);

        token = strtok(NULL, ",");
        realEstates[numRows].price = atoi(token); //fungsi atoi, untuk mengubah string jadi suatu bilangan bulat

        token = strtok(NULL, ",");
        realEstates[numRows].rooms = atoi(token); //fungsi atoi, untuk mengubah string jadi suatu bilangan bulat

        token = strtok(NULL, ",");
        realEstates[numRows].bathroom = atoi(token); //fungsi atoi, untuk mengubah string jadi suatu bilangan bulat

        token = strtok(NULL, ",");
        realEstates[numRows].carpark = atoi(token); //fungsi atoi, untuk mengubah string jadi suatu bilangan bulat

        token = strtok(NULL, ",");
        strcpy(realEstates[numRows].type, token);

        token = strtok(NULL, ",");
        strcpy(realEstates[numRows].furnish, token);

        numRows++;
    }

    fclose(file);
}

//Fungsi untuk menampilkan data berdasarkan jumlah baris yang ditentukan user
void displayData(int rows){
    printf("\n%-25s%-15s%-10s%-7s%-10s%-10s%-15s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    for (int i = 1; i <= rows && i <= numRows; i++) {
        printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
               realEstates[i].location, realEstates[i].city, realEstates[i].price,
               realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
               realEstates[i].type, realEstates[i].furnish);
    }
}

//Untuk menghapus spasi di awal dan akhir string
char* strtrim(char* str){
    // Menghilangkan spasi di awal string
    while (isspace((unsigned char)*str)) {
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    // Menghilangkan spasi di akhir string
    char* end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';

    return str;
}

//Fungsi untuk menampilkan baris berdasarkan kueri(inputan user)
void SelectRow(const char *columnName, const char *query) {
    int found = 0;
    printf("\n%-25s%-15s%-10s%-7s%-10s%-10s%-15s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
	
    for (int i = 0; i < numRows; i++){
    // Menghilangkan spasi di awal dan akhir string sebelum dibandingkan dengan data di realestate.csv
    	char cleanQuery[20];
        strncpy(cleanQuery, strtrim(const_cast<char*>(query)), sizeof(cleanQuery) - 1);
        cleanQuery[sizeof(cleanQuery) - 1] = '\0';

        char cleanFurnish[20];
        strncpy(cleanFurnish, strtrim(const_cast<char*>(realEstates[i].furnish)), sizeof(cleanFurnish) - 1);
        cleanFurnish[sizeof(cleanFurnish) - 1] = '\0';
        
        if(strcmpi(columnName, "Location") == 0 && strcmpi(realEstates[i].location, query) == 0){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "City") == 0 && strcmpi(realEstates[i].city, query) == 0){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "Price") == 0 && realEstates[i].price == atoi(query)){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "Rooms") == 0 && realEstates[i].rooms == atoi(query)){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "Bathroom") == 0 && realEstates[i].bathroom == atoi(query)){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "Carpark") == 0 && realEstates[i].carpark == atoi(query)){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "Type") == 0 && strcmpi(realEstates[i].type, query) == 0){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }else if (strcmpi(columnName, "Furnish") == 0 && strcmpi(cleanFurnish, cleanQuery) == 0){
            found = 1;
            printf("%-25s%-15s%-10d%-7d%-10d%-10d%-15s%-15s\n",
                   realEstates[i].location, realEstates[i].city, realEstates[i].price,
                   realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                   realEstates[i].type, realEstates[i].furnish);
        }
    }

    if (!found){
        printf("Data not found for %s: %s\n", columnName, query);
    }
}

//Fungsi untuk membandingkan dua baris berdasarkan kolom yang ditentukan
const char *globalColumnName;
int compareRows(const void *a, const void *b){
    const char *column = globalColumnName;
    if(strcmpi(column, "Location") == 0){
        return strcmpi(((RealEstate *)a)->location, ((RealEstate *)b)->location);
    }else if (strcmpi(column, "City") == 0){
        return strcmpi(((RealEstate *)a)->city, ((RealEstate *)b)->city);
    }else if (strcmpi(column, "Price") == 0){
        return ((RealEstate *)a)->price - ((RealEstate *)b)->price;
    }else if (strcmpi(column, "Rooms") == 0){
        return ((RealEstate *)a)->rooms - ((RealEstate *)b)->rooms;
    }else if (strcmpi(column, "Bathroom") == 0){
        return ((RealEstate *)a)->bathroom - ((RealEstate *)b)->bathroom;
    }else if (strcmpi(column, "Carpark") == 0){
        return ((RealEstate *)a)->carpark - ((RealEstate *)b)->carpark;
    }else if (strcmpi(column, "Type") == 0){
        return strcmpi(((RealEstate *)a)->type, ((RealEstate *)b)->type);
    }else if (strcmpi(column, "Furnish") == 0){
        return strcmpi(((RealEstate *)a)->furnish, ((RealEstate *)b)->furnish);
    }else{
        return 0; 
    }
}

int compareRowsDescending(const void *a, const void *b){
    return -compareRows(a, b);
}

//Fungsi untuk mengurutkan data berdasarkan kolom tertentu
void SortBy(const char *column, const char *order){
    globalColumnName = column;
    
    if(strcmpi(order, "asc") == 0){
        qsort(realEstates, numRows, sizeof(RealEstate), compareRows);
    }else if (strcmpi(order, "desc") == 0){
        qsort(realEstates, numRows, sizeof(RealEstate), compareRowsDescending);
    }

    displayData(10);
}

//Fungsi untuk menulis data ke file.csv sesuai dengan nama file inputan user
void exportData(const char *filename){
    char Filename[1000];
    strcpy(Filename, filename);
    
    //Untuk mengecek apakah di nama file dari inputan user ada .csv atau tidak
    if(strstr(filename, ".csv") == NULL){
    //Kalau tidak ada .csv dalam file inputan user, tambahkan .csv ke file inputan user
        strcat(Filename, ".csv");
    }

    FILE *file = fopen(Filename, "w");
    if(file == NULL){
        printf("Error opening the file for export.\n");
        return;
    }

    fprintf(file, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");
    for(int i = 0; i < numRows; i++){
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n",
                realEstates[i].location, realEstates[i].city, realEstates[i].price,
                realEstates[i].rooms, realEstates[i].bathroom, realEstates[i].carpark,
                realEstates[i].type, realEstates[i].furnish);
    }

    fclose(file);
    printf("Data successfully written to file %s!\n", Filename);
}


int main(){
    readCSV();
	
	int choice;
	char query[101];
	char columnName[101];
	char sortOrder[10];
	char filename[101];
	
    do{
        printf("\nWhat do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search data\n");
        printf("3. Sort data\n");
        printf("4. Export data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Number of rows: ");
                int rows;
                scanf("%d", &rows);
                displayData(rows);
                break;
            case 2:
                printf("Enter column name to search: ");
                scanf("%s", columnName);

                printf("What data do you want to find? ");
                scanf("%s", query);
				printf("Data found. Detail of data: \n");
                SelectRow(columnName, query);
                break;
            case 3:
                printf("Choose column: ");
                scanf("%s", columnName);
                printf("Sort ascending or descending? ");
                scanf("%s", sortOrder);
                SortBy(columnName, sortOrder);
                break;
            case 4:
                printf("File name: ");
                scanf("%s", filename);
                exportData(filename);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }while (choice != 5);

    return 0;
}
