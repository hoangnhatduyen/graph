//Bai 2 - Doc input1.txt
//      - danh sach ke => input1_1.txt
//      - danh sach canh => input1_2.txt

#include <stdio.h>
#include <iostream>
using namespace std;
void ReadFile()                                   
{
    FILE* fp;
    int row, col, i, j;
    int matran[6][6];
    fp = fopen("input1.txt", "r");
    row = 6;
    col = 6;
    cout<<"Danh sach ke cua do thi vo huong: "<<endl;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(fp, "%d ", &matran[i][j]);
        }
        fscanf(fp,"\n");
    }
    for (i = 0; i < row; i++)
    {
        printf("%d | ",(i+1));
        for (j = 0; j < col; j++)
        {
            if(matran[i][j]==1){   
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
    cout<<"Danh sach canh cua do thi vo huong: "<<endl;
    for (i = 0; i < row; i++)
    {
        for (j = i; j < col; j++)
        {
            if (matran[i][j] == 1)
            {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }
    fclose(fp);
}

void WriteToFile1()
{
    FILE *fp;
    int row, col, i, j;
    int matran[6][6];
    fp = fopen("input1_1.txt", "w");                        
    row = 6;
    col = 6;
    fprintf(fp, "Danh sach ke cua do thi vo huong: \n");
    for (i = 0; i < row; i++)
    {
        fprintf(fp,"%d | ",(i+1));
        for (j = 0; j < col; j++)
        {
            if(matran[i][j]==1){   
                fprintf(fp,"%d ",j+1);
            }
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
void WriteToFile2()
{    
    FILE *fp;
    int row, col, i, j;
    int matran[6][6];
    fp = fopen("input1_2.txt", "w");                                
    fprintf(fp,"Danh sach canh cua do thi vo huong:\n");
    for (i = 0; i < row; i++)
    {
        for (j = i; j < col; j++)
        {
            if (matran[i][j] == 1)
            {
                fprintf(fp,"%d %d\n", i + 1, j + 1);
            }
        }
    }
    fclose(fp);
}

int main()
{
    ReadFile();
    WriteToFile1();
    WriteToFile2();
}
