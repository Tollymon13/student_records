#include <stdio.h>
#include <stdlib.h>

#define company_size 10 // number of companies
#define student_size 10 //number of students

int i, j, data_read = 0, menu;
char company_Name[20], student_Name[20], student_Surname[20], student_pps[20];
char input_Char[20];
// the above variable were variously included throughout the code
typedef struct companies //companies structure
{
    char company_name[20];
    char registration_code[20]; //registration code of the company
    int salary;
    int benefits;

} companies_type;

companies_type my_company[company_size];

typedef struct students //students structure
{
    char student_name[20];
    char student_surmane[20];
    char PPS[20];
    char nat[20]; //i.e. nationality
    int married;
    int children;
    char registration_code[20]; //registration code of the student
    int income;

} students_type;

students_type my_student[student_size];

void companies()
{
    if (data_read == 0) //if the data has not been read before
    {
        FILE * fPointer; //reads the text file
        fPointer = fopen("C:\\Users\\Edy\\Desktop\\em108 test\\companies.txt", "r"); //access location of the file // "r" opens the file in read mode
        char singleLine[1000]; // char creation, limited to 1000 characters

        while(fgets(singleLine, 1000, fPointer) != 0) // reads lines from the text file into an array until the eof
        {
            sscanf(singleLine, "%s %s %d %d", my_company[i].company_name, my_company[i].registration_code, &my_company[i].salary, &my_company[i].benefits); //reads the info and saves it
            i++; //iteration
        }
        printf("\nRegistered Companies:\n");
        for(int i = 0; i<company_size; i++) //loop for each company
            printf("%s %s %d %d\n", my_company[i].company_name, my_company[i].registration_code, my_company[i].salary, my_company[i].benefits); //prints the info of each company

        fclose(fPointer); //closes the file

        FILE * fPointer2;
        fPointer2 = fopen("C:\\Users\\Edy\\Desktop\\em108 test\\students.txt", "r");
        char singleLine2[1000];

        while(fgets(singleLine2, 1000, fPointer2) != 0)
        {
            sscanf(singleLine2, "%s %s %s %s %d %d %s", my_student[j].student_name,
                                                        my_student[j].student_surmane,
                                                        my_student[j].PPS, my_student[j].nat,
                                                       &my_student[j].married,
                                                       &my_student[j].children,
                                                        my_student[j].registration_code);
            j++;
        }
        printf("\nRegistered Students:\n");
        for(int j = 0; j<student_size; j++)
            printf("%s %s %s %s %d %d %s\n", my_student[j].student_name,
                                             my_student[j].student_surmane,
                                             my_student[j].PPS, my_student[j].nat,
                                             my_student[j].married,
                                             my_student[j].children,
                                             my_student[j].registration_code);

        fclose(fPointer);

        data_read = 1; // signals that data has been read
    }
    else
        printf("data was already read"); //warning


}

const char* company_search(char company[20]) // const because it is returning a constant  // create char company
// char* so I can return a string of characters
{
    for(int i=0; i<company_size; i++) // loop for companies
    {
        // the variable company reads the value inputted by the user
        if( strcmp(company, my_company[i].company_name) == 0) //compares if the variable company equals the name of the company
            return my_company[i].registration_code; // if they are the same, return the registration code
    }

    return "-1"; // if they are not return -1

}

const char* student_search(char name[20], char surname[20], char registration[20]) //same procedure //creation of various variables
{
    for(int j=0; j<student_size; j++) //loop that goes around the students
    {
        if( strcmp(name, my_student[j].student_name) == 0 && strcmp(surname, my_student[j].student_surmane) == 0) //check if name and surname variables equal the ones inputted by the user
        {
            strcpy(my_student[j].registration_code, registration); //copies the registration code into the registration variable
            write_file(); //it writes inside the notepad the new registration code
            return "student found, company updated\n\n"; //return message if the student was found
        }
    }

    return "student not found"; //return if the student was not found

}

