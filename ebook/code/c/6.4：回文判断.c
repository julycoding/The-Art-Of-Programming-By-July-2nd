//解法一
/**  
 *check weather s is a palindrome, n is the length of string s 
 *Copyright(C) fairywell 2011 
 */  
bool IsPalindrome(const char *s, int n)  
{  
    if (s == NULL || n < 1) return false; // invalid string  
    char *front, *back;  
    front = s; back = s + n - 1; // set front and back to the begin and endof the string  
    while (front < back) {  
        if (*front != *back) return false; // not a palindrome  
        ++front; --back;  
    }  
    return true; // check over, it's a palindrome  
}  


//解法二
/**  
 *check weather s is a palindrome, n is the length of string s 
 *Copyright(C) fairywell 2011 
 */  
bool IsPalindrome2(const char *s, int n)  
{  
    if (s == NULL || n < 1) return false; // invalid string  
    char *first, *second;  
    int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0; // m is themiddle point of s      
    first = s + m; second = s + n - 1 - m;  
    while (first >= s)  
        if (s[first--] != s[second++]) return false; // not equal, so it's not apalindrome  
    return true; // check over, it's a palindrome  
} 


//问题扩展
/**  
 *find the longest palindrome in a string, n is the length of string s 
 *Copyright(C) fairywell 2011 
 */  
int LongestPalindrome(const char *s, int n)  
{
    int i, j, max;  
    if (s == 0 || n < 1) return 0;  
    max = 0;  
    for (i = 0; i < n; ++i) { // i is the middle point of the palindrome  
        for (j = 0; (i-j >= 0) && (i+j < n); ++j) // if the lengthof the palindrome is odd  
            if (s[i-j] != s[i+j]) break;  
        if (j*2+1 > max) max = j * 2 + 1;  
        for (j = 0; (i-j >= 0) && (i+j+1 < n); ++j) // for theeven case  
            if (s[i-j] != s[i+j+1]) break;  
        if (j*2+2 > max) max = j * 2 + 2;  
    }  
    return max;  
}  
