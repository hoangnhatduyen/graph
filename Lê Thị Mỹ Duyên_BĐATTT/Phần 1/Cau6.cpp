// Bai 6 - Doc input2_1.txt
//       - Ma tran ke          
//       - Danh sach canh      ==> output2_1.txt                     
//       - Bac cua dinh        
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int matran[5][5];
void init(int a[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = 0;
        }
    }
}

void canh(int a[5][5], int i, int j)
{
    a[i][j] = 1;
}

void matrix(int a[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void ReadFile()
{
    FILE *fp;
    char arr[300];
    int row, col, i, j, a, b, dem;
    fp = fopen("input2_1.txt", "r");
    row = 5;
    col = 5;
    fgets(arr, 300, fp);
    cout << arr << endl;
    system("cls");
    cout << "Ma tran ke cua do thi co huong: " << endl;
    init(matran);
    for (i = 0; i < row; i++)
    {
        fscanf(fp, "%d | ", &a);
        if (i == 0)
        {
            for (j = 0; j < 3; j++)
            {
                fscanf(fp, "%d ", &b);
                canh(matran, a - 1, b - 1);
            }
        }
        if (i == 1 || i == 2)
        {
            for (j = 0; j < 1; j++)
            {
                fscanf(fp, "%d ", &b);
                canh(matran, a - 1, b - 1);
            }
        }
        if (i == 3 || i == 4)
        {
            for (j = 0; j < 2; j++)
            {
                fscanf(fp, "%d ", &b);
                canh(matran, a - 1, b - 1);
            }
        }
        fscanf(fp, "\n");
    }
    matrix(matran);
    cout << "Danh sach canh cua do thi co huong: " << endl;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (matran[i][j] == 1)
            {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }
    cout << "So bac cua dinh: " << endl;
    printf("\n====> Ban bac ra cua dinh: \n");
    for (i = 0; i < row; i++)
    {
        dem = 0;
        for (j = 0; j < col; j++)
        {
            if (matran[i][j] == 1)
            {
                dem++;
            }
        }

        printf("DEG + (%d) = %d\n", i + 1, dem);
    }
    printf("\n====> Ban bac vao cua dinh: \n");                    
    for (i = 0; i < row; i++)
    {
        dem = 0;
        for (j = 0; j < col; j++)
        {
            if (matran[j][i] == 1)
            {
                dem++;
            }
        }

        printf("DEG - (%d) = %d\n", i + 1, dem);
    }
    fclose(fp);
}

void WriteToFile()
{
    FILE *fp;
    char arr[300];
    int row, col, i, j, dem, a, b;
    fp = fopen("output2_1.txt", "w");
    row = 5;
    col = 5;
    fprintf(fp, "Ma tran ke cua do thi co huong:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf(fp, "%d ", matran[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "Danh sach canh cua do thi co huong:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (matran[i][j] == 1)
            {
                fprintf(fp, "%d %d\n", i + 1, j + 1);
            }
        }
    }
    fprintf(fp, " So bac cua dinh:\n");
    fprintf(fp, "\n====> Ban bac ra cua dinh: \n");
    for (i = 0; i < row; i++)
    {
        dem = 0;
        for (j = 0; j < col; j++)
        {
            if (matran[i][j] == 1)
            {
                dem++;
            }
        }

        fprintf(fp, "DEG + (%d) = %d\n", i + 1, dem);
    }
    fprintf(fp, "\n====> Ban bac vao cua dinh: \n");
    for (i = 0; i < row; i++)
    {
        dem = 0;
        for (j = 0; j < col; j++)
        {
            if (matran[j][i] == 1)
            {
                dem++;
            }
        }
        fprintf(fp, "DEG - (%d) = %d\n", i + 1, dem);
    }
    fclose(fp);
}

int main()
{
    ReadFile();
    WriteToFile();
}
