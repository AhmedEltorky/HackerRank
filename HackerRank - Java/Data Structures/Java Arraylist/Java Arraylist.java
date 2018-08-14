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
        
        ArrayList<Integer>[] arr = new ArrayList[n];
        
        for (int i = 0;i < n;i++){
            int l = scan.nextInt();
            arr[i] = new ArrayList();
            for (int j = 0;j < l;j++){
                arr[i].add(j, scan.nextInt());
            }            
        }
        
        int q = scan.nextInt();
        for (int i = 0;i < q;i++){
            try{
                System.out.println(arr[scan.nextInt()-1].get(scan.nextInt()-1));
            } catch(Exception ex){
                System.out.println("ERROR!");                
            }            
        } 
    }
}
