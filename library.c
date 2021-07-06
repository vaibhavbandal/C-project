#include<string.h>
#include<conio.h> 
#include<stdlib.h>  
#include<stdio.h>

// File Name = admin.txt
struct admin{
          
          char password[40]; 
}a; 
  // File Name =librarian.txt
struct librarian{ 
          int id;
          char name[40];
          char addr[100];
          char mobile[12];
          char doj[12];
          char aadhar[15];
          float salary;
          char password[40];
}l;  
// File Name =book.txt
struct book{
     char id[50];                   // 1
     char name[50];                 // 2
     char author[50];               // 3
     char std[50];                  // 4
     int totalQuantity;             // 5
     int issueQuantity;             // 6
     int presentQuantity;           // 7
     float price;                   // 8

}b;

// File Name =student.txt
struct student{
         char id[50];   //1
         char name[50];   //2
         char addr[50];   //3
         char aadhar[15];
         char mobile[12];    //4
         char std[20];    //5
         char username[20];    //6
         char password[20];     //7
         char dateofIssue[12];    //8
         char dateofReturn[12];    //9
         char  bID[50];   // if bID is -1 or NULL then those student dont have b .   //10 
}s;

  // Forward Declaration 
void mainHeading(); 
void layout();
void projectInfo();
void mainMenu();
void studentLogin();
void librarianLogin();
void adminLogin(); 
void adminMenu(); 
void insertLibrarian();
void displayLibrarian();
void deleteLibrarian();
void updateLibrarian();
void changePasswordAdmin(); 
void librarianLogin();
void librarianMenu(struct librarian);
void changePasswordLibrarian(struct librarian);  
void bookMenu(struct librarian);
void studentMenu(struct librarian); 
void insertStudent(struct librarian);
void insertBook(struct librarian);
void displayBook(struct librarian);
void displayStudent(struct librarian);
void deleteStudent(struct librarian);
void deleteBook(struct librarian);
void searchBook(struct librarian); 
void searchStudent(struct librarian);
void updateBook(struct librarian);
void updateStudent(struct librarian);
void bookDatabase(struct librarian); 
void bookIssue(struct librarian); 
void bookReturn(struct librarian);  
void studentLogin();
void studentMenu2(char[50]);
void studentBooks(char[50]); 
void studentProfile(char[50]); 
void changePasswordStudent(char[50]);


int main(){ 
            mainMenu(); 
 return 0;}  

 void mainMenu(){ 
                layout(); 
                int ch;
                printf("\n\t\t\t\t----------------------------");
                printf("\n\t\t\t\t         Main Menu          ");
                printf("\n\t\t\t\t----------------------------");
                printf("\n\t\t[1] Admin"); 
                printf("\n\t\t[2] Librarian");
                printf("\n\t\t[3] Student");
                printf("\n\t\t[4] Close Application");
                printf("\n\t\tEnter Your Choice:");
                scanf("%d",&ch); 
                switch (ch)
                {
                case 3:
                          studentLogin();
                    break;
                case 2:
                          librarianLogin();  
                    break;
                case 1:
                          adminLogin();   
                    break;
                case 4:  exit(0);
                    break; 
             
                
                default: 
                    mainMenu(); 
                    break;
                 }
}
 
void mainHeading()
{
printf("\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  Library Management System  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \n\n\n");
} 



void adminLogin(){
          layout();       
          fflush(stdin); 
          printf("\n\t\t\t Enter Admin Password:");
          char password[50];
          gets(password); 

          FILE *fp=fopen("admin.txt","rb");
          if(fp==NULL){
              printf("admin.txt file cant open "); mainMenu(); 
          }
            char s[50];
           fread(&s,sizeof(s),1,fp);
          if(strcmp(password,s)==0){
                   fclose(fp); 
            printf("\n\t\t\t Log in success ");
             printf("\n\t\t\t Enter any key to continue....");
             getch(); 
             adminMenu();
          }else{
            printf("\n\t\t\t Log in Failed...! ");
                   fclose(fp); 

          }
              
 

 printf("\n\t\t\t Enter any key to continue....");
        getch(); 
        mainMenu(); 

}

void adminMenu(){ 
                
          layout();
               int ch; 
                printf("\n\t\t\t\t---------------");
                printf("\n\t\t\t\tAdmin Menu ");
                printf("\n\t\t\t\t---------------");
                printf("\n\t\t [1] Insert New Librarian     ");
                printf("\n\t\t [2] Delete Librarian     ");
                printf("\n\t\t [3] Display Librarian     ");
                printf("\n\t\t [4] Update Librarian     ");
                printf("\n\t\t [5] Change Password Admin     ");
                printf("\n\t\t [6] Exit or Logout");
                printf("\n\n\t\tEnter Your Choice:");
                scanf("%d",&ch); 
                
                switch (ch) 
                {
                case 1:
                            insertLibrarian();                       
                    break;
                case 2:     deleteLibrarian();
                    break;
                case 3:     displayLibrarian();
                    break;
                case 4:     updateLibrarian();       
                    break; 
                case 5:     changePasswordAdmin();   
                    break; 
                case 6:     mainMenu();  
                    break;
                default:     adminMenu(); 
                    break;
                }
} 

void layout(){
  
  system("cls"); mainHeading(); 
}

void insertLibrarian(){

      layout();
            printf("\n\t\t\t  -----------------------Register New Librarian -------------------            \n\n\n\t\t\t\t");

          FILE *fp;
          fp=fopen("librarian.txt","ab+"); //append binary 
          if(fp==NULL){
            printf("\n File open failed -librarian.txt "); adminMenu(); 
          }
           

 
            printf("\n\t\t\t  Enter Id:");
            scanf("%d",&l.id);
            fflush(stdin);
            printf("\n\t\t\t  Enter Name:");
            gets(l.name);
           printf("\n\n\t\t\t  Enter Address:");
            gets(l.addr); 
           printf("\n\n\t\t\t  Enter Aadhar No:");
            gets(l.aadhar); 
           printf("\n\n\t\t\t  Enter Date of Joining:");
            gets(l.doj);
          printf("\n\t\t\t  Enter Mobile No:"); 
            gets(l.mobile);
          printf("\n\n\t\t\t  Enter Salary:"); 
          scanf("%f",&l.salary);   
          fflush(stdin); 
          strcpy(l.password,l.mobile);  
          fwrite(&l,sizeof(l),1,fp); 
          printf("\n\n\t\t\t Submitted succesfully ..");

          fclose(fp);  

        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        adminMenu(); 

}

