#define eps 0.000001
double fabs(double x){
	if (x >= 0)
		return x;
    return x*(-1);		
}
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
	sin_x = s;
	cos_x = 1;
	n = 0;
	s = 0.0;
	do{
		n++;
		s+=cos_x;
		cos_x*=-x*x/(2*n-1)/(2*n);
	}
	while(fabs(cos_x)>eps);
	cos_x=s;
	tg_x= sin_x/cos_x;
	return tg_x;
}
int main(){
	int res;
	double x[5] = {1.0,6.0,3.0,4.0,5.0};
	double ref[5]={1.557407,-0.291006,-0.142546,1.157821,-3.380515};
	int i;
	for( i=0; i < 5 ;i++){	
		if(fabs(fabs(tg(x[i]))-fabs(ref[i]))<=eps)
			res=0;
		else res=1;
		if (res==1)
			break;
	}	
	return res;
}
		
			
	
	