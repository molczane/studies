#include <stdio.h>
#include <stdlib.h>

void dodawanie(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l){

    int i = 0;
    int j=0;
    int r=0; //zmienna na przekroczenie dziesiątki

    for(i=l-1 ; i>-1 ; i--){
        if(((liczba1[m-1-j] + liczba2[n-1-j] +r)<10) && m-1-j>-1 && n-1-j>-1){
            wynik[i] = liczba1[m-1-j] + liczba2[n-1-j] + r;
            j++;
            r=0;
        }
        else if(((liczba1[m-1-j] + liczba2[n-1-j] +r)>=10) && m-1-j>-1 && n-1-j>-1){
            wynik[i] = liczba1[m-1-j] + liczba2[n-1-j] + r - 10;
            j++;
            r=1;
        }
        else if((m-1-j<0) && (n-1-j>=0) &&  ((liczba2[n-1-j] + r) < 10)){
            wynik[i] = 0 + liczba2[n-1-j] + r;
            j++;
            r=0;
        }
        else if((m-1-j<0) && (n-1-j>=0) && ((liczba2[n-1-j] + r) >= 10)){
            wynik[i] = 0 + liczba2[n-1-j] + r - 10;
            j++;
            r=1;
            wynik[0]=r;
        }
        else if((n-1-j<0) && (m-1-j>=0) && ((liczba1[m-1-j] + r) < 10)){
            wynik[i] = 0 + liczba1[m-1-j] + r;
            j++;
            r=0;
        }
        else if((n-1-j<0) && (m-1-j>=0) && ((liczba1[m-1-j] + r) >= 10)){
            wynik[i] = 0 + liczba1[m-1-j] + r - 10;
            j++;
            r=1;
            wynik[0]=r;
        }
        else if(n-1-j<0 && m-1-j<0){
            wynik[0]=r;
        }

    }//endfor

    //for(i=0 ; i<l ; i++)
    //printf("%d" , wynik[i] );


}//endfunc