void displayLibrarian(){
  layout();
          FILE  *fp;
          fp=fopen("librarian.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , librarian.txt ");  adminMenu(); 
          }

            printf("\n\t\t\t ====LIBRARIAN LIST========  ")  ; 
            while (fread(&l,sizeof(l),1,fp)==1)
            {
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %d",l.id); 
            printf("\n\t\t\t NAME = %s",l.name); 
            printf("\n\t\t\t Address = %s",l.addr); 
            printf("\n\t\t\t Aadhar = %s",l.aadhar); 
            printf("\n\t\t\t DATE  = %s",l.doj);     
            printf("\n\t\t\t PHONE  = %s",l.mobile); 
            printf("\n\t\t\t SALARY  = %f",l.salary); 
            printf("\n\t\t\t======================================================");
            }
            
            
        fclose(fp); 
     printf("\n\t\t\t Enter any key to continue....");
        getch();  
        adminMenu(); 
}
       
void deleteLibrarian(){
    layout();
printf("\n\t\t\t  -----------------------Delete Librarian -------------------            \n\n\n\t\t\t\t");
            int id;
            printf("\n\t\t\t Enter Librarian Id :");
            scanf("%d",&id);

            FILE *fp,*ft;

            fp=fopen("librarian.txt","rb"); // read binary
            if(fp==NULL){
              printf("\n File open error .. librarian.txt "); adminMenu();
            }

            ft=fopen("temp.txt","ab+");
            if(ft==NULL){
              printf("\n File open error .. temp.txt "); adminMenu();
            }
            int flag=0;
            while (fread(&l,sizeof(l),1,fp)==1)
            {
               if(l.id==id){
                   flag=1; 
               }else{
                  fwrite(&l,sizeof(l),1,ft);
               }
            }
            
            if(flag==1){
              printf("\n\t\t\t Record Deleted ..");
            }else{
              printf("\n\t\t\t Not Found  ..");
            }

            fclose(fp);
            fclose(ft);

            remove("librarian.txt");
            rename("temp.txt","librarian.txt");  

        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        adminMenu();


}     
 
 void updateLibrarian(){
          layout();
          int id;
          printf("\n\t\t\t  -----------------------Update Librarian -------------------            \n\n\n\t\t\t\t");
          printf("\n\t\t\t Enter Librarian ID for Update:");
          scanf("%d",&id);

           FILE *fp,*ft;

           fp=fopen("librarian.txt","rb"); // read binary
            if(fp==NULL){
              printf("\n File open error .. librarian.txt "); adminMenu();
            }
           
            ft=fopen("temp.txt","ab+"); 
            if(ft==NULL){
              printf("\n File open error .. temp.txt "); adminMenu();
            }


            int flag=0;
            while (fread(&l,sizeof(l),1,fp)==1)
            {
               if(l.id==id){
                   flag=1; 
               }else{
                  fwrite(&l,sizeof(l),1,ft);
               }
            }


            if(flag==1){
            l.id=id;
             fflush(stdin);
            printf("\n\t\t\t  Enter UPDATED Name:");
            gets(l.name);
           printf("\n\n\t\t\t  Enter UPDATED Addr:");
            gets(l.addr);
           printf("\n\n\t\t\t  Enter UPDATED Aadhar Card No:");
            gets(l.aadhar);
           printf("\n\n\t\t\t  Enter UPDATED Date of Joining:");
            gets(l.doj);
          printf("\n\t\t\t  Enter UPDATED Mobile No:"); 
            gets(l.mobile);
          printf("\n\n\t\t\t  Enter UPDATED Salary:"); 
          scanf("%f",&l.salary);   
          fflush(stdin); 
          fwrite(&l,sizeof(l),1,ft);  

                 printf("\n\n\t\t\t Succesfully Updated...");
            }else{
               printf("\n\t\t\t Id not Found..");
            }


            fclose(fp);
            fclose(ft); 

            remove("librarian.txt");
            rename("temp.txt","librarian.txt");  



        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        adminMenu();     
 }
                           
 void changePasswordAdmin(){
        layout();
        char password1[50]; 
        char password2[50];
        printf("\n\t\t\t  ----------------------- Update Password -------------------            \n\n\n\t\t\t\t");
        fflush(stdin);
        printf("\n\t\t\t Enter Old Password:");
        gets(password1);
        FILE *fp;
        fp=fopen("admin.txt","r+");
        if(fp==NULL){
          printf("\n Error in File Opening -admin.txt file"); adminMenu();
        }
        fread(&password2,sizeof(password2),1,fp);
        if(strcmp(password2,password1)==0){ 
          char pass1[50],pass2[50];
              printf("\n\t\t\t Password matched "); 
              printf("\n\t\t\t Enter New Password :");fflush(stdin);
              gets(pass1);fflush(stdin);
              printf("\n\t\t\t Confirm Password :");fflush(stdin); 
              gets(pass2);fflush(stdin);
              if(strcmp(pass1,pass2)==0){
                FILE *ft=fopen("temp.txt","w+");
                if(ft==NULL){
                  printf("\n temp.txt file open error in admin change password ");
                  getch(); adminMenu();
                }
                  fprintf(ft,pass1);
                  fclose(ft);
                  fclose(fp); 
                  remove("admin.txt");
                  rename("temp.txt","admin.txt"); 
                printf("\n\t\t\t Updated Succesfully ");
              }else{
                printf("\n\t\t\t Password don't Matched ...!");
              }
        }else{
            printf("\n\t\t\t Password not matched.."); 
        }
        fclose(fp);
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        adminMenu(); 
 }
          
void librarianLogin(){
        layout();
        fflush(stdin);
        char password[50];
        printf("\n\t\t\t ################################# LIBRARIAN LOGIN ################################# \n\n\n");
        printf("\n\t\t\t YOUR MOBILE NO IS YOUR PASSWORD ,AND YOU CAN CHANGE PASSWORD :");
        printf("\n\t\t\t ENTER PASSWORD :");
        gets(password);

        FILE *fp;
        fp=fopen("librarian.txt","rb"); // File Mode = read binary 
        if(fp==NULL){
          printf("\n\t\t\t Error in file open , librarian.txt "); 
          printf("\n\t\t\t Enter any key to continue....");
          getch();  mainMenu();
        }
        
         int flag=0; struct librarian temp_librarian;
        while (fread(&l,sizeof(l),1,fp)==1)
        {
            if(strcmp(password,l.password)==0){
                 
                  temp_librarian.id=l.id;
                  strcpy(temp_librarian.name,l.name);
                  strcpy(temp_librarian.addr,l.addr);
                  strcpy(temp_librarian.aadhar,l.aadhar);
                  strcpy(temp_librarian.doj,l.doj);
                  strcpy(temp_librarian.mobile,l.mobile);
                  strcpy(temp_librarian.password,l.password);
                  temp_librarian.salary=l.salary; 
                printf("\n\t\t\t Log in Successful "); 
                printf("\n\t\t\t Enter any key to continue....");
                getch(); fclose(fp);  flag=1;
                 break; 
            }
        }
        if(flag==1){
                librarianMenu(temp_librarian);
        } 
            
        printf("\n\t\t\t Log in Failed..!");
         fclose(fp);
        printf("\n\t\t\t Enter any key to continue....");
        getch();   
        mainMenu(); 
}
 
