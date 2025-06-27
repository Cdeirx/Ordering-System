
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>
#define clrscr() system("cls")
#define gotoxy(x, y) { COORD coord = {x, y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); }
#define BOX_TOP 10
#define BOX_BOTTOM 25
#define BOX_LEFT 50
#define BOX_RIGHT 112
#define MAX_ITEMS 100

void display_summary(int P[], int TSB[], char DESC[][15], int SB[], int TSL[], int TS[])
{
    clrscr();
    for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
    for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
    for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
    for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
    gotoxy(BOX_LEFT, BOX_TOP); printf("+");
    gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
    gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
    gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");

    gotoxy(BOX_LEFT + 22, 11); printf("SUMMARY OF SALES");
    gotoxy(BOX_LEFT + 19, 13); printf("    SB  SOLD  SF  SALES");
    for (int i = 0; i < 3; i++)
    {
        gotoxy(BOX_LEFT + 5, 14 + i); printf("%s", DESC[i]);
        gotoxy(BOX_LEFT + 23, 14 + i); printf("%d", SB[i]);
        gotoxy(BOX_LEFT + 29, 14 + i); printf("%d", TS[i]);
        gotoxy(BOX_LEFT + 33, 14 + i); printf("%d", TSB[i]);
        gotoxy(BOX_LEFT + 39, 14 + i); printf("%d", TSL[i]);
    }
    gotoxy(BOX_LEFT + 17, 18); printf("Press any key to continue...");
    gotoxy(BOX_LEFT + 25, 19); getch();
}

void reset_order(int TSB[], int SB[], int S[], int SL[], int TSL[], int TS[], int *T, int *QTY)
{
    TSB[0] = SB[0]; TSB[1] = SB[1]; TSB[2] = SB[2];
    TS[0] = S[0]; TS[1] = S[1]; TS[2] = S[2];
    TSL[0] = SL[0]; TSL[1] = SL[1]; TSL[2] = SL[2];
    *T = 0;
    *QTY = 0;
}

