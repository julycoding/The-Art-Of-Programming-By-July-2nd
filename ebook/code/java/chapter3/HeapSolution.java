class HeapSolution implements IFindMinK {

    @Override
    public int[] findMinK(int[] data, int k) {
        MaxHeap heap = new MaxHeap(k);
        for (int n : data) {
            heap.insert(n);
        }
        return heap.getAll();
    }
}