void librarianMenu(struct librarian currentLibrarian){

                layout();
               int ch; 
                printf("\n\t\t\t\t--------------------");
                printf("\n\t\t\t\t LIBRARIAN  MENU                  %s",currentLibrarian.name); 
                printf("\n\t\t\t\t--------------------");
                printf("\n\t\t\t [1] Book Operation ");
                printf("\n\t\t\t [2] Book Issue "); 
                printf("\n\t\t\t [3] Book Return "); 
                printf("\n\t\t\t [4] Student Operation ");
                printf("\n\t\t\t [5] Change Password  ");
                printf("\n\t\t\t [6] Book Database  ");          
                printf("\n\t\t\t [7] Logout or Exit ");
                printf("\n\n\t\tEnter Your Choice:");
                scanf("%d",&ch); 
                
                switch (ch) 
                { 
                case 1:
                            bookMenu(currentLibrarian);                        
                    break;
                case 2:     bookIssue(currentLibrarian);
                    break;
                case 3:     bookReturn(currentLibrarian);
                    break; 
                  case 4:
                            studentMenu(currentLibrarian);                        
                    break;
                case 5:     changePasswordLibrarian(currentLibrarian);  
                    break;
                case 6:      bookDatabase(currentLibrarian); 
                    break; 
                case 7:       mainMenu();  
                    break;
                default:     librarianMenu(currentLibrarian); 
                    break;
                }
}   
 
void  changePasswordLibrarian(struct librarian currentLibrarian){
   layout();

 printf("\n\t\t\t  ----------------------- Update Password  Libraian-------------------            \n\n\n\t\t\t\t");
            fflush(stdin);
            char pass[50];
            printf("\n\t\t\t Enter Old Password :");
            gets(pass);

 
        
           int flag=0;
           
              if(strcmp(l.password,pass)==0){
                flag=1; 
              } 
             
         
            if(flag==0){      
              printf("\n\t\t\t Password wrong !"); 
            }else{
              FILE *fp; 
                  fp=fopen("librarian.txt","rb+");
                  FILE *ft;
                     ft=fopen("temp.txt","ab+");
                     if(ft==NULL){
                            printf("\n\t\t\t File Error -temp.txt ");
                            getch(); librarianMenu(currentLibrarian); 
                      }
                      struct librarian l2;
                       while(fread(&l,sizeof(l),1,fp)==1)
                       {
                             if(strcmp(l.password,pass)==0){
                                      l2.id=l.id;
                                      l2.salary=l.salary;
                                      strcpy(l2.name,l.name);
                                      strcpy(l2.addr,l.addr);
                                      strcpy(l2.aadhar,l.aadhar);
                                      strcpy(l2.doj,l.doj);
                                      strcpy(l2.mobile,l.mobile);
                                      strcpy(l2.password,l.password);
                              }else{
                                fwrite(&l,sizeof(l),1,ft);
                              }
                       } 
                        char pass1[50],pass2[50];
                          fflush(stdin);
                        printf("\n\t\t\t Enter New Password:");
                        gets(pass1);
                        fflush(stdin);
                        printf("\n\t\t\t Confirm Password:");
                        gets(pass2);
                           if(strcmp(pass1,pass2)==0){
                                strcpy(l2.password,pass1);
                                printf("\n\t\t\t Password updated succesfully ");
                           }else{
                                printf("\n\t\t\t Confirm Password dont matched  ");
                           }
                                fwrite(&l2,sizeof(l2),1,ft);
                                fclose(fp);
                                fclose(ft); 
                                remove("librarian.txt");
                                rename("temp.txt","librarian.txt");

            }  
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        librarianMenu(currentLibrarian);  
}             

void bookMenu(struct librarian  currentLibrarian){
         layout();

        printf("\n\t\t\t ************ Book Operation *************");
            printf("\n\t\t\t [1] Insert New ");
            printf("\n\t\t\t [2] Delete ");
            printf("\n\t\t\t [3] Update ");
            printf("\n\t\t\t [4] Display");
            printf("\n\t\t\t [5] Search  ");
            printf("\n\t\t\t [6] Exit ");
            printf("\n\t\t\t Enter Choice:");
            int ch;
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:  insertBook(currentLibrarian);  
                 break;
            case 2: deleteBook(currentLibrarian);   
                break; 
            case 3:  updateBook(currentLibrarian); 
                break;
            case 4: displayBook(currentLibrarian); 
                break;
            case 5: searchBook(currentLibrarian); 
                break;
            case 6:      librarianMenu(currentLibrarian);  
                break;
            default:     bookMenu(currentLibrarian);   
                break;
            } 
            
            


        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        librarianMenu(currentLibrarian);
}

void studentMenu(struct librarian  currentLibrarian){
         layout();

        printf("\n\t\t\t ************ Student Operation *************");
            printf("\n\t\t\t [1] Insert New ");
            printf("\n\t\t\t [2] Delete ");
            printf("\n\t\t\t [3] Update ");
            printf("\n\t\t\t [4] Display");
            printf("\n\t\t\t [5] Search  ");
            printf("\n\t\t\t [6] Exit ");
            printf("\n\t\t\t Enter Choice:");
            int ch;
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:  insertStudent(currentLibrarian);  
                 break;
            case 2: deleteStudent(currentLibrarian);  
                break;
            case 3:  updateStudent(currentLibrarian); 
                break;
            case 4: displayStudent(currentLibrarian); 
                break;
            case 5: searchStudent(currentLibrarian); 
                break;
            case 6:      librarianMenu(currentLibrarian);  
                break;
            default:     studentMenu(currentLibrarian);   
                break;
            }
            
            


        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        librarianMenu(currentLibrarian);
}
 
