import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scan = new Scanner(System.in);
        int  n = scan.nextInt();
        int arr[] = new int[n];
        for (int i = 0;i < n;i++){
            arr[i] = scan.nextInt();            
        }
        
        int counter = 0, sum = 0;
        
        for (int i = 0;i < n;i++){
            for (int z = i;z < n;z++){
                sum = 0;
                for (int j = i;j <= z;j++){
                    sum += arr[j];
                }
                if (sum < 0){
                    counter++;
                }
            }
        }
        
        System.out.println(counter);
    }
}
