import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        BitSet b1 = new BitSet(n);
        BitSet b2 = new BitSet(n);
        
        for (int i = 0;i < m;i++){
            String op = scan.next();
            int n1 = scan.nextInt();
            int n2 = scan.nextInt();
            
            switch(op){
                case "AND":
                    if (n1 == 1){
                        b1.and(b2);                        
                    } else {
                        b2.and(b1);                        
                    }
                    break;
                case "OR":
                    if (n1 == 1){
                        b1.or(b2);                        
                    } else {
                        b2.or(b1);                        
                    }
                    break;
                case "XOR":
                    if (n1 == 1){
                        b1.xor(b2);                        
                    } else {
                        b2.xor(b1);                        
                    }
                    break;
                case "FLIP":
                    if (n1 == 1){
                        b1.flip(n2);                        
                    } else {
                        b2.flip(n2);                        
                    }
                    break;
                case "SET":
                    if (n1 == 1){
                        b1.set(n2);                        
                    } else {
                        b2.set(n2);                       
                    }
                    break;
                default:
                    break;                    
            }
            
            System.out.println(b1.cardinality() + " " + b2.cardinality());
        }
    }
}