void insertStudent(struct librarian currentLibrarian){
        layout();
             printf("\n\t\t\t  -----------------------Register New Student -------------------            \n\n\n\t\t\t\t");
   
          FILE *fp;
          fp=fopen("student.txt","ab+"); //append binary mode 
          if(fp==NULL){
            printf("\n\t\t\t File open failed -student.txt "); getch();  studentMenu(currentLibrarian); 
          }


            fflush(stdin);
            printf("\n\t\t\t  Enter Id (STUDENT PRN NUMBER):");
            scanf("%s",&s.id); 

            fflush(stdin);
            printf("\n\t\t\t  Enter Name:");
            gets(s.name);

            fflush(stdin);
           printf("\n\n\t\t\t  Enter Addr:");
            gets(s.addr);

            fflush(stdin);
           printf("\n\n\t\t\t  Enter Aadhar No:");
            gets(s.aadhar);

            fflush(stdin);
          printf("\n\t\t\t  Enter Mobile No:"); 
            gets(s.mobile); 


            fflush(stdin);
          printf("\n\t\t\t  Enter Faculty:"); 
            gets(s.std); 


            strcpy(s.username,s.id);
            strcpy(s.password,s.mobile);
            strcpy(s.dateofIssue,"NULL");
            strcpy(s.dateofReturn,"NULL");
            strcpy(s.bID,"NULL");
            

          fflush(stdin); 
          fwrite(&s,sizeof(s),1,fp); 
          printf("\n\t\t\t Submitted succesfully ..");

        fclose(fp);  
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu(currentLibrarian); 
}

void insertBook(struct librarian currentLibrarian){
        layout();
 
            printf("\n\t\t\t  -----------------------Register New Book -------------------            \n\n\n\t\t\t\t");

          FILE *fp;
          fp=fopen("book.txt","ab+"); //append binary 
          if(fp==NULL){
            printf("\n\t\t\t File open failed -book.txt "); getch();  bookMenu(currentLibrarian); 
          }

          fflush(stdin);
          printf("\n\t\t\t Enter Book ID :");
          scanf("%s",&b.id);

          fflush(stdin);
          printf("\n\t\t\t Enter Book Author :");
          gets(b.author);

          fflush(stdin);
          printf("\n\t\t\t Enter Book Name :");
          gets(b.name); 

          fflush(stdin);
          printf("\n\t\t\t Enter Book Class/Faculty  :");
          gets(b.std);

          fflush(stdin);
          printf("\n\t\t\t Enter Book Price  :");
          scanf("%f",&b.price);

          fflush(stdin);
          printf("\n\t\t\t Enter Book Quantity  :");
          scanf("%d",&b.totalQuantity);
         

         b.issueQuantity=0;
         b.presentQuantity=b.totalQuantity;
           

           fflush(stdin); 
         fwrite(&b,sizeof(b),1,fp);
         fclose(fp);  

         printf("\n\t\t\t Inserted Successfully ");

        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        bookMenu(currentLibrarian); 
}

void displayBook(struct librarian currentLibrarian){
  layout();
           FILE  *fp;
          fp=fopen("book.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , book.txt "); getch(); bookMenu(currentLibrarian); 
          }

            printf("\n\t\t\t ====BOOK LIST========  ")  ; 
            while (fread(&b,sizeof(b),1,fp)==1)
            {
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",b.id); 
            printf("\n\t\t\t NAME = %s",b.name); 
            printf("\n\t\t\t AUTHOR = %s",b.author); 
            printf("\n\t\t\t CLASS  = %s",b.std);     
            printf("\n\t\t\t PRICE  = %f",b.price); 
            printf("\n\t\t\t QUANTITY  = %d",b.totalQuantity); 
            printf("\n\t\t\t======================================================");
            }
            
        fclose(fp);
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        bookMenu(currentLibrarian);
}

void displayStudent(struct librarian currentLibrarian){
       layout();
           FILE  *fp;
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n File open error , student.txt "); getch();  studentMenu(currentLibrarian); 
          }

            printf("\n\t\t\t ====STUDENT  LIST========  ")  ; 
            while (fread(&s,sizeof(s),1,fp)==1)
            {
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",s.id); 
            printf("\n\t\t\t NAME = %s",s.name); 
            printf("\n\t\t\t Address = %s",s.addr); 
            printf("\n\t\t\t Aadhar No = %s",s.aadhar);   
            printf("\n\t\t\t MOBILE  = %s",s.mobile);     
            printf("\n\t\t\t USERNAME  = %s",s.username); 
            printf("\n\t\t\t CLASS  = %s",s.std); 
            printf("\n\t\t\t DATE OF ISSUE  = %s",s.dateofIssue); 
            printf("\n\t\t\t DATE OF RETURN  = %s",s.dateofReturn); 
            printf("\n\t\t\t BOOK ID  = %s",s.bID); 
            printf("\n\t\t\t======================================================");
            }
            
        fclose(fp);
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu(currentLibrarian); 
}

void deleteStudent(struct librarian currentLibrarian){
               layout();
          char id[50];

             printf("\n\t\t\t  ======== Delete Student ========");

            printf("\n\t\t\t Enter Student Id :");
            scanf("%s",&id);

            FILE *fp,*ft;

            fp=fopen("student.txt","rb"); // read binary
            if(fp==NULL){
              printf("\n\t\t\t File open error .. student.txt "); studentMenu(currentLibrarian);
            }

            ft=fopen("temp.txt","ab+");
            if(ft==NULL){
              printf("\n\t\t\t File open error .. temp.txt "); studentMenu(currentLibrarian);
            }
            int flag=0;
            while (fread(&s,sizeof(s),1,fp)==1)
            {  
               if(strcmp(s.id,id)==0){
                   flag=1; 
               }else{
                  fwrite(&s,sizeof(s),1,ft);
               }
            }
            
            if(flag==1){
              printf("\n\t\t\t Record Deleted ..");
            }else{
              printf("\n\t\t\t Not Found  ..");
            }

            fclose(fp);
            fclose(ft);

            remove("student.txt");
            rename("temp.txt","student.txt");  


        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu(currentLibrarian); 
}

void searchBook(struct librarian currentLibrarian){
        layout();
          FILE  *fp;
            printf("\n\t\t\t  -----------------------Search Book -------------------            \n\n\n\t\t\t\t");
          fp=fopen("book.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , book.txt ");  bookMenu(currentLibrarian); 
          }
                    char id[50];fflush(stdin);
                    printf("\n\t\t\tEnter book Id :");
                    scanf("%s",&id);


             int flag=0;
            while (fread(&b,sizeof(b),1,fp)==1)
            {
              if(strcmp(id,b.id)==0){  flag=1;
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",b.id); 
            printf("\n\t\t\t NAME = %s",b.name); 
            printf("\n\t\t\t AUTHOR = %s",b.author); 
            printf("\n\t\t\t CLASS  = %s",b.std);     
            printf("\n\t\t\t PRICE  = %f",b.price);  
            printf("\n\t\t\t QUANTITY  = %d",b.totalQuantity); 
            printf("\n\t\t\t======================================================"); break;
              }
            }
            
        fclose(fp);

        if(flag==0){
             printf("\n\t\t\t Not Found !");
        }

        printf("\n\t\t\t Enter any key to continue....");
        getch();   
        bookMenu(currentLibrarian);
}
  
