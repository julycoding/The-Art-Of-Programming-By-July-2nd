import java.math.BigInteger;

class PrimeCompare implements ICompare {
    
    @Override
    public boolean compare(String longString, String shortString) {
        BigInteger product = new BigInteger("1");

        for (int i = 0; i < longString.length(); i++) {
            int index = longString.charAt(i) - 'A';
            product = product.multiply(BigInteger.valueOf(primeTable[index]));
        }
        
        for (int j = 0; j < shortString.length(); j++) {
            int index = shortString.charAt(j) - 'A';
            BigInteger prime = BigInteger.valueOf(primeTable[index]);
            if (!(product.mod(prime).equals(BigInteger.ZERO))) {
                return false;
            } 
        }
        return true;
    }

    private long[] primeTable = new long[]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
}
