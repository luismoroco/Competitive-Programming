#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/stringmatching

typedef int long long ll;

int 
main(int argc, char const *argv[]) {
    size_t a = 0, b = 0;
    char *pattern = NULL, *text = NULL;
    ssize_t p_len = 0, t_len = 0;
    while ((p_len = getline(&pattern, &a, stdin)) >= 0 && (t_len = getline(&text, &b, stdin)) >= 0) {
        int pl = p_len-1, tl = t_len-1;
        int suf[pl], len = 0, i = 1, j = 0, first = 1;
        suf[0] = 0;
        while (i < pl) { 
            if (pattern[i] == pattern[len]) suf[i++] = ++len;
            else if (len) len = suf[len-1];
            else suf[i++] = 0;
        }
        i = 0;
        while (i < tl) { 
            if (pattern[j] == text[i]) { 
                j++; i++; 
            } 
            if (j == pl) {
                if (first) first = 0;
                else putchar(' ');
                printf("%d", i-j);
                j = suf[j - 1]; 
            } else if (i < tl && pattern[j] != text[i]) { 
                if (j) j = suf[j-1]; 
                else i++; 
            } 
        } 
        putchar('\n');
        free(pattern);
        free(text);
        a = 0;
        b = 0;
    }
    return 0;
}