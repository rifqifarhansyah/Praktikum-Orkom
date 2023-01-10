/*
Nama    : Mohammad Rifqi Farhansyah
NIM     : 13521166
Praktikum Arsikom No 3
*/

#include <stdlib.h>
#include <stdio.h>

void Holoro() {
    int lokal[6];
    scanf("%d %d %d %d %d %d", lokal[0], lokal[1], lokal[2], lokal[3], lokal[4], lokal[5]);
    if (lokal[0] != 1){
        illegal_move();
    }
    int i=1;
    while (i < 6){
        if(i%2==0){
            if(lokal[i] != i * lokal[i-1]) goto LAB_0001172e;
        }
        else if(lokal[i] != i + lokal[i-1]){
            LAB_0001172e:
                illegal_move();
        }
        i += 1;
    }  
}