import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";
        
        // Complete the function
        // 'smallest' must be the lexicographically smallest substring of length 'k'
        // 'largest' must be the lexicographically largest substring of length 'k'
        
        int n = s.length() - (k - 1);
        String ss[] = new String[n];
        
        for (int i = 0;i < n;i++){
            ss[i] =  s.substring(i, i+3);
        }
        
        smallest = largest = ss[0];
        for (int i = 1;i < n;i++){
            if (largest.compareTo(ss[i]) < 0){
                largest = ss[i];
            }
            if (smallest.compareTo(ss[i]) > 0){
                smallest = ss[i];
            }
        }       
        
        return smallest + "\n" + largest;
    }

    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
}
