# student_records

## Introduction

A university keeps records of students and companies engaged in the INTRA programme using a 
computer program. This program uses two files (named students.txt and companies.txt) which 
store details on the students and companies, respectively. The files use lines with the following 
format for storing information. 

### students.txt 
Name Surname PPS Nationality Married Children Registration 
Each line contains 7 pieces of information about a student, separated by space. The first two pieces 
of information represent the student name and surname, the third the associated PPS as an 
alphanumeric code, the fourth the student nationality as an alphabetic field, the fifth is an 
indication whether the individual is married or not (e.g. 1 or 0), the sixth is the number of children
the student has and the final field is an alphanumeric entry which contains the registration code 
of the company the student performs his/her INTRA with. 

### companies.txt 
Company Registration Salary Benefits 
Each line contains 4 pieces of information about companies, separated by space. The first is the 
company name, the second is the company unique alphanumeric registration code, the third is 
the salary, expressed in euro and finally benefits indicates whether the company offers or not 
benefits (1 or 0). 

## Development

In this section, I will briefly discuss the thought process behind all the functions I used and what are their meaning/purpose. Similarly, I included a large number of comments inside the code.

### Structures
The declaration of the structures happened outside of the int main function. I have declared the tag of the structures using typedef struct and ended the with the type which varied base on the function. The contents of the functions varied from structure to structure, most essentially, they contained all the required info by the questions. At the end of both structures, I have declared the “name” of each structure, including its size, i.e. company type my_company[company_size].
The company_size/students_size was defined at the top of the code as 10 each (e.g. #define company_size 10), limiting both values. 

### void companies
The void companies function aims at reading all the info from the given text files. It starts with an if statement (i.e. data_read == 0), that prevents the data from being read twice. The first file to be read is the companies file. Inside the if statement, I declared a pointer fPointer that will read the lines inside the text files. Then I used the fopen command to open the specific text file (i.e. using its path) in reading mode (i.e. “r”).  Next, I declared the char single Line and used it together with the fPointer inside a while loop (i.e. both of these variables were affected by the fgets command which made the loop read the lines from the text file into an array until the EOF). I also have used the “sscanf” command that basically reads the info from text file and saves it for all the required variables (i.e. name, surname etc.). Outside of the while loop, I created a different for loop that goes through each company inside the text file and print its info. The reading of companies stops with the command “fclose”. In the same manner, this process repeats for the students’ text file with no major changes rather than the name of the text file. At the end of the if statement I declared that data_read = 1, meaning that the loading of info was successful. Outside of the if statement, there is an else statement that prints a warning message (i.e. prevents one from loading the data again).


### char company_search
The company_search was declared as const because it needed to return a constant and char* so it can return a string of characters. Inside the parameters of the function, I declared the variable company. Then, I used a for loop that goes through all the companies. Inside the for loop, I used an if statement and string compare the variable company with my_company[i].company_name. If they are equal, then the if statement would return the registration code of the company. Otherwise, the function will return “-1”. 

This function will further be explained in the user () function.

### char student_search
The student_search function used const char* for the same reasons as company_search.  Inside the parameters, I declared char name, surname and registration. Next, I used a for loop that will go trough all the students. The loop contained an if statement that used string compare for name and surname. The if statement will happen only if the name and surname equal any of the registered student’s name and surname. Inside the if statement, there is a string copy command that copies the info of my_student[j].registration_code into the variable registration. At the end of the function, I called a different function “write_file” and returned the message “student found”. Likewise, the company_search function, if the student is not found, a warning message will be printed to the screen. 

This function will further be explained in the user () function.

### void Write_file

The write_file function aims to modify one’s company registration code with the new inputted value. I have created a pointer fptr which will read the text file character by character. Further, I used the fopen command to access the path of the user in writing mode (i.e. “w”) and print the required values using fprintf inside a for loop. I closed the function using fclose.

### void student_search_PPS

This function will search for a given PPS number, and if there is a match, it will print a set of details about this specific student. There is a for loop, and inside it, there is a string comparison between student_PPS variable and my_student [j].PPS. If these two values are equal, then the program will print the required information on screen. However, there are two important functions which are also called in this if statement, namely:
student_intra(my_student[j].registration_code)
income_calculation();

This function works on the same basis of match = 0 or match = 1, which I have discussed previously.

### void student_intra

Student_intra function behaves like other functions so that I will discuss just the important parts. Inside the if statement, there is a string comparison between the variable reg_intra and my_company[i].registration_code. This function was called in student_search_PPS with the parameters my_student[j].registration_code, which basically will compare the registration codes provided by the companies with the ones provided by the students. If the function finds a match, then it will print this company’s name, registration code and salary. 

Similarly, this function uses the match=0 or match =1 system.

### void income_calculation

There are two loops, one that goes through all the student and one through all the companies. The main if statement covers all the other if statements and it work only if the registration code of the companies equals the student one. Inside this if statement, I created another if statement for the companies that offer benefits. Likewise, this if statement has an else which indicates that if the company has no benefits, then one’s income equals the salary. If the student has benefits, then there is an if statement checking if this individual has one or more children and if it is married. If that is the case, then, the student will receive an additional 8% to his salary. Likewise, if the student is married but has no children an addition 5% is added to his salary. The last case is if the student is unmarried but has children, the company offering an addition 3% to his salary.
At the end of the for loop, there is an if statement that uses string comparison to check if a person is Irish or not (i.e. equals 1 or -1, meaning that the strings are not equal). The international allowance is 200 euro, and it is not affected by benefits.

### const char company_search_name

Company_search_name function helps seach_bar and create_file_user functions to find the company names of specific students. It contains a for loop, in which there is an if statement and a string comparison between the variable code and my_company[i].registration. Instead of the variable “code”, search_bar and create_file_user functions use my_student[j].registration_code inside the parameters, comparing the registration code of the company with the student’s registration code. If they are equal, then the program will return the name of the company.

### void search_bar

A function like others, with a few distinct features. The if statement of the function checks if the first letter inputted by the user (i.e. [0]) is more significant or equal than 65 (i.e. ASCII CODE for A) and smaller or equal than 90 (ASCII CODE for Z). Then, I used a for loop that will go through all the students and another if statement that checks if the first inputted letter equals any first letters of the student’s names. If that is the case, then the function will print the required details, but if the introduced letter is the lower case, then a warning message will be displayed. Similarly, if the letter does not match any of the students first letters, then a different warning message will be printed.

### void create_file_user

I have used the char variable path to declare the path of the file (i.e. C:\\Users\\Edy\\Desktop\\em108 test\\), but this location depends from user to user, so the examiner must change the to make this function work. Next, I asked the user to input the name of the file, which will be appended with the path using strncat. Likewise, I have appended “.txt” at the end of the path, so the file will become a text file. The following steps were to open the file in writing mode using fopen, use fprintf to write inside the file what was required and fclose to close the file.


### void user

The first thing I did was to call the print_menu function, which prints all the options my program can offer. Then, I asked the user to input their preference using scanf. The while loop stopped the program if the user picked the number six or higher. 

The switch contained the following cases:
- Case 1 simply just calls the companies function which will load the info of the program. 
- Case 2 asks the user for a company name using printf and scanf. I also have created the variable char REG, in which the code will copy the read value and registration code from the company_search(company_Name). The introduced name for the company will be sent in the company_search function and compared with company names, and if there is a match, the registration code will be copied in REG and printed on the screen. The student name function works the same but with more variables inside the parameters and the use of the writing function
- Case 3 requires the user to input its PPS number. This value will then be called in the student_search_PPS function and consequently print the details required.
- Case 4 asks the user to introduce a letter using caps only. I also printed the given template, to make the program most aesthetic (i.e. |  Name  |  Surname  |  PPS  |  Company  |  Income  |). Finally, I called the search_bar function to find the given student’s info.
- Case 5, I just called the create_file_user function.

At the end of function, there is an if statement, that will print a goodbye message if one introduces the number six or higher.

### print menu
It just prints indications for the user and presents all options the program can offer.

### int main

I printed 2 welcoming messages and called the user function.