void student_serach_PPS(char student_PPS[20]) //function that searches for ones PPS //creation of student_PPS char function
{
    int match=0;
    for(int j=0; j<student_size; j++) //loop for students
    {
        if( strcmp(student_PPS, my_student[j].PPS) == 0) //compare the variable_PPS with the  PPS one inputted
        {
            //if they are equal, then the following will happen
            printf("name: %s\n", my_student[j].student_name); // the ones name will be printed
            printf("surname: %s\n", my_student[j].student_surmane); //surname
            printf("nationality: %s\n", my_student[j].nat); // the nationality
            printf("married status: %d\n", my_student[j].married); //the marriage status
            printf("number of children: %d\n", my_student[j].children); //the number of children
            student_intra(my_student[j].registration_code); //call the function
            income_calculation(); //function that calculates the income
            printf("income: %d\n", my_student[j].income); //print of the income

            match=1; //indicates successful match
        }
    }
    if (match == 0) // if there is no match
    {
        printf("no match");
    }
}

void student_intra(char reg_intra[20]) //prints intra related stuff
{

    int match=0;
    for(int i=0; i<company_size; i++) //company loop
    {
        if (strcmp(reg_intra, my_company[i].registration_code) == 0) //compares the reg_intra variable with the registration code one inputted
        {
            printf("company name: %s\n", my_company[i].company_name); //print of the company name
            printf("registration: %s\n", my_company[i].registration_code); //print of the registration code
            printf("salary: %d\n", my_company[i].salary); //print of the salary
            match =1;
        }

    }
    if (match == 0) //if there is no match
    {
        printf("no match");
    }
}

void user() //function that will improve the UI of the program

{

    print_menu(); //call the print function
    scanf("%d", &menu);
    while(menu < 6) //repeats up to 6 times
    {

        switch (menu)
        {

        case 1:
            companies(); //loads the info into the program
            break;
        case 2:
            printf("company name: ");
            scanf("%s", company_Name); //ask for a company name
            char REG[20] ; // variable creation
            strcpy(REG, company_search(company_Name)); //copies the read value into the variable REG after company_search receives the company's registration code
            printf("registration code: %s\n", REG); //prints the code
            printf("student name(first name):");
            scanf("%s", student_Name); //reads name
            printf("student surname:");
            scanf("%s", student_Surname); //reads surname
            printf("%s\n", student_search(student_Name, student_Surname, REG)); //prints the activated function with the registration code associated with that one person
            break;
        case 3:
            printf("student PPS:");
            scanf("%s", student_pps); //reads the pps
            student_serach_PPS(student_pps); //activates the function
            break;
        case 4:
            printf("introduce the letter(CAPS LOCK): "); //ask for caps only because all of the names start with an upper case letter
            scanf("%s", input_Char); //the input is recorded
            printf("|  Name  |  Surname  |  PPS  |  Company  |  Income  | \n"); //basic template that will be always be printed
            search_bar(input_Char); //calling the function
            break;
        case 5:
            create_file_user(); //calling of the function

        }
        print_menu(); //call of the printing menu
        scanf("%d", &menu);
    }
    if (menu >= 6) //if it exceeds the limit the program prints the following message:
    {
        printf("\nGoodbye from the DCU records\n");
    }
}

void write_file()
{

    FILE *fptr; //reads text file character by character

    fptr = fopen("C:\\Users\\Edy\\Desktop\\em108 test\\students.txt", "w"); //open the location of the text file in writing mode
    for(int j=0; j<student_size; j++) //loop for each student
        fprintf(fptr, "%s %s %s %s %d %d %s\n", my_student[j].student_name,
                                                my_student[j].student_surmane,
                                                my_student[j].PPS,
                                                my_student[j].nat,
                                                my_student[j].married,
                                                my_student[j].children,
                                                my_student[j].registration_code);
    //the  above function prints the values inside the text file
    fclose(fptr); //closes the text file


}

void print_menu() //prints messages
{
    printf("\nPlease select what interests you:\n");
    printf("1: Load the info into the program\n");
    printf("2: INTRA system for specific students\n");
    printf("3: PPS and INTRA-related values system  for specific students\n");
    printf("4: Search bar (i.e. input a letter system)\n");
    printf("5: Create a file and write students info in it\n");
    printf("6: Exit the program\n");

}

