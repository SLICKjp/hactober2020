#include <stdio.h>

void main()
{
    int r1, c1, r2, c2, s = 0;
    int ar[10][10], arr[10][10], multi[10][10];

    printf("Enter number of rows and columns of first matrix\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter elements of first matrix\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &ar[i][j]);

    printf("Enter number of rows and columns of second matrix\n");
    scanf("%d%d", &r2, &c2);

    if (c1 == r2)
    {
        printf("Enter elements of second matrix\n");
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                scanf("%d", &arr[i][j]);

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                {
                    s = s + ar[i][k] * arr[k][j];
                }
                multi[i][j] = s;
                s = 0;
            }
        }

        printf("Product of the matrices are :\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
                printf("%d\t", multi[i][j]);
            printf("\n");
        }
    }
    else
        printf("Product of matrix not possible !");
}
