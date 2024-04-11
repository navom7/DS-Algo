package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SortAnArray {
    public static void main(String[] args) {
        List<Integer> integerList = Arrays.asList(1,2,3,5,62,1,2,3,5);

        Collections.sort(integerList);
        integerList.sort((Integer a, Integer b) -> b-a);
        integerList.forEach((Integer i) -> {
            System.out.println(i);
        });
    }
}
