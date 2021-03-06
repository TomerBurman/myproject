#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <stdio.h>
#include "Patient.h"
void Menu();//Prints main menu
void registerMenu();//Prints register menu
void sign_in_Menu();//Prints sign in menu
//void doctor_Menu(Doctor* d);//Prints doctor menu
void patient_Menu(Patient* p);//Prints patient menu
//int flush_database();
//check if IDs between doctor and patient are same
int main() { 
	
	//Menu();
	///*FILE* fp = fopen("DoctorData.dat", "ab");
	//Doctor d2;
	//Doctor d = { .un = "Tomer",.pass = "Burman",.ID = "207598970",
	//.name = "Tomer",.last_n = "Burman",.specialty = "Doctor",.gender = "Male" };
	//fwrite(&d, sizeof(Doctor), 1, fp);
	//fseek(fp, 0, SEEK_SET);
	//fclose(fp);
	//fp = fopen("DoctorData.dat", "rb+");
	//fread(&d2, sizeof(Doctor), 1, fp);
	//printDoctor(&d2);
	//fclose(fp);*/
	///*FILE* fp = fopen("DoctorData.txt", "rb+");
	//Doctor d = { .un = "Tomer",.pass = "054209T",.ID = "207598970",.name = "Tomer",.last_n = "Burman",.specialty = "Doctor",.gender = "Male" };
	//Doctor d2;
	//fwrite(&d, sizeof(Doctor), 1, fp);
	//fseek(fp, 0, SEEK_SET);
	//	fread(&d2, sizeof(Doctor), 1, fp);
	//	printDoctor(&d2);*/
	//return 0;
}

/*Menu function - prints menu*/
void Menu() {
	enum choice { REGISTER = 1, SIGN_IN = 2, EXIT = 3 };
	int choice;
	do{
	printf("Hello ! Please choose one of the following :\n");
	printf("(1). Register\n (2). Sign in\n (3). Exit the system\n");
	scanf("%d", &choice);
		switch (choice) {
		case REGISTER:
			registerMenu();
			break;
		case SIGN_IN:
			sign_in_Menu();
			break;
	/*	case MANAGING_DATABASE :
			flush_database();*/
		case EXIT:
			printf("Goodbye ! :)\n");
			break;
		default:
			printf("You entered a wrong input. Please try again\n");
			break;
		}
	} while (choice != EXIT);

}

/*Registeration menu - prints registeration methods :
uses initiateDoctor and registerDoctor. allocates and releases memory.*/
void registerMenu() {
	enum registeration { DOCTOR = 1, PATIENT = 2, GO_BACK = 3 };
	int choice,flag=0;
	Patient* p;
	Doctor d;
	do {
		printf("How would you like to register ?\n");
		printf("(1). Doctor\n (2). Patient\n (3). Go back\n");
		scanf("%d", &choice);
		switch (choice) {
		case DOCTOR:
			flag = initiateDoctor(&d);
			if (flag)
				if(registerDoctor(&d))
			printf("Registed successfuly ! \n");
			break;
		case PATIENT:
			p = malloc(sizeof(Patient));
			flag = initiatePatient(p);
			if (flag)
				if (registerPatient(p))
					printf("Registed successfuly ! \n");
			free(p);
			break;
		case GO_BACK:
			break;
		default:
			printf("You entered a wrong input. please try again.\n");
			break;
		}
	} while (choice != GO_BACK);
}

/*Sign in menu - prints sign in methods : 
uses sign_in function and menu functions, allocates and releases memory. */
void sign_in_Menu() {
	enum sign_in { DOCTOR = 1, PATIENT = 2, GO_BACK = 3 };
	int choice;
	Doctor* d;
	Patient* p;
	do {
		printf("Sign in as:\n");
		printf("(1). Doctor\n (2). Patient\n (3). Go back\n");
		scanf("%d", &choice);
		switch (choice) {
		case DOCTOR:
			d = malloc(sizeof(Doctor));
			d = sign_inD(d);
			if(!d)
			printDoctor(d);
			if (d)
				/*doctor_Menu(d);*/
			free(d);
			break;
		case PATIENT:
			p = malloc(sizeof(Patient));
			p = sign_inP(p);
			printPatient(p);
		/*	if (p)
				patient_Menu();*/
			free(p);
		case GO_BACK:
			break;
		default:
			printf("You entered a wrong choice. Please try again.\n");
			break;
		}
	} while (choice != GO_BACK);
}
//
//void doctor_Menu(Doctor* d) {
//	enum doctor_Menu { PRINT_DOCTOR = 1, EDIT_DOCTOR = 2 };
//	int choice;
//	do {
//		printf("Hello dr.%s %s.\n What would you like to do ?\n", d->name, d->last_n);
//		scanf("%d", &choice);
//		switch (choice) {
//		case PRINT_DOCTOR:
//			printDoctor(d);
//		case EDIT_DOCTOR:
//			editDoctor(d);
//		}
//	}
//}

void patient_Menu(Patient* p) {


}

//int flush_database() {
//	FILE* fp = fopen("DoctorData.txt", "w");
//	if (!fp) {
//		perror("Error flushing\n");
//		return 0;
//	}
//	FILE* fp = fopen("PatientData.txt", "w");
//	if (!fp) {
//		perror("Error flushing\n");
//		return 0;
//	}
//	return 1;
//}