#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_REG 100


struct data
{
    char name[100];
    int age;
    char gender[10];
    char nid[10];
    char username[100];
    char password[100];
    int supply;

}person[MAX_REG];




int i=0;
int new_age=18;



void usermenu();
void fillStructure()
{
    system("cls");
    int x;


    FILE *in;

    in = fopen("info.txt" , "a");

    if(in == NULL)
    {
        printf("ERROR!");
        exit(1);
    }



        fflush(stdin);

        printf("Enter name(no spaces)>>");
         gets(person[i].name);
         fflush(stdin);

         printf("Enter age(minimum age is %d)>", new_age);
         scanf("%d", &person[i].age);

         if(person[i].age< new_age)
         {
         printf("You are too young to take the vaccine\n");
         printf("Press enter to continue\n");
         getch();
         return 0;
         }

         fflush(stdin);

         printf("Enter gender>");
         gets(person[i].gender);
         fflush(stdin);

         do
         {
           printf("Enter nid(must be exactly 7 characters long) >");
           gets(person[i].nid);
           x = strlen(person[i].nid);

         }while(x<7 || x >7);




    fflush(stdin);


    while(1)
    {
         printf("\n\n Username cannot have spaces\n");
         printf("The username must be of 5 or more characters\n");
         printf("Please enter a username to login later>");
         scanf("%s", person[i].username);


         printf("\n\nThe password must be of 5 or more characters\n");
         printf("Don't use spaces while setting your password\n\n");

         printf("Please enter a password>");
         scanf("%s", person[i].password);

              if(strlen(person[i].password)>=5 && strlen(person[i].username) >=5)
              {
                     break;
              }

           printf("\nUser name or password provided doesn't comply with the instructions given\n");
           printf("Please press enter and try again\n");
           getch();
           system("cls");
    }


    fprintf(in ,"%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , person[i].name , person[i].age , person[i].gender , person[i].nid , person[i].username, person[i].password);
    fclose(in);



    printf("REGISTRATION COMPLETE\n \n");
    printf("Press enter to continue \n");
    getch();


    printf("\n\n\n");

      i +=1;

      usermenu();


}




void printStructure();
void usermenu()
{
    int in;
              system("cls");
               while(1)
               {
                   system("cls");

                  printf("\n\t----------------------" );
                  printf("\n\n");
                  printf("\n\t2.View your registration");

                  printf("\n\t0.Goback");
                  printf("\n\t----------------------" );

                  printf("\n\tEnter input");
                  scanf("%d", &in);

                  if(in == 2)
                  {
                      system("cls");
                      printf("\n\n");
                     printStructure();
                     printf("Press enter to continue");
                     getch();
                  }


                  if(in == 0)
                  {
                      break;
                  }
               }
}





void modifyStructure()                    //USER DEFINED function to modify data
{
    system("cls");

    char check[10];

    char input_nid[10];
    char username[100], password[100];

    int x,j, flag=0, count = 3;


    fflush(stdin);
    printf("Enter input nid(7 characters)>");
    gets(input_nid);


    char view_name[50] , view_gender[10] , view_nid[10] ,us[30] , pass[30];
    int view_age;

    char up_name[50] , up_gender[10], up_nid[10];
    int up_age;

    FILE *old;

    FILE *newinfo;

    old = fopen("info.txt" , "r");

    if(old == NULL)
    {
        printf("Error");
        exit(1);
    }

    newinfo = fopen("newinfo.txt" , "w");

    if(newinfo == NULL)
    {
        printf("ERROR!");
        exit(1);
    }

    while(fscanf(old , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , &view_age, view_gender , view_nid , us , pass) !=EOF)
    {

        if(strcmp(view_nid , input_nid)==0)
        {
            flag = 1;

            while(count!=0)
            {
                printf("You have %d chances to get your password correct\n", count);

                fflush(stdin);
                printf("Enter username>");
                gets(username);

                printf("Enter password>");
                gets(password);


                if(strcmp(us, username)==0 && strcmp(pass, password)==0 )
                {


                     fflush(stdin);
                     printf("The names of fields are the followin: \n");
                     printf("name, age, gender\n");
                     printf("Enter the name of the field you want to modify in lower case>");
                     gets(check);

                     if(strcmp(check , "name")==0)
                     {
                         printf("Enter new name>");
                         gets(up_name);

                         fprintf(newinfo , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , up_name , view_age, view_gender , view_nid , us , pass);


                     }

                    if(strcmp(check , "age")==0)
                    {
                       printf("Enter new age>");
                       scanf("%d", &up_age);

                       fprintf(newinfo , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , up_age, view_gender , view_nid , us , pass);
                    }

                    if(strcmp(check , "gender")==0)
                    {
                       printf("Enter new gender>");
                       gets(up_gender);

                       fprintf(newinfo , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , view_age, up_gender , view_nid , us , pass);
                    }



                    printf("CHANGED SUCCESSFULLY\n\n");
                  break;
                }

                      else
                      {
                         printf("Wrong username or password");
                         printf("\n\n");

                      }

                     count-=1;

            }


        }

        else
        {
            fprintf(newinfo , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , view_age, view_gender , view_nid , us , pass);
        }



    }

    fclose(newinfo);
    fclose(old);

    remove("info.txt");
    rename("newinfo.txt" , "info.txt");

        if(flag == 0)
        {
            printf("Noone is registered using the NID you provided");
            printf("\n\n");
        }




   printf("\n");
}






void erase()
{
    system("cls");

    FILE *old , *newinfo;

    char nid[10];

    old = fopen("info.txt" , "r");
    newinfo = fopen("newinfo.txt" , "w");

    printf("Enter the nid of the person you want to delete>");
    fflush(stdin);
    gets(nid);


    char view_name[50] , view_gender[10] , view_nid[10] ,us[30] , pass[30];
    int view_age , found = 0;

    while(fscanf(old , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , &view_age, view_gender , view_nid , us , pass) !=EOF)
    {
        if(strcmp(nid , view_nid) != 0)
        {
            fprintf(newinfo , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , view_age, view_gender , view_nid , us , pass);
        }

        else
        {
            found = 1;
            printf("\nSuccessfully deleted\n");
        }
    }


    if(found == 0)
    {
        printf("The nid isn't registered in this system");
    }


    fclose(old);
    fclose(newinfo);

    remove("info.txt");
    rename("newinfo.txt" , "info.txt");

}






void printStructure()
{
     system("cls");

                printf("name>%s\n", person[i-1].name);

                printf("age>%d\n", person[i-1].age);

                printf("gender>%s\n", person[i-1].gender);

                printf("nid> %s", person[i-1].nid);

                printf("\n\n\n");



}




void adminview();
void eligibility();
void shots();

void adminlogin()
{
    system("cls");

    char admin_user[100] = "admin";
        char admin_pass[100] = "adminpass";
           int input;


            char user[100], pass[100];

            printf("\n\n\t");
              printf("Enter username:");
              scanf("%s",user);
              printf("\tEnter password:");
              scanf("%s",pass);
           printf("\n");

                    if (strcmp(user, admin_user) ==0 && strcmp(pass, admin_pass) == 0)
                      {
                           printf("\nAccess granted.\n");
                           printf("Press enter to continue\n");
                           getch();
                              while(1)
                              {

                                   system("cls");
                                   printf("\n\t----------------------" );
		                           printf("\n\t ADMIN MENU" );
                                   printf("\n\t1. View all registrations" );
		                           printf("\n\t2. Change number of shots" );
		                           printf("\n\t3. Change minimum age" );
		                           printf("\n\t4. Erase an entry" );
		                           printf("\n\tEnter 0 to go back." );
                                   printf("\n\t----------------------" );
                                   printf("\n\tEnter choice>");
                                   scanf("%d", &input);

                                   if(input == 0)
                                   {
                                       break;
                                   }

                                   switch(input)
                                   {
                                   case 1:
                                    adminview();
                                    break;

                                   case 2:
                                    shots();
                                    break;

                                   case 3:
                                     eligibility();
                                     break;

                                   case 4:
                                    erase();
                                     break;
                                   }

                                   printf("\nPress enter to continue");
                                   getch();

                              }
                      }

                      else
                      {
                          printf("\nACCESS DENIED\n");

                      }


}






void adminview()
{
    system("cls");
    int j;

    printf("\n\tViweing all registrations\n");

    FILE *out;

    out = fopen("info.txt" , "r");

    char view_name[50] , view_gender[10] , view_nid[10] ,us[30] , pass[30];
    int view_age;

    while(fscanf(out , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , &view_age, view_gender , view_nid , us , pass) !=EOF)
    {




        printf("\tname>%s\n", view_name);

        printf("\tage>%d\n", view_age);

        printf("\tgender>%s\n", view_gender);

        printf("\tnid> %s", view_nid);

        printf("\n\n");

     }



}




void eligibility()
{



    printf("\nEnter new age here>\n");
    scanf("%d", &new_age);

    printf("%d set as new age successfully!\n", new_age);
}






void shots()
{
    printf("\nEnter new available daily shots here>\n");
    scanf("%d", &person[i].supply);

    printf("%d set as new daily shots!\n", person[i].supply);
}





void viewform();
void userlogin()
{
    int input;


    while(1)
    {

        system("cls");
        printf("\n\t----------------------" );
		printf("\n\t MAIN MENU" );
		printf("\n\t1. View your registration form" );
		printf("\n\t2. Modify your form" );
		printf("\n\tEnter 0 to go back." );
        printf("\n\t----------------------" );
        printf("\n\tEnter choice>");
        scanf("%d", &input);


        if(input == 0)
        {
            break;
        }

        switch(input)
        {
        case 1: viewform();
        printf("\n\nPress enter to continue\n");
        getch();

        break;

        case 2: modifyStructure();
        printf("\n\nPress enter to continue\n");
        getch();
        break;




        }

    }


}






void viewform()
{
    char input_nid[100], user[100], pass[100];
    int j, found =0;

    fflush(stdin);
    printf("Enter nid>");
    gets(input_nid);

    char view_name[50] , view_gender[10] , view_nid[10] ,us[30] , pass1[30];
    int view_age;

    FILE *out;

    out = fopen("info.txt" , "r");

    if(out == NULL)
    {
        printf("ERROR!");
        exit(1);
    }

    while(fscanf(out , "%s\t%d\t%s\t\t%s\t\t%s\t\t\t%s\n" , view_name , &view_age, view_gender , view_nid , us , pass1) !=EOF)
    {


                if(strcmp(view_nid , input_nid)==0)
                {
                    found = 1;
                    printf("Enter username>");
                    gets(user);

                    printf("Enter password>");
                    gets(pass);

                    if(strcmp(us , user)==0 && strcmp(pass1, pass)==0)
                    {
                        printf("\n\n");
                        printf("Name>%s\n", view_name);
                        printf("Age>%d\n", view_age);
                        printf("Gender>%s\n", view_gender);
                        printf("Nid>%s\n", view_nid);
                        printf("\n\n");

                    }

                    else{printf("WRONG USERNAME OR PASSWORD\n");}

                }
    }

    fclose(out);

            if(found == 0)
            {
                printf("This nid isn't registered");
            }

}






void members()
{
    printf("\n\t DEVELOPED BY \n");
    Sleep(1000);

    printf("\n\tMD.Refayet Ullah Siddique\n\n\n");
    Sleep(1000);

}


void generalNews(){
  if(!person[i].supply){

        person[i].supply=30;

    printf("\n\tTodays available dose is %d\n",person[i].supply);
  }else{
         printf("\n\tTodays available dose is %d\n",person[i].supply);
  }

}


int main()
{
    int input;

    while(1)
    {
        system("cls");
        		printf("\n\t----------------------" );
		printf("\n\t MAIN MENU" );
		printf("\n\t1. General Information." );
		printf("\n\t2. Register for vaccine." );
		printf("\n\t3. Use as user." );
		printf("\n\t4. Use as Admin." );
		printf("\n\t5. To view developers");
		printf("\n\tEnter 0 to exit." );
        printf("\n\t----------------------" );
        printf("\n\tEnter choice");
        scanf("%d", &input);

        switch(input)
        {
          case 1:
                system("cls");
                generalNews();
                printf("\tPress enter to continue");
                getch();
                break;

          case 2:
              system("cls");
              if(input == 2 && i< MAX_REG)
              {
                  fillStructure();


                 break;

              }
              else
              {
                  printf("\nMax registrations reached\n");
                  printf("Press enter to continue\n");
                  getch();
                  break;
              }

           case 3:
               userlogin();
               break;


           case 4:
               system("cls");
                adminlogin();
                printf("Press enter to continue");
                getch();
           break;


           case 5:
                system("cls");
                members();
                printf("Press enter to continue");
                getch();
             break;


           case 0: exit(1);
                break;



           default:
            printf("\nINVALID INPUT.Press enter and read instructions carefully\n");
            getch();
            break;

        }

    }

    return 0;
}