int main()
{

    int P[] = {50, 40, 30}, SB[] = {100, 100, 100}, TSB[] = {100, 100, 100}, CTR = 1;
    int order_items[MAX_ITEMS] = {0}, order_qty[MAX_ITEMS] = {0}, order_subtotal[MAX_ITEMS] = {0};
    int QTY = 0, ST = 0, T = 0, GT = 0, TSL[] = {0, 0, 0}, TS[] = {0, 0, 0}, SL[] = {0, 0, 0}, S[] = {0, 0, 0};
    int CTRII = 0, PAY, C, CHO, TGT = 0;
    char DESC[][15] = {"HAMBURGER", "FRENCH FRIES", "COKE"}, OPT, OPT1, OPT3;

menu:
    clrscr();
    for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
    for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
    for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
    for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
    gotoxy(BOX_LEFT, BOX_TOP); printf("+");
    gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
    gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
    gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");

    gotoxy(BOX_LEFT + 20, 11); printf("CUSTOMER: %d", CTR);
    gotoxy(BOX_LEFT + 35, 11); printf("Or NO. %d", CTR);
    gotoxy(BOX_LEFT + 31, 12); printf("MENU");
    for (int CTRM = 0; CTRM < 3; CTRM++)
    {
        gotoxy(BOX_LEFT + 19, 14 + CTRM); printf("%d.", CTRM + 1);
        gotoxy(BOX_LEFT + 22, 14 + CTRM); printf("%s", DESC[CTRM]);
        gotoxy(BOX_LEFT + 36, 14 + CTRM); printf("%d", P[CTRM]);
        gotoxy(BOX_LEFT + 40, 14 + CTRM); printf("%d", TSB[CTRM]);
    }
    gotoxy(BOX_LEFT + 19, 17); printf("4. EXIT");
    gotoxy(BOX_LEFT + 22, 19); printf("Enter your choice:");
    gotoxy(BOX_LEFT + 40, 19); scanf("%d", &CHO);

    if (CHO >= 1 && CHO <= 3)
    {
        if (TSB[CHO - 1] == 0)
        {
            clrscr();
            for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
            for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
            for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
            for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
            gotoxy(BOX_LEFT, BOX_TOP); printf("+");
            gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
            gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
            gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
            gotoxy(BOX_LEFT + 12, 18); printf("Out of stock. Please choose another item.");
            gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
            gotoxy(BOX_LEFT + 25, 17); getch();
            if ((TSB[0] == 0 && TSB[1] == 0 && TSB[2] == 0) && CTRII > 0)
            {
                clrscr();
                for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT + 15, 18); printf("You've taken all the stock");
                gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
                getch();
                goto payment;
            }
            else if ((TSB[0] == 0 && TSB[1] == 0 && TSB[2] == 0) && CTRII == 0)
            {
                clrscr();
                for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT + 17, 18); printf("Menu is out of order");
                gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
                getch();
                return 0;
            }
            else
            {
                goto menu;
            }
        }
        else
        {
enter:
            clrscr();
            for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
            for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
            for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
            for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
            gotoxy(BOX_LEFT, BOX_TOP); printf("+");
            gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
            gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
            gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
            gotoxy(BOX_LEFT + 13, 18); printf("How many would you like to purchase?");
            gotoxy(BOX_LEFT + 30, 19);
            if (scanf("%d", &QTY) != 1)
            {
                while (getchar() != '\n');
                clrscr();
                for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT + 10, 18); printf("Invalid input. Please enter a number.");
                gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
                getch();
                goto enter;
            }
            else if (QTY <= TSB[CHO - 1] && QTY > 0)
            {
                TSB[CHO - 1] -= QTY;
                ST = QTY * P[CHO - 1];
                TS[CHO - 1] += QTY;
                TSL[CHO - 1] += (QTY * P[CHO - 1]);
                T += ST;

                order_items[CTRII] = CHO - 1;
                order_qty[CTRII] = QTY;
                order_subtotal[CTRII] = ST;
                CTRII++;

                clrscr();
                for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");

                gotoxy(BOX_LEFT + 8, 13); printf("ITEM DESCRIPTION  PRICE QTY SUBTOTAL");
                for (int i = 0; i < CTRII; i++)
                {
                    gotoxy(BOX_LEFT + 11, 14 + i); printf("%d.", i + 1);
                    gotoxy(BOX_LEFT + 15, 14 + i); printf("%s", DESC[order_items[i]]);
                    gotoxy(BOX_LEFT + 28, 14 + i); printf("%d", P[order_items[i]]);
                    gotoxy(BOX_LEFT + 34, 14 + i); printf("%d", order_qty[i]);
                    gotoxy(BOX_LEFT + 40, 14 + i); printf("%d", order_subtotal[i]);
                }
                gotoxy(BOX_LEFT + 17, CTRII + 18); printf("Press any key to continue...");
                getch();

buy_another:
                clrscr();
                for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT + 12, 18); printf("Would you like to buy another item? (Y/N)");
                gotoxy(BOX_LEFT + 25, 19); scanf(" %c", &OPT1);
                if (OPT1 == 'Y' || OPT1 == 'y')
                {
                    ST = 0;
                    clrscr();
                    goto menu;
                }
                else if (OPT1 == 'N' || OPT1 == 'n')
                {
                    payment:
                    TGT += T;
                    clrscr();
                    for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                    for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                    for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                    for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                    gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                    gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                    gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                    gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                    gotoxy(BOX_LEFT + 20, 15); printf("Total: %d", T);
                    gotoxy(BOX_LEFT + 17, 16); printf("Grand Total: %d", TGT);
                    gotoxy(BOX_LEFT + 16, 18); printf("Enter your payment: ");
                    gotoxy(BOX_LEFT + 35, 18);
                    if (scanf("%d", &PAY) != 1)
                    {
                        while (getchar() != '\n');
                        clrscr();
                        for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                        for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                        for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                        for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                        gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                        gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                        gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                        gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                        gotoxy(BOX_LEFT + 10, 18); printf("Invalid payment. Try again.");
                        gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
                        getch();
                        TGT -= T;
                        goto payment;
                    }
                    else if (PAY >= T)
                    {
another_customer:
                        C = PAY - T;
                        clrscr();
                        for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                        for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                        for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                        for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                        gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                        gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                        gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                        gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                        gotoxy(BOX_LEFT + 20, 15); printf("Change: %d", C);
                        gotoxy(BOX_LEFT + 12, 16); printf("Another customer? (Y/N)");
                        gotoxy(BOX_RIGHT - 8, 16); scanf(" %c", &OPT);
                        if (OPT == 'Y' || OPT == 'y')
                        {
                            display_summary(P, TSB, DESC, SB, TSL, TS);
                            CTR++;
                            CTRII = 0;
                            GT = TGT;
                            T = 0;
                            for (int CTRS = 0; CTRS < 3; CTRS++)
                            {
                                SL[CTRS] = TSL[CTRS];
                                S[CTRS] = TS[CTRS];
                                SB[CTRS] = TSB[CTRS];
                            }
                            goto menu;
                        }
                        else if (OPT == 'N' || OPT == 'n')
                        {
                            display_summary(P, TSB, DESC, SB, TSL, TS);
                            return 0;
                        }
                        else
                        {
                            goto another_customer;
                        }
                    }
                    else
                    {
cancel:
                        clrscr();
                        for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                        for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                        for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                        for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                        gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                        gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                        gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                        gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                        gotoxy(BOX_LEFT + 7, 18); printf("Insufficient funds. Cancel order? (Y/N) ");
                        gotoxy(BOX_RIGHT - 7, 18); scanf(" %c", &OPT3);
                        if (OPT3 == 'Y' || OPT3 == 'y')
                        {
                            reset_order(TSB, SB, S, SL, TSL, TS, &T, &QTY);
                            CTRII = 0;
                            TGT = GT;
                            goto menu;
                        }
                        else if (OPT3 == 'N' || OPT3 == 'n')
                        {
                            TGT -= T;
                            goto payment;
                        }
                        else
                        {
                            clrscr();
                            goto cancel;
                        }
                    }
                }
                else
                {
                    clrscr();
                    for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                    for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                    for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                    for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                    gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                    gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                    gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                    gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                    gotoxy(BOX_LEFT + 12, 18); printf("Invalid input. Please enter Y or N.");
                    gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
                    getch();
                    goto buy_another;
                }
            }
            else
            {
                while (getchar() != '\n');
                clrscr();
                for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
                for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
                for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
                for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
                gotoxy(BOX_LEFT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
                gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
                gotoxy(BOX_LEFT + 10, 18); printf("Enter number from 1-%d only", TSB[CHO - 1]);
                gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
                getch();
                goto enter;
            }
        }
    }
    else if (CHO == 4)
    {
ex:
        clrscr();
        for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
        for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
        for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
        for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
        gotoxy(BOX_LEFT, BOX_TOP); printf("+");
        gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
        gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
        gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
        gotoxy(BOX_LEFT + 8, 18); printf("Are you sure you want to exit? (Y/N) ");
        gotoxy(BOX_RIGHT - 8, 18); scanf(" %c", &OPT);
        if ((OPT == 'Y' || OPT == 'y') && CTRII >= 1)
        {
            reset_order(TSB, SB, S, SL, TSL, TS, &T, &QTY);
            clrscr();
            for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
            for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
            for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
            for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
            gotoxy(BOX_LEFT, BOX_TOP); printf("+");
            gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
            gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
            gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
            gotoxy(BOX_LEFT + 7, 18); printf("Order Cancelled Successfully");
            gotoxy(BOX_LEFT + 17, 19); printf("Press any key to continue...");
            getch();
            return 0;
        }
        else if ((OPT == 'Y' || OPT == 'y') && CTRII < 1)
        {
            display_summary(P, TSB, DESC, SB, TSL, TS);
            return 0;
        }
        else if (OPT == 'N' || OPT == 'n')
        {
            goto menu;
        }
        else
        {
            goto ex;
        }
    }
    else
    {
        while (getchar() != '\n');
        clrscr();
        for (int c = BOX_LEFT + 1; c < BOX_RIGHT; c++) { gotoxy(c, BOX_TOP); printf("-"); }
        for (int r = BOX_TOP + 1; r < BOX_BOTTOM; r++) { gotoxy(BOX_RIGHT, r); printf("|"); }
        for (int c = BOX_RIGHT - 1; c > BOX_LEFT; c--) { gotoxy(c, BOX_BOTTOM); printf("-"); }
        for (int r = BOX_BOTTOM - 1; r > BOX_TOP; r--) { gotoxy(BOX_LEFT, r); printf("|"); }
        gotoxy(BOX_LEFT, BOX_TOP); printf("+");
        gotoxy(BOX_RIGHT, BOX_TOP); printf("+");
        gotoxy(BOX_RIGHT, BOX_BOTTOM); printf("+");
        gotoxy(BOX_LEFT, BOX_BOTTOM); printf("+");
        gotoxy(BOX_LEFT + 10, 17); printf("Invalid choice. Please select 1-4.");
        gotoxy(BOX_LEFT + 10, 18); printf("Press any key to continue...");
        getch();
        goto menu;
    }

    return 0;
}
