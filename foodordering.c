#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int choice,x,i,j,choice2;
int flag=1,c,success=1;
char mobile_no[100];
char name[100];
int total = 0, food_choice, n, food;
int hotel_choice, hotel_id;
int ch,confirm;

void signup();
void login();
int validate();
void acc_check();
void hotel_initialize();
void searchby_hotels();
void searchby_food();
void hotels(int hotel_choice);
void food_order(int food);
void cart();

struct details{
    char uname[100];
    char mobile_no[10];
}s[100];

struct hotels{
    char hotel[100];
    char food1[100];
    char food2[100];
    char food3[100];
    int first,second,third;
}h[5];

int main()
{
    while(1){
        printf("WELCOME TO FOOD ORDERING\n\n");
        printf("1) SIGNUP\n2) LOGIN\n3) EXIT\n");
        printf("Select any of the options: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1: signup(); break;
            case 2: login(); break;
            case 3: printf("Exiting"); exit(0); break;
            default : printf("Please select any valid option\n"); break;
        }
    }
}

void signup()
{
    printf("Enter username: ");
    scanf("%s",name);
    printf("Enter mobile number: ");
    scanf("%s",mobile_no);

    x = validate();
    if(x == 1)
    {
        acc_check();
        login();
    }
}

int validate()
{
    for(i = 0; name[i] != '\0'; i++) {
        if(!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))) {
            printf("Enter valid name\n");
            flag = 0;
            break;
        }
    }
    if (flag == 1) c = 0;

    if(strlen(mobile_no) == 10) {
        for(i=0; i<10; i++) {
            if(!(mobile_no[i]>='0' && mobile_no[i]<='9')) {
                printf("\nPlease Enter Valid mobile Number\n");
                return 0;
            }
        }
    } else {
        printf("\nPlease Enter Valid mobile Number\n");
        return 0;
    }
    return 1;
}

void acc_check()
{
    for (i = 0; i < 100; i++) {
        if (!(strcmp(name, s[i].uname) && strcmp(mobile_no, s[i].mobile_no))) {
            printf("\nAccount Already Exists. Please Login\n");
            main();
            break;
        }
    }
    if (i == 100) {
        strcpy(s[i].uname, name);
        strcpy(s[i].mobile_no, mobile_no);
        i++;
        printf("\nAccount Successfully Created!\n");
    }
}

void login()
{
    printf("\nWELCOME TO LOGIN PAGE\n");
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter mobile number: ");
    scanf("%s",mobile_no);
    for(i=0;i<100;i++) {
        if(strcmp(s[i].uname,name) == 0 && strcmp(s[i].mobile_no, mobile_no) == 0) {
            printf("\nWELCOME %s\n", name);
            printf("YOU SUCCESSFULLY LOGGED IN\n");
            printf("We provide two ways of search\n");
            printf("1) Search by hotel\n2) Search by food\n3) Exit\n");
            printf("Enter a choice: ");
            scanf("%d",&choice2);
            switch(choice2) {
                case 1: searchby_hotels(); break;
                case 2: searchby_food(); break;
                case 3: main(); break;
                default: printf("Enter a valid choice\n"); break;
            }
            break;
        }
        if(i == 99) {
            printf("Login failed! Account not found.\n");
            main();
        }
    }
}

void hotel_initialize()
{
    strcpy(h[1].hotel, "Hotel 1");
    strcpy(h[1].food1, "Sandwich");
    strcpy(h[1].food2, "Pizza");
    strcpy(h[1].food3, "Fried Rice");
    h[1].first=70; h[1].second=100; h[1].third=120;

    strcpy(h[2].hotel, "Hotel 2");
    strcpy(h[2].food1, "Parotta");
    strcpy(h[2].food2, "Dosa");
    strcpy(h[2].food3, "Noodles");
    h[2].first=80; h[2].second=35; h[2].third=90;

    strcpy(h[3].hotel, "Hotel 3");
    strcpy(h[3].food1, "Burger");
    strcpy(h[3].food2, "Falooda");
    strcpy(h[3].food3, "Biryani");
    h[3].first=60; h[3].second=55; h[3].third=95;
}

