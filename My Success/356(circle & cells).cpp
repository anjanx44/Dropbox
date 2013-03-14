#include<stdio.h>
#include<math.h>
int main(){

double a,b,c,d=0,e,f,g;
double i,j,k=0,l=0,m=0,n;
int ra=0,se=0,h=0,z=0;
while(scanf("%lf",&a)==1){
if(z==1)printf("\n");
z=1;
b=(2*a-1)/2;
for(i=1;i<a;i++){
for(j=1;j<a;j++){

if((sqrt(i*i+j*j))<b){
d+=1;
}
}

}
for(k=a-1;k>1;k--){
for(l=a-1;l>1;l--){

if((sqrt(k*k+l*l))>b){
m+=1;

}
}

}
d=d*4;
m=m*4;
h=(int)a;
ra=(int)d;
se=(int)(4*a*a-d-m);
printf("In the case n = %d, %d cells contain segments of the circle.\n",h,se);
printf("There are %d cells completely contained in the circle.\n",ra);

d=0;
m=0;
h=0;
ra=0;
se=0;

}

return 0;
}
