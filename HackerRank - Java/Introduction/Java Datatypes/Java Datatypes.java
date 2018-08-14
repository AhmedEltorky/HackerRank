import java.util.*;
import java.io.*;


class Solution{
    public static void main(String []argh){
        byte b;
        short s;
        int ii;
        boolean iif = false, sf = false, bf = false, lf = false;

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for (int i=0;i<t;i++){            
            try{
                long l = sc.nextLong();
                lf = true;
                System.out.println(l + " can be fitted in:");
                ii = (int) l;
                if (ii == l) iif = true;
                s = (short) l;
                if (s == l) sf = true;
                b = (byte)l;
                if (b == l) bf = true;                                  
            } catch (Exception e){
                if (!bf && !sf && !iif){
                    System.out.println(sc.next()+" can't be fitted anywhere.");                    
                }
            } finally {
                if (bf){
                    System.out.println("* byte");
                } 
                if(sf){
                    System.out.println("* short");
                }
                if (iif){
                    System.out.println("* int");
                }
                if (lf){
                    System.out.println("* long");
                }
                iif = sf = bf = lf = false;
            }
        }
    }
}

