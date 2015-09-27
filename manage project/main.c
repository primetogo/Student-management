#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* Student management version alpha */

/* All function list */
void FileExists(void), AddStudent(void), DeleteStudent(void), UpdateStudent(void), Menu(void), DisplayData(void);
void CalculateGrade(void), Grading(int score, char *name, char *surname), UpdateScore(void);
void main(void){
	Menu();
}

/* Main menu for select mode to work on */
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
	printf("   5 - Display student data \n");
	printf("   6 - Update student score \n");
	printf("   7 - Exit! \n");
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
		system("cls");
		FileExists();
		UpdateStudent();
	}else if(modeSelect == '4'){
		system("cls");
		FileExists();
		CalculateGrade();
	}else if(modeSelect == '5'){
		system("cls");
		FileExists();
		DisplayData();		
	}else if(modeSelect == '6'){
		system("cls");
		FileExists();
		UpdateScore();
	}else if(modeSelect == '7'){
		exit(0);
	}
	Menu();
}

/* Checking if text file is exists or not */
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
		fclose(file);
	}
	else{
	    time_t current_time;
    	char* c_time_string;
    	char header[200] = "Name                Surname                ID            Year      score\n";
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
		fprintf(file, "################################################################################\n");
		fclose(file);
	}
}
	
/* function to adding new student */
void AddStudent(void){
	char stuName[200], stuSurname[200], id[200], year[200]; 
	int ch, score;
	int counter;
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#         Adding student to Database            # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Press N to continue or 0 to exit.      \n");
    ch = getch();
    if(ch == 48){
    	system("cls");
    	Menu();
	}
	printf("   Please, insert student information below.      \n");	
	printf("Student name? --> ");
	scanf("%s", &stuName);
	printf("Surname? --> ");
	scanf("%s", &stuSurname);
	printf("student id? --> ");
	scanf("%s", &id);
	printf("student year? --> ");
	scanf("%s", &year);
	
	int stuNameLength = strlen(stuName), stuSurnameLength = strlen(stuSurname), idLength = strlen(id);
	int yearLength = strlen(year);
	int firstGap = 19 - stuNameLength, secondGap = 22 - stuSurnameLength, thirdGap = 13 - idLength, forthGap = 9 - yearLength;
	
	score = 0;       
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
	fprintf(file,"%d", score);
	fprintf(file, "\n");
	fclose(file);
	printf("Adding new student successfuly!... \n");
	printf("Press any key to continue!");
	getch();
	
}

/* function for deleting student */
void DeleteStudent(void){
	char studentID[20];
	bool recordExists = false;
	char textTemp[2048];
	char *test;
	int ch;
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#         Delete student from Database          # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Press N to continue or 0 to exit.      \n");
    ch = getch();
    if(ch == 48){
    	system("cls");
    	Menu();
	}
	printf("   Please, insert student id that you want to delete.      \n");
	printf("Student id --> ");
	scanf("%s", &studentID);
	
	FILE *file1, *file2;
	file1 = fopen("studb.txt", "r");
	file2 = fopen("temp.txt", "w+");
	while(fgets(textTemp, sizeof(textTemp), file1) != NULL){
		test = strstr(textTemp, studentID);   
		if(test == NULL){
			fprintf(file2,"%s", textTemp);
		}
		else{
			recordExists = true;
		}
	}
	fclose(file1);
	fclose(file2);
	if(recordExists == true){
		remove("studb.txt");
		rename("temp.txt", "studb.txt");
	    printf("Delete student successfuly!... \n");
		printf("Press any key to continue!");
		getch();
	}else{
		printf("Student ID not found! \n");
		printf("Press any key to re-enter ID!");
		getch();
		system("cls");
		DeleteStudent();
	}
}

