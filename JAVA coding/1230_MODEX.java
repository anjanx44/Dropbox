import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0)
		{
			BigInteger p = sc.nextBigInteger();
			BigInteger q = sc.nextBigInteger();
			BigInteger n = sc.nextBigInteger();
			System.out.println(p.modPow(q,n));
		}
	}
}	