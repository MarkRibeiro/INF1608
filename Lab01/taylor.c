#include<stdio.h>
#include"taylor.h"
double tan1(double x){
    return x + ((x*x*x)/3) + ((2*(x*x*x*x*x))/15);
}

double tan2(double x){
    return (x-((x*x*x)/6))/(1-(x*x)/2);
}