/* function for updating student data */
void UpdateStudent(void){
	char studentID[20], stuName[200], stuSurname[200], year[200];
	char textTemp[2048];
	bool recordExists = false;
	char *test;
	int ch,score;
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#           Update student in Database          # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Press N to continue or 0 to exit.      \n");
    ch = getch();
    if(ch == 48){
    	system("cls");
    	Menu();
	}
	printf("   Please, insert student id that you want to edit.      \n");
	printf("Student id --> ");
	scanf("%s", &studentID);
	printf("   Please, insert information below.      \n");
	printf("Student name? --> ");
	scanf("%s", &stuName);
	printf("Surname? --> ");
	scanf("%s", &stuSurname);
	printf("student year? --> ");
	scanf("%s", &year);
	score = 0;
	
	int stuNameLength = strlen(stuName), stuSurnameLength = strlen(stuSurname), idLength = strlen(studentID);
	int yearLength = strlen(year);
	int firstGap = 19 - stuNameLength, secondGap = 22 - stuSurnameLength, thirdGap = 13 - idLength, forthGap = 9 - yearLength, 
	counter;
	
	FILE *file1, *file2;
	file1 = fopen("studb.txt", "r");
	file2 = fopen("temp.txt", "w+");
	while(fgets(textTemp, sizeof(textTemp), file1) != NULL){
		test = strstr(textTemp, studentID);   
		if(test == NULL){
			fprintf(file2,"%s", textTemp);
		}
		else{
			fprintf(file2, " ");
			fprintf(file2, stuName);
			for(counter = 0; counter <= firstGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2, stuSurname);
			for(counter = 0; counter <= secondGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2, studentID);
			for(counter = 0; counter <= thirdGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2, year);
			for(counter = 0; counter <= forthGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2,"%d", score);
			fprintf(file2, "\n");
			recordExists = true;
		}
		
	}
	fclose(file1);
	fclose(file2);
	if(recordExists == true){
		remove("studb.txt");
		rename("temp.txt", "studb.txt");
	    printf("Update student successfuly!... \n");
	    printf("Press any key to continue!");
		getch();
	}else{
		printf("Student ID not found! \n");
	    printf("Press any key to re-enter ID!");
		getch();
		system("cls");
		UpdateStudent();
	}
}

/* function for displaying student data */
void DisplayData(void){
	int ch;
	char textTemp[2048];
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#             Display Student Data              # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Press N to continue or 0 to exit.      \n");
    ch = getch();
    if(ch == 48){
    	system("cls");
    	Menu();
	}
	printf("\n \n \n");
	FILE *file = fopen("studb.txt", "r");
	while(fgets(textTemp, sizeof(textTemp), file) != NULL){
		printf("%s \n", textTemp);
	}
	fclose(file);
	printf("Press any key to continue!");
	getch();
}

/* function for calculating grade */
void CalculateGrade(void){
	int ch, partCount = 0;
	char studentID[20], *test, *par, *name, *surname;
	char textTemp[2048], *score;
	bool recordExists = false;
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#            Calculate student grade            # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Press N to continue or 0 to exit.      \n");
    ch = getch();
    if(ch == 48){
    	system("cls");
    	Menu();
	}
	printf("\n");
	printf("   Please, insert student id that you want to edit.      \n");
	printf("Student id --> ");
	scanf("%s", &studentID);
	FILE *file1 = fopen("studb.txt", "r");
	while(fgets(textTemp, sizeof(textTemp), file1) != NULL){
		test = strstr(textTemp, studentID); 
		if(test != NULL){
			par = strtok(textTemp, " ");
			while(par != NULL){
				if(partCount == 4){
					score = par;
				}else if(partCount == 0){
					name = par;
				}else if(partCount == 1){
					surname = par;
				}
				par = strtok(NULL, " ");
				partCount++;
				recordExists = true;
			}
		}	
	}
	if(recordExists == true){
		Grading(atoi(score), name, surname);
		fclose(file1);
		printf("Press any key to continue!");
		getch();
	}else{
		printf("Student ID not found! \n");
	    printf("Press any key to re-enter ID!");
		getch();
		system("cls");
		CalculateGrade();
	}
}

