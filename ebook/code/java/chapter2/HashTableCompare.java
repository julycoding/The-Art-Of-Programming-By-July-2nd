class HashTableCompare implements ICompare {
    @Override
    public boolean compare(String longString, String shortString) {
        int[] hash = new int[26];
        
        int num = 0;

        for (int j = 0; j < shortString.length(); j++) {
            int index = shortString.charAt(j) - 'A';
            if (hash[index] == 0) {
                num++;
            }
            hash[index]++;
        }

        for (int k = 0; k < longString.length(); k++) {
            int index = longString.charAt(k) - 'A';
            hash[index]--;
            if (hash[index] == 0) {
               num--;
               if (num == 0) {
                    break;
               }
            }
        }

        return num == 0;
    }    

}
