/**
	AUTHOR 		:	TEERTHA DEB
	STOP_STALK 	:	stopstalk.com/user/profile/Teertha_Deb
	GitHub		:	github.com/TeerthaDeb
**/

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#define clr system("cls")
struct customer
{
    char fname[100] ,lname[100],acc_type[15],phone[15],Sex[7],bdate[12];
    long long int acc_num,ammount;
};

void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes&0xF0)+(ForgC&0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void gxy(short col, short row)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { col,row };
	SetConsoleCursorPosition(h, position);
}

void wait(int k)
{
    int i;
    for(i=0;i<5;i++){
        printf(" .");
        Sleep(k);
    }
}

void drawboard()
{
    time_t t; time(&t);
    int i,j;
    gxy(0,0);printf("%c" ,201);for(i=0;i<78;i++) printf("%c" ,205); printf("%c" ,187);
    for(i=0;i<23;i++){
        gxy(0,i+1);printf("%c" ,186); gxy(79,i+1); printf("%c" ,186);
    }
    gxy(0,23);
    for(i=0;i<80;i++){
        if(i==0)printf("%c" , 200);
        else if(i==79) printf("%c" ,188);
        else printf("%c", 205);
    }
    gxy(27,22);printf("Date : %s",ctime(&t));
}

void Transection()
{
    clr;
    gxy(0,0);
    drawboard();
    FILE *ptr;
    ptr=fopen("record.dat" , "rb+");
    rewind(ptr);
    gxy(6,2),printf("Enter account number to start transaction: ");
    long long int tmp_acc_num;
    scanf("%lld" ,&tmp_acc_num);
    struct customer cus1,cus2;
    int size=sizeof(struct customer),acc_found=0;
    while(fread(&cus1, size , 1 ,ptr)==1){
        if(tmp_acc_num==cus1.acc_num){
            gxy(6,5),printf("Name=%s %s and amount=%u",cus1.fname,cus1.lname,cus1.ammount);
            gxy(6,8),printf("[1] to cash out");
            gxy(6,10),printf("[2] to cash in");
            gxy(6,12);printf("Enter choice(1/2): ");
            char ch;
            acc_found=1;
            long long int money;
            ch=getch();
            switch(ch){
            	case '1':{																																//perfect
            		case1:
            		gxy(6,14),printf("Enter the amount you want to cash out: ");
            		scanf("%lld",&money);
            		if(money>cus1.ammount){
            			gxy(6,15),printf("This account has only: %lld ", cus1.ammount);
            			gxy(6,16),printf("Enter the amount again: ");
            			Sleep(1800);
            			gxy(15,14);printf("                                                 ");
            			gxy(6,15),printf("                                                  ");
            			gxy(6,16),printf("                                                  ");
            			goto case1;
					}
            		fseek(ptr,-size,SEEK_CUR);
            		cus1.ammount-=money;
            		fwrite(&cus1,size,1,ptr);
            		fseek(ptr,size,SEEK_CUR);
            		gxy(6,17),printf("Successfully Cashed out...\b"),Sleep(1900);
					break;
				}
            	case '2':{																													            //perfect
            				gxy(6,14),printf("Enter the ammount you want to cash in: ");
            				fseek(ptr , -size, SEEK_CUR);
            				scanf("%lld",&money);
            				cus1.ammount+=money;
            				fwrite(&cus1,size,1,ptr);
            				fseek(ptr,size,SEEK_CUR);
            				gxy(6,17),printf("Successfully Cashed In...\b"),Sleep(1900);
            				break;
						}
                default : {
                    gxy(6,13),printf("Invalid Input");
                    wait(600);
                    Transection();
                    break;
                }
        	}
    	}
	}
	if(acc_found==0){
            gxy(6,4),printf("No account number found!!");
            gxy(6,6), printf("Going to main menu");
            wait(600);
    	}
	fclose(ptr);
}

