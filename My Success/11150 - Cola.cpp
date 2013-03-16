/*
Shiakh Shiam Rahman 
UVa : 11150 - Cola
*/
    #include<stdio.h>

    int main()
    {
    long int num,half,total;
    while(scanf("%ld",&num)==1)
    {
		half=num/2;
		total=num+half;
		printf("%ld\n",total);
    }
    return 0;
    }
/*
Integer Number_of_bottles_u_can_enjoy = N

continue while ( N >= 3 ) {
N = N – 2
Number_of_bottles_u_can_enjoy ++
}

if ( N is equals to 2 )
Number_of_bottles_u_can_enjoy ++

output: Number_of_bottles_u_can_enjoy

don’t be confused !
Number_of_bottles_u_can_enjoy is a variable name
I have just been introduced u, how to declare an integer variable in horrible way
or, u can say that, Shahab has made a revolutionary change of naming a variable !!
*/