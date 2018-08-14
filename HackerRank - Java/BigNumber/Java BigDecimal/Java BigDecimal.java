import java.math.BigDecimal;
import java.util.*;

class Solution{
    public static void main(String []args){
        //Input
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String []s=new String[n+2];
        for(int i=0;i<n;i++){
            s[i]=sc.next();
        }
        sc.close();
                //Write your code here
                BigDecimal bd, max;
                int max_index;
        
                for (int i = 0;i < n-1;i++){  
                    max = new BigDecimal(s[i]);
                    max_index = -1;
                    for (int j = i+1;j < n;j++){
                        bd = new BigDecimal(s[j]);
                        if (max.compareTo(bd) == -1){
                            max = bd;
                            max_index = j;
                        }
                    }
                    if (max_index != -1){
                        s[n] = s[i];
                        s[i] = s[max_index];
                        s[max_index] = s[n];
                    }      
                }
                        //Output
        for(int i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }
    }
}
