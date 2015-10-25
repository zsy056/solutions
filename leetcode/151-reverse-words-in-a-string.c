void reverseWords(char *s) {
    int n = strlen(s);
    if (n == 0)
        return;
    int i = 0, j = 0;
    while (j < n && isspace(s[j]))
        ++j;
    while (j < n) {
        if (!isspace(s[j]) || j == 0 || !isspace(s[j-1])) {
            s[i] = s[j];
            ++i;
        }
        ++j;
    }
    n = i > 0 && isspace(s[i-1]) ? i - 1 : i;
    s[n] = '\0';
    for (int k = 0; k < n-k-1; ++k) {
        char tmp = s[k];
        s[k] = s[n-k-1];
        s[n-k-1] = tmp;
    }
    i = 0, j = 0;
    while (j < n) {
        while (j < n && !isspace(s[j]))
            ++j;
        for (int k = 0; i+k < j-k-1; ++k) {
            char tmp = s[i+k];
            s[i+k] = s[j-k-1];
            s[j-k-1] = tmp;
        }
        ++j;
        i = j;
    }
}