/* function to determine grade from score */
void Grading(int score, char *name, char *surname){
	char grade[12];
	if(score >= 95 && score <= 100){
		strcpy(grade, "A+");
	}
	else if(score >= 90 && score <= 94){
		strcpy(grade, "A");
	}
	else if(score >= 85 && score <= 89){
        strcpy(grade, "B+");		
	}
	else if(score >= 80 && score <= 84){
		strcpy(grade, "B");
	}
	else if(score >= 75 && score <= 79){
		strcpy(grade, "C+");
	}
	else if(score >= 70 && score <= 74){
		strcpy(grade, "C");
	}
	else if(score >= 65 && score <= 69){
		strcpy(grade, "D+");
	}
	else if(score >= 60 && score <= 64){
		strcpy(grade, "D");
	}
	else if(score <= 59){
		strcpy(grade, "F");
	}
	printf("student name is %s %s got grade %s \n", name, surname, grade);
}

/* function to updating student score */
void UpdateScore(){
	char studentID[20], ch, *name, *surname, *year, *id, *par, textTemp1[2048], textTemp2[2048], *test;
	int partCount = 0, score;
	bool recordExists = false;
	printf("################################################# \n");
	printf("#                                               # \n");
	printf("#              Edit student score               # \n");
	printf("#                                               # \n");
	printf("################################################# \n \n");
	printf("   Press N to continue or 0 to exit.      \n");
    ch = getch();
    if(ch == 48){
    	system("cls");
    	Menu();
	}
	printf("\n");
	printf("   Please, insert student id that you want to edit.      \n");
	printf("Student id --> ");
	scanf("%s", &studentID);
	
	FILE *file1, *file2;
	file1 = fopen("studb.txt", "r");
	while(fgets(textTemp1, sizeof(textTemp1), file1) != NULL){
		test = strstr(textTemp1, studentID); 
		if(test != NULL){
			par = strtok(textTemp1, " ");
			while(par != NULL){
				if(partCount == 0){
					name = par;
				}else if(partCount == 1){
					surname = par;
				}else if(partCount == 2){
					id = par;
				}else if(partCount == 3){
					year = par;
				}
				par = strtok(NULL, " ");
				partCount++;
				recordExists = true;
			}
		}	
	}
	fclose(file1);

	if(recordExists == true){
		printf("\n Student name is %s %s What score do you want to enter?: ", name, surname);
		scanf("%d", &score);
		file1 = fopen("studb.txt", "r");
		file2 = fopen("temp.txt", "w+");
		int stuNameLength = strlen(name), stuSurnameLength = strlen(surname), idLength = strlen(id);
		int yearLength = strlen(year);
		int firstGap = 19 - stuNameLength, secondGap = 22 - stuSurnameLength, thirdGap = 13 - idLength, forthGap = 9 - yearLength, 
		counter;
		
		while(fgets(textTemp2, sizeof(textTemp2), file1) != NULL){
			test = strstr(textTemp2, studentID);
			if(test != NULL){
				fprintf(file2, " ");
			fprintf(file2, name);
			for(counter = 0; counter <= firstGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2, surname);
			for(counter = 0; counter <= secondGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2, id);
			for(counter = 0; counter <= thirdGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2, year);
			for(counter = 0; counter <= forthGap; counter++){
				fprintf(file2, " ");
			}
			fprintf(file2,"%d", score);
			fprintf(file2, "\n");
			}
			else{
				fprintf(file2,"%s", textTemp2);
			} 
		}
		fclose(file2);
		fclose(file1);
		remove("studb.txt");
		rename("temp.txt", "studb.txt");
		printf("Update student score successfuly!... \n");
	    printf("Press any key to continue!");
		getch();
		
	}else{
		printf("Student ID not found! \n");
	    printf("Press any key to re-enter ID!");
		getch();
		system("cls");
		UpdateScore();
	}
	
	
}

