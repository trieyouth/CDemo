//
// Created by dongcan.cdc on 2022/3/18.
//

#ifndef CDEMO_LONGESTPALINDROME_H
#define CDEMO_LONGESTPALINDROME_H

#include <string>

using namespace std;

namespace yujiu {
    class LongestPalindrome {
    public:
        string longestPalindrome(string s);

        bool isPalindrome(string basicString, int i, int j, byte flags[]);
    };
}


#endif //CDEMO_LONGESTPALINDROME_H
