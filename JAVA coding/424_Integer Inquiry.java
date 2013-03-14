import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		while(true)
		{
			BigInteger p = sc.nextBigInteger();
			if(p.equals(BigInteger.valueOf(0)))
				break;
			sum = sum.add(p);	
		}
		System.out.println(sum);
	}
}	