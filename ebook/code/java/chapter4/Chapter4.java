import java.util.Arrays;
import java.util.HashMap;

public class Chapter4 {

    // Solution 1. Brute force
    public Pair findSum_1(int[] data, int sum) {
        for (int i = 0; i < data.length - 1; ++i) {
            for (int j = i + 1; j < data.length; ++j) {
                if (data[i] + data[j] == sum) {
                    Pair ans = new Pair(data[i], data[j]);
                    return ans;
                }
            }
        }
        return new Pair(-1, -1);
    }

    // Solution 2. Sort and binary search
    public Pair findSum_2(int[] data, int sum) {
        Arrays.sort(data);
        for (int i = 0; i < data.length; ++i) {
            int num1 = data[i];
            int num2 = sum - data[i];
            // get the position of num2 in the array
            int num2Pos = binarySearch(data, num2);
            // we have to care about the duplicate number
            if (num2Pos != -1 && num2Pos != i) {
                Pair ans = new Pair(num1, num2);
                return ans;
            }
        }
        return new Pair(-1, -1);
    }

    public int binarySearch(int[] data, int target) {
        int left = 0;
        int right = data.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] > target) {
                right = right - 1;
            } else if (data[mid] < target) {
                left = left + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    // Solution 3. two-array
    public Pair findSum_3(int[] data, int sum) {
        int[] data2 = new int[data.length];
        for (int i = 0; i < data.length; ++i) {
            data2[i] = sum - data[i];
        }
        int left = 0;
        int right = data.length - 1;
        while (left < data.length && right >= 0) {
            // we have to care about the duplicate number
            if (data[left] == data2[right] && left != right) {
                int num1 = data[left];
                int num2 = sum - num1;
                Pair ans = new Pair(num1, num2);
                return ans;
            } else if (data[left] > data2[right])
                right--;
            else
                left++;
        }
        return new Pair(-1, -1);

    }

    // Solution 4. Hashmap
    public Pair findSum_4(int[] data, int sum) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        // count every element
        for (int i = 0; i < data.length; ++i) {
            if (!map.containsKey(data[i]))
                map.put(data[i], 1);
            else
                map.put(data[i], map.get(data[i]) + 1);
        }
        for (int i = 0; i < data.length; ++i) {
            int num1 = data[i];
            int num2 = sum - data[i];
            if (map.containsKey(num2)) {
                // we have to care about the duplicate number
                if (num1 == num2 && map.get(num2) >= 2) {
                    Pair ans = new Pair(num1, num2);
                    return ans;
                } else if (num1 != num2) {
                    Pair ans = new Pair(num1, num2);
                    return ans;
                }
            }
        }
        return new Pair(-1, -1);
    }

    // Solution 5. two-pointer
    public Pair findSum_5(int[] data, int sum) {
        Arrays.sort(data);
        int begin = 0;
        int end = data.length - 1;
        while (end > begin) {
            long current_sum = data[begin] + data[end];
            if (current_sum == sum) {
                Pair ans = new Pair(data[begin], data[end]);
                return ans;
            } else if (current_sum > sum) {
                end--;
            } else {
                begin++;
            }
        }
        return new Pair(-1, -1);
    }

    public static void main(String[] argv) {
        Chapter4 solutions = new Chapter4();

        int[] data = new int[] { 1, 2, 4, 7, 11, 15 };
        int target = 15;
        Pair ans = null;

        System.out.println("input: " + Arrays.toString(data));
        System.out.println("sum: " + target);

        System.out.println("1.Brute force solution:");
        ans = solutions.findSum_1(data, target);
        System.out.println(ans);

        System.out.println("2.Sort and binary search solution:");
        ans = solutions.findSum_2(data, target);
        System.out.println(ans);

        System.out.println("3.Two-array solution:");
        ans = solutions.findSum_3(data, target);
        System.out.println(ans);

        System.out.println("4.HashMap solution:");
        ans = solutions.findSum_4(data, target);
        System.out.println(ans);

        System.out.println("5.Two-pointer solution:");
        ans = solutions.findSum_5(data, target);
        System.out.println(ans);
    }
}

class Pair {
    private int num1;
    private int num2;

    public Pair(int num1, int num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    public int getNum1() {
        return num1;
    }

    public void setNum1(int num1) {
        this.num1 = num1;
    }

    public int getNum2() {
        return num2;
    }

    public void setNum2(int num2) {
        this.num2 = num2;
    }

    public String toString() {
        return "first_num is " + num1 + " , second_num is " + num2;
    }
}