void income_calculation()
{
    for (int j=0; j<student_size; j++) //loop that goes through every single student
    {
        for (int i=0; i<company_size; i++) //loop that goes through every single company
        {
            if (strcmp(my_student[j].registration_code, my_company[i].registration_code) == 0) // matching student's code with the company code
            {
                if(my_company[i].benefits == 1) //if the company has benefits
                {
                    if (my_student[j].children >= 1 && my_student[j].married == 1) //if the student has one or more children and is married
                    {
                        my_student[j].income = (my_company[i].salary)/100 * 8 + my_company[i].salary; // calculation for the final income

                    }
                    else if (my_student[j].children == 0 && my_student[j].married == 1)
                        my_student[j].income = (my_company[i].salary)/100 * 5 + my_company[i].salary; //income for married students but that have no child
                    else if (my_student[j].children >= 1 && my_student[j].married == 0)
                        my_student[j].income = (my_company[i].salary)/100 * 3 + my_company[i].salary; //income for unmarried students but that have one child

                    else
                        my_student[j].income = my_company[i].salary; //students with no benefits/children
                }
                else
                    my_student[j].income = my_company[i].salary; //students with no benefits/children
            }
        }

        if (strcmp(my_student[j].nat,  "Irish") == 1 || strcmp(my_student[j].nat,  "Irish") == -1) //checking the nationality // 1 and -1 mean that the compared strings are different
            my_student[j].income = my_student[j].income + 200;

    }

}


const char* company_search_name(char code[20])  //function that helps one to print the company's name for the search bar
{
    for(int i=0; i<company_size; i++)  //loop that goes though all of the companies
    {
        if(strcmp(code, my_company[i].registration_code) == 0) //compares the introduce code with the company's registration code
            return my_company[i].company_name; //if they are the same return the companies name
    }
    return "-1"; //else return -1
}


void search_bar(char input_char[20])   //function for the search bar
{
    int match = 0;
    if (input_char[0] >= 65 && input_char[0] <= 90) //ASCII CODE for upper case A and upper case Z
    {                                               //it compares the first letter
        for(int j=0; j<student_size; j++)//loop
        {

            if(input_char[0] == my_student[j].student_name[0]) // if the introduced character matches the first letter of the students name then do the following condition
            {
                printf("|  %s  |  %s  |  %s  |  %s  |  %d  | \n", my_student[j].student_name,
                                                                  my_student[j].student_surmane,
                                                                  my_student[j].PPS,
                                                                  company_search_name(my_student[j].registration_code), //compares registration code of the students to the one of the companies
                                                                  my_student[j].income); //print
                match = 1;
            }

        }
        if (match == 0)
        {
            printf("student not found");
        }
    }

    else
        printf("wrong input\n");
}
void create_file_user()
{
    char file_name[20]; //string that stores data
    char path[1000] = "C:\\Users\\Edy\\Desktop\\em108 test\\"; //my computer's path, which must be changed to examiner's path
    printf("file name: ");
    scanf("%s",file_name); //reads the name of the file
    strncat (path, file_name, 20); // appends the path to the file_name
    printf("path: %s", path); //prints the path
    strncat (path, ".txt", 4); // appends the path to ".txt" to create a text file // 4 is the number of characters of ".txt"
    FILE *fPointer; //create a pointer
    fPointer = fopen(path,"w"); //open a new file in the specified path // use w to indicate a writing action
    fprintf(fPointer, "Name | Surname | Nationality | Company | Registration | Income\n"); // print the following message inside the text file
    for(int j=0; j<student_size; j++) //loop for each student
        fprintf(fPointer, "%s %s %s %s %s %s %d\n", my_student[j].student_name,
                                                    my_student[j].student_surmane,
                                                    my_student[j].PPS, my_student[j].nat,
                                                    company_search_name(my_student[j].registration_code),
                                                    my_student[j].registration_code, my_student[j].income);
    //print the above message in the text file
    fclose(fPointer); //close the file
    printf("\nsuccessfully compiled\n"); //message that indicates a successful process


}

int main()
{
    printf("Welcome to the DCU records!\n");
    printf("\nREMEMBER THAT YOU MUST LOAD THE INFO INTO THE PROGRAM BEFORE GOING AHEAD\n");
    user();

    return 0;
}
