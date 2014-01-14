/**
 * a simple max heap with fixed length
 **/

import java.util.Arrays;

public class MaxHeap {
    
    private int[] data;
    private int size = 0;

    public MaxHeap(int capacity) {
        data = new int[capacity];
        Arrays.fill(data, Integer.MAX_VALUE);
    }
    
    // return all the element in the heap
    public int[] getAll() {
        return Arrays.copyOfRange(data, data.length - size, data.length);
    }

    public void insert(int m) {
        if (data.length > 0 && m < data[0]) { // only if the element is less than the heap top, we will do the insertion
            data[0] = m;
            maxHeapify(0);
            if (size < data.length) {
                size++;
            }
        }
    }    

    private void maxHeapify(int n) {
        if (n < 0 || n >= data.length) {
            return;
        }   
        int nLeft = n * 2;
        int nRight = n * 2 + 1;
        int pLargest = n;

        if (nLeft < data.length && data[pLargest] < data[nLeft]) {
            pLargest = nLeft;
        }

        if (nRight < data.length && data[pLargest] < data[nRight]) {
            pLargest = nRight;
        }
        if (pLargest != n) {
            swap(pLargest, n);
            maxHeapify(pLargest);
        }
    }

    private void swap(int i, int j) {
        int temp = data[j];
        data[j] = data[i];
        data[i] = temp;
    }
}