void searchStudent(struct librarian currentLibrarian){
        layout();
       FILE  *fp;
       printf("\n\t\t\t  -----------------------Search Student -------------------            \n\n\n\t\t\t\t");
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , student.txt ");  studentMenu(currentLibrarian); 
          }
                    char id[50];fflush(stdin);
                    printf("\n\t\t\tEnter Student Id :");
                    scanf("%s",&id);
               int flag=0; 
       while (fread(&s,sizeof(s),1,fp)==1)
            {if(strcmp(id,s.id)==0){  flag=1;
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",s.id); 
            printf("\n\t\t\t NAME = %s",s.name); 
            printf("\n\t\t\t Address = %s",s.addr); 
            printf("\n\t\t\t Aadhar No = %s",s.aadhar); 
            printf("\n\t\t\t MOBILE  = %s",s.mobile);     
            printf("\n\t\t\t USERNAME  = %s",s.username); 
            printf("\n\t\t\t CLASS  = %s",s.std); 
            printf("\n\t\t\t DATE OF ISSUE  = %s",s.dateofIssue); 
            printf("\n\t\t\t DATE OF RETURN  = %s",s.dateofReturn); 
            printf("\n\t\t\t BOOK ID  = %s",s.bID);  
            printf("\n\t\t\t======================================================");
            }
            }

        fclose(fp);

        if(flag==0){
             printf("\n\t\t\t Not Found !");
        }

        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu(currentLibrarian);
}

void updateStudent(struct librarian currentLibrarian){ 

        layout();
          printf("\n\t\t\t  -----------------------Update Student -------------------            \n\n\n\t\t\t\t");
          char id[50];
          printf("\n\t\t\t Enter Student ID for Update:");
          scanf("%s",&id);

           FILE *fp,*ft;

           fp=fopen("student.txt","rb"); // read binary
            if(fp==NULL){
              printf("\n\t\t\t File open error .. student.txt "); studentMenu(currentLibrarian);
            }
           
            ft=fopen("temp.txt","ab+"); 
            if(ft==NULL){
              printf("\n\t\t\t File open error .. temp.txt "); studentMenu(currentLibrarian);
            }

              struct student temp;

            int flag=0;
            while (fread(&s,sizeof(s),1,fp)==1)
            {
               if(strcmp(id,s.id)==0){
                   flag=1; 
             strcpy(temp.username,s.username);
             strcpy(temp.password,s.password);
             strcpy(temp.dateofIssue,s.dateofIssue);
             strcpy(temp.dateofReturn,s.dateofReturn);
             strcpy(temp.bID,s.bID); 
               }else{
                  fwrite(&s,sizeof(s),1,ft);
               }
            }


            if(flag==1){
       
             strcpy(s.id,id);
             strcpy(s.username,temp.username);
             strcpy(s.password,temp.password);
             strcpy(s.dateofIssue,temp.dateofIssue);
             strcpy(s.dateofReturn,temp.dateofReturn);
             strcpy(s.bID,temp.bID);
                 

             fflush(stdin);
            printf("\n\t\t\t  Enter UPDATED Name:");
            gets(s.name);

             fflush(stdin);
           printf("\n\n\t\t\t  Enter UPDATED Addr:");
            gets(s.addr);

             fflush(stdin);
           printf("\n\n\t\t\t  Enter UPDATED Aadhar No:");
            gets(s.aadhar);

             fflush(stdin);
            printf("\n\n\t\t\t  Enter UPDATED Faculy or Class:");
            gets(s.std);

             fflush(stdin);
             printf("\n\t\t\t  Enter UPDATED Mobile No:"); 
             gets(s.mobile);
          

          fflush(stdin); 
          fwrite(&s,sizeof(s),1,ft);  

                 printf("\n\t\t\t Succesfully Updated...");

           
         }
            else{
               printf("\n\t\t\t Id not Found..");
            } 

  
            fclose(ft);  
            fclose(fp); 
            remove("student.txt");
            rename("temp.txt","student.txt");


        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu(currentLibrarian);
}

void deleteBook(struct librarian currentLibrarian){
        layout();
  printf("\n\t\t\t  -----------------------Delete Book -------------------            \n\n\n\t\t\t\t");
         char  id[50];
         printf("\n\t\t\t Enter Book ID:");
         scanf("%s",&id);

        FILE *fp;
        fp=fopen("book.txt","rb"); 
        if(fp==NULL){
          printf("\n\t\t\t File open error - book.txt !"); getch(); bookMenu(currentLibrarian);
        }
       
       int flag=0;
       // checking book for deleting with issue quantity 
        while(fread(&b,sizeof(b),1,fp)==1)
        {
               if(strcmp(b.id,id)==0){ flag=2;
                         if(b.issueQuantity==0){
                           flag=1; break;
                         }
                         break; 
               }
        }
        
        fclose(fp);  
        if(flag==0){
           printf("\n\t\t\t Id Not Found !");
        }else if(flag==2){
           printf("\n\t\t\t Issue Quantity Should be 0 for delete this book ");
        }else if(flag==1){
                FILE *fp; 
                fp=fopen("book.txt","rb");
                if(fp==NULL){
                  printf("\n\t\t\t File Open Error -book.txt "); getch(); librarianMenu(currentLibrarian);
                }
                FILE *ft; 
                ft=fopen("temp.txt","ab+");
                if(ft==NULL){
                  printf("\n\t\t\t File Open Error -temp.txt "); getch(); librarianMenu(currentLibrarian);
                }
               while (fread(&b,sizeof(b),1,fp)==1)
               {
                      if(strcmp(id,b.id)==0){

                      }else{
                            fwrite(&b,sizeof(b),1,ft);
                      }
               } 
               fclose(fp);
               fclose(ft); 
               remove("book.txt");
               rename("temp.txt","book.txt"); 
           printf("\n\t\t\t Deleted Successfully ");
        }
        
        


        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        bookMenu(currentLibrarian);
}

