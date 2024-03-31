#include<bits/stdc++.h>
using namespace std;

struct comparator {
    bool operator ()(const pair<int, pair<int, char>>& p1, const pair<int, pair<int, char>>& p2) {
        return p1.first > p2.first;
    }
};

int maxprofit(map<int, vector<pair<int, char>>>& m) {
    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, comparator >pq;
    int ans = 0;
    for (auto x : m) {
        int curr = x.first;
        int size = (int)(x.second).size();
        for (int i = 0; i < size; i++) {
            if ((int)pq.size() < curr) {
                pq.push({ x.second[i].first,{x.first,x.second[i].second} });
                ans += x.second[i].first;
            }
            else if (pq.top().first < x.second[i].first) {
                ans -= pq.top().first;
                pq.pop();
                pq.push({ x.second[i].first,{x.first,x.second[i].second} });
                ans += x.second[i].first;
            }
        }
    }
    multimap<int, char> dl;
    while (!pq.empty()) {
        dl.insert(pq.top().second);
        pq.pop();
    }
    for (auto q : dl) {
        cout << q.second << ' ';
    }
    cout << endl;
    return ans;
}

int main() {
    int n;
    cin >> n;
    map<int, vector<pair<int, char>>> m;
    for (int i = 0; i < n; i++) {
        char c;
        int d, p;
        cin >> c >> d >> p;
         m[d].push_back({ p,c });
    }
    cout << maxprofit(m) << endl << endl;
    return 0;
}
