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
	char name[10];
	char surname[10];
	char studentID[6];	
};
struct borrow{
	struct bookinfo;
	struct student;
};
void main(){
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
	printf("1-Searching with Book Name(book)\n2-Searching with Book ID(id)\n3-Searching with Writer's Name(writer)\n");
	char optype[15];
	
	printf("Enter the Operation Type: ");
	scanf("%s", &optype);
	//system("cls");
	char bookname1[20];
	char writer[20];
	int bookid1;
	if(strcmp(optype,"book")==0 || strcmp(optype,"1")==0){
	    printf("Please Enter the Book Name: ");
	    scanf("%s",bookname1);
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
			while(!feof(studentpointer)){
				fread(studentinfo,sizeof(struct student),1,studentpointer);
			
				
				if(strcmp((book->bookname),bookname1)==0){
					//printf("Name of the Book %s\n", book->bookname);
					//printf("Name of the Writer: %s\n", book->writer);
					//printf("ID of the Book: %d\n", book->bookID);
					if(strcmp((book->StudentID),(studentinfo->studentID))==0){
					printf("The Name of the Book: %s\n",book->bookname);
      				printf("The Writer of the Book: %s\n",book->writer);
      				printf("The ID of the Book: %d\n",book->bookID);
      				printf("Name of the Student: %s\n",studentinfo->name);
      				printf("Surname of the Student %s\n",studentinfo->surname);
      				printf("ID Number of the Student: %s\n",studentinfo->studentID);
					}
					else{
						printf("The name of the Book: %s\n",book->bookname);
      					printf("The writer of the Book: %s\n",book->writer);
      					printf("The ID of The Book: %d\n",book->bookID);
						printf("Book is avaliable");
					}
				
				}
			}
		}
		break;
	}
	else if(strcmp(optype,"id")==0){
		printf("Enter the Book ID: ");
		scanf("%d",&bookid1);
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
				if((book->bookID)==bookid1){
					if(strcmp((book->StudentID),(studentinfo->studentID))==0){
					printf("The Name of the Book: %s\n",book->bookname);
      				printf("The Writer of the Book: %s\n",book->writer);
      				printf("The ID of the Book: %d\n",book->bookID);
      				printf("Name of the Student: %s\n",studentinfo->name);
      				printf("Surname of the Student %s\n",studentinfo->surname);
      				printf("ID Number of the Student: %s\n",studentinfo->studentID);
					}
					else{
						printf("The name of the Book: %s\n",book->bookname);
      					printf("The writer of the Book: %s\n",book->writer);
      					printf("The ID of The Book: %d\n",book->bookID);
						printf("Book is avaliable");
					}
					break;
					
				}	//fread(book,sizeof(struct bookinfo),1,fpointer);
		}
	}

	else if(strcmp(optype,"writer")==0){
		printf("Enter the Writer of Book: ");
		scanf("%s", writer);
		while(!feof(fpointer)){
			fread(book, sizeof(struct bookinfo),1,fpointer);
				if(strcmp((book->writer),writer)==0){
					printf("Name of the Book %s\n", book->bookname);
					printf("Name of the Writer: %s\n", book->writer);
					printf("ID of the Book: %d\n", book->bookID);
			}
		}
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
		
	else if(strcmp(op,"Take")==0){
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
		printf("\nChoose one operation: \n");
		printf("\nEnter the name of the book (N)\n");
		printf("\nEnter the ID of the book (ID)\n");
		char id[20];
		char op[5];
		scanf("%s", op);
		char bookname123[20];
		int bookid123;
		fpointer=fopen("Books.txt","r+");
		if(strcmp(op,"N")==0){
			printf("Bookname: ");
			scanf("%s", bookname123);
				while(!feof(fpointer)){	
				fread(book,sizeof(struct bookinfo),1,fpointer);
				if(strcmp((book->bookname),bookname123)==0){
					
				}
			}
			
				printf("\nEnter the Student ID to Borrow the Book: ");
				scanf("%s", id);
				strcpy(book->StudentID,id);
				fseek(fpointer,-1*sizeof(struct bookinfo),SEEK_CUR);
				fwrite(book,sizeof(struct bookinfo),1,fpointer);
		}
		else if(strcmp(op,"ID")==0){
			printf("ID: ");
			scanf("%d", &bookid123);
			while(!feof(fpointer)){	
				fread(book,sizeof(struct bookinfo),1,fpointer);
				if((book->bookID)==bookid123){
					
				}
			}
			printf("Enter the Student ID to Borrow the Book: ");
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
	printf("Enter the Book ID: ");
	int id;
	printf("Enter the book ID: ");
	scanf("%d", &id);
	while(!feof(fpointer)){
		fread(book,sizeof(struct bookinfo),1,fpointer);
		if(book->bookID==id){
			

		}

	}
	
	fseek(fpointer,-1*sizeof(struct bookinfo),SEEK_CUR);
	strcpy(book->StudentID,"");
	fprintf(fpointer,book);
	fclose(fpointer);
}