void updateBook(struct librarian currentLibrarian){
        layout();
         printf("\n\t\t\t  -----------------------Update Book -------------------            \n\n\n\t\t\t\t");
        char  id[50];
         printf("\n\t\t\t Enter Book ID:");
         scanf("%s",&id);

        FILE *fp;
        fp=fopen("book.txt","rb"); 
        if(fp==NULL){
          printf("\n\t\t\t File open error - book.txt !"); getch(); bookMenu(currentLibrarian);
        }
       
       int flag=0; struct book temp; 
       // checking book for update  
        while(fread(&b,sizeof(b),1,fp)==1)
        {
               if(strcmp(b.id,id)==0){ 
                 strcpy(temp.id,b.id);
                 temp.issueQuantity=b.issueQuantity;
                 temp.totalQuantity=b.totalQuantity;
                 temp.presentQuantity=b.presentQuantity; 
                        flag=1; break;
               }
        }
        fclose(fp);
        
        if(flag==1){
              fflush(stdin);
            printf("\n\t\t\t Enter Updated Name:");
                   gets(temp.name);
              fflush(stdin);
            printf("\n\t\t\t Enter Updated Author:");
                   gets(temp.author);
              fflush(stdin);
            printf("\n\t\t\t Enter Updated Std/Faculty:");
                   gets(temp.std);
              fflush(stdin);
            printf("\n\t\t\t Enter Updated Price:");
                  scanf("%f",&temp.price);
            printf("\n\t\t\t Total Quantity =%d",b.totalQuantity);
            printf("\n\t\t\t How many Quantity you want to add:");
            int add; scanf("%d",&add);
              temp.totalQuantity+=add; 
              temp.presentQuantity+=add;
                  
                 FILE *fp; 
                fp=fopen("book.txt","rb");
                if(fp==NULL){
                  printf("\n\t\t\t File Open Error -book.txt "); getch(); librarianMenu(currentLibrarian);
                }
                FILE *ft; 
                ft=fopen("temp.txt","ab+");
                if(ft==NULL){
                  printf("\n\t\t\t File Open Error -temp.txt "); getch(); librarianMenu(currentLibrarian);
                }

                fwrite(&temp,sizeof(temp),1,ft);
               while (fread(&b,sizeof(b),1,fp)==1)
               {
                      if(strcmp(id,b.id)==0){

                      }else{
                            fwrite(&b,sizeof(b),1,ft);
                      }
               } 
               fclose(fp);
               fclose(ft);  
               remove("book.txt");
               rename("temp.txt","book.txt"); 
               printf("\n\t\t\t Updated Successfully "); 
        }else{
              printf("\n\t\t\t Id Not Found  !");
        }
        printf("\n\t\t\t Enter any key to continue....");
        getch();   
        bookMenu(currentLibrarian);
}

void bookDatabase(struct librarian currentLibrarian){
        layout();
       
          FILE  *fp;
          fp=fopen("book.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , book.txt "); getch();    librarianMenu(currentLibrarian); 
          }

            printf("\n\t\t\t ====BOOK DATABASE========  ")  ; 
            while (fread(&b,sizeof(b),1,fp)==1)
            {
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",b.id); 
            printf("\n\t\t\t TOTAL QUANTITY  = %d",b.totalQuantity); 
            printf("\n\t\t\t PRESENT QUANTITY  = %d",b.presentQuantity); 
            printf("\n\t\t\t ISSUE QUANTITY  = %d",b.issueQuantity); 
            printf("\n\t\t\t======================================================");
            }
             
        fclose(fp);

        printf("\n\t\t\t Enter any key to continue....");
        getch();   
        librarianMenu(currentLibrarian); 
     
}

void bookIssue(struct librarian currentLibrarian){
 layout();
          char sId[50],bId[50];fflush(stdin);
          printf("\n\t\t\t --------Book Issue --------------\n\n\n");
            printf("\n\t\t\t Enter Student Id:");
            scanf("%s",&sId);
        FILE  *fp;
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , student.txt ");  librarianMenu(currentLibrarian); 
          }
               int flag=0; 
       while (fread(&s,sizeof(s),1,fp)==1){

                     if(strcmp(sId,s.id)==0){ 
                              flag=1;
                              if(strcmp(s.bID,"NULL")==0){
                                 flag=2; break; 
                              }
                              break;
                      }
            }
        fclose(fp);
        if(flag==0){
          printf("\n\t\t\t Student Id not Found !");
        }else if(flag==1){
           printf("\n\t\t\t This student has already book and book id =%s",s.bID);
        }else if(flag==2){

                  fflush(stdin);
                  printf("\n\t\t\t Enter Book Id:");
                  scanf("%s",&bId);
              FILE  *fp;
           fp=fopen("book.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , book.txt "); getch();  librarianMenu(currentLibrarian); 
          }
                   
               int flag=0; 
       while (fread(&b,sizeof(b),1,fp)==1){
                     if(strcmp(bId,b.id)==0){ 
                          flag=1;
                                if(b.presentQuantity>0){
                                  flag=2;
                                   break;
                                }
                              break;
                      }

            }
        fclose(fp);
         if(flag==0){
           printf("\n\t\t\t Book Id Not Found !");
        }else if(flag==1){
           printf("\n\t\t\t Book Not Available for Issue !");
        }else if(flag==2){
              //   Ready for Issue        BOOK UPDATE 
             FILE *fp;
        fp=fopen("book.txt","rb"); 
        if(fp==NULL){
          printf("\n\t\t\t File open error - book.txt !"); getch(); bookMenu(currentLibrarian);
        }
       int flag=0; struct book temp; 
        while(fread(&b,sizeof(b),1,fp)==1)
        { 
               if(strcmp(b.id,bId)==0){ 
                 strcpy(temp.id,b.id);
                 strcpy(temp.name,b.name);
                 strcpy(temp.author,b.author);
                 strcpy(temp.std,b.std);
                 temp.price=b.price;
                 temp.issueQuantity=b.issueQuantity;
                 temp.totalQuantity=b.totalQuantity;
                 temp.presentQuantity=b.presentQuantity; 
                        flag=1; break;
               }
        }
        fclose(fp);
        temp.issueQuantity++; 
        temp.presentQuantity--;  
        if(flag==1){ 
                 FILE *fp; 
                fp=fopen("book.txt","rb");
                if(fp==NULL){
                  printf("\n\t\t\t File Open Error -book.txt "); getch(); librarianMenu(currentLibrarian);
                }
                FILE *ft; 
                ft=fopen("temp.txt","ab+");
                if(ft==NULL){
                  printf("\n\t\t\t File Open Error -temp.txt "); getch(); librarianMenu(currentLibrarian);
                }
               while (fread(&b,sizeof(b),1,fp)==1)
               {
                      if(strcmp(bId,b.id)==0){
                             fwrite(&temp,sizeof(temp),1,ft);
                      }else{
                             fwrite(&b,sizeof(b),1,ft);
                      }
               } 
               fclose(fp);
               fclose(ft);  
               remove("book.txt");
               rename("temp.txt","book.txt"); 
            // -------------------------------------------------------------------------------------
              // STUDENT UPDATE 
                fp=fopen("student.txt","rb");
                if(fp==NULL){
                  printf("\n\t\t\t File Open Error -student.txt "); getch(); librarianMenu(currentLibrarian);
                }
                ft=fopen("temp.txt","ab+");
                if(ft==NULL){
                  printf("\n\t\t\t File Open Error -temp.txt "); getch(); librarianMenu(currentLibrarian);
                }
           struct student tempStudent; 
               while (fread(&s,sizeof(s),1,fp)==1)
               {
                      if(strcmp(sId,s.id)==0){
                             strcpy(tempStudent.id,s.id);
                             strcpy(tempStudent.name,s.name);
                             strcpy(tempStudent.addr,s.addr);
                             strcpy(tempStudent.aadhar,s.aadhar);
                             strcpy(tempStudent.mobile,s.mobile);
                             strcpy(tempStudent.password,s.password);
                             strcpy(tempStudent.username,s.username);
                             strcpy(tempStudent.std,s.std);
                             printf("\n\t\t\t Enter Date of Issue :"); fflush(stdin);
                             gets(tempStudent.dateofIssue);
                             strcpy(tempStudent.dateofReturn,"NULL");
                             strcpy(tempStudent.bID,bId); 
                            fwrite(&tempStudent,sizeof(tempStudent),1,ft);
                      }else{
                             fwrite(&s,sizeof(s),1,ft);
                      }
               } 
               fclose(fp);
               fclose(ft);  
               remove("student.txt");
               rename("temp.txt","student.txt"); 
               printf("\n\t\t\t Issue Successfully ");
        } 
        }
        printf("\n\t\t\t Enter any key to continue....");
        getch();   
        librarianMenu(currentLibrarian); 
  }

}    

