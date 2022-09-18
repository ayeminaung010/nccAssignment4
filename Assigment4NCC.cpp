#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIZE 100

void insertData();
void findData();
void updateData();


int programs  = 0;
    FILE *fptr;

struct NccAssigment4{
    char name[20];
    int password;
    int age;
    int id;
    char address[20];
    int amount;
};


int main(){
    do
    {
      printf("\nPress 1 to Insert Data.. :\n");
        printf("Press 2 to Find your Data.. :\n");
        printf("Press 3 to Update your Data.. :\n");

        scanf("%d",&programs);
        switch (programs)
        {
        case 1:
            insertData();
            break;
        case 2:
            findData();
            break;
        case 3:
            updateData();
            break;
        default:
            printf("Wrong input Try Again!");

        }
    } while (programs != NULL);
}

void insertData(){
    int number = 0;
    printf("How many people do u want ..:");
    scanf("%d",&number);
     fptr = fopen("assigment4.txt","a");
    for (int i = 0; i < number; i++)
    {

        struct NccAssigment4 *user;
        user = (struct NccAssigment4*)calloc(number,sizeof(struct NccAssigment4));
        puts("\nEnter your id, name,password,age,address,amount");
        printf(">:");
        scanf("%d%s%d%d%s%d",&user[i].id,&user[i].name ,&user[i].password ,&user[i].age , &user[i].address ,&user[i].amount );


         if(fptr == NULL){
            printf("File cannot open !");
            exit(1);
        }else{
            fprintf(fptr,"%d%10s%10d%10d%10s%10d \n",user[i].id,user[i].name ,user[i].password ,user[i].age , user[i].address ,user[i].amount);
        }


    }
    fclose(fptr);

}
void findData(){
    char data[SIZE];

    int id;
    fptr =  fopen("assigment4.txt","r");
    
    if(fptr == NULL){
        printf("You cannot read the file you dont have file");
        exit(1);
    }else if(sizeof(fscanf(fptr,"%s",&data )) == '\0' ){
        printf("you dont have data..");

    }else{

        NccAssigment4 user1,user;

        fscanf(fptr,"%d%s%d%d%s%d",&user1.id,&user1.name ,&user1.password ,&user1.age , &user1.address ,&user1.amount );

        printf("Enter id to find data ...:");
        scanf("%d",&user.id);

        if(user1.id == user.id){
            printf("\nid is %d\n",user1.id);
            printf("name is %s\n",user1.name);
            printf("password is %d\n",user1.password);
            printf("age is %d\n",user1.age);
            printf("address is %s\n",user1.address);
            printf("amount is %d\n",user1.amount);
        }


    }

    fclose(fptr);

}

void updateData(){
    fptr =  fopen("assigment4.txt","r");
    char data[SIZE];

    int id;
    FILE *fptr1;
    if(fptr == NULL){
        printf("Your file does not have data..,You cannot read the file");
        exit(1);
    }else{
         NccAssigment4 user1,user;

        fgets( data,SIZE,fptr);
        fscanf(fptr,"%d%s%d%d%s%d",&user1.id,&user1.name ,&user1.password ,&user1.age , &user1.address ,&user1.amount );

        printf("Enter id to change data ...:");
        scanf("%d",&user.id);

        if(user1.id == user.id){
            printf("\nid is %d\n",user1.id);
            printf("name is %s\n",user1.name);
            printf("password is %d\n",user1.password);
            printf("age is %d\n",user1.age);
            printf("address is %s\n",user1.address);
            printf("amount is %d\n",user1.amount);
        }
        fptr1 = fopen("assigment4.txt","a");
        printf("Enter new  username to update ");
        scanf("%s",&user1.name);

        printf("After changing, your data......:\n");

        printf("\nid is %d\n",user1.id);
        printf("name is %s\n",user1.name);
        printf("password is %d\n",user1.password);
        printf("age is %d\n",user1.age);
        printf("address is %s\n",user1.address);
        printf("amount is %d\n",user1.amount);

        if(fptr == NULL){
            printf("File cannot open !");
            exit(1);
        }else{
            fprintf(fptr1,"%d%10s%10d%10d%10s%10d \n",user1.id,user1.name ,user1.password ,user1.age , user1.address ,user1.amount);
        }

        fclose(fptr1);
    }

    fclose(fptr);
}
