#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> g;

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        g.resize(n);
        for (int i = 0; i < n - 1; ++i) {
            g[i].emplace_back(i + 1, 1);
        }
        vector<int> res;

        for (auto it : queries) {
            g[it[0]].emplace_back(it[1], 1);
            res.push_back(dijkstra(n));
        }
        return res;
    }

    int dijkstra(int n) {
        vector<int> dist(n, 1e9);
        vector<bool> st(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        dist[0] = 0;
        heap.push({0, 0});

        while (!heap.empty()) {
            auto [d, t] = heap.top();
            heap.pop();

            if (st[t]) continue;

            st[t] = true;

            for (auto [j, weight] : g[t]) {
                if (dist[j] > dist[t] + weight) {
                    dist[j] = dist[t] + weight;
                    heap.push({dist[j], j});
                }
            }
        }

        if (dist[n-1] == 1e9) return -1;
        return dist[n-1];
    }
};
