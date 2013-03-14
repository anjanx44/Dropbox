
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cas=1,t = sc.nextInt();
		while(t-->0)
		{
			String s1 = sc.next();
			String s2 = sc.next();
			BigInteger p = new BigInteger(s1,2);
			BigInteger q = new BigInteger(s2,2);
			if(p.gcd(q).equals(BigInteger.valueOf(1)))
				System.out.println("Pair #"+ (cas++) + ": Love is not all you need!");
			else
				System.out.println("Pair #"+ (cas++) + ": All you need is love!");
				
		}
	}
}