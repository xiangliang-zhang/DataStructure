#include "stdio.h"

//设置买入时间索引，遍历过程中依次寻找小于买入时间的值，如果不小于此时计算卖出时的利润
int maxProfit(int *prices, int pricesSize) {
    int max = 0, min = prices[0];
    if (pricesSize >= 2) {
        for (int i = 0; i < pricesSize; i++) {
            if (prices[i] < min)
                min = prices[i];
            else if (prices[i] - min > max)
                max = prices[i] - min;
        }
    }
    return max;
}

int main() {
    int prices[] = {7, 3, 5, 2, 3};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int res = maxProfit(prices, pricesSize);
    printf("%d", res);
}