void searchby_hotels()
{
    hotel_initialize();
    printf("\nPlease Choose the hotels:\n");
    printf("1) %s\n2) %s\n3) %s\n4) Exit\n", h[1].hotel,h[2].hotel,h[3].hotel);
    printf("Select the hotel: ");
    scanf("%d", &hotel_choice);
    if (hotel_choice > 4) {
        printf("Please Enter valid choice\n");
        searchby_hotels();
    } else if (hotel_choice == 4) exit(1);
    else hotels(hotel_choice);
}

void hotels(int hotel_choice)
{
    total = 0;
    while (1) {
        printf("\nList of foods available in %s:\n", h[hotel_choice].hotel);
        printf("1) %s Rs: %d\n", h[hotel_choice].food1, h[hotel_choice].first);
        printf("2) %s Rs: %d\n", h[hotel_choice].food2, h[hotel_choice].second);
        printf("3) %s Rs: %d\n", h[hotel_choice].food3, h[hotel_choice].third);
        printf("4) Cart\n5) Exit\nEnter your choice: ");
        scanf("%d", &food_choice);
        if (food_choice == 1) {
            printf("Enter quantity of %s: ", h[hotel_choice].food1);
            scanf("%d", &n);
            total += n * h[hotel_choice].first;
        } else if (food_choice == 2) {
            printf("Enter quantity of %s: ", h[hotel_choice].food2);
            scanf("%d", &n);
            total += n * h[hotel_choice].second;
        } else if (food_choice == 3) {
            printf("Enter quantity of %s: ", h[hotel_choice].food3);
            scanf("%d", &n);
            total += n * h[hotel_choice].third;
        } else if (food_choice == 4) {
            cart();
        } else if (food_choice == 5) {
            searchby_hotels();
        } else {
            printf("Please Enter valid Choice\n");
        }
    }
}

void searchby_food()
{
    total = 0;
    hotel_initialize();
    while(1) {
        printf("\nPlease choose the food:\n");
        printf("1) %s %d\n", h[1].food1, h[1].first);
        printf("2) %s %d\n", h[1].food2, h[1].second);
        printf("3) %s %d\n", h[1].food3, h[1].third);
        printf("4) %s %d\n", h[2].food1, h[2].first);
        printf("5) %s %d\n", h[2].food2, h[2].second);
        printf("6) %s %d\n", h[2].food3, h[2].third);
        printf("7) %s %d\n", h[3].food1, h[3].first);
        printf("8) %s %d\n", h[3].food2, h[3].second);
        printf("9) %s %d\n", h[3].food3, h[3].third);
        printf("10) Cart\n11) Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&food);
        if(food > 10){
            printf("Please enter valid choice\n");
            searchby_food();
        }
        if(food == 10) cart();
        if(food == 11) exit(1);
        else food_order(food);
    }
}

void food_order(int food)
{
    if (food >= 1 && food <= 3) hotel_id = 1;
    else if (food >= 4 && food <= 6) hotel_id = 2;
    else hotel_id = 3;

    if ((food % 3) == 1) {
        printf("Enter quantity of %s: ", h[hotel_id].food1);
        scanf("%d", &n);
        total += n * h[hotel_id].first;
    }
    else if ((food % 3) == 2) {
        printf("Enter quantity of %s: ", h[hotel_id].food2);
        scanf("%d", &n);
        total += n * h[hotel_id].second;
    }
    else if ((food % 3) == 0) {
        printf("Enter quantity of %s: ", h[hotel_id].food3);
        scanf("%d", &n);
        total += n * h[hotel_id].third;
    }
}

void cart()
{
    printf("\nYour Total Order Amount is: %d\n", total);
    printf("Do you wish to order? (yes=1 / no=0): ");
    scanf("%d", &ch);
    if (ch == 1) {
        printf("Thank you for your order! Your food is on the way.\n");
        exit(1);
    } else if (ch == 0) {
        printf("Do you want to exit =1 or Go back =0: ");
        scanf("%d", &confirm);
        if (confirm == 1) {
            printf("Order cancelled! Thank you, visit again!\n");
            exit(1);
        } else {
            login();
        }
    } else {
        printf("Please enter correct choice\n");
        cart();
    }
}