void bookReturn(struct librarian currentLibrarian){
             layout();
      char sId[50],bId[50];fflush(stdin);
      printf("\n\t\t\t --------------- Book Return ----------\n\n\n ");
            printf("\n\t\t\t Enter Student Id:");
            scanf("%s",&sId);
        FILE  *fp;
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , student.txt ");  librarianMenu(currentLibrarian); 
          }
                  fflush(stdin);
                  printf("\n\t\t\t Enter Book Id:");
                  scanf("%s",&bId);      
               int flag=0; 
       while (fread(&s,sizeof(s),1,fp)==1){
                     if(strcmp(sId,s.id)==0){ 
                              flag=1;
                              if(strcmp(s.bID,bId)==0){
                                 flag=2; break; 
                              }
                              break;
                      }
            }
        fclose(fp);

        if(flag==0){
          printf("\n\t\t\t Student Id not Found !");
        }else if(flag==1){
           printf("\n\t\t\t Book Id Dont Matched.. !");
        }else if(flag==2){
// ----------------------------------------------------------------------OKKK
                  // STUDENT ID AND BOOK ID MATCHED
             FILE *fp;
        fp=fopen("book.txt","rb"); 
        if(fp==NULL){
          printf("\n\t\t\t File open error - book.txt !"); getch(); bookMenu(currentLibrarian);
        }
       
       int flag=0; struct book temp; 
        while(fread(&b,sizeof(b),1,fp)==1)
        { 
               if(strcmp(b.id,bId)==0){ 
                 strcpy(temp.id,b.id);
                 strcpy(temp.name,b.name);
                 strcpy(temp.author,b.author);
                 strcpy(temp.std,b.std);
                 temp.price=b.price;
                 temp.issueQuantity=b.issueQuantity;
                 temp.totalQuantity=b.totalQuantity;
                 temp.presentQuantity=b.presentQuantity; 
                        flag=1; break;
               }
        }
        fclose(fp);
        
        temp.issueQuantity--; 
        temp.presentQuantity++;  
                 
                fp=fopen("book.txt","rb");
                if(fp==NULL){
                  printf("\n\t\t\t File Open Error -book.txt "); getch(); librarianMenu(currentLibrarian);
                }
                FILE *ft; 
                ft=fopen("temp.txt","ab+");
                if(ft==NULL){
                  printf("\n\t\t\t File Open Error -temp.txt "); getch(); librarianMenu(currentLibrarian);
                }

               while (fread(&b,sizeof(b),1,fp)==1)
               {
                      if(strcmp(bId,b.id)==0){
                            fwrite(&temp,sizeof(temp),1,ft);
                      }else{
                            fwrite(&b,sizeof(b),1,ft);
                      }
               } 
               fclose(fp);
               fclose(ft);  
               remove("book.txt");
               rename("temp.txt","book.txt"); 
               
            // -------------------------------------------------------------------------------------
              // STUDENT UPDATE 

                fp=fopen("student.txt","rb");
                if(fp==NULL){
                  printf("\n\t\t\t File Open Error -student.txt "); getch(); librarianMenu(currentLibrarian);
                }
                ft=fopen("temp.txt","ab+");
                if(ft==NULL){
                  printf("\n\t\t\t File Open Error -temp.txt "); getch(); librarianMenu(currentLibrarian);
                }

           struct student tempStudent; 
               while (fread(&s,sizeof(s),1,fp)==1)
               {
                      if(strcmp(sId,s.id)==0){
                             strcpy(tempStudent.id,s.id);
                             strcpy(tempStudent.name,s.name);
                             strcpy(tempStudent.addr,s.addr);
                             strcpy(tempStudent.aadhar,s.aadhar);
                             strcpy(tempStudent.mobile,s.mobile);
                             strcpy(tempStudent.password,s.password);
                             strcpy(tempStudent.username,s.username);
                             strcpy(tempStudent.std,s.std);
                             strcpy(tempStudent.dateofIssue,"NULL");
                             strcpy(tempStudent.dateofReturn,"NULL");
                             strcpy(tempStudent.bID,"NULL"); 
                             fwrite(&tempStudent,sizeof(tempStudent),1,ft);
                      }else{
                             fwrite(&s,sizeof(s),1,ft);
                      }
               }
               fclose(fp);
               fclose(ft);  
               remove("student.txt");
               rename("temp.txt","student.txt"); 
               printf("\n\t\t\t Return Successfully ");
        
    }
        printf("\n\t\t\t Enter any key to continue....");
        getch();   
        librarianMenu(currentLibrarian);     
}

