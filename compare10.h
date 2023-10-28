#include <stdio.h>
#include <stdlib.h>

int porownywanie(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l){

    int i = 0;

    if(m>n){
        return 0;
    }//endelif
    else if(m<n){
        return 1;
    }//endelif
    else if(m==n){

        for(i=0;i<l;i++){
            wynik[i]=liczba1[i]-liczba2[i];
        }//endfor

        for(i=0;i<l;i++){
            if(wynik[i]!=0)
                break;
            else if(wynik[i]==0){
                if(i==l-1)
                    return 2;
                else
                    continue;
            }//endelif
        }//endfor

        for(i=0;i<l;i++){
            if(wynik[i]==0)
                continue;
            else if(wynik[i]>0)
                return 0;
            else if(wynik[i]<0)
                return 1;
        }


    }//endelif

}//endfunc