void NewAccount()
{
    long long int i,n;
    clr;
    gxy(0,0);
    FILE *ptr,*ptr2;
    drawboard();
    gxy(6,3),printf("How many accounts you want to add: "); scanf("%lld" ,&n);
    struct customer cus1 , cus2;
    for(i=0;i<n;i++){
        ptr=fopen("temp.dat" , "wb+");ptr2=fopen("record.dat" , "rb+");
        gxy(16,5),printf("Enter details No.%lld of %lld" ,i+1,n);
        gxy(10,7),printf("Enter first Name: "); scanf("%s" ,&cus1.fname);
        gxy(10,8),printf("Enter last Name: "); scanf("%s" ,&cus1.lname);
        gxy(10,9),printf("Enter Phone Number: "); scanf("%s" ,&cus1.phone);
        gxy(10,10),printf("Enter Account Number: "); scanf("%lld" ,&cus1.acc_num);
        while(fread(&cus2, sizeof(struct customer), 1, ptr2)){
        	while(cus2.acc_num==cus1.acc_num){
        		gxy(8,15),printf("\a\a!!!!There is an account with the same account number");
        		gxy(10,16),printf("Enter Account Number again: "); scanf("%lld" ,&cus1.acc_num);
        		gxy(8,15),printf("\t\t\t\t\t\t\t");
        		gxy(8,16),printf("\t\t\t\t\t\t");
        		fseek(ptr2, 0 , SEEK_CUR);
			}
		}
        gxy(10,11),printf("Enter Initial amount: "); scanf("%lld" ,&cus1.ammount);
        gxy(10,12),printf("Enter Date of Birth:(dd/mm/yy) : "); scanf("%s" ,&cus1.bdate);
        gxy(10,13),printf("Account Type :(saving/current): "); scanf("%s" ,&cus1.acc_type);
        gxy(10,14),printf("Enter Gender: ");scanf("%s",&cus1.Sex);
        fwrite(&cus1, sizeof(struct customer), 1, ptr);
        clr;
        drawboard();
        fclose(ptr);
        fclose(ptr2);
        ptr=fopen("record.dat" , "ab+");
        ptr2=fopen("temp.dat" , "rb+");
        fread(&cus1 , sizeof(struct customer),1,ptr2);
        fwrite(&cus1, sizeof(struct customer),1,ptr);
        fclose(ptr);
        fclose(ptr2);
    }
    remove("temp.dat");
}

void ShowInfo()
{
    int i=0,j=1;
    clr;
    gxy(0,0);
    FILE *ptr;
    struct customer cus;
    ptr=fopen("record.dat" , "rb");
    if(ptr==NULL){
    	gxy(15,15);printf("There Currently there is no account with the bank");
    	gxy(15,17);printf("Going to mainmenu");
    	wait(1000);
    	fclose(ptr);
    	return ;
	}
    {
    	gxy(0,0),printf("%c" ,201);for(i=0;i<78;i++) printf("%c" ,205); printf("%c" ,187);
   	 	gxy(0,1),printf("%c" ,186); gxy(79,1),printf("%c" ,186);
    	gxy(0,2);
    	for(i=0;i<80;i++){
        if(i==0)printf("%c" , 204);
        else if(i==79) printf("%c" ,185);
        else printf("%c", 205);
    }
    }
    gxy(1,1),printf("Account Number\t|\t\tName\t\t|\tPhone\t|\tamount");
    while(fread(&cus, sizeof(struct customer), 1, ptr)){
        j++;
        gxy(0,j+1),printf("%c" ,186);
        char name[200];
        strcpy(name , cus.fname);
        strcat(name , " ");
        strcat(name , cus.lname);
        printf("%15lld|%31s|%15s|%14lld" ,cus.acc_num,name,cus.phone,cus.ammount);
        gxy(79,j+1),printf("%c" ,186);
    }
    gxy(0,j+2);
    for(i=0;i<80;i++){
        if(i==0)printf("%c" , 200);
        else if(i==79) printf("%c" ,188);
        else printf("%c", 205);
    }
    gxy(15,j+5),printf("Press any key to go to main menu.\b");
    fclose(ptr);
    getch();
}

