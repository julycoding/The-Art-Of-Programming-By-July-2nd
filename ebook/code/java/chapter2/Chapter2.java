class Chapter2 {
    public static void main (String[] args) {
        System.out.println("QuickSort and Compare:");
        ICompare sortAndCompare = new SortAndCompare();
        System.out.println(sortAndCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(sortAndCompare.compare("ASDF", "GHJK"));
    
        System.out.println("Counting Sort and Compare:");
        ICompare countAndCompare = new CountAndCompare();
        System.out.println(countAndCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(countAndCompare.compare("ASDF", "GHJK"));

        System.out.println("Using HashTable:");
        ICompare hashTableCompare = new HashTableCompare();
        System.out.println(hashTableCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(hashTableCompare.compare("ASDF", "GHJK"));
       
        System.out.println("Using Prime Product and Mode:");
        ICompare primeCompare = new PrimeCompare();
        System.out.println(primeCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(primeCompare.compare("ASDF", "GHJK"));
       
    }
}
