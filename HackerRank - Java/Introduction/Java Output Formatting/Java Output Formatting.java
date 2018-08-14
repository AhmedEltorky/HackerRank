import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            System.out.println("================================");
            for(int i=0;i<3;i++){
                String s1=sc.next();
                int x=sc.nextInt();
                //Complete this line
                // System.out.printf("%s\t%d\n", s1, x);
                System.out.print(s1);
                int len = 15 - s1.length();
                for (int j = 0;j < len;j++){
                     System.out.print(" ");
                }
                if (x < 10){
                    System.out.print("00");                    
                } else if (x < 100){
                    System.out.print("0");                    
                }
                System.out.printf("%d\n", x);
            }
            System.out.println("================================");

    }
}



