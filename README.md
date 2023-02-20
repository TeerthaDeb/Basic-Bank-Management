"//***********************************************************************",
"// Author: Maharaj Teertha Deb ;\t*\t; GitHub: github.com/TeerthaDeb",
"//***********************************************************************\n\n",

Welcome to the Basic Project


A Report on Project: 
Bank Management System

by

## Maharaj Teertha Deb

## Git: github.com/TeerthaDeb
## Stop_stalk : stopstalk.com/user/profile/Teertha_Deb

## List of functions and their operation in the Project:

1.	setcolor(): This function is used to make colors in the projects. For example: when the project file is opened for the first time, the texts are colored yellow. When user enters in the main menu, the text is then colored white and when user enters to the remove account section the text and borders are then colored red.

2.	gxy(): This function is used to move the cursor in any position of the screen. 

3.	drawboard(): This function is used to draw board on the screen. When the project is opened, it is found that there are boxes in the main menu as well as in the other sections of the project. This function is called to draw boxes in the output screen while the project is being executed.

4.	wait(): This function is used to show the loading screen to the user. When the project is saving or deleting record files, it takes some times. Then loading screen is displayed to the user, thus it indicates that the program is saving, deleting or replacing something to the record file. 

5.	Transection(): This function manages all the transection parts of the project. 
 
6.	NewAccount(): When user tries to create new account with the back, NewAccount function is called to create new account. 

7.	ShowInfo(): This function collects all the brief information about all the account holders from the record file and presents them.

8.	Check_account(): This function is used to see the full information of an account. 

9.	ext(): This function is used when user want to exit from the project. 

10.	change_password(): This function allows user to change password of the management system. But password is encrypted before being saved.

11.	matchpass(): matchpass function is called to math the log in password. User needs to enter log in password in order to log into the management system. If given password is matched with the current password, then user gets access, otherwise the function doesn’t allow into the system.

12.	Remove_Account(): The function is called to remove the target account from the record file.

13.	SetPass(): This function allows users to set a new password for the system. It asks user to set a new password and again asks to confirm the password. If both the passwords match, this function encrypts the password and sets this as log in password for the management system.

14.	MainMenu(): This is the core function of the management system. When user logs into the management, this function is called. User calls other functions, according to users need, through this function.

15.	GetStdHandle(): GetStdHandle function gives a mechanism for retrieving the standard output, input or error handles

16.	getConsoleScreenBufferInfo(): The function retrieves information about the specified console screen buffer.

17.	setConsoleTextAttribute(): The function sets the foreground text and background color attributes of characters written to the screen buffer. This function affects only text written after the function call.

18.	setConsoleCursorPosition(): This function sets the cursor position in the console screen buffer. 

19.	printf(): This function prints the parameters passed to it. It has format specifier to represent int, char, float etc. variables.

20.	scanf(): This function takes input for varies datatypes variables. User needs to use the specific format specifier for specific datatypes.

21.	time(): This function sets int value to the variable passed to it. Value is the seconds passed since the first second of the year 1970

22.	ctime(): This function takes int type variable and returns the specific date as string datatype, counting the variable passed to the function. 

23.	fopen(): This function opens specific file from a specific location, with the mode passed to the function.

24.	rewind(): This function takes a file pointer to the beginning of file that the file pointer is pointing.

25.	sizeof(): This function returns the value of any datatype, structure or array passed to the function.

26.	fread(): This function reads packet(structure, array or other datatype) of data from a specific file that the pointer is pointing and returns the values to  structure, array or any other datatype variable.

27.	fseek(): This function seeks the curser to a particular location of the file that is being pointed by a file pointer.

28.	fwrite(): This function writes packet(structure, array or other datatype) of data, written to the packet, to a specific file that the pointer is pointing.

29.	fclose(): This function closes the file that is being pointed by the pointer that is passed to the function.

30.	remove(): This function deletes the specific file from a specific location passed to the function.

31.	rename(): This function renames a file to another name;

32.	strcat(): This function takes two strings as it’s parameter and joins the second string to the first string passed to the function.

33.	strcpy(): The function copies the string pointed by source (including the null character) to the destination. 

34.	strcmp(): This function compares two strings and returns zero if two strings are same and returns nonzero value otherwise.

35.	exit(): exit() function terminates the program. File buffers are flushed, streams are closed, and temporary files are deleted.

## Description of the project:
1. Login: When the project is opened for the first time, is asks user to select a password.
 If given password and confirm password is not same, then the program will ask the user to set password again. And if both password matches, the password is set.
  

2. Main Menu: The program will then take user to the main menu and user will get all the access of the system through this.
	Userneeds press any key to manage the system.
 

3. Create New account: If user selects 1, then user will be directed to the new account section. 
	And will be asked how many accounts  to be added. User can select any number of accounts to be created, and then can give the informations nedded to open a bank account.
	However, if there are any previous accounts with the bank, these account(s) will remain as they are, but new account with an account number of any existing account will not be created, as all the accounts should be unique.
  

4. Show all accounts: If user wants to see all the accounts and necessary details, user needs to go back to main menu and press 2
	All the accounts will be listed in the screen.
 

5. Transection :  This project allows user to make successful transection for the account holders. 
	User needs to go to the main menu and select 3 to call the transection section of the project. When user calls the transection section, program asks for the account number, as all account numbers are unique, no multiple accounts will be selected during the process.
  	If user enters the correct account number then the program will show the name and amount of the account holder to make sure that the user selected the target account successfully and how much can be cashed out.

	If user wants to cash out more amount than the amount is in the account, the program will warn the user that it is not possible.
  
	But It is possible to cash out lower or equal amount currently stored in the account. However, any amount can be cashed in to the account.
 

6. Check full details of an account : If user needs to check full details of an existing account, user needs to go to the main menu section and then select 4. 
	Then user will be asked to account holder name or account number.  
	If the name or account number is not present in the record, a message will pop up that no such account with the name or account number is present in the record But if present then it will be shown in the screen.
 

7. Delete an account : Sometimes some accounts need to be deleted. 
	And user can do this easily by going to main menu and press 5. The texts in the screen then will be red to warn the user that the deleted account can’t be recalled.
  	If user enters an account number, the account will be deleted from the list.
 
 
8. Update current password:  Some times the current password for the project needs to be changed. 
	User can change this by selecting 6 from the main menu. 
	User then need to enter the current password and then can set a new password for the management system. When a password is set, the password is encrypted by bitmasking to ensure security.
  

9. Exiting from program:  Finally, when everything is done, user can call the ext function from main menu by pressing 7 and all the memory will be cleared and the program will be terminated within a few seconds.
