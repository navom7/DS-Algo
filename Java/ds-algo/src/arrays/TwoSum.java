package arrays;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TwoSum {
    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(10,5,2,3,-6,9,11);
        int targetSum = 4;
        Map<Integer, Boolean> mp = new HashMap<>();
        arr.forEach((Integer i) -> {
            if(mp.containsKey(targetSum - i)) {
                Integer key = targetSum-i;
                System.out.println(i + " " + key);
                return;
            }
            mp.put(i, true);
        });


    }
}
