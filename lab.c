#include <stdio.h>
#define eps 0.00001
#include <math.h>
double tg(double x){
	double  s, sin_x, cos_x, tg_x ;
	int n;
	n = 0;
	s=0.0;
	sin_x = x;
	do{
		n++;
		s+=sin_x;
		sin_x*=-x*x/(2.0*n+1)/(2*n);
		
	}
	while(fabs(sin_x)>eps);
	printf("%f\n", s);
	sin_x = s;
	cos_x = 1;
	n = 0;
	s = 1;
	do{
		n++;
		s+=cos_x;
		cos_x*=-x*x/(2*n-1)/(2*n);
	}
	while(fabs(cos_x)>eps);
	printf("%f\n", s);
	cos_x=s;
	tg_x= sin_x/cos_x;
	printf("%f\n", tg_x);

	return tg_x;



}


int main(){
	double x;
	x=tg(30.0);
	printf("%f\t", x);
	

	return 0;

 }