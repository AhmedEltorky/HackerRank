import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scan = new Scanner(System.in);
        
        BigInteger bi1 = new BigInteger(scan.nextLine());
        BigInteger bi2 = new BigInteger(scan.nextLine());
        
        System.out.println(bi1.add(bi2));
        System.out.println(bi1.multiply(bi2));
    }
}
