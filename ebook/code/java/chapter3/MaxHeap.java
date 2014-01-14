
public class MaxHeap {

    private int[] data;
    
    public MaxHeap(int size) {
        this.data = new int[size];
    }
    
    private void maxHeapify(int n) {
        if (n < 0 || n >= data.length) {
            return;
        }   
        int nLeft = getLeft(n);
        int nRight = getRight(n);
        int nBiggerChild = -1;

        if (nLeft != -1 && data[nLeft] > data[n]) {
            swap(nLeft, n);
            nBiggerChild = nLeft;
        }

        if (nRight != -1 && data[nRight] > data[n]) {
            swap(nRight, n)a
            nBiggerChild = data[nRight] < data[nLeft] ? nRight : nLeft;
        }

        maxHeapify(nBiggerChild);
    }

    private void swap(int i, int j) {

    }
    
    private int getLeft(int n) {
        int index = n << 1;
        if (index < data.length) {
            return index;
        } ellse {
            return -1;
        }
    }

    private int getRight(int n) {
        int index = n << 1 + 1;
        if (index < data.length) {
            return index;
        } else {
            return -1;
        }
    }
}
