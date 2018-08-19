import java.util.*;

public class Solution {

    public static boolean canWin(int leap, int[] game) {
        // Return true if you can win the game; otherwise, return false.
        int pointer = 0;
        for (int i = 0;i < game.length;i++){
            if (game[i] == 0){
                pointer = i;                
            } else {
                break;
            }
        }
        
        if ((pointer + leap) >= game.length){
            return true;
        } else if ((pointer + leap) < game.length){
            do {
                if ((pointer + leap) < game.length && game[pointer + leap] == 0){
                    pointer = pointer + leap;
                } else if ((pointer + leap) >= game.length){
                    return true;
                } else {
                    break;
                }
            } while(true);
        }
        
        return false;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}
