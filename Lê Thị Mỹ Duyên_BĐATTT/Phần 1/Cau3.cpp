//Bai 3 - Doc input1_1.txt
//      - Ma tran ke        
//      - danh sach canh    ==> output1_1.txt                         
//      - Bac cua dinh      
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int matran[6][6];
void init(int a[6][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            a[i][j] = 0;
        }
    }
}

void canh(int a[6][6], int i, int j)
{
    a[i][j] = 1;
    a[j][i] = 1;
}

void matrix(int a[6][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void ReadFile()
{
     FILE *fp;
    char arr[300];
    int row, col, i, j, dem, a, b;
    fp = fopen("input1_1.txt", "r");
    row = 6;
    col = 6;
    fgets(arr, 300, fp);
    cout<<arr<<endl;
    system("cls");
    cout<<"Ma tran ke cua do thi vo huong: "<<endl;
    init(matran);
    for (i = 0; i < row; i++)
    {
        fscanf(fp,"%d | ",&a);
        for (j = 0; j < 4; j++)
        {      
            fscanf(fp,"%d ",&b);
            canh(matran, a-1, b-1);
        }
        fscanf(fp,"\n");
    }
    matrix(matran);
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
    cout<<"So bac cua dinh: "<<endl;
    for(i=0;i<row;i++){
        dem=0;
        for(j=0;j<col;j++){
            if(matran[i][j]==1){
                dem++;
            }
        }
        printf("DEG(%d) = %d\n",i+1,dem);
    }
    fclose(fp);
}

void WriteToFile()
{
    FILE *fp;
    char arr[300];
    int row, col, i, j, dem;
    fp = fopen("output1_1.txt", "w");                        
    row = 6;
    col = 6;
    fprintf(fp,"Ma tran ke cua do thi vo huong:\n"); 
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fprintf(fp,"%d ",matran[i][j]);
        }
        fprintf(fp,"\n");
    }
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
    fprintf(fp,"So bac cua dinh:\n");
    for(i=0;i<row;i++){
        dem=0;
        for(j=0;j<col;j++){
            if(matran[i][j]==1){
                dem++;
            }
        }
        fprintf(fp,"DEG(%d) = %d\n",i+1,dem);
    }
    fclose(fp);
}

int main(){
    ReadFile();
    WriteToFile();
}
