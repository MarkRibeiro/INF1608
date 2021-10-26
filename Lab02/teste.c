#include<stdio.h>
#include<math.h>
#define PI 3.14

double p1(double x){
	return 1-(((pow(x, 2))-PI*x+(pow(PI, 2))/4)/2)+((pow(x, 4))-2*PI*pow(x, 3)+(((3*pow(PI, 2))*(pow(x, 2)))/2)-((pow(PI, 3))*x)/2+(pow(PI, 4))/16)/24;
}

double p2(double x){
    return 1.0f-(1.0f/2.0f)*pow(x-(PI/2), 2)+(1/24.0f)*pow(x-(PI/2), 4);
           //1-(1/2)*   (x-(PI/2))^2 +(1/24)*   (x-(PI/2))^4
}

int main (){
	printf("%f\n", p1(3));
    printf("%f\n", p2(3));
	return 0;
}