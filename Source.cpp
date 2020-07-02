#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define N 5
#pragma warning(disable : 4996)

void keyboard(int a[N][N])
{
    int i, j;
    printf("Введите элементы матрицы А: \n\n");
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
}

void file(int a[N][N]) {

    int i, j;

    FILE* fp;
    fp = fopen("C:/C/in2.txt", "r");

    if (fp) {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                fscanf_s(fp, "%d", &a[i][j]);
        printf("Матрица из файла:\n\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%3d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        fclose(fp);
    }
    else
        printf("Файл отсутствует!\n");

}

int* mas_x(int(*a)[N], int* x, void (*pfunc)(int[N][N])) {

    pfunc(a);
    int i,k, count = 0;

    for (i = 0; i < N; i++){
      int  j = 0;
      int  d = 0;
        while( j < N ) {

            if (a[i][j] > 0) {
                count = 0;
                for (k = 0; k < N; k++) {
                    count += a[k][j];
                }
                x[i] = count;
                j = N;
                d = 1;
            }
            else j++;
           
            if (j == N  and d == 0)  x[i] = 0; 
            
        }
    }

    return x;
}

void wfile(int x[]) {
    FILE* fp;
    int i;

    fp = fopen("C:/C/out2.txt", "w");
    for (i = 0; i < N; i++) {
        fprintf(fp, "%3d", x[i]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int rec_otr(int x[], int max, int i) {

    if (x[i] >= max)  
    {
        max = x[i];

        return 0;
    }
    else {

        if (x[i] < 0)
            return rec_otr(x, max, i + 1) + 1;
        else
            return rec_otr(x, max, i + 1);
    }
}

void output(const int x[], const int a[][N])
{
    int i, j;
    printf("Матрица А:\n\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%5d", a[i][j]);

        printf("\n");
    }
    printf("\n");
    printf("Массив Х:\n\n");
    for (i = 0; i < N; i++)
        printf("%5d", x[i]);
    printf("\n");
}

int main()
{
    setlocale(LC_CTYPE, "");
    int a[N][N], x[N], swp;
    int n = N;
    int max = 0;
    int i,f = 0;


    void (*pfunc)(int[N][N]);
    do
    {
        printf("Ввод матрицы:\n\n1 - с клавиатуры\n2 - из файла\n\n");
        scanf("%d", &swp); printf("\n");
    } while (swp != 1 && swp != 2);

    switch (swp)
    {
    case 1: pfunc = &keyboard;
        output(mas_x(a, x, pfunc), a);
        break;
    case 2: pfunc = &file;
        output(mas_x(a, x, pfunc), a);
    }
    wfile(x);

    for (i = 0; i < N; i++) {
    if (f = 0) {
        f = 1;
        max = x[i];
    }
    else {
        if (x[i] > max)
            max = x[i];
    }
}
    printf("\n"); 
    printf("Y = %d", rec_otr(x, max, 0));
    ptintf("wow!");

    _getch();
}