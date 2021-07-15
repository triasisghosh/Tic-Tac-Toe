#include <stdio.h>
char mat[3][3];
void printmat();
void input(char p);
int check(char p);
int main()
{
    char pn1[10], pn2[10], p1, p2;
    int draw = 1;
game:
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat[i][j] = ' ';
    puts("\n!!! WELCOME TO TIC-TAC-TOE GAME !!!");
    printf("\nPlayer 1 please enter your name: ");
    fflush(stdin);
    gets(pn1);
    printf("\nPlayer 2 please enter your name: ");
    fflush(stdin);
    gets(pn2);
    printf("\n%s choose your symbol: ", pn1);
    fflush(stdin);
    p1 = getchar();
    printf("\n%s choose your symbol: ", pn2);
    fflush(stdin);
    p2 = getchar();
    puts("\nHere is your board.");
    printmat(mat);
    puts("\nPositions:");
    printf("\n1,1 | 1,2 | 1,3\n -     -     -\n2,1 | 2,2 | 2,3\n -     -     -\n3,1 | 3,2 | 3,3\n");
    for (int i = 1; i <= 9; i++)
        if (i % 2 != 0)
        {
            printf("\n%s,your turn.", pn1);
            input(p1);
            printmat();
            if (check(p1) == 1)
            {
                printf("\nCongratulations %s,You won!!!\n", pn1);
                draw = 0;
                break;
            }
        }

        else
        {
            printf("\n%s,your turn.", pn2);
            input(p2);
            printmat();
            if (check(p2) == 1)
            {
                printf("\nCongratulations %s,You won!!!\n", pn2);
                draw = 0;
                break;
            }
        }
    if (draw == 1)
        puts("\nIt's a draw.");
    printf("\nWant to play again?(y/n): ");
    fflush(stdin);
    char check = getchar();
    if (check == 'y' || check == 'Y')
        goto game;
    else
        return 0;
}

void printmat()
{
    int k = 0;
    printf("\n");
    for (int i = 1; i <= 5; i++)
    {
        if (i % 2 == 0)
        {
            printf("- - -");
            k++;
        }
        else
            for (int j = 1; j <= 3; j++)
            {
                printf("%c", mat[i - k - 1][j - 1]);
                if (j == 1 || j == 2)
                    printf("|");
            }
        printf("\n");
    }
}

void input(char p)
{
    int r, c;
enter:
    printf("Enter the row and column position: ");
    scanf("%d%*c%d", &r, &c);
    if (mat[r - 1][c - 1] == ' ')
        mat[r - 1][c - 1] = p;
    else
    {
        printf("postion already full or invalid!!!\n");
        goto enter;
    }
}

int check(char p)
{
    if (mat[1][1] == p)
    {
        if (mat[0][0] == p && mat[2][2] == p)
            return 1;
        else if (mat[0][2] == p && mat[2][0] == p)
            return 1;
        else if (mat[0][1] == p && mat[2][1] == p)
            return 1;
        else if (mat[1][0] == p && mat[1][2] == p)
            return 1;
    }
    else if (mat[0][0] == p)
    {
        if (mat[0][1] == p && mat[0][2] == p)
            return 1;
        else if (mat[1][0] == p && mat[2][0] == p)
            return 1;
    }
    else if (mat[2][2] == p)
    {
        if (mat[1][2] == p && mat[0][2] == p)
            return 1;
        else if (mat[2][0] == p && mat[2][1] == p)
            return 1;
    }
}