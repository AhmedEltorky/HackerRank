import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        String delims = "[ .,'?!]+";
        String tokens[] = s.split(delims);
        System.out.println(tokens.length);
        for (int i = 0;i < tokens.length;i++){
            System.out.println(tokens[i]);
        }
        scan.close();
    }
}

