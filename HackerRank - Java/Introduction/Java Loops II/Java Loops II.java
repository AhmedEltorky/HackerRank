import java.util.*;
import java.io.*;


class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            
            int sum = 0;
            for (int j = 0;j < n;j++){
                sum = a;
                for (int m = 0;m <=j;m++){
                    sum += (Math.pow(2, m) * b);
                }
                System.out.printf("%d ", sum);                            
            }
            System.out.println();
        }
        in.close();
    }
}