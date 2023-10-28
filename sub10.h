#include <stdio.h>
#include <stdlib.h>


void odejmowanie(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l, int c){

    int i=0;

    //printf("\n\n%d\n\n" , c);

    for(i=0;i<l;i++){
        if(c==0 || c==2){
            if( m-i-1<0 && n-i-1<0 )
                break;
            else if(n-i-1<0){
                if(liczba1[m-i-1]==-1){
                    liczba1[m-i-1]=9;
                    liczba1[m-i-2]=liczba1[m-i-2]-1;
                }//endif
                wynik[l-i-1]=liczba1[m-i-1];
            }//endelif
            else if( liczba1[m-i-1] >= liczba2[n-i-1])
                wynik[l-i-1] = liczba1[m-i-1] - liczba2[n-i-1];
            else if(liczba1[m-1-i] < liczba2[n-i-1]){
                wynik[l-i-1] = liczba1[m-i-1] + 10 - liczba2[n-i-1];
                liczba1[m-i-2]=liczba1[m-i-2]-1;
            }//endelif
        }//endif
        else if(c==1){
            if( m-i-1<0 && n-i-1<0 )
                break;
            else if(m-i-1<0){
                if(liczba2[n-i-1]==-1){
                    liczba2[n-i-1]=9;
                    liczba2[n-i-2]=liczba2[n-i-2]-1;
                }//endif
                wynik[l-i-1]=liczba2[n-i-1];
            }//endelif
            else if( liczba2[n-i-1] >= liczba1[m-i-1])
                wynik[l-i-1] = liczba2[n-i-1] - liczba1[m-i-1];
            else if(liczba2[n-1-i] < liczba1[m-i-1]){
                wynik[l-i-1] = liczba2[n-i-1] + 10 - liczba1[m-i-1];
                liczba2[n-i-2]=liczba2[n-i-2]-1;
            }//endelif
        }//endelif
    }//endfor
}//endfunc