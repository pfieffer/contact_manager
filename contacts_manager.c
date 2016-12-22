#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
 struct contact
{
long ph;
char name[20],add[20],email[30];
}con;
 
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,c,found;
 
int main()
{
main:
       /* ************Main menu ***********************  */
printf("\n\t\t**** Contacts Manager ****");
printf("\n\n\n\t\t\tMAIN MENU\n\t\t++++++++++++++++++++++++\n\t\t[1] Add a new Contact\n\t\t[2] Edit a contact\n\t\t[3] Search for a contact\n\t\t[4] List all contacts\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t++++++++++++++++++++++++\n\t\t");
printf("Please enter your choice:");
scanf("%d",&ch);
 
switch(ch)
{
case 0:
printf("\n\n\t\tAre you sure u want to exit?");
break;
//Add a new contact
case 1:
 
fp=fopen("contact.dll","a");
while(1)
{
         fflush(stdin);
         printf("\n\nYou are now creating a new contact.\n\nTo exit enter blank space in the name input\nName: ");
         gets(con.name);
         if(strcmp(con.name,"")==0 || strcmp(con.name," ")==0)
                                   break;
         fflush(stdin);
         printf("Phone: ");
         scanf("%ld",&con.ph);
         fflush(stdin);
         printf("Address: ");
         gets(con.add);
         fflush(stdin);
         printf("Email address: ");
         gets(con.email);
         printf("\n");
         fwrite(&con,sizeof(con),1,fp);
}
fclose(fp);
break;
 
//edit a contact
case 2:

fp=fopen("contact.dll","r");
ft=fopen("temp.dll","w");
fflush(stdin);
printf(">>Edit contact\n===============================\n\n\t>>Enter the name of contact to edit:");
gets(name);
while(fread(&con,sizeof(con),1,fp)==1)
{
 if(strcmp(name,con.name)!=0)
 fwrite(&con,sizeof(con),1,ft);
}
fflush(stdin);
printf("\n\n>>Editing '%s'\n\n",name);
printf(">>Name: ");
gets(con.name);
fflush(stdin);
printf(">>Phone:");
scanf("%ld",&con.ph);
fflush(stdin);
printf(">>Address:");
gets(con.add);
fflush(stdin);
printf(">>Email address:");
gets(con.email);
printf("\n");
fwrite(&con,sizeof(con),1,ft);
fclose(fp);
fclose(ft);
remove("contact.dll");
rename("temp.dll","contact.dll");
break;

 
 
 
//search contact
case 3:

do
{
     
     found=0;
     printf("\n\n\t>>>CONTACT SEARCH\n\t********************\n\t..::Name of contact to search: ");
     fflush(stdin);
     gets(query);
     l=strlen(query);
     fp=fopen("contact.dll","r");
 
     printf("\n\n>>Search result for '%s' \n===================================================\n",query);
                          while(fread(&con,sizeof(con),1,fp)==1)
                          {
                           for(i=0;i<=l;i++)
                           name[i]=con.name[i];
                           name[l]='\0';
                           if(strcmp(name,query)==0)
                           {
                            printf("\n>>Name   : %s\n>>Phone  : %ld\n>>Address: %s\n>>Email  : %s\n",con.name,con.ph,con.add,con.email);
                            found++;
                            }
                           }
 
 if(found==0)
 printf("\n>>No match found!");
                else
                    {
                    printf("\n>>%d match(s) found!",found);
                    fclose(fp);
                    printf("\n>>Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
                    scanf("%d",&c);
                    }
}while(c==1);

break;
 
 
//list all contacts
case 4:

printf("\n\t\t________________________________\n\t\t\tLIST OF CONTACTS\n\t\t________________________________\nName\t\tPhone No\tAddress\t\t\tE-mail ad.\n=================================================================\n\n");
 

 
fp=fopen("contact.dll","r");
fflush(stdin);
while(fread(&con,sizeof(con),1,fp)==1)
{
 printf("%-16s%-16ld%-23s%-16s\n",con.name,con.ph,con.add,con.email);

}

printf("\n---------------------------------------------------------------------- \n\n");
getch();

fclose(fp);
 
break;
 


//delete a contact
case 5:

fflush(stdin);
printf("\n\n\t>>>DELETE A CONTACT\n\t==========================\n\t..::Enter  the name of contact to delete:");
gets(name);
fp=fopen("contact.dll","r");
ft=fopen("temp.dll","w");
while(fread(&con,sizeof(con),1,fp)!=0)
if (strcmp(name,con.name)!=0)
fwrite(&con,sizeof(con),1,ft);
fclose(fp);
fclose(ft);
remove("contact.dll");
rename("temp.dll","contact.dll");
break;
 
default:
printf("Invalid choice");
break;
}

 
 
printf("\n\n\n>>>Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
scanf("%d",&ch);
switch (ch)
{
case 1:
goto main;
 
 
case 0:
break;
 
default:
printf("Invalid choice");
break;
}
 
return 0;
}
