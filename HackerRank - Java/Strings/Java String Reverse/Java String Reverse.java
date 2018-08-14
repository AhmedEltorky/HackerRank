import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A = sc.next();
        /* Enter your code here. Print output to STDOUT. */
        char arr[] = A.toCharArray();
        
        for (int i = 0;i < arr.length/2;i++){            
            char temp = arr[i];
            temp = arr[i];
            arr[i] = arr[arr.length-1-i]; 
            arr[arr.length-1-i] = temp;            
        }
        
        String test = String.valueOf(arr);
        
        if (test.equals(A)){
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

