#include <stdio.h>

#define GRows 5
#define GCol 5

void UpdateStatus(int maingird[GRows][GCol]);
void StatusReport(int maingird[GRows][GCol]);
void SystemDiagnostic(int maingird[GRows][GCol]);
void StatusPrinter(int Pow, int OLoad, int Maint);

int main() {
    int ch, flag = 1;
    int maingird[GRows][GCol] = {0};

    while (flag == 1) {
        printf("\nSystem main menu\n");
        printf("1.Update section status\n");
        printf("2.Query section status\n");
        printf("3.Run system diagnostics\n");
        printf("0.Exit\n");
        printf("Enter Choice (0-3): ");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                printf("Exit\n");
                flag = 0;
                break;
            case 1:
                UpdateStatus(maingird);
                break;
            case 2:
                StatusReport(maingird);
                break;
            case 3:
                SystemDiagnostic(maingird);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

void StatusPrinter(int Pow, int OLoad, int Maint) {
    printf("Power: ");
    if (Pow == 1) {
        printf("ON\n");
    } else {
        printf("OFF\n");
    }

    printf("OverLoad: ");
    if (OLoad == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    printf("Maintenance: ");
    if (Maint == 1) {
        printf("Required\n");
    } else {
        printf("Not Required\n");
    }
}

void UpdateStatus(int maingird[GRows][GCol]) {
    int Row, Col;
    int Pow, OLoad, Maint;
    
    while (1) {
        printf("\nEnter Row Number (1 - %d): ", GRows);
        scanf("%d", &Row);
        printf("Enter Col Number (1 - %d): ", GCol);
        scanf("%d", &Col);

        if (Row >= 1 && Row <= GRows && Col >= 1 && Col <= GCol) {
            Row--; Col--;
            break;
        } else {
            printf("Invalid row or column.\n");
        }
    }

    printf("Enter Power Status (0 = off, 1 = on): ");
    scanf("%d", &Pow);
    printf("Enter OverLoad Status (0 = normal, 1 = overloaded): ");
    scanf("%d", &OLoad);
    printf("Enter Maintenance Status (0 = not required, 1 = required): ");
    scanf("%d", &Maint);

    int Sector = 0;
    if (Pow == 1) {
        Sector = Sector | 1;
    }
    if (OLoad == 1) {
        Sector = Sector | 0b10;
    }
    if (Maint == 1) {
        Sector = Sector | 0b100;
    }

    maingird[Row][Col] = Sector;
    printf("Status updated!\n");
}

void StatusReport(int maingird[GRows][GCol]) {
    int Row, Col;
    printf("\nEnter Row Number (1 - %d): ", GRows);
    scanf("%d", &Row);
    printf("Enter Col Number (1 - %d): ", GCol);
    scanf("%d", &Col);

    if (Row < 1 || Row > GRows || Col < 1 || Col > GCol) {
        printf("Invalid coordinates!\n");
        return;
    }

    Row--; Col--;
    int Sector = maingird[Row][Col];

    if (Sector == 0) {
        printf("No data for this sector yet\n");
        return;
    }

    int Pow = (Sector >> 0) & 1;
    int OLoad = (Sector >> 1) & 1;
    int Maint = (Sector >> 2) & 1;

    printf("\nGrid Report for (%d, %d)\n", Row + 1, Col + 1);
    StatusPrinter(Pow, OLoad, Maint);
}

void SystemDiagnostic(int maingird[GRows][GCol]) {
    int OLoad, Maint, Sector, Count = 0;

    for (int i = 0; i < GRows; i++) {
        for (int j = 0; j < GCol; j++) {
            Sector = maingird[i][j];
            OLoad = (Sector >> 1) & 1;
            Maint = (Sector >> 2) & 1;
            if (OLoad == 1 || Maint == 1) {
                Count++;
            }
        }
    }

    printf("\nSystem Diagnostics:\n");
    printf("Sectors currently Overloaded or Requiring Maint: %d\n", Count);
}
