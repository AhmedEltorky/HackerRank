import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

class Solution{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            String IP = in.next();
            System.out.println(IP.matches(new MyRegex().pattern));
        }

    }
}
//Write your code here

class MyRegex {
    
    public static String pattern;
    
    public MyRegex(){
        pattern = Pattern.compile("[0-255].[0-255].[0-255].[0-255]").pattern();   
        System.out.println(pattern);
    }
    
}
