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
			int b = sc.nextInt();
			int t = sc.nextInt();
			String cs,s  = sc.next();
			BigInteger a;
			try
	        {
		        a=new BigInteger(s,b);
		        cs=a.toString(t).toUpperCase();
		        System.out.println(s + " base "+ b +" = "+ cs +" base "+ t);
	        }
	        catch(Exception ex){
	        	System.out.println(s +" is an illegal base "+ b +" number");
	        }
		}
	}
}