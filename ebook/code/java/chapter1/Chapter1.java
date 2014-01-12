class Chapter1 {
    
    // Version 1
    public void leftShiftV1 (char[] s, int m) {
        while (m > 0) {
            leftShiftOne(s);
            m--;
        }
    }

    private void leftShiftOne (char[] s) {
        int len = s.length;
        int i = 0;
        char c = s[0];
        while (i < len - 1) {
            s[i] = s[i + 1];
            i++;
        }
        s[len - 1] = c;
    }


    // Version2
    public void leftShiftV2(char[] s, int m) {
        int len = s.length;
        m = m % len;
        reverse(s, 0, m - 1);
        reverse(s, m, len - 1);
        reverse(s, 0, len - 1);
    }

    private void reverse (char[] s, int from, int to) {
        while(from < to) {
            char c = s[from];
            s[from] = s[to];
            s[to] = c;
            from++;
            to--;
        }
    }

    public static void main (String[] args) {
        Chapter1 chapter1 = new Chapter1();
        
        String str = "asdfghjkl";
        System.out.println("Original String:");
        System.out.println(str);
        char[] arr1 = str.toCharArray();
        char[] arr2 = str.toCharArray();

        chapter1.leftShiftV1(arr1, 2);
        chapter1.leftShiftV2(arr2, 2);
        
        System.out.println("Left shift V1:");
        System.out.println(new String(arr1));
        System.out.println("left Shift V2:");
        System.out.println(new String(arr2));
    }
}
