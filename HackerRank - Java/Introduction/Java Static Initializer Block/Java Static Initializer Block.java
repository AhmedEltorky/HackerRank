import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    // Write your code here
static int H, B;
static boolean flag;
static Scanner input;

static {
    input = new Scanner(System.in);
    B = input.nextInt();
    H = input.nextInt();
    
    if (H > 0 && B > 0){
        flag = true;        
    } else {
        System.out.println("java.lang.Exception: Breadth and height must be positive");
    }
}

public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
		
	}//end of main

}//end of class