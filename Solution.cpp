#include <cmath>
#include <climits>
#include <iostream>
#include "Solution.h"
//
// Created by dongcan.cdc on 2022/3/18.
//

int Solution::reverse(int x) {
    if (x == 0) {
        return 0;
    }
    bool xIsN = x < 0;
    int num = abs(x);
    int res = 0;
    int max = INT_MAX / 10;
    int tmp = INT_MAX % 10;
    while (num > 0) {
        if (res > max) {
            return 0;
        }
        if (res == max && num % 10 > tmp) {
            return 0;
        }
        res = res * 10 + num % 10;
        num = num / 10;
    }
    return xIsN ? -1 * res : res;
}
