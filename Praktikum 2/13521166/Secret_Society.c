/*
Nama    : Mohammad Rifqi Farhansyah
NIM     : 13521166
Praktikum Arsikom No 3
*/

#include <stdlib.h>
#include <stdio.h>

int func4(int x,int y){
    if(y<x){
        y = func4(y,x);
    }
    else{
        y=func4(y%x,x);
    }
    return y;
}

void Secret_Society(char* input){
    int inp,a,b,lcm;
    inp = sscanf(input,"%d %d",&a,&b);
    if (((inp != 2) || (362889 < a)) || (362889 < b)) {
        illegal_move();
    }
    lcm = func4(a,b);
    if ((b * a) / lcm != 362880) {
        illegal_move();
    }
}

