#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


void librarinmenu(char operation[10]);
struct database{
	struct bookinfo *book;
	struct student *studentinfo;
};
struct bookinfo{
char bookname[20];
int bookID;
char writer[20];
char StudentID[20];


};
struct student{
	char name[20];
	char surname[20];
	char studentID[20];	
};
struct borrow{
	struct bookinfo;
	struct student;
};
void main(){
	int statusNum1(fpointer,book);
	int statusNum2(studentpointer,studentinfo);
    FILE *studentpointer;
	struct student *studentinfo=(struct student*) malloc(sizeof(struct student));
	struct bookinfo *book =(struct bookinfo*) malloc(sizeof(struct bookinfo));
char username[10];
char password[10];
char username1[10];
char password1[10];
FILE *fpointer;
//system("COLOR 1D");





    printf("\n\t\t\t\t********************************************\n");
	printf("\t\t\t\t***     WELCOME TO                         ***\n");
	printf("\t\t\t\t***                                        ***\n");
	printf("\t\t\t\t***         LIBRARY                        ***\n");
	printf("\t\t\t\t***                                        ***\n");
	printf("\t\t\t\t***             MANAGEMANT                 ***\n");
	printf("\t\t\t\t***                                        ***\n");
	printf("\t\t\t\t***                 SYSTEM                 ***\n");
	printf("\t\t\t\t***                                        ***\n");
    printf("\t\t\t\t**********************************************\n");
    


int req=0;
int try=0;
FILE *userfp;
userfp=fopen("userpass.txt","r");
fscanf(userfp,"%s %s",username,password);

// printf("Welcome to the library system.\n");
do{


	
/*printf("Please enter your username and password to access the operations...\n");
printf("Username: ");
scanf("%s", &username);
printf("Password: ");
scanf("%s", &password);
if(strcmp(username,"admin")==0&&strcmp(password,"sifre")==0){*/

    printf("\n\t\t\t\tPlease Enter Your Username: ");
    scanf("%s",username1);
    printf("\n\t\t\t\tPlease Enter Your Password: ");
    scanf("%s",password1);
    if(try==3){
	exit(0);
    }
    else{	
    
	if(strcmp(username,username1)==0&&strcmp(password,password1)==0){
    	req = 0;
    	librarianmenu(username,fpointer,book,studentinfo,studentpointer);
   	}
	
	
	else{
		// system("cls");
		try+=1;
		printf("\n\t\t\t\tWrong Username or Password: %d/3",try);
		req=1;
	}

}	


}while(req);

}
	//struct bookinfo *book=(struct bookinfo*) malloc(sizeof(struct bookinfo));
 //librarianmenu(username,fpointer,book,studentpointer);
	/*studentpointer=fopen("Students.txt","w");
	scanf("%s", studentinfo->name);
	scanf("%s", studentinfo->surname);
	scanf("%s", studentinfo->studentID);
	fwrite(studentinfo,sizeof(struct student),1,studentpointer);
	fclose(studentpointer);*/



 void add(FILE *fpointer,struct bookinfo *book){
	
	fpointer=fopen("Books.txt","a");
	
	printf("\t\t\t\t Please Enter the Book Name: ");
	scanf("%s", book->bookname);	
	printf("\t\t\t\tPlease Enter the Writer's Name: ");
	scanf("%s", book->writer);
	printf("\t\t\t\tPlease Enter the ID of the Book: ");
	scanf("%d", &book->bookID);
	// scanf("%s", book->StudentID);
	fwrite((book), sizeof(struct bookinfo),1,fpointer);
	fclose(fpointer);
	
}


 void src(FILE *fpointer){
	struct bookinfo *book=(struct bookinfo*) malloc(sizeof(struct bookinfo));
	struct student *studentinfo=(struct student*) malloc(sizeof(struct student));
	FILE *studentpointer;
	studentpointer=fopen("Students.txt","r");
	fpointer=fopen("Books.txt","r");
	int srcl=0;
	do{
	
	printf("\t\t\t\tChoose the operation type\n");
	printf("\t\t\t\t1-Searching with Book Name(book)\n\t\t\t\t2-Searching with Book ID(id)\n\t\t\t\t3-Searching with Writer's Name(writer)\n");
	char optype[15];
	
	printf("\t\t\t\tEnter the Operation Type: ");
	scanf("%s", &optype);
	//system("cls");
	char bookname1[20];
	char writer[20];
	int bookid1;
	if(strcmp(optype,"book")==0 || strcmp(optype,"1")==0){
	    printf("\t\t\t\tPlease Enter the Book Name: ");
	    scanf("%s",bookname1);
	    system("cls");
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
			//while(!feof(studentpointer)){
				
				if(strcmp((book->bookname),bookname1)==0){
					while(!feof(studentpointer)){
						fread(studentinfo,sizeof(struct student),1,studentpointer);	
					
					if(strcmp((book->StudentID),(studentinfo->studentID))==0){
					printf("\t\t\t\tThe Name of the Book: %s\n",book->bookname);
      				printf("\t\t\t\tThe Writer of the Book: %s\n",book->writer);
      				printf("\t\t\t\tThe ID of the Book: %d\n",book->bookID);
      				printf("\t\t\t\tName of the Student: %s\n",studentinfo->name);
      				printf("\t\t\t\tSurname of the Student %s\n",studentinfo->surname);
      				printf("\t\t\t\tID Number of the Student: %s\n",studentinfo->studentID);
      				break;
					}
					
					/*else if(strcmp((book->StudentID),(studentinfo->studentID))!=0)
					printf("\t\t\t\tThe Name of the Book: %s\n",book->bookname);
      				printf("\t\t\t\tThe Writer of the Book: %s\n",book->writer);
      				printf("\t\t\t\tThe ID of the Book: %d\n",book->bookID);
      				break;
					}*/
				}
				}
			//}
		}
	}
	


	else if(strcmp(optype,"id")==0){
		printf("\t\t\t\tEnter the Book ID: ");
		scanf("%d",&bookid1);
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
				if((book->bookID)==bookid1){
					while(!feof(studentpointer)){
						fread(studentinfo,sizeof(struct student),1,studentpointer);	
					if(strcmp((book->StudentID),(studentinfo->studentID))==0){
					printf("\t\t\t\tThe Name of the Book: %s\n",book->bookname);
      				printf("\t\t\t\tThe Writer of the Book: %s\n",book->writer);
      				printf("\t\t\t\tThe ID of the Book: %d\n",book->bookID);
      				printf("\t\t\t\tName of the Student: %s\n",studentinfo->name);
      				printf("\t\t\t\tSurname of the Student %s\n",studentinfo->surname);
      				printf("\t\t\t\tID Number of the Student: %s\n",studentinfo->studentID);
      				break;
					}
				}
				}	//fread(book,sizeof(struct bookinfo),1,fpointer);
		}
	}

	else if(strcmp(optype,"writer")==0){
		printf("\t\t\t\tEnter the Writer of Book: ");
		scanf("%s", writer);
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
			printf("The book written by %s ",book->writer);
				if(strcmp((book->writer),writer)==0){
					
					printf("%s\n", book->bookname);
			}
		}
		break;
	}
	/*else if(strcmp(optype,"all")==0){
		int count = 0,i=0;
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
				count++;					
		}
		rewind(fpointer);
		for(i = 0; i<count-1; i++){	
			fread(book, sizeof(struct bookinfo),1,fpointer);		
			printf("Name of the Book %s\n", book->bookname);
			printf("Name of the Writer: %s\n", book->writer);
			printf("ID of the Book: %d\n", book->bookID);
		}
	}
	*/

	else{
		printf("\n\t\t\t\tWrong Choice Please Try Again!!\n");
		srcl=1;
	}
	fclose(fpointer);
	fclose(studentpointer);
}while(srcl);
}


 void librarianmenu(char operation1[10],FILE *fpointer, struct bookinfo *book,struct student *studentinfo,FILE *studentpointer){
 char op[10];
 char bookname[20];
 int bookID;
 int libloop=0;
     
     do{

	if(strcmp(operation1,"admin")==0){
	printf("\n\t\t\t\tPlease Enter Name of the Operation\n");
	printf("\t\t\t\t1-Add a New Book (Add)\n");
	printf("\t\t\t\t2-Search a Book (Src)\n");
	printf("\t\t\t\t3-Delete a Book (Dlt)\n");
	printf("\t\t\t\t4-Give a Book (Give)\n");
	printf("\t\t\t\t5-Take a Book Back(Take)");
	printf("\t\t\n\t\t\t\t>>: ");
	scanf("%s", &op);
	//system("cls");
	//While
	if(strcmp(op,"Add")==0 || strcmp(op,"1")==0){	
		add(fpointer,book);
	}	
	
	else if(strcmp(op,"Src")==0 || strcmp(op,"2")==0){
		src(fpointer);
	}
	
	
	/*else if(strcmp(op,"Dlt")==0 || strcmp(op,"3")==0){
		dlt(fpointer);
			}*/
		
	else if(strcmp(op,"Give")==0 || strcmp(op,"4")==0){
		borrow(fpointer);
			}
		
	else if(strcmp(op,"Take")==0 || strcmp(op,"5")==0){
		deletestudentname();
	}
	else {
	
	 
	 printf("\n\t\t\t\tWrong Choose Please Try Again!!\n");
		libloop=1;
	}
}
	}while(libloop);

}





 void borrow(FILE *fpointer){
		struct bookinfo *book=(struct bookinfo*) malloc(sizeof(struct bookinfo));
		printf("\n\t\t\t\tChoose one operation: \n");
		printf("\n\t\t\t\tEnter the name of the book (N)\n");
		printf("\n\t\t\t\tEnter the ID of the book (ID)\n");
		char id[20];
		char op[5];
		scanf("%s", op);
		char bookname123[20];
		int bookid123;
		fpointer=fopen("Books.txt","r+");
		if(strcmp(op,"N")==0){
			printf("\t\t\t\tBookname: ");
			scanf("%s", bookname123);
				while(!feof(fpointer)){	
				fread(book,sizeof(struct bookinfo),1,fpointer);
				if(strcmp((book->bookname),bookname123)==0){
				printf("\n\t\t\t\tEnter the Student ID to Borrow the Book: ");
				scanf("%s", id);
				strcpy(book->StudentID,id);
				fseek(fpointer,-1*sizeof(struct bookinfo),SEEK_CUR);
				fwrite(book,sizeof(struct bookinfo),1,fpointer);
				break;
				}
			}
			
				
		}
		else if(strcmp(op,"ID")==0){
			printf("ID: ");
			scanf("%d", &bookid123);
			while(!feof(fpointer)){	
				fread(book,sizeof(struct bookinfo),1,fpointer);
				if((book->bookID)==bookid123){
					
				}
			}
			printf("\t\t\t\tEnter the Student ID to Borrow the Book: ");
			scanf("%s", id);
			strcpy(book->StudentID,id);
			fseek(fpointer,-1*sizeof(struct bookinfo),SEEK_CUR);
			fwrite(book,sizeof(struct bookinfo),1,fpointer);
		}
		fclose(fpointer);
	}
