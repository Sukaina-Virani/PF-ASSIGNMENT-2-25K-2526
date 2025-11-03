#include<stdio.h>
#include<string.h>

void customerInfo(char name[], char CNIC[]);
void Inventory(int code[], int stock[], float price[], int count);
int Cart(int code[], int stock[], float price[], int count, int cartCode[], int cartQty[], int cartCount);
float Bill(int cartCode[], int cartQty[], float price[], int count);
void Invoice(char name[], char cnic[], float total);

int main()
{
    int choice, run = 1;
    int cartCode[100], cartQty[100], cartCount = 0;
    int code[4] = {1, 2, 3, 4};
    int stock[4] = {50, 10, 20, 8};
    float price[4] = {100, 200, 300, 150};
    int count = 4;
    char name[25], CNIC[13];
    float total = 0;

    printf("--- SUPERMARKET MANAGEMENT SYSTEM ---\n\n");
    customerInfo(name, CNIC);

    while(run == 1)
    {
        printf("\nMenu:\n");
        printf("1. Display Inventory\n");
        printf("2. Purchase Items\n");
        printf("3. Display Total Bill\n");
        printf("4. Show Invoice\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 0)
        {
            printf("Exiting program..\n");
            run = 0;
        }
        else if (choice == 1)
        {
            Inventory(code, stock, price, count);
        }
        else if (choice == 2)
        {
            cartCount = Cart(code, stock, price, count, cartCode, cartQty, cartCount);
        }
        else if (choice == 3)
        {
            total = Bill(cartCode, cartQty, price, cartCount); 
            printf("\n");
        }
        else if (choice == 4)
        {
            Invoice(name, CNIC, total);
        }
        else
            printf("Invalid choice!\n");
    }
}

// Customer info
void customerInfo(char name[], char CNIC[]) 
{
    printf("Enter customer name: ");
    scanf("%s", name);
    printf("Enter CNIC number: ");
    scanf("%s", CNIC);
    printf("Customer info saved.\n");
}

// Display inventory
void Inventory(int code[], int stock[], float price[], int count) 
{
    printf("\nProduct Code\tStock\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%d\t%.2f\n", code[i], stock[i], price[i]);
    }
}

// Purchase Items
int Cart(int code[], int stock[], float price[], int count, int cartCode[], int cartQty[], int cartCount)
{
    int proCode, qty, available, more = 1;

    while(more == 1)
    {
        available = 0;
        printf("Enter Product Code Of Item You want to Purchase: ");
        scanf("%d", &proCode);

        for (int i = 0; i < count; i++)
        {
            if (proCode == code[i])
            {
                available = 1;
                printf("Quantity: ");
                scanf("%d", &qty);

                if (qty <= stock[i])
                {
                    stock[i] -= qty;
                    cartCode[cartCount] = proCode;
                    cartQty[cartCount] = qty;
                    cartCount++;
                    printf("Item added to cart\n");
                }
                else
                {
                    printf("Stock not available.\n");
                }
                break;
            }
        }

        if (!available)
        {
            printf("Invalid product code!\n");
        }

        printf("Do you want to add more items? (1=YES, 0=NO): ");
        scanf("%d", &more);
    }

    return cartCount;
}

// Total Bill
float Bill(int cartCode[], int cartQty[], float price[], int count)
{
    float total = 0;
    float disTotal=0;
    printf("\nItem purchased:\n");
    printf("Code\tQty\tPrice\tTotal\n");

    for (int i = 0; i < count; i++)
    {
        int code = cartCode[i];
        int qty = cartQty[i];
        float cost = price[code - 1] * qty;

        printf("%d\t%d\t%.2f\t%.2f\n", code, qty, price[code - 1], cost);
        total = total + cost;
    }
    char promo[20];
    printf("\nEnter promo code (if any): ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0)
    {
        disTotal = total - (total * 0.25);
        printf("Promo code is valid! 25%% discount applied.\n");
    } else {
        printf("No discount applied.\n");
    }    
    printf("\nBill before discount: %.2f\n",total);
    printf("\nFinal Bill after discount: %.2f\n", disTotal);
    return disTotal;
}

// Show invoice
void Invoice(char name[], char cnic[], float total)
{
    printf("\n---INVOICE---\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);

    printf("Total Bill: %.2f\n", total);
    printf("\n");
    printf("Thank you for shopping!\n");
}
