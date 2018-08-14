import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner input = new Scanner(System.in);
        int index = 0;

        do {
            System.out.printf("%d %s\n", index+1, input.nextLine());
            index+=1;
        } while (input.hasNextLine());
    }
}