import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static BigInteger f(BigInteger b)
	{
		return b.multiply(b);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cas=1,t = sc.nextInt();
		while(t-->0)
		{			
			BigInteger p = sc.nextBigInteger();
			BigInteger lo = BigInteger.valueOf(0),hi = p;
			if(p.equals(BigInteger.ZERO)){ System.out.println( "0" );continue; }
			if(p.equals(BigInteger.ONE)){ System.out.println( "1" );continue; }
			while(true)
			{
				BigInteger mid = (lo.add(hi)).divide(BigInteger.valueOf(2));
				BigInteger y = f(mid);
				if(y.equals(p)){ System.out.println( mid ); break; }
				if( y.compareTo(p) > 0 )
					hi = mid;
				else 
					lo = mid;
			}
		}
	}
}
