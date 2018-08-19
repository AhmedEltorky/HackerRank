import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        List<Integer> list = new ArrayList();
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        for (int i = 0;i < n;i++){
            list.add(scan.nextInt());            
        }
        
        int q = scan.nextInt();
        scan.nextLine();
        for (int i = 0;i < q;i++){
            if (scan.next().equals("Insert")){
                list.add(scan.nextInt(), scan.nextInt());
            } else {
                list.remove(scan.nextInt());   
            }                
        }
        
        for (int i = 0;i < list.size();i++){
            System.out.print(list.get(i) + " ");            
        }
    }
}
