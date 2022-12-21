#include <stdio.h>
#include <stdlib.h>
    
#pragma warning(disable : 4996)

#define N 16

char T[N] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

void swap(char** L1, char** L2, int* len1, int* len2);
int isBigger(char* L01, char* L02, int len1, int len2);
int addition(char* L01, char* L02, int len1, int len2, int sys, char** L03);
int subtraction(char* L01, char* L02, int len1, int len2, int sys, char** L03);
int multiplication(char* L01, char* L02, int len1, int len2, int sys, char** L03);
int division(char* L01, char* L02, int len1, int len2, int sys, char** L03);
int modulo(char* L01, char* L02, int len1, int len2, int sys, char** L03);
int power(char* L01, char* L02, int len1, int len2, int sys, char** L03);
int base_to_10(char* L01, char* Sysin1, int len1, int syslen, char** L03);
int base_from_10(char* L01, char* Sysout1, int len1, int syslen, char** L03);
int base_to_base(char* L01, char* Sysin1, char* Sysout1, int len1, int sysinlen, int sysoutlen, char** L03);

int main()
{
    char wyb = '1';
    char* L03 = NULL;
    char oper;
    char ch;
    char chpom;
    int sys = 0;
    int k = 0;
    int licznik = 1;
    char* L1 = NULL;
    char* L2 = NULL;
    char* Pom = NULL;
    int sizeplik = 1;
    char* Plikpisz = NULL;
    char* Plik = (char*)malloc(2 * sizeof(char));
    char* Jeden = (char*)malloc(2 * sizeof(char));
    char* Pomplik = NULL;
    Jeden[0] = '1';
    Plik[0] = '0';
    int len1 = 0;
    int len2 = 0;

    FILE* fpin = fopen("in.txt", "r");
    FILE* fpom = fopen("in.txt", "r");

    printf("By zapisac wyniki w jednym pliku wpisz: 1\nBy zapisac kazdy wynik w odzielnym pliku wpisz: 2\n");
    scanf("%c", &wyb);

    //zapis do odzielnych plikow
    if (wyb == '2')
    {
        FILE* fpout;
        while ((oper = fgetc(fpin)) != EOF)
        {
            //tworzenie kolejnych plikow o nazwach 1.txt, 2.txt,...,n.txt 
            sizeplik = addition(Plik, Jeden, sizeplik, 1, 10, &Pomplik);
            free(Plik);

            Plik = (char*)malloc((sizeplik + 1) * sizeof(char));
            for (int i = 0; i < sizeplik; i++) Plik[i] = Pomplik[i];

            free(Plikpisz);
            Plikpisz = (char*)malloc((sizeplik + 15) * sizeof(char));
            for (int i = 0; i < sizeplik; i++) Plikpisz[i + 9] = Pomplik[i];
            free(Pomplik);
            Plikpisz[0] = '.';
            Plikpisz[1] = '/';
            Plikpisz[2] = 'W';
            Plikpisz[3] = 'y';
            Plikpisz[4] = 'n';
            Plikpisz[5] = 'i';
            Plikpisz[6] = 'k';
            Plikpisz[7] = 'i';
            Plikpisz[8] = '/';
            Plikpisz[sizeplik + 9] = '.';
            Plikpisz[sizeplik + 10] = 't';
            Plikpisz[sizeplik + 11] = 'x';
            Plikpisz[sizeplik + 12] = 't';
            Plikpisz[sizeplik + 13] = '\0';
            fpout = fopen(Plikpisz, "w");

            if ((oper == '1') || (oper == '2') || (oper == '3') || (oper == '4') || (oper == '5') || (oper == '6') || (oper == '7') || (oper == '8') || (oper == '9'))
            {
                //operacje konwersji
                //Wpisanie danych do L1, Sysin i Sysout
                k = 0;
                while (k < 4)
                {
                    chpom = fgetc(fpom);
                    if (chpom == '\n') k++;
                    putc(chpom, fpout);
                }
                int len1 = 0;
                char* Sysin;
                char* Sysout;
                int sysinlen;
                int sysoutlen;
                if (oper == '1')
                {
                    Sysin = (char*)malloc(3 * sizeof(char));
                    Sysin[0] = '1';
                    ch = fgetc(fpin);
                    Sysin[1] = ch;
                    sysinlen = 2;
                }
                else
                {
                    Sysin = (char*)malloc(2 * sizeof(char));
                    Sysin[0] = oper;
                    sysinlen = 1;
                }
                ch = fgetc(fpin);
                ch = fgetc(fpin);

                if (ch == '1')
                {
                    Sysout = (char*)malloc(3 * sizeof(char));
                    Sysout[0] = '1';
                    ch = fgetc(fpin);
                    Sysout[1] = ch;
                    sysoutlen = 2;
                }
                else
                {
                    Sysout = (char*)malloc(2 * sizeof(char));
                    Sysout[0] = ch;
                    sysoutlen = 1;
                }
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                while ((ch = fgetc(fpin)) != '\n')
                {
                    len1++;
                    free(L1);
                    L1 = (char*)malloc((len1 + 1) * sizeof(char));
                    L1[len1 - 1] = ch;
                    for (int i = 0; i < len1 - 1; i++) L1[i] = Pom[i];
                    free(Pom);
                    Pom = (char*)malloc((len1 + 1) * sizeof(char));
                    for (int i = 0; i < len1; i++) Pom[i] = L1[i];
                }
                //operacja konwersji
                L03 = NULL;
                int size = base_to_base(L1, Sysin, Sysout, len1, sysinlen, sysoutlen, &L03);
                if (size == -2) fprintf(fpout, "Podano zle dane");
                for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                free(L03);
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                chpom = fgetc(fpom);
                fprintf(fpout, "\n");
                fprintf(fpout, "\n");
                free(Sysin);
                free(Sysout);
            }
            else
            {
              //operacje arytmetyczne
              //wpisanie danych do L1, L2 oraz uzyskanie systemu dzialania
                k = 0;
                while (k < 6)
                {
                    chpom = fgetc(fpom);
                    if (chpom == '\n') k++;
                    putc(chpom, fpout);
                }
                len1 = 0;
                len2 = 0;
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                if (ch == '1')
                {
                    ch = fgetc(fpin);
                    sys = 10 + (ch - '0');
                }
                else sys = ch - '0';
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                while ((ch = fgetc(fpin)) != '\n')
                {
                    len1++;
                    free(L1);
                    L1 = (char*)malloc((len1 + 1) * sizeof(char));
                    L1[len1 - 1] = ch;
                    for (int i = 0; i < len1 - 1; i++) L1[i] = Pom[i];
                    free(Pom);
                    Pom = (char*)malloc((len1 + 1) * sizeof(char));
                    for (int i = 0; i < len1; i++) Pom[i] = L1[i];
                }
                ch = fgetc(fpin);
                while ((ch = fgetc(fpin)) != '\n')
                {
                    len2++;
                    free(L2);
                    L2 = (char*)malloc((len2 + 1) * sizeof(char));
                    L2[len2 - 1] = ch;
                    for (int i = 0; i < len2 - 1; i++) L2[i] = Pom[i];
                    free(Pom);
                    Pom = (char*)malloc((len2 + 1) * sizeof(char));
                    for (int i = 0; i < len2; i++) Pom[i] = L2[i];
                }
                //wybor operacji
                if (oper == '/')
                {
                    L03 = NULL;
                    int size = division(L1, L2, len1, len2, sys, &L03);
                    if (size == -1) fprintf(fpout, "Dzielenie przez 0");
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)    putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '%')
                {
                    L03 = NULL;
                    int size = modulo(L1, L2, len1, len2, sys, &L03);
                    if (size == -1) fprintf(fpout, "Dzielenie przez 0");
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '+')
                {
                    L03 = NULL;
                    int size = addition(L1, L2, len1, len2, sys, &L03);
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '^')
                {
                    L03 = NULL;
                    int size = power(L1, L2, len1, len2, sys, &L03);
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '*')
                {
                    L03 = NULL;
                    int size = multiplication(L1, L2, len1, len2, sys, &L03);
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else    fprintf(fpout, "Podano zle dane");
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                chpom = fgetc(fpom);
                fprintf(fpout, "\n");
                fprintf(fpout, "\n");
            }
            printf("zostala wykonana operacja nr %d\n", licznik);
            licznik++;
        }
        free(Jeden);
        free(Plik);
        free(Plikpisz);
        free(L2);
        free(L1);
        free(Pom);
        system("PAUSE");
        return 0;
    }
    else
    {
        //wypisanie wynikow do jednego pliku
        FILE* fpout = fopen("./Wyniki/out.txt", "w");
        while ((oper = fgetc(fpin)) != EOF)
        {
            if ((oper == '1') || (oper == '2') || (oper == '3') || (oper == '4') || (oper == '5') || (oper == '6') || (oper == '7') || (oper == '8') || (oper == '9'))
            {
                //operacje konwersji
                //Wpisanie danych do L1, Sysin i Sysout
                k = 0;
                while (k < 4)
                {
                    chpom = fgetc(fpom);
                    if (chpom == '\n') k++;
                    putc(chpom, fpout);
                }
                int len1 = 0;
                char* Sysin;
                char* Sysout;
                int sysinlen;
                int sysoutlen;
                if (oper == '1')
                {
                    Sysin = (char*)malloc(3 * sizeof(char));
                    Sysin[0] = '1';
                    ch = fgetc(fpin);
                    Sysin[1] = ch;
                    sysinlen = 2;
                }
                else
                {
                    Sysin = (char*)malloc(2 * sizeof(char));
                    Sysin[0] = oper;
                    sysinlen = 1;
                }
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                if (ch == '1')
                {
                    Sysout = (char*)malloc(3 * sizeof(char));
                    Sysout[0] = '1';
                    ch = fgetc(fpin);
                    Sysout[1] = ch;
                    sysoutlen = 2;
                }
                else
                {
                    Sysout = (char*)malloc(2 * sizeof(char));
                    Sysout[0] = ch;
                    sysoutlen = 1;
                }
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                while ((ch = fgetc(fpin)) != '\n')
                {
                    len1++;
                    free(L1);
                    L1 = (char*)malloc((len1 + 1) * sizeof(char));
                    L1[len1 - 1] = ch;
                    for (int i = 0; i < len1 - 1; i++) L1[i] = Pom[i];
                    free(Pom);
                    Pom = (char*)malloc((len1 + 1) * sizeof(char));
                    for (int i = 0; i < len1; i++) Pom[i] = L1[i];
                }
                //operacja konwersji
                L03 = NULL;
                int size = base_to_base(L1, Sysin, Sysout, len1, sysinlen, sysoutlen, &L03);
                if (size == -2) fprintf(fpout, "Podano zle dane");
                for (int i = 0; i < size; i++)
                {
                    putc(L03[i], fpout);
                }
                free(L03);
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                chpom = fgetc(fpom);
                fprintf(fpout, "\n");
                fprintf(fpout, "\n");
                free(Sysin);
                free(Sysout);
            }
            else
            {
              //operacje arytmetyczne
              //wpisanie danych do L1, L2 oraz uzyskanie systemu dzialania
                k = 0;
                while (k < 6)
                {
                    chpom = fgetc(fpom);
                    if (chpom == '\n') k++;
                    putc(chpom, fpout);
                }
                len1 = 0;
                len2 = 0;
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                if (ch == '1')
                {
                    ch = fgetc(fpin);
                    sys = 10 + (ch - '0');
                }
                else sys = ch - '0';
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                while ((ch = fgetc(fpin)) != '\n')
                {
                    len1++;
                    free(L1);
                    L1 = (char*)malloc((len1 + 1) * sizeof(char));
                    L1[len1 - 1] = ch;
                    for (int i = 0; i < len1 - 1; i++) L1[i] = Pom[i];
                    free(Pom);
                    Pom = (char*)malloc((len1 + 1) * sizeof(char));
                    for (int i = 0; i < len1; i++) Pom[i] = L1[i];
                }
                ch = fgetc(fpin);
                while ((ch = fgetc(fpin)) != '\n')
                {
                    len2++;
                    free(L2);
                    L2 = (char*)malloc((len2 + 1) * sizeof(char));
                    L2[len2 - 1] = ch;
                    for (int i = 0; i < len2 - 1; i++) L2[i] = Pom[i];
                    free(Pom);
                    Pom = (char*)malloc((len2 + 1) * sizeof(char));
                    for (int i = 0; i < len2; i++) Pom[i] = L2[i];
                }

                //wybor operacji
                if (oper == '/')
                {
                    L03 = NULL;
                    int size = division(L1, L2, len1, len2, sys, &L03);
                    if (size == -1) fprintf(fpout, "Dzielenie przez 0");
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '%')
                {
                    L03 = NULL;
                    int size = modulo(L1, L2, len1, len2, sys, &L03);
                    if (size == -1) fprintf(fpout, "Dzielenie przez 0");
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '+')
                {
                    L03 = NULL;
                    int size = addition(L1, L2, len1, len2, sys, &L03);
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '^')
                {
                    L03 = NULL;
                    int size = power(L1, L2, len1, len2, sys, &L03);
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else if (oper == '*')
                {
                    L03 = NULL;
                    int size = multiplication(L1, L2, len1, len2, sys, &L03);
                    if (size == -2) fprintf(fpout, "Podano zle dane");
                    for (int i = 0; i < size; i++)  putc(L03[i], fpout);
                    free(L03);
                }
                else fprintf(fpout,"Podano zle dane");
                ch = fgetc(fpin);
                ch = fgetc(fpin);
                chpom = fgetc(fpom);
                fprintf(fpout, "\n");
                fprintf(fpout, "\n");
            }
            printf("zostala wykonana operacja nr %d\n", licznik);
            licznik++;
        }
        free(L2);
        free(L1);
        free(Pom);
        system("PAUSE");
        return 0;
    }
}
void swap(char** L1, char** L2, int* len1, int* len2)
{
    char* L3 = *L2;
    *L2 = *L1;
    *L1 = L3;
    int len3 = *len2;
    *len2 = *len1;
    *len1 = len3;
}
int isBigger(char* L01, char* L02, int len1, int len2)
{
    if (len2 > len1)  return -1; // 2 is bigger
    else if (len1 == len2)
    {
        int i = 0;
        while (L01[i] == L02[i])
        {
            i++;
            if (i == len1)    return 0; // equal
        }
        if (L02[i] > L01[i])
        {
            return -1; // 2 is bigger
        }
        else return 1;// 1 is bigger
    }
    else    return 1; // 1 is bigger
}
int addition(char* L01, char* L02, int len1, int len2, int sys, char** L03)
{
    int j1, j2, g = 0;
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L2 = (char*)malloc((len2 + 1) * sizeof(char));
    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    for (int k = 0; k < len2; k++) L2[k] = L02[k];
    if (len1 < len2)   swap(&L1, &L2, &len1, &len2);

    // appending zeros to L2 L2
    if (len1 != len2)
    {
        int lenr = len1 - len2;
        L2 = (char*)realloc(L2, (len1 + 1) * sizeof(char));
        for (int p = 1; p <= len2; p++)  L2[len2 + lenr - p] = L2[len2 - p];
        for (int m = 0; m < lenr; m++)  L2[m] = '0';
    }
    //addition
    for (int i = len1 - 1; i >= 0; i--)
    {
        j1 = 0;
        j2 = 0;
        while (T[j1] != L1[i]) j1++;
        while (T[j2] != L2[i]) j2++;
        if ((j1 >= sys) || (j2 >= sys)) return -2;
        int tmp = j1 + j2 + g;
        int res = tmp % sys;
        g = tmp / sys;
        L1[i] = T[res];
    }
    if (g > 0)
    {
        len1 = len1 + 1;
        L1 = (char*)realloc(L1, (len1 + 1) * sizeof(char));
        for (int n = len1 - 1; n >= 0; n--)    L1[n] = L1[n - 1];
        L1[0] = T[g];
    }
    // removal of excess zeros
    int count = 0;
    while (L1[count] == '0')
    {
        if (count == len1 - 1) break;
        count++;
    }
    len1 = len1 - count;
    for (int k = 0; k < len1; k++) L1[k] = L1[k + count];
    L1 = (char*)realloc(L1, (len1 + 1) * sizeof(char));
    *L03 = L1;
    free(L2);
    return len1;
}
int subtraction(char* L01, char* L02, int len1, int len2, int sys, char** L03)
{
    int j1, j2, g = 0, min = 0;
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L2 = (char*)malloc((len2 + 1) * sizeof(char));

    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    for (int k = 0; k < len2; k++) L2[k] = L02[k];

    // appending zeros to  L2
    if (len1 > len2)
    {
        int lenr = len1 - len2;
        L2 = (char*)realloc(L2, (len1 + 1) * sizeof(char));
        for (int p = 1; p <= len2; p++)  L2[len2 + lenr - p] = L2[len2 - p];
        for (int m = 0; m < lenr; m++)  L2[m] = '0';
    }
    // substraction
    for (int i = len1 - 1; i >= 0; i--)
    {
        j1 = 0;
        j2 = 0;
        while (T[j1] != L1[i]) j1++;
        while (T[j2] != L2[i]) j2++;
        if ((j1 >= sys) || (j2 >= sys)) return -2;
        if (j1 - j2 - g < 0)
        {
            L1[i] = T[sys + j1 - j2 - g];
            g = 1;
        }
        else
        {
            L1[i] = T[j1 - j2 - g];
            g = 0;
        }
    }
    // removal of excess zeros
    int licz = 0;
    while (L1[licz] == '0')
    {
        if (licz == len1 - 1) break;
        licz++;
    }
    len1 = len1 - licz;
    for (int k = 0; k < len1; k++) L1[k] = L1[k + licz];
    L1 = (char*)realloc(L1, (len1 + 1) * sizeof(char));
    *L03 = L1;
    free(L2);
    return len1;
}
int multiplication(char* L01, char* L02, int len1, int len2, int sys, char** L03)
{
    int j1, j2, g = 0, cr = 0;
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L2 = (char*)malloc((len2 + 1) * sizeof(char));
    for (int k = 0; k < len1; k++)   L1[k] = L01[k];
    for (int k = 0; k < len2; k++)   L2[k] = L02[k];
    if (isBigger(L1, L2, len1, len2) == -1) swap(&L1, &L2, &len1, &len2);

    // appending zeros to  L2
    if (len1 != len2)
    {
        int lenr = len1 - len2;
        L2 = (char*)realloc(L2, (len1 + 1) * sizeof(char));
        for (int p = 1; p <= len2; p++)  L2[len2 + lenr - p] = L2[len2 - p];
        for (int m = 0; m < lenr; m++)  L2[m] = '0';
    }
    //declaration of temp tabs
    char* L3 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L4 = (char*)malloc((len1 + 1) * sizeof(char));
    for (int k = 0; k < len1; k++)        L3[k] = '0';
    int size1 = len1;
    int size2 = len1;
    // multiplication
    for (int i = len1 - 1; i >= len1 - len2; i--)
    {
        g = 0;
        cr = 0;
        for (int k = len1 - 1; k >= 0; k--)
        {
            j1 = 0;
            j2 = 0;
            while (T[j1] != L1[k]) j1++;
            while (T[j2] != L2[i]) j2++;

            //checking if input is correct
            if ((j1 >= sys) || (j2 >= sys)) return -2;

            int temp = j1 * j2 + g;
            g = temp / sys;
            L4[k] = T[temp % sys];
        }
        size2++;
        L4 = (char*)realloc(L4, (size2 + 1) * sizeof(char));
        for (int n = size2; n >= 0; n--)    L4[n] = L4[n - 1];
        L4[0] = '0';

        if (g > 0)
        {
            L4[0] = T[g];
        }
        char* tempL2 = NULL;
        size1 = addition(L3, L4, size1, size2, sys, &tempL2);
        free(L3);
        L3 = (char*)malloc((size1 + 1) * sizeof(char));
        for (int li = 0; li < size1; li++) L3[li] = tempL2[li];
        free(tempL2);
        for (int m = 0; m < size2 - len1; m++)  L4[size2 - 1 - m] = '0';
    }
    // removing unnecessary zeros at the begging of a number 
    int licz = 0;
    while (L3[licz] == '0')
    {
        if (licz == size1 - 1) break;
        licz++;
    }
    size1 = size1 - licz;
    for (int k = 0; k < size1; k++) L3[k] = L3[k + licz];
    L3 = (char*)realloc(L3, (size1 + 1) * sizeof(char));
    *L03 = L3;
    free(L1);
    free(L2);
    free(L4);
    return size1;
}
int division(char* L01, char* L02, int len1, int len2, int sys, char** L03)
{
    int czy;
    int licz = 1;
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L2 = (char*)malloc((len2 + 1) * sizeof(char));
    int sizewyn;
    int j1;

    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    for (int k = 0; k < len2; k++) L2[k] = L02[k];

    // checking if input is correct
    for (int k = 0; k < len1; k++)
    {
        j1 = 0;
        while (T[j1] != L1[k]) j1++;
        if (j1 >= sys) return -2;
    }
    for (int k = 0; k < len2; k++)
    {
        j1 = 0;
        while (T[j1] != L2[k]) j1++;
        if (j1 >= sys) return -2;
    }
    // checkign whick number is bigger
    czy = isBigger(L1, L2, len1, len2);

    // division by 0
    int m = 0;
    while (L2[m] == '0')
    {
        m++;
        if (m >= len2)
        {
            printf("Dzielenie przez 0");
            return -1;
        }
    }
    //L1 = L2
    if (czy == 0)
    {
        char* Wynik = (char*)malloc(2 * sizeof(char));
        Wynik[0] = '1';
        *L03 = Wynik;
        sizewyn = 1;
    }
    else if (czy == -1)
    {
        char* Wynik = (char*)malloc(2 * sizeof(char));
        Wynik[0] = '0';
        *L03 = Wynik;
        sizewyn = 1;
    }
    else
    {
        // division
        int n = 0;
        int size1 = 0;
        int size2 = len2;
        char* P1 = (char*)malloc((size1 + 1) * sizeof(char));
        char* PomL2 = NULL;

        // searching for starting point
        while (n < 1)
        {
            size1++;
            P1 = (char*)realloc(P1, (size1 + 1) * sizeof(char));
            for (int i = 0; i < size1; i++) P1[i] = L1[i];

            if (isBigger(P1, L2, size1, len2) > -1) n++;
        }
        sizewyn = len1 - size1 + 1;
        int x = size1;
        int j = size1;
        char* Wynik = (char*)malloc((sizewyn + 1) * sizeof(char));

        for (int i = 0; i < sizewyn; i++)
        {
            n = 0;
            licz = 1;
            free(PomL2);
            PomL2 = (char*)malloc((len2 + 1) * sizeof(char));
            for (int j = 0; j < len2; j++) PomL2[j] = L2[j];
            size2 = len2;
            while (n < 1)
            {
                if (isBigger(P1, L2, size1, len2) == 0)
                {
                    free(P1);
                    P1 = (char*)malloc(2 * sizeof(char));
                    P1[0] = L1[i + j];
                    Wynik[i] = T[licz];
                    size1 = 1;
                    n++;
                }
                else if (isBigger(P1, L2, size1, len2) > 0)
                {
                    if (isBigger(P1, PomL2, size1, size2) > 0)
                    {
                        licz++;
                        char* Pom2 = NULL;
                        size2 = addition(PomL2, L2, size2, len2, sys, &Pom2);
                        free(PomL2);
                        PomL2 = (char*)malloc((size2 + 1) * sizeof(char));
                        for (int j = 0; j < size2; j++) PomL2[j] = Pom2[j];
                        free(Pom2);
                    }
                    else if (isBigger(P1, PomL2, size1, size2) == 0)
                    {
                        free(P1);
                        P1 = (char*)malloc(2 * sizeof(char));
                        P1[0] = L1[i + x];
                        Wynik[i] = T[licz];
                        n++;
                        size1 = 1;
                    }
                    else if (isBigger(P1, PomL2, size1, size2) < 0)
                    {
                        Wynik[i] = T[licz - 1];
                        char* Pom2 = NULL;
                        size2 = subtraction(PomL2, L2, size2, len2, sys, &Pom2);
                        free(PomL2);
                        PomL2 = (char*)malloc((size2 + 1) * sizeof(char));
                        for (int j = 0; j < size2; j++) PomL2[j] = Pom2[j];
                        free(Pom2);
                        Pom2 = NULL;
                        size1 = subtraction(P1, PomL2, size1, size2, sys, &Pom2) + 1;
                        free(P1);
                        P1 = (char*)malloc((size1 + 1) * sizeof(char));
                        for (int m = 0; m < size1 - 1; m++) P1[m] = Pom2[m];
                        free(Pom2);
                        P1[size1 - 1] = L1[i + x];
                        n++;
                    }
                }
                else if (isBigger(P1, L2, size1, len2) < 0)
                {
                    if (P1[0] == '0') size1--;
                    size1++;
                    P1 = (char*)realloc(P1, (size1 + 1) * sizeof(char));
                    P1[size1 - 1] = L1[i + x];
                    Wynik[i] = '0';
                    n++;
                }
            }
        }
        free(PomL2);
        free(P1);
        *L03 = Wynik;
    }
    free(L1);
    free(L2);
    return sizewyn;
}
int modulo(char* L01, char* L02, int len1, int len2, int sys, char** L03)
{
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L2 = (char*)malloc((len2 + 1) * sizeof(char));
    int sizewyn;
    int j1 = 0;
    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    for (int k = 0; k < len2; k++) L2[k] = L02[k];

    //checking if input is correct
    for (int k = 0; k < len1; k++)
    {
        j1 = 0;
        while (T[j1] != L1[k]) j1++;
        if (j1 >= sys) return -2;
    }
    for (int k = 0; k < len2; k++)
    {
        j1 = 0;
        while (T[j1] != L2[k]) j1++;
        if (j1 >= sys) return -2;
    }
    // div by  0
    int m = 0;
    while (L2[m] == '0')
    {
        m++;
        if (m >= len2)
        {
            printf("Dzielenie przez 0");
            return -1;
        }
    }
    if (isBigger(L1, L2, len1, len2) == 0)
    {
        // L1 == L2
        char* Wynik = (char*)malloc(2 * sizeof(char));
        Wynik[0] = '0';
        *L03 = Wynik;
        free(L1);
        free(L2);
        return 1;
    }
    else if (isBigger(L1, L2, len1, len2) == -1)
    {
        // L2 > L1
        sizewyn = len1;
        *L03 = L1;
        free(L2);
        return sizewyn;
    }
    else
    {
        // L1 < L2
        char* Pom = NULL;
        char* Temp = NULL;
        sizewyn = division(L1, L2, len1, len2, sys, &Pom);
        Temp = (char*)malloc((sizewyn + 1) * sizeof(char));
        for (int j = 0; j < sizewyn; j++) Temp[j] = Pom[j];
        free(Pom);
        Pom = NULL;
        sizewyn = multiplication(Temp, L2, sizewyn, len2, sys, &Pom);
        free(Temp);
        Temp = (char*)malloc((sizewyn + 1) * sizeof(char));
        for (int j = 0; j < sizewyn; j++) Temp[j] = Pom[j];
        free(Pom);
        Pom = NULL;
        sizewyn = subtraction(L1, Temp, len1, sizewyn, sys, &Pom);
        free(Temp);
        *L03 = Pom;
        free(L1);
        free(L2);
        return sizewyn;
    }
}
int power(char* L01, char* L02, int len1, int len2, int sys, char** L03)
{
    int size = 1;
    int j1 = 0;
    int sizewyn = len1;
    char* Wynik;
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    char* L2 = (char*)malloc((len2 + 1) * sizeof(char));

    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    for (int k = 0; k < len2; k++) L2[k] = L02[k];
    // checking if input is correct

    for (int k = 0; k < len1; k++)
    {
        j1 = 0;
        while (T[j1] != L1[k]) j1++;
        if (j1 >= sys) return -2;
    }
    for (int k = 0; k < len2; k++)
    {
        j1 = 0;
        while (T[j1] != L2[k]) j1++;
        if (j1 >= sys) return -2;
    }
    Wynik = (char*)malloc((len1 + 1) * sizeof(char));
    for (int j = 0; j < len1; j++) Wynik[j] = L1[j];

    char* P = (char*)malloc((size + 1) * sizeof(char));
    char* D = (char*)malloc((size + 1) * sizeof(char));
    // P always ewuals "1"
    // D temp tab counting how many times the power operation has been made
    P[0] = '1';
    D[0] = '1';

    int m = 0;
    while (L2[m] == '0')
    {
        if (m >= len2)
        {
            char* Wynik = (char*)malloc(2 * sizeof(char));
            Wynik[0] = '1';
            *L03 = Wynik;
            return 1;
        }
        m++;
    }
    while (isBigger(D, L2, size, len2) != 0)
    {
        char* Temp1;
        char* Temp2;
        size = addition(D, P, size, 1, sys, &Temp1);
        free(D);
        D = (char*)malloc((size + 1) * sizeof(char));
        for (int j = 0; j < size; j++) D[j] = Temp1[j];
        free(Temp1);

        sizewyn = multiplication(Wynik, L1, sizewyn, len1, sys, &Temp2);
        free(Wynik);
        Wynik = (char*)malloc((sizewyn + 1) * sizeof(char));
        for (int j = 0; j < sizewyn; j++) Wynik[j] = Temp2[j];
        free(Temp2);
    }
    *L03 = Wynik;
    free(L1);
    free(L2);
    free(P);
    free(D);
    return sizewyn;
}
int base_to_10(char* L01, char* Sysin1, int len1, int syslen, char** L03)
{
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    char* Sysin = (char*)malloc((syslen + 1) * sizeof(char));
    for (int p = 0; p < syslen; p++)    Sysin[p] = Sysin1[p];
    int sys;
    if (syslen > 1)
    {
        sys = 10 + Sysin[1] - '0';
    }
    char* Wynik = (char*)malloc(2 * sizeof(char));
    Wynik[0] = '0';
    char* Ilocz = (char*)malloc(2 * sizeof(char));
    Ilocz[0] = '1';
    char* Indeks = (char*)malloc(2 * sizeof(char));
    char* Pom = NULL;
    char* Pomwyn = NULL;
    char* Temp = NULL;
    int size1 = 1;
    int sizeilocz = 1;
    int sizewyn = 1;
    int sizeindeks;
    int j = 0;;
    for (int i = 0; i < len1; i++)
    {
        //przepisanie danego znaku do tab indeks w systemie 10
        j = 0;
        while (T[j] != L1[len1 - 1 - i]) j++;
        if (j > 9)
        {
            sizeindeks = 2;
            free(Indeks);
            Indeks = (char*)malloc((sizeindeks + 1) * sizeof(char));
            Indeks[0] = '1';
            Indeks[1] = T[j - 10];
        }
        else
        {
            sizeindeks = 1;
            free(Indeks);
            Indeks = (char*)malloc((sizeindeks + 1) * sizeof(char));
            Indeks[0] = T[j];
        }
        //dodanie do Wyniku kolejnej uzyskanej wartosci
        if (Indeks[0] != '0')
        {
            Pom = NULL;
            size1 = multiplication(Ilocz, Indeks, sizeilocz, sizeindeks, 10, &Pom);
            Pomwyn = NULL;
            sizewyn = addition(Pom, Wynik, size1, sizewyn, 10, &Pomwyn);
            free(Pom);
            free(Wynik);
            Wynik = (char*)malloc((sizewyn + 1) * sizeof(char));
            for (int i = 0; i < sizewyn; i++) Wynik[i] = Pomwyn[i];
            free(Pomwyn);
        }
        //Ilocz przyjmuje wartosc kolejnych poteg liczby podanej jako system
        Temp = NULL;
        sizeilocz = multiplication(Ilocz, Sysin, sizeilocz, syslen, 10, &Temp);
        free(Ilocz);
        Ilocz = (char*)malloc((sizeilocz + 1) * sizeof(char));
        for (int i = 0; i < sizeilocz; i++) Ilocz[i] = Temp[i];
        free(Temp);
        printf("\n%d\n", i);
    }
    *L03 = Wynik;
    free(L1);
    free(Ilocz);
    free(Indeks);
    free(Sysin);
    return sizewyn;
}
int base_from_10(char* L01, char* Sysout1, int len1, int syslen, char** L03)
{
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    char* Sysout = (char*)malloc((syslen + 1) * sizeof(char));
    for (int p = 0; p < syslen; p++)    Sysout[p] = Sysout1[p];
    int dzielnik;
    //ustalenie maksymalnej dlugosci wyniku z zapasem
    int sizewyn = (5 * len1) + 1;
    char* Wynik = (char*)malloc((sizewyn + 1) * sizeof(char));
    for (int l = 0; l < sizewyn; l++) Wynik[l] = '0';
    char* Pom = malloc((len1 + 1) * sizeof(char));
    for (int i = 0; i < len1; i++) Pom[i] = L1[i];
    int sizepom = len1;
    int roznica = sizepom;
    int podstawa;
    char* Temp2;
    char* Temp3;
    int i = 0;
    while ((sizepom != 1) || (Pom[0] != '0'))
    {
        i++;
        podstawa = sizepom;
        Temp3 = NULL;
        Temp2 = NULL;
        roznica = modulo(Pom, Sysout, sizepom, syslen, 10, &Temp3);
        sizepom = division(Pom, Sysout, sizepom, syslen, 10, &Temp2);

        free(Pom);
        Pom = (char*)malloc((sizepom + 1) * sizeof(char));
        for (int j = 0; j < sizepom; j++) Pom[j] = Temp2[j];
        if (roznica > 1) dzielnik = (10 * (Temp3[0] - '0') + (Temp3[1] - '0'));
        else if (roznica == 0) dzielnik = 0;
        else   dzielnik = (Temp3[0] - '0');
        Wynik[sizewyn - i] = T[dzielnik];
        printf("%d\n", sizepom);
        free(Temp3);
        free(Temp2);
    }
    free(Pom);
    int licz = 0;

    //usuniecie nadmiarowych zer
    while (Wynik[licz] == '0')
    {
        if (licz == sizewyn - 1) break;
        licz++;
    }
    sizewyn = sizewyn - licz;
    char* TempL5 = (char*)malloc(sizewyn + 1 * sizeof(char));

    for (int k = 0; k < sizewyn; k++) TempL5[k] = Wynik[k + licz];

    *L03 = TempL5;
    free(Sysout);
    free(L1);
    free(Wynik);
    return sizewyn;
}
int base_to_base(char* L01, char* Sysin1, char* Sysout1, int len1, int sysinlen, int sysoutlen, char** L03)
{
    char* L1 = (char*)malloc((len1 + 1) * sizeof(char));
    for (int k = 0; k < len1; k++) L1[k] = L01[k];
    char* Sysin = (char*)malloc((sysinlen + 1) * sizeof(char));
    for (int k = 0; k < sysinlen; k++)    Sysin[k] = Sysin1[k];
    char* Sysout = (char*)malloc((sysoutlen + 1) * sizeof(char));
    for (int k = 0; k < sysoutlen; k++)    Sysout[k] = Sysout1[k];

    char* Pom = NULL;
    char* Wynik = NULL;
    int sizewyn = 1;
    int sys,sysout;
    int j1;
    //sprawdzenie czy dane poprawne:
    if (sysinlen > 1)
    {       
        sys = 10 + Sysin[1] - '0';
    }
    else sys = Sysin[0] - '0';
    if (sys < 2 || sys>16) return -2;
    if (sysoutlen > 1)
    {
        sysout = 10 + Sysout[1] - '0';
    }
    else sysout = Sysout[0] - '0';
    if (sysout < 2 || sysout>16) return -2;

    for (int k = 0; k < len1; k++)
    {
        j1 = 0;
        while (T[j1] != L1[k]) j1++;
        if (j1 >= sys) return -2;
    }
    if (isBigger(Sysin, Sysout, sysinlen, sysoutlen) == 0)
    {
        //systemy identyczne - konwersja nie jest potrzebna
        free(Pom);
        free(Wynik);
        free(Sysin);
        free(Sysout);
        *L03 = L1;
        return len1;
    }
    sizewyn = base_to_10(L1, Sysin, len1, sysinlen, &Pom);
    sizewyn = base_from_10(Pom, Sysout, sizewyn, sysoutlen, &Wynik);
    *L03 = Wynik;
    free(Pom);
    free(L1);
    free(Sysin);
    free(Sysout);
    return sizewyn;
}