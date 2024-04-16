package leetcode;

/*

34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class FindFirst34 {
    public static void main(String[] args) {

    }
}

class Solution {
    public int[] searchRange(int[] nums, int target) {
        List<Integer> lst = Arrays.stream(nums)
                .boxed()
                .collect(Collectors.toList());

        Integer s = -1;
        Integer e = -1;


        for(int i = 0; i < lst.size(); i++) {
            if(lst.get(i) == target) {
                if(s == -1) {
                    s = i;
                }
                e = i;
            }
        }

        List<Integer> res = new ArrayList<>();
        res.add(s);
        res.add(e);

        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
