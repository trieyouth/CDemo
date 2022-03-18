//
// Created by dongcan.cdc on 2022/3/18.
//

#include "Aoti.h"

using namespace std;

namespace yujiu {
    Aoti::Aoti(int s) {

    }

    int Aoti::myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        long res = 0;
        bool isNav = false;
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            i++;
            isNav = true;
        }
        if (!isNav && s[i] == '+') {
            i++;
        }
        for (; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                break;
            }
            int tmp = s[i] - '0';
            res = res * 10 + tmp;
            if (!isNav && res > INT_MAX) {
                return INT_MAX;
            }
            if (isNav && res * -1 < INT_MIN) {
                return INT_MIN;
            }
        }
        return isNav ? int (res * -1) : (int) res;
    }

}
