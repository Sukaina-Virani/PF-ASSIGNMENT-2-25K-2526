#include <stdio.h>
#include <string.h>

int NewBook(int isbn[], char name[][50], float price[], int quant[], int BookC);
void BookSale(int isbn[], char name[][50], float price[], int quant[], int BookC);
void LowStockReport(int isbn[], char name[][50], float price[], int quant[], int BookC);

int main() {
    int ch, flag=1, BookC=0 ;
    int isbn[100],quant[100];   
    char name[100][50];
    float price[100];                   

    while (flag == 1) {
        printf("\n-----LIBERTY BOOK STORE MENU-----\n");
        printf("1. Add New Book\n");
        printf("2. Process a sale\n");
        printf("3. Low Stock Report\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                printf("GoodBye!\n");
                flag = 0;
                break;
            case 1:
                BookC = NewBook(isbn, name, price, quant, BookC);
                break;
            case 2:
                BookSale(isbn, name, price, quant, BookC);
                break;
            case 3:
                LowStockReport(isbn, name, price, quant, BookC);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        
    }

    return 0;
}
    // Adding NewBook
int NewBook(int isbn[], char name[][50], float price[], int quant[], int BookC) {
    if (BookC == 100) {
        printf("Inventory is full!\n");
        return BookC;
    }

    int newisbn, newQaunt;
    float newprice;
    char newName[50];
    int valid = 1;

    printf("\nEnter ISBN number: ");
    scanf("%d", &newisbn);

    if (newisbn <= 0) {
        printf("Invalid ISBN!\n");
        valid = 0;
    }

    for (int i = 0; i < BookC; i++) {
        if (isbn[i] == newisbn) {
            printf("ISBN already exists!\n");
            valid = 0;
            break;
        }
    }

    if (valid == 1) {
        printf("--Enter details of the book--\n ");
        printf("Name: ");
        scanf(" %[^\n]", newName); 
        printf("Price: ");
        scanf("%f", &newprice);
        printf("Quantity: ");
        scanf("%d", &newQaunt);

        if (newprice > 0 && newQaunt > 0) {
            isbn[BookC] = newisbn;
            strcpy(name[BookC], newName);
            price[BookC] = newprice;
            quant[BookC] = newQaunt;
            BookC++;
            printf("Book added successfully!\n");
        } else {
            printf("Invalid Input!\n");
        }
    }
    return BookC;
}

// BookSale
void BookSale(int isbn[], char name[][50], float price[], int quant[], int BookC) {
    int sellISBN, sellQty, index = -1;

    printf("\nEnter ISBN: ");
    scanf("%d", &sellISBN);

    for (int i = 0; i < BookC; i++) {
        if (isbn[i] == sellISBN) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not available!\n");
        return;
    }

    printf("Enter quantity:");
    scanf("%d", &sellQty);

    if (sellQty <= 0 || sellQty > quant[index]) {
        printf("Quantity not available!\n");
        return;
    }

    float FinalBill = sellQty * price[index];

    printf("\n---INVOICE---\n");
    printf("Book: %s\n", name[index]);
    printf("ISBN: %d\n", isbn[index]);
    printf("Price per book: Rs. %.2f\n", price[index]);
    printf("Quantity sold: %d\n", sellQty);
    printf("Total price: Rs. %.2f\n", FinalBill);

    quant[index] = quant[index] - sellQty;
    printf("Book sold!\n");
}

// Show low stock books
void LowStockReport(int isbn[], char name[][50], float price[], int quant[], int BookC) {
    if (BookC == 0) {
        printf("\nNo books in stock!\n");
        return;
    }

    int count = 0;
    printf("\n---LOW STOCK REPORT---\n");

    for (int i = 0; i < BookC; i++) {
        if (quant[i] < 5) {
            count++;
            printf("\nBook: %d\n", count);
            printf("ISBN: %d\n", isbn[i]);
            printf("Name: %s\n", name[i]);
            printf("Price: Rs. %.2f\n", price[i]);
            printf("Quantity left: %d\n", quant[i]);
        }
    }

    if (count == 0)
        printf("All books are in stock.\n");
}
