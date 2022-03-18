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
        byte flag[length * length];
        for (int i = 0; i < s.length(); i++) {
            for (int j = s.length() - 1; j >= 0; j--) {
                flag[i * length + j] = (byte) 0;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s, i, j, flag)) {
                    if (j - i > longest) {
                        begin = i;
                        end = j;
                        longest = j - i;
                    }
                }else{

                }
            }
        }
        return s.substr(begin, (end - begin) + 1);
    }

    bool LongestPalindrome::isPalindrome(string s, int begin, int end, byte flags[]) {
//        while (begin <= end) {
//            if (s[begin] != s[end]) {
//                return false;
//            }
//            begin++;
//            end--;
//        }
//        return true;
        int idx = s.length() * begin + end;

        if (flags[idx] == (byte) -1) {
            return false;
        }

        if (flags[idx] == (byte) 1) {
            return true;
        }

        if (begin == end) {
            flags[idx] = (byte) 1;
            return true;
        }

        if (end - begin == 1) {
            if (s[begin] == s[end]) {
                flags[idx] = (byte) 1;
                return true;
            } else {
                flags[idx] = (byte) -1;
                return false;
            }
        }

        if (isPalindrome(s, begin + 1, end - 1, flags) && s[begin] == s[end]) {
            flags[idx] = (byte) 1;
            return true;
        }
        flags[idx] = (byte) -1;
        return false;
    }
}
