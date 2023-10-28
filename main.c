#include <stdio.h>
#include <stdlib.h>
#include "adding10.h"
#include "multi10.h"
#include "power10.h"
#include "sub10.h"
#include "compare10.h"
#include "divide10v2.h"
#include "divide10_mod.h"

int main(){

    //-------------------------------------------------------------------------//
    //          OTWIERANIE DANYCH Z PLIKU I PRZEPISYWANIE DO TABLICY           //
    //-------------------------------------------------------------------------//

    FILE *data;
    data = fopen("me_01_in.txt" , "r"); //otwieramy plik do odczytu

    char input[500]; //tutaj będziemy przechowywać dane z pliku - jak nie dziala zmien na int
    int i; //iterator
    int c;

    for(i=0 ; i<500 ; i++){
        input[i] = 0;
    } // inicjujemy całą tablicę na zera

    if (data == NULL){
        printf("FILE NOT FOUND\n");
        exit (0);
    } //zabezpieczenie przed pustym plikiem

    for (i = 0; i < 500; i++)
        fscanf(data, "%c", &input[i] );
    //ładujemy dane z pliku


    fclose(data);// zamykamy plik

    //----------------------------------------------------------------------------//
    //                     WCZYTYWANE DANYCH  DO TABLIC                          //
    //---------------------------------------------------------------------------//

    char dzialanie = input[0] ; //wczytywanie działania


    int system[2]; //miejsce na system

    int j = 0;

    for(i=2 ; input[i] != '\n' ; ++i){ // ważna linijka!!
        system[j] = input[i];
        j = j+1;
    } //wczytywanie jaki to system


    int k = 0; //zmienna interacyjna argumentu

    if(system[0]== '2' || system[0] == '3'|| system[0] == '4'|| system[0] == '5'|| system[0] == '6'|| system[0] == '7'|| system[0] == '8'|| system[0] == '9'){
        k=5;
    }
    else if(system[0] == '1'){
        k=6;
    }

    char argument1[40];
    for(i=0 ; i<40 ; i++)     // inicjujemy tablicę na argument pierwszy działania
        argument1[i] = ' ';

    // Chcemy teraz zainicjować pierwszy argument naszego działania

    int m = 0;

    for(i=0 ; i<40 ; i=i+1){
        if(input[k+i] != '\n'){
            argument1[i] = input[k+i];
            m=k+i+3;
        }
        else
            break;
    }


    int n = 0;

    char argument2[40];
    for(i=0 ; i<40 ; i++)     // inicjujemy tablicę na argument drugi działania
        argument2[i] = ' ';    //było 0

    for(i=0 ; i<40 ; i=i+1){
        if(input[m+i] != '\n'){
            argument2[i] = input[m+i];
            n=m+i+5;
        }
        else
            break;
    }


    int system1[2] = {0,0}; //miejsce na system1
    int system2[2] = {0,0}; //miejsce na system2

    int l = 0;

    for(i=0 ; input[n+i] != ' ' ; ++i){ // ważna linijka!!
        system1[i] = input[n+i];
        l = n+i+2;
    } //wczytywanie z jakiego systemu1 konwertujemy



    int p = 0;

    for(i=0 ; input[l+i] != '\n' ; ++i){ // ważna linijka!!
        system2[i] = input[l+i];
        p = l+i+3;
    } //wczytywanie do jakiego systemu2 konwertujemy!!


    int system_arg[40];
    for(i=0 ; i<40 ; i++){
        system_arg[i] = 0;
    }  // inicjujemy tablicę na liczbę do konwersji

    for(i=0 ; input[p+i] != '\n' ; ++i){ // ważna linijka!!
        system_arg[i] = input[p+i];
        //l = n+i+2;
    } //wczytywanie z jakiego systemu1 konwertujemy


    //-------------------------------------------------------------------------//
    //       ROZMIARY TABLIC NA ARGUMENTY I WYNIK  ORAZ ICH INICJALIZACJA      //
    //-------------------------------------------------------------------------//

    m = 0;
    n = 0;
    l = 0;

    for(i=0 ; argument1[i] != ' ' ; i++){
        m++;
    } //rozmiar tablicy na liczba1

    for(i=0 ; argument2[i] != ' ' ; i++){
        n++;
    } //rozmiar tablicy na liczba2


    if(dzialanie=='*'){
        if(m>n)
            l=m*2;
        else
            l=n*2;
    }// rozmiar wyniku
    else if(dzialanie=='+'){
        if(m>n)
            l=m+1;
        else
            l=n+1;
    }
    else if(dzialanie=='-'){
        if(m>n)
            l=m;
        else
            l=n;
    }
    else if(dzialanie=='c'){
        if(m>n)
            l=m+1;
        else
            l=n+1;
    }
    else if(dzialanie=='/'){
        if(m>n)
            l=m;
        else
            l=n;
    }
    else if(dzialanie=='%'){
        if(m>n)
            l=m;
        else
            l=n;
    }
    else if(dzialanie=='^'){
        l=40;
    }//jak cos sie bedzie dzialo to skasowac


    int liczba1[m];
    int liczba2[n];
    int wynik[l];
    for(i=0 ; i<l ; i++)
        wynik[i]=0; //wynik!

    //---------------------KONWERSJA Z ARGUMENTÓW Z TYPU CHAR NA INT-----------------------//

    for(i=0 ; i<m ; ++i)
        liczba1[i] = argument1[i] - 48;  //konwertujemy tablice z licza na inty

    for(i=0 ; i<n ; ++i)
        liczba2[i] = argument2[i] - 48;  //konwertujemy tablice z liczbą na inty



    //-------------------------------------------------------------------------------//
    //                       TERAZ WYBIERAMY DZIAŁANIA                               //
    //-------------------------------------------------------------------------------//

    if(dzialanie == '+') {
        dodawanie(liczba1, liczba2, wynik, m, n, l);
    }
    else if(dzialanie == '*'){
        mnozenie(liczba1,liczba2,wynik,m,n,l);
    }
    else if(dzialanie == '/') {
        dzieleniev2(liczba1, liczba2, wynik, m, n, l);
    }
    else if(dzialanie=='-'){
        c = porownywanie(liczba1,liczba2,wynik,m,n,l);
        odejmowanie(liczba1,liczba2,wynik,m,n,l,c);
    }
    else if (dzialanie == '%'){
        dzielenie_mod(liczba1,liczba2,wynik,m,n,l);
    }
    else if(dzialanie=='^'){
        potegowanie(liczba1,liczba2,wynik,m,n,l);
    }
    else if(dzialanie=='c'){
        porownywanie(liczba1,liczba2,wynik,m,n,l);
    }
    else
        printf("\n\nnie znam tego jeszcze:((");

    //--------------------------------------------------------//

    printf("\nWYNIK: ");
    for(i=0;i<l;i++)
        printf("%d",wynik[i]);
    printf("\n");
    printf("Sprawdź plik me_01_out.txt");

    //------------------WPISANIE WYNIKÓW W PLIK WYJŚCIOWY-------------------//
    FILE *out;
    out = fopen("me_01_out.txt" , "w"); //otwieramy plik do zapisu

    fprintf(out, "%c" , dzialanie);
    fprintf(out, " ");
    for(i=0;i<2;i++)
        if(system[i]!=NULL)
            fprintf(out , "%c" , system[i]);
    fprintf(out, "\n\n");
    for(i=0;i<m;i++)
        fprintf(out, "%d" , liczba1[i]);
    fprintf(out, "\n\n");
    for(i=0;i<n;i++)
        fprintf(out, "%d" , liczba2[i]);
    fprintf(out, "\n\n");
    for(i=0;i<l;i++)
        fprintf(out, "%d" , wynik[i]);
    fprintf(out, "\n\n");
    for(i = 0 ; i<2 ; ++i){
        if(system1[i] != 0)
            fprintf(out , "%c" , system1[i]);
        else
            break;
    } //wpisujemy system1*/
    fprintf(out, " ");
    for(i = 0 ; i<2 ; ++i){
        if(system2[i] != NULL)
            fprintf(out , "%c" , system2[i]);
    } //wpisujemy system2
    fprintf(out, "\n\n");
    for(i = 0 ; i<40 ; ++i){
        if(system_arg[i] != 0)
            fprintf(out , "%c" , system_arg[i]);
        else
            break;
    } //wpisujemy system_arg
    fprintf(out, "\n\n");
    fprintf(out , "NO DATA");
    fprintf(out , "\n");

    fclose(out);

    return 0;
}//endfunc
