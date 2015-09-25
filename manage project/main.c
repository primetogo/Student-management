#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>
#include <string.h>

/* Student management version alpha */

void FileExists(void), AddStudent(void);

void main(void){
	Menu();
}

void Menu(void){
	system("cls");
	char modeSelect;
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#       Student Management Enroll System        # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Please, select your work from menu.               \n");
	printf("   1 - Add new student \n");
	printf("   2 - Delete student  \n");
	printf("   3 - Update student data \n");
	printf("   4 - Calculating grade \n");
	printf("   5 - Exit! \n");
	printf("   Go to -> ");
	scanf("%c", &modeSelect);
	
	if(modeSelect == '1'){
		system("cls");
		FileExists();
		AddStudent();	
	}else if(modeSelect == '2'){
		system("cls");
		FileExists();
		DeleteStudent();
	}else if(modeSelect == '3'){
		
	}else if(modeSelect == '4'){
	}else if(modeSelect == '5'){
		exit(0);
	}
	Menu();
}

void FileExists(void){
	FILE *file;
	int i, j, k, l, m, n;
	for(i = 0; i <= 10; i++){
		system("cls");
		printf("Checking file status! \n");
		printf("[ ");
		for(j = 0; j <= i; j++){
			printf("#");
		}
		printf(" ]");
	}
	system("cls");
	if(access("studb.txt", F_OK) != -1){
		printf("File is exists checking file permission! \n");
		if(access("studb.txt", R_OK) != -1){
			for(k = 0; k <= 5; k++){
				system("cls");
				printf("TEST READING\n");
				printf("[ ");
				for(l = 0; l <= k; l++){
					printf("#");
				}
				printf(" ]");
			}
			system("cls");
			printf("File can be read! \n");
		}
		if(access("studb.txt", W_OK) != -1){
			for(m = 0; m <= 5; m++){
				system("cls");
				printf("TEST WRITING\n");
				printf("[ ");
				for(n = 0; n <= m; n++){
					printf("#");
				}
				printf(" ]");
			}
			system("cls");
			for(m = 0; m <= 5; m++){
				system("cls");
				printf("File is ready continue on process! \n");
				printf("[ ");
				for(n = 0; n <= m; n++){
					printf("#");
				}
				printf(" ]");
			}
			system("cls");
		}	
	}
	else{
	    time_t current_time;
    	char* c_time_string;
    	char header[200] = "Name                        Surname                        ID                    Year              score\n";
		current_time = time(NULL);
		c_time_string = ctime(&current_time);
		file = fopen("studb.txt", "w");
		fprintf(file, "############################################\n");
		fprintf(file, "#                                          #\n");
		fprintf(file, "       Student Enrollment System File       \n");
		fprintf(file, "    created on %s", c_time_string);
		fprintf(file, "#                                          #\n");
		fprintf(file, "############################################\n");
		fprintf(file, " ");
		fprintf(file, header);
		fprintf(file, "#########################################################################################################\n");
	}
}
	
		
	


void AddStudent(void){
	char stuName[200], stuSurname[200], id[200], year[200], score[200]; 
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#       Student Management Enroll System        # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Please, insert student information below.      \n");
	printf("Student name? --> ");
	scanf("%s", &stuName);
	printf("Surname? --> ");
	scanf("%s", &stuSurname);
	printf("student id? --> ");
	scanf("%s", &id);
	printf("student year? --> ");
	scanf("%s", &year);
	score[0] = "0";       
	int stuNameLength = strlen(stuName), stuSurnameLength = strlen(stuSurname), idLength = strlen(id);
	int yearLength = strlen(year);
	int firstGap = 27 - stuNameLength, secondGap = 30 - stuSurnameLength, thirdGap = 21 - idLength, forthGap = 17 - yearLength;
	int counter;
	FILE *file;
	file = fopen("studb.txt", "a");
	fprintf(file, " ");
	fprintf(file, stuName);
	for(counter = 0; counter <= firstGap; counter++){
		fprintf(file, " ");
	}
	fprintf(file, stuSurname);
		for(counter = 0; counter <= secondGap; counter++){
		fprintf(file, " ");
	}
	fprintf(file, id);
		for(counter = 0; counter <= thirdGap; counter++){
		fprintf(file, " ");
	}
	fprintf(file, year);
		for(counter = 0; counter <= forthGap; counter++){
		fprintf(file, " ");
	}
	fprintf(file, score);
	fprintf(file, "\n");
	fclose(file);
	printf("Adding new student successfuly!... \n");
	printf("Press any key to continue!");
	getch();
	
}

void DeleteStudent(void){
	char studentID[20];
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#       Student Management Enroll System        # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Please, insert student id that you want to delete.      \n");
	printf("Student id --> ");
	scanf("%s", &studentID);
	
	FILE *file1, *file2;
	file1 = fopen("studb.txt", "r");
	char *test;
	file2 = fopen("temp.txt", "w+");
	char textTemp[2048];
	while(fgets(textTemp, sizeof(textTemp), file1) != NULL){
		test = strstr(textTemp, studentID);   
		if(test == NULL){
			fprintf(file2,"%s", textTemp);
		}
	}
	fclose(file1);
	fclose(file2);
	remove("studb.txt");
	rename("temp.txt", "studb.txt");
    printf("Delete student successfuly!... \n");
	printf("Press any key to continue!");
	getch();
}

void UpdateStudent(void){
	
}
