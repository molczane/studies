//
// Created by Ernest  on 13/11/2022.
//

#ifndef UNTITLED_DIVIDE10_MOD_H
#define UNTITLED_DIVIDE10_MOD_H

#endif //UNTITLED_DIVIDE10_MOD_H


#include <stdio.h>
#include <stdlib.h>

void odejmowanie();
int porownywanie();
void mnozenie();

void dzielenie_mod(int liczba1[] , int liczba2[] , int wynik[] , int m , int n , int l){

    int i = 0;
    int wynik_p[l];
    for(i=0;i<l;i++)
        wynik_p[i]=0;
    int wynik_h[l];
    for(i=0;i<l;i++)
        wynik_h[i]=0;

    dzieleniev2(liczba1, liczba2, wynik_p, m, n, l);
    mnozenie(wynik_p, liczba2,wynik_h,l,n,l);
    odejmowanie(liczba1, wynik_h,wynik,m,l,l,0);
}