void studentLogin(){
  layout();
         
        char temp_username[50],temp_password[50];
         printf("\n\t\t\t**************** STUDENT LOGIN *************** \n\n\n");
         printf("\n\t\t\t Your Username is your ID(STUDENT PRN NUMBER) and password in your mobile no "); 
         printf("\n\t\t\t Enter Username :"); scanf("%s",temp_username);
         printf("\n\t\t\t Enter Password :"); scanf("%s",temp_password);

            FILE  *fp;
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , student.txt "); getch();  mainMenu(); 
          }
              
              int flag=0; char temp_id[50];
            while (fread(&s,sizeof(s),1,fp)==1)
            {
              if((strcmp(s.username,temp_username)==0)&&(strcmp(s.password,temp_password)==0)){
                   flag=1;  strcpy(temp_id,s.id);  break;
              }
            }
            
        fclose(fp); 
       
      if(flag==0){
            printf("\n\t\t\t Login Failed  Check Username and Password !"); 
      }else{
            printf("\n\t\t\t Login Successfully .."); 
                    printf("\n\t\t\t Enter any key to continue....");
               getch();
              studentMenu2(temp_id);
      }


        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        mainMenu(); 
}

void studentMenu2(char sId[50]){
          layout();
        
            printf("\n\t\t\t ************ Welcome Student ************* \n\n");
            printf("\n\t\t\t [1] Books  ");
            printf("\n\t\t\t [2] Profile"); 
            printf("\n\t\t\t [3] Change Password ");
            printf("\n\t\t\t [4] Logout ");
            printf("\n\t\t\t Enter Your Choice:"); int ch;
            scanf("%d",&ch);
            switch(ch){ 
                case 1:  studentBooks(sId);    break;
                case 2: studentProfile(sId);     break; 
                case 3: changePasswordStudent(sId);    break;
                case 4:  mainMenu();   break;
                default: studentMenu2(sId);  break;
            }

        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        mainMenu();    
}


void studentBooks(char sId[50]){
        layout();
          FILE  *fp;
          fp=fopen("book.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , book.txt "); getch(); studentMenu2(sId);
          }
            printf("\n\t\t\t ====BOOK LIST========  ")  ; 
            while (fread(&b,sizeof(b),1,fp)==1)
            {
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",b.id); 
            printf("\n\t\t\t NAME = %s",b.name); 
            printf("\n\t\t\t AUTHOR = %s",b.author); 
            printf("\n\t\t\t CLASS  = %s",b.std);     
            printf("\n\t\t\t PRICE  = %f",b.price); 
            printf("\n\t\t\t QUANTITY  = %d",b.totalQuantity); 
            printf("\n\t\t\t======================================================");
            }
       fclose(fp);
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu2(sId);    
}

void studentProfile(char sId[50]){
          layout();

          FILE  *fp;
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , student.txt "); getch();  studentMenu2(sId); 
          }

            printf("\n\t\t\t ====STUDENT  PROFILE========  ")  ; 
            while (fread(&s,sizeof(s),1,fp)==1) 
            { 
              if(strcmp(s.id,sId)==0){
            printf("\n\t\t\t======================================================");
            printf("\n\t\t\t ID = %s",s.id); 
            printf("\n\t\t\t NAME = %s",s.name); 
            printf("\n\t\t\t ADDRESS = %s",s.addr); 
            printf("\n\t\t\t Aadhar No = %s",s.aadhar); 
            printf("\n\t\t\t MOBILE  = %s",s.mobile);     
            printf("\n\t\t\t USERNAME  = %s",s.username); 
            printf("\n\t\t\t PASSWORD  = %s",s.password); 
            printf("\n\t\t\t CLASS  = %s",s.std); 
            printf("\n\t\t\t DATE OF ISSUE  = %s",s.dateofIssue); 
            printf("\n\t\t\t DATE OF RETURN  = %s",s.dateofReturn); 
            printf("\n\t\t\t BOOK ID  = %s",s.bID); 
            printf("\n\t\t\t======================================================"); 
             break;
              }
            }
            
        fclose(fp);
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu2(sId);
} 

void changePasswordStudent(char sId[50]){
         layout();
          printf("\n\t\t\t ************ Update Student Password ************* \n\n");
       char old_password[50],new1[50],new2[50];
       printf("\n\t\t\t Enter Old Password:");
       scanf("%s",&old_password);

          FILE  *fp;
          fp=fopen("student.txt","rb");
          if(fp==NULL){
            printf("\n\t\t\t File open error , student.txt "); getch();  studentMenu2(sId); 
          }

         int flag=0;
            while (fread(&s,sizeof(s),1,fp)==1) 
            { 
              if(strcmp(s.id,sId)==0){
                    if(strcmp(old_password,s.password)==0){
                       flag=1;
                    }
                 break;
              }
            }
            
        fclose(fp);

        if(flag==0){
               printf("\n\t\t\t Password Dont match ..!");
        }else if(flag==1){
                    printf("\n\t\t\t Enter new password:");  scanf("%s",&new1);
                    printf("\n\t\t\t Confirm new password:"); scanf("%s",&new2);
                    if(strcmp(new1,new2)!=0){
                           printf("\n\t\t\t New Password dont match , try again !"); 
                    }else{ 

                         FILE *fp,*ft;

           fp=fopen("student.txt","rb"); // read binary
            if(fp==NULL){
              printf("\n\t\t\t File open error .. student.txt "); studentMenu2(sId);
            }
            
            ft=fopen("temp.txt","ab+");  // append binary 
            if(ft==NULL){
              printf("\n\t\t\t File open error .. temp.txt "); studentMenu2(sId);
            }    
                      struct student temp;

           
            while (fread(&s,sizeof(s),1,fp)==1)
            {
               if(strcmp(sId,s.id)==0){
             strcpy(temp.id,sId);    
             strcpy(temp.name,s.name);    
             strcpy(temp.addr,s.addr);    
             strcpy(temp.aadhar,s.aadhar);    
             strcpy(temp.mobile,s.mobile);    
             strcpy(temp.std,s.std);    
             // new password set here 
             strcpy(temp.password,new1);    
             strcpy(temp.username,s.username);
             strcpy(temp.dateofIssue,s.dateofIssue);
             strcpy(temp.dateofReturn,s.dateofReturn);
             strcpy(temp.bID,s.bID); 
             fwrite(&temp,sizeof(temp),1,ft);
               }else{
                  fwrite(&s,sizeof(s),1,ft);
               }
            } 
            
            fclose(ft);  
            fclose(fp); 
            remove("student.txt");
            rename("temp.txt","student.txt"); 
                          printf("\n\t\t\t Successfully Changed Password "); 
            }
        }
        printf("\n\t\t\t Enter any key to continue....");
        getch();  
        studentMenu2(sId); 
}










