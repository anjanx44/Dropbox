import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		//System.out.println("Enter the value:");
		while(true){
			String str = sc.next();
			BigInteger p = new BigInteger(str);
			if(p.compareTo(BigInteger.valueOf(0)) < 0 )
				break;
			System.out.println(p.toString(3));
		}
	}
}