import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			String ans, p_str  = sc.next();
			int b = sc.nextInt();
			int t = sc.nextInt();
			BigInteger p = new BigInteger(p_str,b);
			ans = p.toString(t);
			if(ans.length()>7)
				System.out.printf("%7s\n","ERROR");
			else 
			{
				ans = ans.toUpperCase();
				System.out.printf("%7s\n",ans);
			}
			//System.out.println((p.mod(q)).toString(b));
		}
	}
}