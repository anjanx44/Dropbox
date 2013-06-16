//copied form tausiq
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
 
public class Main {
 
    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner input = new Scanner (System.in);
         
        while ( input.hasNext() ) {
            int n = input.nextInt();
            String str = input.next();
            HashMap <String, Integer> m = new HashMap <String, Integer> ();
             
            for ( int i = 0; i < str.length() - n + 1; i++ ) {
                String subs = str.substring(i, i + n);
                if ( m.containsKey(subs))
                    m.put(str.substring(i, i + n), m.get(subs) + 1);
                else m.put(str.substring(i, i + n), 1);
            }
             
            Set s = m.entrySet();
            Iterator it = s.iterator();
             
            String ret = "";
            int max = Integer.MIN_VALUE;
             
            while ( it.hasNext() ) {
                Map.Entry k = (Map.Entry)it.next();
                String key = (String) k.getKey();
                int val = (Integer) k.getValue();
                 
                if ( val > max ) {
                    max = val;
                    ret = key;
                }
            }
             
            System.out.println (ret);
        }
    }
}