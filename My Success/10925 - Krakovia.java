/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 10925 - Krakovia
*/
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cas = 1;
		while(true)
		{
			int N = sc.nextInt();
			int F = sc.nextInt();
			if(N==0 && F==0) break;
			BigInteger sum = BigInteger.valueOf(0);
			for(int i=0;i<N;i++)
			{
				BigInteger V = sc.nextBigInteger();
				sum = sum.add(V);
			}
			System.out.println("Bill #" + (cas++) +" costs "+ sum 
			+": each friend should pay "+ sum.divide(BigInteger.valueOf(F))+"\n");
		}
	}
}	