void Check_account()
{
	clr;
	drawboard();
	gxy(0,0);
    FILE *ptr;
    struct customer cus;
    char cho;
    ptr=fopen("record.dat" , "rb");
	gxy(6,3),printf("How You want to search: ");
	gxy(6,5),printf("[1] By name: ");
	gxy(6,7),printf("[2] By account Number: ");
	gxy(6,9),printf("Enter Your choice(1/2): ");
	cho=getch();
	switch(cho){
		case '1':{
			cas1:
			clr;
			drawboard();
			gxy(4,9),printf("Enter The first name You want to check: ");
			char name[50];
			scanf("%s" ,&name);
			int acc_find=0;
            while(fread(&cus, sizeof(struct customer), 1, ptr)){
			 	if(!strcmp(name , cus.fname)){
			 		clr;
					drawboard();
			 		acc_find=1;
        			gxy(10,6),printf("First Name: %s" ,cus.fname);
        			gxy(10,7),printf("Last Name: %s" ,cus.lname);
       				gxy(10,8),printf("Phone Number: %s" ,cus.phone);
        			gxy(10,9),printf("Account Number: %lld" ,cus.acc_num);
        			gxy(10,10),printf("Amount: %lld",cus.ammount);
        			gxy(10,11),printf("Date of Birth : %s" ,cus.bdate);
        			gxy(10,12),printf("Account Type : %s"  ,cus.acc_type);
        			gxy(10,13),printf("Gender: %s",cus.Sex);
        			gxy(16,15),printf("Press any key to go to main menu...");
                    getch();
				 }
			 }
			 if(acc_find==0){
			 	char ch2;
			 	fseek(ptr, 0, SEEK_SET);
			 	gxy(9,10),printf("NO account found with the Name: ");
			 	gxy(9,12),printf("Do You want to search again: (Y/N): ");
			 	ch2=getch();
			 	if(ch2=='Y'||ch2=='y') goto cas1;
			 }
			break;
		}
		case '2':{
			cas2:
			clr;
			drawboard();
			long long int ac_num;
			gxy(4,9),printf("Enter The account number you want to check: ");
			scanf("%lld" ,&ac_num);
			int acc_find=0;
			 while(fread(&cus, sizeof(struct customer), 1, ptr)){
			 	if(ac_num-cus.acc_num==0){
			 		clr;
			 		drawboard();
			 		acc_find=1;
        			gxy(10,6),printf("First Name: %s" ,cus.fname);
        			gxy(10,7),printf("Last Name: %s" ,cus.lname);
       				gxy(10,8),printf("Phone Number: %s" ,cus.phone);
        			gxy(10,9),printf("Account Number: %lld" ,cus.acc_num);
        			gxy(10,10),printf("Amount: %lld",cus.ammount);
        			gxy(10,11),printf("Date of Birth : %s" ,cus.bdate);
        			gxy(10,12),printf("Account Type : %s"  ,cus.acc_type);
        			gxy(10,13),printf("Gender: %s",cus.Sex);
        			gxy(16,15),printf("Press any key to go to main menu...");
                    getch();
				 }
			 }
			 if(acc_find==0){
			 	char ch2;
			 	fseek(ptr, 0, SEEK_SET);
			 	gxy(9,10),printf("NO account found with the Number: ");
			 	gxy(9,12),printf("Do You want to search again: (Y/N): ");
			 	ch2=getch();
			 	if(ch2=='Y'||ch2=='y') goto cas2;
			 }
			break;
		}
	}
	fclose(ptr);
}

void ext()
{
	setcolor(14);
    clr;
    drawboard();
    gxy(35,11);printf("exiting.");
    wait(700);
    gxy(0,24);
    exit(0);
}

void change_password()
{
	int i;
    clr;
    drawboard();
    FILE *ptr;
    ptr=fopen("pa.tj","rb+");
    char pa1[100],pa2[100];
    gxy(22,9),printf("Enter Current Password: ");
    scanf("%s",&pa1);
    for(i=0;pa1[i];i++){
        pa1[i]=1+~pa1[i];
    }
    fgets(pa2, 100, ptr);
    if(strcmp(pa1,pa2)){
        gxy(14,11);printf("Password Not matched.\a");
    	fclose(ptr);
    	printf("Going to main menu.");
    	wait(600);
    }
    else{
    	fclose(ptr);
		clr;
    	drawboard();
   		ptr=fopen("pa.tj","wb+");
    	gxy(10,8),printf("Set a New password for your management system: ");
    	char pa1[100],pa2[100];
    	scanf("%s" ,&pa1);
    	gxy(15,10),printf("Confirm password: ");
    	scanf("%s" ,&pa2);
    	if(!strcasecmp(pa1,pa2)){
        	gxy(10,20),printf("Password matched.Setting password");
        	wait(200);
        	for(i=0;pa1[i];i++){                                        //encrypt
            	pa1[i]=1+~pa1[i];
        	}
        	fputs(pa1, ptr);
    	}
    	else{
        fclose(ptr);
        clr;
        gxy(10,20),printf("Both passwords did not matched. Enter the password again.");
        Sleep(600);
        fclose(ptr);
        change_password();
    	}
	}
}

