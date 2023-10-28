#include <stdio.h>
#include <stdlib.h>

void mnozenie(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l){

    int i=0;
    int j=0;
    int r=0;
    int p=0;

    for(j=0;j<n;j++){
        for(i=0 ; i<=l-1-j ; i++){
            if(m-1-i>=0){
                p=wynik[l-1-i-j];
                wynik[l-1-i-j] = (liczba1[m-1-i]*liczba2[n-1-j]+r+wynik[l-1-i-j])%10;
                r=((liczba1[m-1-i]*liczba2[n-1-j]+r+p)-((liczba1[m-1-i]*liczba2[n-1-j]+r+p)%10))/10;
            }//endif
            else if(m-1-i<0){
                wynik[l-1-i-j] = + r;
                r=0;
            }//endelif
        }//endfor
    }//endfor  //mnożenie które działa.........


}//endfunc
