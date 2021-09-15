#include<stdio.h>
#include<math.h>
#include"taylor.h"
#define PI 3.1415926535897932
void teste(int d){
    printf("\tTESTE PI/%d\n", d);
    printf("math.h:\t\t%f\n", tan(PI/d));
    printf("tan1:\t\t%f\n", tan1(PI/d));
    printf("tan2:\t\t%f\n", tan2(PI/d));
    printf("tan1(erro):\t%f\n", fabs(tan(PI/d) - tan1(PI/d)));
    printf("tan2(erro):\t%f\n", fabs(tan(PI/d) - tan2(PI/d)));
    printf("\n");
    if(fabs(tan(PI/d) - tan1(PI/d)) < fabs(tan(PI/d) - tan2(PI/d))){
        printf("*tan1 tem o menor erro*\n");
    } 
    else {
        printf("*tan2 tem o menor erro*\n");
    }
    printf("\n");
}

int main (){
    teste(10);
    teste(8);
    teste(6);
    teste(4);
    teste(3);
    return 0;
}