void matchpass()
{
    int i;
    clr;
    drawboard();
    FILE *ptr;
    ptr=fopen("pa.tj","rb+");
    char pa1[100],pa2[100];
    gxy(22,9),printf("Enter Password: ");
    scanf("%s",&pa1);
    for(i=0;pa1[i];i++){
        pa1[i]=1+~pa1[i];
    }
    fgets(pa2, 100, ptr);
    if(strcmp(pa1,pa2)){
        gxy(14,11);printf("Password Not matched. Enter again.\a");
        wait(800);
    fclose(ptr);
    matchpass();
    }

    else{
        clr;
        drawboard();
        gxy(20,9),printf("Password Matched.");
    }
    fclose(ptr);
}

void Remove_Account()
{
    FILE *ptr1,*ptr2;
    ptr1=fopen("record.dat" , "rb");
    ptr2=fopen("temp.dat" , "wb+");
    setcolor(04);
    clr;
    drawboard();
    struct customer cus1  , cus2 ;
    gxy(6,4),printf("Enter the Account Number that you want to remove: ");
    unsigned long long int delacc,tmp;
    scanf("%u" ,&delacc);
    int acc_find=0;
    while(fread(&cus1, sizeof(struct customer), 1, ptr1)){
        tmp=cus1.acc_num;
        if(tmp==delacc){
            acc_find=999;
        }
        else{
            cus2=cus1;
            fwrite(&cus2, sizeof(struct customer) ,1 , ptr2);
        }
    }
    if(acc_find>0){
        gxy(10,6),printf("Deleted the target account");
        gxy(10,8),printf("Going to main menu");
        Sleep(750);
        wait(600);
    }
    else{
        gxy(10,6),printf("Not found the target account");
        gxy(10,8),printf("Want to search again? (Y/N)");
        char cho;
        cho=getch();
        if(cho=='Y'||cho=='y'){
            fseek(ptr1 , 0 ,SEEK_SET);
            fseek(ptr2 , 0 ,SEEK_SET);
            Remove_Account();
        }
    }
    fclose(ptr1),fclose(ptr2);
    remove("record.dat");
    rename("temp.dat" , "record.dat");
}

void SetPass()
{
	int i;
	FILE *ptr;
	clr;
   	drawboard();
   	ptr=fopen("pa.tj","wb+");
   	gxy(10,8),printf("Set a password for your management system: ");
   	char pa1[100],pa2[100];
   	scanf("%s" ,&pa1);
   	gxy(15,10),printf("Confirm password: ");
   	scanf("%s" ,&pa2);
   	if(!strcasecmp(pa1,pa2)){
       	gxy(10,20),printf("Password matched.Setting password");
       	wait(600);
       	for(i=0;pa1[i];i++){                                        //encrypt
           	pa1[i]=1+~pa1[i];
       	}
       	fputs(pa1, ptr);
   	}
   	else{
       fclose(ptr);
       gxy(10,20),printf("Both passwords did not matched. Enter the password again: ");
       Sleep(2400);
       fclose(ptr);
       SetPass();
   	}
   	fclose(ptr);
}

void MainMenu()
{
	setcolor(15);
    clr;
    char ch;
    drawboard();
    gxy(30,1);printf(">>>>>MAIN MENU<<<<<");
    gxy(27,4);printf("[1] to Create new account");
    gxy(27,6);printf("[2] to Show All accounts");
    gxy(27,8);printf("[3] to Start Transection");
    gxy(27,10);printf("[4] to Check existing account");
    gxy(27,12);printf("[5] to Remove an account");
    gxy(27,14);printf("[6] to Change Password");
    gxy(27,16);printf("[7] to Exit");
    gxy(27,20);printf("Enter Your choice(1-7) : ");ch=getch();
    printf("ch=%c" ,ch);
    switch(ch){
        case '1':{
                    NewAccount();
                    break;
                    }
        case '2':{
                    ShowInfo();
                    break;
                    }
        case '3':{
        			Transection();
					break;
				}
		case '4':{
					Check_account();
					break;
				}
        case '5':{
                    Remove_Account();
                    break;
                }
        case '6':{
                    change_password();
                    break;
                	}
        case '7':{
                    ext();
                    }
        default :{
        			clr;
        			drawboard();
        			gxy(10,10),printf("Invalid Input");
        			wait(450);
					break;
		}
    }
    MainMenu();
}

void main()
{
	setcolor(14);
    FILE *ptr;
    ptr=fopen("pa.tj","ab+");
    fseek(ptr, 0, SEEK_END);
    if(ftell(ptr)==0){
        fclose(ptr);
        SetPass();
    }
    else{
    	int i;
        fclose(ptr);
        matchpass();
        gxy(20,15),printf("Going to Main Menu.");
        wait(600);
    }
    fclose(ptr);
    MainMenu();
    gxy(0,24);
}
