
import java.util.HashMap;

public class JumpGame {
    static HashMap<Integer,Boolean> memo;

    static boolean helper(int [] nums, int i){
        if(i==nums.length-1) return true;
        if(i>=nums.length-1) return false;
        if(memo.containsKey(i)){
            return false;
        }
        boolean res = false;
        for(int j=1; j<=nums[i]; j++){
            res = helper(nums,i+j);
            if(res) return true;
        }
        memo.put(i,false);
        return false;
    }
    
    static boolean jumpGame(int [] nums){
        memo = new HashMap<>();
        return helper(nums,0);
    }
    public static void main(String args[]){
        int nums[] = {2,3,1,1,4};
        System.out.println(jumpGame(nums));
    }
}
