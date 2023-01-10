/*
Nama    : Mohammad Rifqi Farhansyah
NIM     : 13521166
Praktikum Arsikom No 3
*/

#include <stdlib.h>
#include <stdio.h>

void Holoh3ro(char* input) {
    int a, b, cek, z;
    char n;
    cek = sscanf(input, "%d %c %d", &a, &n, &b);

    if (cek < 3){
        illegal_move();
    }
    switch (a){
    case 0:
        z = 'q';
        if(b != 943){
            illegal_move();
            z = 'q';
        }
        break;
    case 1:
        z = 'n';
        if(b != 107){
            illegal_move();
            z = 'n';
        }
        break;
    case 2:
        z = 'u';
        if(b != 683){
            illegal_move();
            z = 'u';
        }
        break;
    case 3:
        z = 'q';
        if(b != -805){
            illegal_move();
            z = 'q';
        }
        break;
    case 4:
        z = 'v';
        if(b != 527){
            illegal_move();
            z = 'v';
        }
        break;
    case 5:
        z = 'f';
        if(b != 467){
            illegal_move();
            z = 'f';
        }
        break;
    case 6:
        if(b != 997){
            illegal_move();
            goto L20;
        }
        LAB_0001188c:
            illegal_move();
    default:
        switchD_000117c7_caseD_8:
            illegal_move();
            z = 'e';
            break;
    case 7:
        L20:
            if (b != 464) goto LAB_0001188c;
            goto switchD_000117c7_caseD_8;
    }
    if (n != z){
        illegal_move();
    }  
}