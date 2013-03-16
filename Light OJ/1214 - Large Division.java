import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cas=1,tc = sc.nextInt();
		while(tc-- >0)
		{
			BigInteger p = sc.nextBigInteger();
			if(p.compareTo(BigInteger.ZERO)<0) p = p.abs();

			BigInteger q = sc.nextBigInteger();
			if(q.compareTo(BigInteger.ZERO)<0) q = q.abs();

			System.out.printf("Case %d: ",cas++);

			if(p.mod(q).equals(BigInteger.valueOf(0)))
				System.out.println("divisible");
			else
				System.out.println("not divisible");
		}
	}
}
