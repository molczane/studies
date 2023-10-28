//
// Created by Ernest  on 13/11/2022.
//

#ifndef UNTITLED_DIVIDE10V2_H
#define UNTITLED_DIVIDE10V2_H

#endif //UNTITLED_DIVIDE10V2_H

#include <stdio.h>
#include <stdlib.h>

void odejmowanie();
int porownywanie();
void mnozenie();

void dzieleniev2(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l){

    int i=0;
    int j=0;
    int k=0;
    int t=0;
    int q=0;
    int d=0;
    int e=0;
    int r[1];
    r[0]=1;

    int liczba1_1[m+1];
    for(i=0;i<m+1;i++)
        liczba1_1[i]=0;
    for(i=1;i<m+1;i++)
        liczba1_1[i]=liczba1[i-1];
    /*printf("\n\nLICZBA1_1 to: ");
    for(i=0;i<m+1;i++)
        printf("%d" , liczba1_1[i]);*/

    int liczba2_h[n+1];
    for(i=0;i<n+1;i++)
        liczba2_h[i]=0;
    for(i=1;i<n+1;i++)
        liczba2_h[i]=liczba2[i-1];
    /*printf("\nLICZBA2_H to: ");
    for(i=0;i<n+1;i++)
        printf("%d" , liczba2_h[i]);*/

    int liczba1_h[n+1];
    for(i=0;i<n+1;i++)
        liczba1_h[i]=0;
    for(i=0;i<n+1;i++)
        liczba1_h[i]=liczba1_1[i];
    /*printf("\nLICZBA1_H to: ");
    for(i=0;i<n+1;i++)
        printf("%d" , liczba1_h[i]);*/

    int wynik_por[n+1];
    for(i=0;i<n+1;i++)
        wynik_por[i]=0;

    int wynik_p[n+1];
    for(i=0;i<n+1;i++)
        wynik_p[i]=0;

    if(m<n)
        for(i=0;i<l;i++)
            wynik[i]=0;// to jest jesli dzielna jest na pewno mniejsza niz dzielnik
    else if(m>n){

        for(j=0;j<=m-n;j++) {

            d = porownywanie(liczba1_h, liczba2_h, wynik_por, n + 1, n + 1, n + 1);
            for(i=0;i<n+1;i++)
                wynik_por[i]=0;//zerujemy tablice porownań, żeby potem się nic nie zepsuło

            if(d==0 || d==2){

                for(r[0]=1;r[0]<11;r[0]++){

                    mnozenie(liczba2_h,r,wynik_p,n+1,1,n+1);
                    e = porownywanie(liczba1_h , wynik_p , wynik_por , n+1,n+1,n+1);

                    //---------------------DRUKOWANIE KONTROLNE--------------------//
                    /*printf("\n");
                    printf("WYNIK_P to: ");
                    for(i=0;i<n+1;i++)
                        printf("%d" , wynik_p[i]);
                    printf(" LICZBA1_H to: ");
                    for(i=0;i<n+1;i++)
                        printf("%d" , liczba1_h[i]);
                    printf(" r[0] to: %d" , r[0]);
                    printf(" e = %d" , e);
                    printf(" j = %d" , j);*/
                    //--------------------------------------------------------------//

                    for(i=0;i<n+1;i++)
                        wynik_por[i]=0;
                    for(i=0;i<n+1;i++)
                        wynik_p[i]=0;     //zerujemy te dwie tablice, bo nie chcemy, żeby nam coś zostało

                    if(e==0)
                        continue;//endelif
                    else if(e==1){
                        wynik[n-1+j]=r[0]-1;
                        break;
                    }//endelif
                    else if(e==2){
                        wynik[n-1+j]=r[0];
                        break;
                    }//endelif


                }//endfor

                //------------TERAZ MUSIMY USTALIC NOWĄ TABLICE LICZBA1_H----------//

                r[0]=wynik[n-1+j];
                mnozenie(liczba2_h,r,wynik_p,n+1,1,n+1);
                odejmowanie(liczba1_h,wynik_p,wynik_por,n+1,n+1,n+1,0);

                    //---------------------DRUKOWANIE KONTROLNE--------------------//
                    /*printf("\nr[0] to: %d " , r[0]);
                    printf("LICZBA1_H to: ");
                    for(i=0;i<n+1;i++)
                        printf("%d" , liczba1_h[i]);
                    printf(" WYNIK_P to: ");
                    for(i=0;i<n+1;i++)
                        printf("%d" , wynik_p[i]);
                    printf(" WYNIK_POR to: ");
                    for(i=0;i<n+1;i++)
                        printf("%d" , wynik_por[i]);
                    printf(" j = %d\n" , j);*/
                    //--------------------------------------------------------------//

                for(i=0;i<n;i++)
                    liczba1_h[i]=wynik_por[i+1];
                liczba1_h[n]=liczba1_1[n+1+j];
                /*printf("\nLICZBA1_H to teraz: ");
                for(i=0;i<n+1;i++)
                    printf("%d" , liczba1_h[i]);
                printf("\n");*/

                //-----------------------------------------------------------------//

                for(i=0;i<n+1;i++)
                    wynik_por[i]=0;
                for(i=0;i<n+1;i++)
                    wynik_p[i]=0;   //znowu zerujemy, bo znowu będą jakieś kwiatki

            }//endif
            else if(d==1) {

                for(i=1;i<n+1;i++)
                    liczba1_h[i-1]=liczba1_h[i];
                liczba1_h[n]=liczba1_1[n+j+1];
                /*printf("\nLICZBA1_H to teraz: ");
                for(i=0;i<n+1;i++)
                    printf("%d" , liczba1_h[i]);*/

                continue;//tutaj musisz więcej nie tylko continue!!!!!! edit1: - już zrobiłem

            }//endelif

        }//endfor

    }//endelif
    else if(m==n){
        d = porownywanie(liczba1_h, liczba2_h, wynik_por, n + 1, n + 1, n + 1);
        for(i=0;i<n+1;i++)
            wynik_por[i]=0;

        if(d==2){
            for(i=0;i<l;i++)
                wynik[i]=0;
            wynik[l-1]=1;
        }//endif
        else if(d==1){
            for(i=0;i<l;i++)
                wynik[i]=0;
        }//endelif
        else if(d==0){

            for(r[0]=1;r[0]<11;r[0]++){

                mnozenie(liczba2_h,r,wynik_p,n+1,1,n+1);
                e = porownywanie(liczba1_h , wynik_p , wynik_por , n+1,n+1,n+1);

                for(i=0;i<n+1;i++)
                    wynik_por[i]=0;
                for(i=0;i<n+1;i++)
                    wynik_p[i]=0;     //zerujemy te dwie tablice, bo nie chcemy, żeby nam coś zostało

                if(e==0)
                    continue;//endelif
                else if(e==1){
                    k=r[0]-1;
                    break;
                }//endelif
                else if(e==2){
                    k=r[0];
                    break;
                }//endelif



            }//endfor

            for(i=0;i<l;i++)
                wynik[i]=0;
            wynik[l-1]=k;

        }//endelif

    }//endelif

}//endfunc

