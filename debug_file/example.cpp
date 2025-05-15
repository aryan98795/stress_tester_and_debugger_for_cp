/*
NOTE:-It is unable to debug staic arrays like int arr[10].
*/
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
    // Basic types
    int x = 42;
    double y = 3.14;
    string s = "hello";

    // STL containers
    vector<int> vec = {1, 2, 3, 4};
    set<string> st = {"apple", "banana", "cherry"};
    map<int, string> mp = {{1, "one"}, {2, "two"}};
    pair<int, string> pr = {7, "seven"};
    tuple<int, string, double> tpl = {10, "ten", 10.5};

    // Stack, Queue, Priority Queue
    stack<int> stck;
    stck.push(1); stck.push(2);

    queue<string> q;
    q.push("a"); q.push("b");

    priority_queue<int> pq;
    pq.push(3); pq.push(1); pq.push(2);

    // Debug output
    debug(x, y, s);
    debug(vec);
    debug(st);
    debug(mp);
    debug(pr);
    debug(tpl);

    // For debugging stack, queue, and pq (convert to printable containers)
    vector<int> stack_dump;
    while (!stck.empty()) stack_dump.push_back(stck.top()), stck.pop();
    reverse(stack_dump.begin(), stack_dump.end());
    debug(stack_dump);

    vector<string> queue_dump;
    while (!q.empty()) queue_dump.push_back(q.front()), q.pop();
    debug(queue_dump);

    vector<int> pq_dump;
    while (!pq.empty()) pq_dump.push_back(pq.top()), pq.pop();
    debug(pq_dump);

    return 0;
}
