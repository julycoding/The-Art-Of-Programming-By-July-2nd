import java.util.Arrays;

class SortAndCompare implements ICompare {
    @Override
    public boolean compare(String longString, String shortString) {
        char[] longStr = longString.toCharArray();
        char[] shortStr = shortString.toCharArray();
        Arrays.sort(longStr);
        Arrays.sort(shortStr);

        int posShort = 0, posLong = 0;
        while (posShort < shortStr.length && posLong < longStr.length) {
            while (posLong < longStr.length && longStr[posLong] < shortStr[posShort]) {
                posLong++;
            }

            if (posLong == longStr.length || longStr[posLong] != shortStr[posShort]) {
                break;
            }
            
            posShort++;
        }
        return posShort == shortStr.length;
    }
}
