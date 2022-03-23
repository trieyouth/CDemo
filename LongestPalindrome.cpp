//
// Created by dongcan.cdc on 2022/3/18.
//
#include <iostream>
#include "LongestPalindrome.h"

using namespace std;

namespace yujiu {
    string LongestPalindrome::longestPalindrome(string s) {
        int length = s.length();
        if (length <= 1) {
            return s;
        }
        int begin = 0;
        int end = 0;
        int longest = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i > longest) {
                        begin = i;
                        end = j;
                        longest = j - i;
                        break;
                    }
                }
            }
        }
        return s.substr(begin, (end - begin) + 1);
    }

    bool LongestPalindrome::isPalindrome(string s, int begin, int end) {
        while (begin <= end) {
            if (s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
}
