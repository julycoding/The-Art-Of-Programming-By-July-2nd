class CountAndCompare implements ICompare {
    @Override
    public boolean compare(String longString, String shortString) {
        int posLong = 0, posShort = 0;
        longString = countSort(longString);
        shortString = countSort(shortString);
        while (posLong < longString.length() && posShort < shortString.length()) {
            while (posLong < longString.length() && longString.charAt(posLong) < shortString.charAt(posShort)) {
                posLong++;
            }

            if (posLong >= longString.length() || longString.charAt(posLong) != shortString.charAt(posShort)) {
                return false;
            } else {
                posShort++;
            }
        }
        return posShort == shortString.length();
    }

    private String countSort(String str) {
        int[] help = new int[26];
        for (int i = 0; i < str.length(); i++) {
            int index = str.charAt(i) - 'A';
            help[index]++;
        }
        StringBuilder buf = new StringBuilder();
        for (int i = 0; i < 26; i++) {
           for (int j = 0; j < help[i]; j++) {
               buf.append((char)(i + (int)'A'));
           } 
        }
        return buf.toString();
    }


}
