#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u;
    int v;
    long long c;
    Edge() {}
    Edge(int u, int v, long long c): u(u), v(v), c(c) {}
};

struct PqEle {
    int u;
    int num;
    long long content;
    PqEle() {}
    PqEle(int u, int num, long long content): u(u), num(num), content(content) {}
    bool operator <(const PqEle& o) const {
        return make_pair(num, content) > make_pair(o.num, o.content);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto t0 = clock();
    int n, m;
    long long l;
    cin >> n >> m >> l;
    vector<vector<Edge>> adj_list(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a;
        --b;
        if (c <= l) {
            adj_list[a].push_back(Edge(a, b, c));
            adj_list[b].push_back(Edge(b, a, c));
        }
    }
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].first;
        --queries[i].second;
    }
    auto dijkstra = [&](int start_id) {
        priority_queue<PqEle> pq;
        pq.push(PqEle(start_id, 0, 0LL));
        vector<bool> visited(n, false);
        vector<int> dist(n, -1);
        while (!pq.empty()) {
            auto p = pq.top();
            int node_id = p.u;
            pq.pop();
            if (visited[node_id]) {
                continue;
            }
            dist[node_id] = p.num;
            visited[node_id] = true;
            for (auto& edge : adj_list[node_id]) {
                if (!visited[edge.v]) {
                    if (edge.c + p.content > l) {
                        pq.push(PqEle(edge.v, p.num + 1, edge.c));
                    } else {
                        pq.push(PqEle(edge.v, p.num, edge.c + p.content));
                    }
                }
            }
        }
        return dist;
    };
    vector<vector<int>> dists(n);
    for (int i = 0; i < n; ++i) {
        dists[i] = dijkstra(i);
    }
    for (auto q : queries) {
        cout << dists[q.first][q.second] << "\n";
    }
    cerr << "time used = " << (clock() - t0) << endl;
    return 0;
}
