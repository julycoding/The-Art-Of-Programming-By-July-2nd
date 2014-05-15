public class Chapter6 {

    // Solution 1. factor-array
    public void findAmicableNumber_1() {
        int[] sum = new int[5000010];
        int i, j;
        for (i = 0; i <= 5000000; ++i) {
            sum[i] = 1;
        }
        for (i = 2; i + i < 5000000; ++i) {
            j = i + i;
            while (j <= 5000000) {
                sum[j] += i;
                j += i;
            }
        }
        // start with 220, beacause we know the first pair is (220, 284)
        for (i = 220; i <= 5000000; ++i) {
            // we have to care about the duplicate pair
            if (sum[i] > i && sum[i] <= 5000000 && sum[sum[i]] == i) {
                System.out.println(i + "," + sum[i]);
            }
        }
    }

    public static void main(String[] argv) {
        Chapter6 solutions = new Chapter6();
        System.out.println("1. factor-array solution:");
        solutions.findAmicableNumber_1();

    }
}
