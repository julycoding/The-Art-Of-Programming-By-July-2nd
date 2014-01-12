class Chapter2 {
    public static void main (String[] args) {
        ICompare sortAndCompare = new SortAndCompare();
        System.out.println(sortAndCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(sortAndCompare.compare("abcd", "efg"));
    
        ICompare countAndCompare = new CountAndCompare();
        System.out.println(countAndCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(countAndCompare.compare("ASDF", "GHJK"));

        ICompare hashTableCompare = new HashTableCompare();
        System.out.println(hashTableCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(hashTableCompare.compare("ASDF", "GHJK"));
       
        ICompare primeCompare = new PrimeCompare();
        System.out.println(primeCompare.compare("ABCDEFGHLMNOPQRS", "DCGSRQPOM"));
        System.out.println(primeCompare.compare("ASDF", "GHJK"));
       
    }
}