void addStudent(FILE *studentpointer,struct bookinfo *book){
struct student *studentinfo=(struct student*) malloc(sizeof(struct student));

    studentpointer=fopen("Students.txt","a");

printf("\t\t\t\t Please Enter the Student Name: ");
scanf("%s", studentinfo->name);
printf("\t\t\t\tPlease Enter the Surname Name: ");
scanf("%s", studentinfo->surname);
printf("\t\t\t\tPlease Enter the ID of the Student: ");
scanf("%s",studentinfo->studentID);
// scanf("%s", book->StudentID);
fwrite((studentinfo), sizeof(struct student),1,studentpointer);
fclose(studentpointer);
}
	


void deletestudentname(){
	FILE *fpointer;
	struct bookinfo *book=(struct bookinfo*) malloc(sizeof(struct bookinfo));
	fpointer=fopen("Books.txt","r+");
	int id1;
	printf("\t\t\t\tEnter the Book ID: ");
	scanf("%d", &id1);
	while(!feof(fpointer)){
		fread(book,sizeof(struct bookinfo),1,fpointer);
		if(book->bookID==id1){
			
		strcpy(book->StudentID,"e");
			fseek(fpointer,-1*sizeof(struct bookinfo),SEEK_CUR);
			fwrite(book,sizeof(struct bookinfo),1,fpointer);
			break;
		}
			
	}
	
	
	

	fclose(fpointer);		
}

int statusNum1(FILE *fpointer,struct bookinfo *book){
	int count1=0;
	fpointer=fopen("Books.txt","r");
	while(!feof(fpointer)){
		fread(book,sizeof(struct bookinfo),1,fpointer);
		count1+=1;
	}
	count1-=1;
	//printf("Registered Customer: %d",count);
	fclose(fpointer);
	return count1;
}

int statusNum2(FILE *studentpointer,struct student *studentinfo){
	int count2=0;
	studentpointer=fopen("Students.txt","r");
	while(!feof(studentpointer)){
		fread(studentinfo,sizeof(struct student),1,studentpointer);
		count2+=1;
	}
	count2-=1;
	//printf("Registered Customer: %d",count);
	fclose(studentpointer);
	return count2;
}






