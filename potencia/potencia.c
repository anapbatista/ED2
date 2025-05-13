#include <stdio.h>

int expo(int base, int exp) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % 1000;

    int meio = expo(base, exp / 2);
    
    int resultado = (meio * meio) % 1000;

    if (exp % 2 == 1)
        resultado = (resultado * (base % 1000)) % 1000;

    return resultado;
}



int main(){

int n; //0 a 99
int k; //0 a 10^9

scanf("%d",&n);
scanf("%d",&k);



int resultado = expo(n, k);
    
printf("%d\n", resultado );


    return 0;
}