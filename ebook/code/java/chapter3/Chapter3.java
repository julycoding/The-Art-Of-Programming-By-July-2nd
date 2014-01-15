import java.util.Arrays;

public class Chapter3 {

    public static void main(String[] args) {
        int[] data = new int[]{9, 8, 6, 4, 1, 2, 3, 5, 11, 0};
        int k = 3;
        
        System.out.println("input: " + Arrays.toString(data));
        System.out.println("k: " + k);

        System.out.println("\r\n Using MaxHeap:");
        IFindMinK solution1 = new HeapSolution();
        int[] answer = solution1.findMinK(data, k);
        System.out.println(Arrays.toString(answer));
    }

}
