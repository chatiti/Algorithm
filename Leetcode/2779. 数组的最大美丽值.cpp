#include <bits/stdc++.h>

using namespace std;

//事件扫描法 计算最大的区间重叠数，左端点+1，右端点-1，先-再+;注意右边区间+1
//1. 定义事件
//对于每个元素 num，可以将其转换为范围 [num - k, num + k] 内的任意值。因此，我们可以将这个范围表示为两个事件：
//
//一个是范围的开始事件，位置为 num - k，权重为 +1。
//另一个是范围的结束事件，位置为 num + k + 1，权重为 -1。
//这些事件记录在 events 向量中。
//
//2. 排序事件
//将所有事件按位置排序。如果两个事件的位置相同，则结束事件（权重为 -1）排在前面。这是因为我们希望在同一个位置，先处理结束事件以正确维护重叠区间的计数。
//
//3. 扫描事件
//遍历排序后的事件，维护当前重叠区间的计数 currentBeauty，并记录最大的重叠区间数 maxBeauty。

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        vector<pair<int, int>> events;

        for (auto it: nums) {
            events.emplace_back(it - k, 1);
            events.emplace_back(it + k+1, -1);
        }
        std::sort(events.begin(), events.end());
        int res = 0;
        int count = 0;
        for (auto it: events) {
            count += it.second;
            res = max(res, count);
        }

        return res;
    }
};
