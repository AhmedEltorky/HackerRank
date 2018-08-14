import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int x, y;       
        Scanner input = new Scanner(System.in);
        
        try {
            x = input.nextInt();
            y = input.nextInt();
            System.out.println(x/y);            
        } catch (InputMismatchException ex){
            System.out.println("java.util.InputMismatchException");
        } catch (ArithmeticException ex){
            System.out.println("java.lang.ArithmeticException: / by zero"); 
        }
    }
}
