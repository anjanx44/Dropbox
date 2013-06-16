/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)
UVa - 10519 - Really Strange
*/
import java.math.BigInteger;
import java.util.Scanner;
class Main
{
   public static void main( String args[] )
   {
		Scanner input = new Scanner( System.in );
		BigInteger ans =  new BigInteger ("0");
		BigInteger N1 =  new BigInteger ("0");
		while(input.hasNextBigInteger()){
		N1= input.nextBigInteger();
		if(N1.equals(BigInteger.valueOf(0)))
		{
			 System.out.println(1);
			 continue;
		}
		ans=N1.multiply(N1);
		ans=ans.subtract(N1);
		ans=ans.add(BigInteger.valueOf(2));
		System.out.println(ans);
   	}

   }
}