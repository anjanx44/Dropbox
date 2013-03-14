// Is the String a palindrome?
boolean palindrome(String word) {
    int i = 0, j = word.length()- 1;
    while (i < j) {
        if (word.charAt(i++) != word.charAt(j--)) {
            return false;
        }
    }
    return true;
}