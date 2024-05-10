#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // For usleep
#include <conio.h>

#define MAX_DRINKS 5

typedef struct
{
    int code;
    char name[20];
    int price;
    int quantity;
} Drink;

Drink drinks[MAX_DRINKS] = {
    {1, "Cola", 75000, 7},
    {2, "Sprite", 7500, 7},
    {3, "Pepsi", 8500, 7},
    {4, "Fanta", 7500, 7},
    {5, "NutriBoost", 6500, 7}};

void display()
{
    printf("*******************************************\n");
    printf("\t\tSoft Drinks\n");
    printf("*******************************************\n");
    printf("%-12s%-12s%-12s%-12s\n", "Code", "Name", "Price(IDR)", "Quantity");
    for (int i = 0; i < MAX_DRINKS; i++)
    {
        printf("%-12d%-12s%-12d%-12d\n", drinks[i].code, drinks[i].name, drinks[i].price, drinks[i].quantity);
    }
}

void loading()
{
    printf("Loading...\n");

    for (int i = 0; i < 100; i++)
    {
        printf("\rProgress: [%d%%]", i);
        fflush(stdout);
        usleep(10000);
    }
    printf("\nLoading Complete\n");
}

void beliDrink(int drinkCode, int bayar)
{
    int index = -1;

    printf("Enter drink code: ");
    scanf("%d", &drinkCode);

    printf("Enter your money: ");
    scanf("%d", &bayar);

    for (int i = 0; i < MAX_DRINKS; i++)
    {
        if (drinks[i].code == drinkCode)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Maaf, minuman tidak tersedia\n");
        getch();
    }
    else if (drinks[index].quantity == 0)
    {
        printf("Maaf, %s stock tidak ada.\n", drinks[index].name);
        getch();
    }
    else if (bayar < drinks[index].price)
    {
        printf("Nominal uang tidak cukup.\n");
        getch();
    }
    else
    {
        printf("Mohon ditunggu %s. Terima Kasih!\n", drinks[index].name);
        drinks[index].quantity--;
        printf("Kembalian: $%d\n", bayar - drinks[index].price);
        getch();
    }
}

int main()
{
    printf("WELCOME TO NOLAN VM!\n");
    loading();
    sleep(3);
    system("cls");
    display();
    int drinkCode, bayar; // Variables to hold user input
    beliDrink(drinkCode, bayar);
    display();
    getch();
    return 0;
}
