#include <stdio.h>
#include <stdlib.h>

int porownywanie();
void odejmowanie();
void mnozenie();

void potegowanie(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l){

    int i = 0;
    int jeden[n];
    int zero[n];
    int e = 0;
    int wynik_p[n];
    int liczba2_h[n];
    int wynik_h[l];
    int liczba1_h[l];

    for(i=0;i<n;i++)
        wynik_p[i]=0;
    for(i=0;i<n;i++)
        zero[i]=0;
    for(i=0;i<n-1;i++)
        jeden[i]=0;
    jeden[n-1]=1;
    e = porownywanie(liczba2,zero,wynik_p,n,n,n);
    for(i=0;i<n;i++)
        wynik_p[i]=0;
    for(i=0;i<n;i++)
        liczba2_h[i]=0;
    for(i=0;i<l;i++)
        liczba1_h[i]=0;
    for(i=0;i<m;i++)
        liczba1_h[l-1-i]=liczba1[m-1-i];
    //printf("\nliczba1_h: ");
    //for (i = 0; i < l ; ++i)
        //printf("%d" , liczba1_h[i]);
    for(i=0;i<l;i++)
        wynik_h[i]=0;

    //mnozenie(liczba1_h,liczba1,wynik_h,l,m,l);
    //printf("\nwynik mnożenia: ");
    //for(i=0;i<l;i++)
        //printf("%d", wynik_h[i]);

    odejmowanie(liczba2,jeden,liczba2_h,n,n,n,0);
    for(i=0;i<n;i++)
        liczba2[i]=liczba2_h[i];
    for(i=0;i<n;i++)
        liczba2_h[i]=0; //zmiejszamy o jeden zeby mnozylo odpowienia ilosc razy//

    for(;;){

        mnozenie(liczba1_h,liczba1,wynik_h,l,m,l);
        //printf("\nwynik mnożenia: ");
        //for(i=0;i<l;i++)
            //printf("%d", wynik_h[i]);
        odejmowanie(liczba2,jeden,liczba2_h,n,n,n,0);
        for(i=0;i<l;i++)
            liczba1_h[i]=wynik_h[i];
        //printf("\nliczba1_h to: ");
        //for(i=0;i<l;i++)
            //printf("%d", liczba1_h[i]);
        for(i=0;i<n;i++)
            liczba2[i]=liczba2_h[i];
        for(i=0;i<n;i++)
            liczba2_h[i]=0;
        e = porownywanie(liczba2,zero,wynik_p,n,n,n);
        if(e==2){
            for(i=0;i<l;i++)
                wynik[i]=wynik_h[i];
            break;
        }//endif
        for(i=0;i<n;i++)
            wynik_p[i]=0;
        for(i=0;i<l;i++)
            wynik_h[i]=0;

    }//endfor

    for(i=0;i<l;i++)
        wynik[i]=wynik_h[i];

}
