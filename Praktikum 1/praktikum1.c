#include <stdio.h>
#include <stdlib.h>

/*
gura - menghitung x|y hanya dengan ~ dan &
contoh: gura(6, 5) = 7
legal ops: ~ &
Max ops: 5
Rating: 1
 */
int gura(int x, int y){
    return ~((~x)&(~y));
}

/*
rushia - Berikan nilai terkecil dalam two's complement
legal ops: ~ & ^ | + << >>
Max ops: 4
rating: 1
*/
int rusia(void){
    return (0x1 << 31);
}

/*
kobokan - hitung sisa dari x jika dibagi 2 pangkat n
contoh: kobokan(100, 5) = 4
semua input bernilai positif dan keluaran harus positif
legal ops: ~ & | + << >>
max ops: 5
rating : 2
*/
unsigned int kobokan(unsigned int x, unsigned int n){
    return x&~((~0>>n)<<n);
}

/*
fauna - mengembalikan byte ke-n dari word x
byte diurutkan dari 0 (LSB) ke 3 (MSB)
contoh : fauna(0x12345678,1) = 0x56
legal ops: ~ & ^ | + << >>
max ops: 6
rating: 2
*/
int fauna(int x, int n){
    return (x>>(n<<3))&0xff;
}

/*
yamada - periksa apakah x berada diantara 135 dan 182 inklusif
contoh yamada(182) = 1
yamada(1000) = 0
yamada(140) = 1
legal ops: ~ & ^ | + << >>
max ops: 12
rating 3
*/
int yamada(int x){
    // 135 = 10000111
    // 182 = 10110110
    // 140 = 10001100
    // ~135 = 01111000 = 120
    // ~182 = 01001001 = 73
    // ~140 = 01110011 = 115
    // 120+1+140
    return !((x>>31)|((x+~135+1)>>31)|((182+~x+1)>>31));
    // !((0)|());
}


/*
pekora - balik urutan byte pada x
contoh: pekora(0x01020304) = 0x04030201
legal ops: ~ & ^ | + << >>
max ops: 25
rating: 3
*/
int pekora(int x){
    // 0x01020304 = 00000001 00000010 00000011 00000100
    // 0x04030201 = 00000100 00000011 00000010 00000001
    // 00000001000000100000001100000100 x
    // 00000000000000000000000011111111 0xff
    // x & 0xff
    // 00000000000000000000000000000100 part1

    // 00000000000000000000000000001000 1 << 3
    // 00000000000000010000001000000011 x >> 8
    // 00000000000000000000000011111111 0xff
    // (x>>(1<<3)) & 0xff
    // 00000000000000000000000000000011 part2

    // 00000000000000000000000000010000 2 << 3
    // 00000000000000000000000100000010 x >> 16
    // 00000000000000000000000011111111 0xff
    // (x>>(2<<3)) & 0xff
    // 00000000000000000000000000000010 part3

    // 00000000000000000000000000011000 3 << 3
    // 00000000000000000000000000000001 x >> 24
    // 00000000000000000000000011111111 0xff
    // (x>>(3<<3)) & 0xff
    // 00000000000000000000000000000001 part4

    // 00000000000000000000001000000000 part3 << 8
    // 00000000000000000000001000000001
    int part1 = x & 0xFF;
    int part2 = (x >> (1<<3)) & 0xFF;
    int part3 = (x >> (2<<3)) & 0xFF;
    int part4 = (x >> (3<<3)) & 0xFF;
    int res = part4 | (part3 << 8);
    res = res | (part2 << 16);
    res = res | (part1 << 24);
    return res;
}

/*
mumei - geser x kekanan dengan syarat aturan logical shift
asumsikan 0<=n<=31
contoh: mumei(0x87654321,4)=0x08765432
legal ops: ~ & ^ | + << >>
max ops: 20
rating 3
*/
int mumei(int x, int n){
    // 0x87654321 = 10000111011001010100001100100001
    // 0x08765432 = 00001000011101100101010000110010
    //              10000000000000000000000000000000
    //              00001000000000000000000000000000
    //              00010000000000000000000000000000
    //              11101111111111111111111111111111
    //              00001000011101100101010000110010
    int shift = x >> n;
    int log = 0x1 << 31;
    log = log >> n;
    log = log << 1;
    return (shift & ~log);
}

/*
moona - hitung banyak bit nol dari kanan (trailing zeroes) dalam representasi 32 bit nilai x
anda diperbolehkan menggunakan konstanta besar pada soal ini
contoh: moona(128) = 7
moona(-2) = 1
moona(57) = 0
moona(24) = 3
moona(0) = 32
legal ops: ~ & ^ | + << >>
max ops: 50
rating: 4
*/
int moona(int x){
    // 00000000000000000000000010000000
    // 00000000000000001111111111111110
    // 00000000000000000000000000111001
    // 00000000000000000000000000000000

    // 11111111111111111111111111111111
    int res=0;
    res=0;
    res+=!(x);
    res+=!(x&65535) << 4;
    res+=!(x&16711935) << 3;
    res+=!(x&252645135) << 2;
    res+=!(x&858993459) << 1;
    res+=!(x&1431655765);
    return res;
}

/*
ollie - hitung sisa dari a jika dibagi 30
contoh: epsilon(100) = 10
legal ops: ~ & ^ | + << >>
max ops: 40
rating: 4
*/
unsigned int ollie(unsigned int a){
    int x;
    x = (a>>4)+(a&15);
    x = (x>>4)+(x&15);
    x = (x>>4)+(x&15);
    x = (x>>4)+(x&15);
    x = (x>>4)+(x&15);
    x = (x>>4)+(x&15);
    x = (x>>4)+(x&15);
    x = (x>>4)+(x&15);

    x=x>>(((x+1)>>4)<<2);
    a=((a&1)+x)&1;
    x+=a<<3;
    x+=a<<2;
    x+=a<<1;
    x+=a;
    return x;
}

/*
coco - hitung 2*f untuk suatu bilangan floating point f
argumen f dan hasil merupakan representasi bit dari bilangan desimal
dalam bentuk single-precision floating point
jika f NaN, kembalikan f
legal ops: semua operasi integer/unsigned termasuk ||, &&, juga if, while
max ops: 30
rating: 4
*/
unsigned coco(unsigned uf){
    int sign = uf & (0x80 << 24);
    int exp = (0x7F << 24) | (0x80 << 16);
    int ufexp = uf & exp;
    int isZero = !ufexp;
    if(isZero){
        uf = (uf<<1) | sign;
    }else if(ufexp != exp){
        uf += (1<<23);
    }
    return uf;
}


int main(){
    printf("%d\n", gura(6, 5));
    printf("%d\n", rusia());
    printf("%d\n", kobokan(100, 5));
    printf("%d\n", fauna(0x12345678,1));
    printf("%d\n", yamada(140));
    printf("%d\n", pekora(0x01020304));
    printf("%d\n", mumei(0x87654321,4));
    printf("%d\n", ollie(100));
    printf("%d\n", moona(128));
    return 0;
}


