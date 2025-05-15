#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T>
istream &operator>>(istream &is, vector<T> &V)
{
    for (auto &e : V)
        is >> e;
    return is;
}
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> const &val) { return (out << "(" << val.first << "," << val.second << ") "); }
template <class T>
ostream &operator<<(ostream &out, ordered_set<T> const &S)
{
    out << "{ ";
    for (const auto &s : S)
        out << s << " ";
    return (out << "}");
}
template <typename CharT, typename Traits, typename T>
ostream &_containerprint(basic_ostream<CharT, Traits> &out, T const &val) { return (out << val << " "); }
template <typename L, size_t N>
ostream &operator<<(ostream &out, array<L, N> const &cont)
{
    out << "[ ";
    for (auto &&elem : cont)
        _containerprint(out, elem);
    return (out << "]");
}
template <typename T>
ostream &operator<<(ostream &out, queue<T> q)
{
    out << "[";
    while (!q.empty())
    {
        out << q.front();
        q.pop();
        if (!q.empty())
            out << ", ";
    }
    return out << "]";
}
template <typename CharT, typename Traits, typename T1, typename T2>
ostream &_containerprint(basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) { return (out << "(" << val.first << "," << val.second << ") "); }
template <class L, class R, class chash = hash<L>>
ostream &operator<<(ostream &out, gp_hash_table<L, R, chash> const &M)
{
    out << "{ ";
    for (const auto &m : M)
        out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template <class P, class Q = vector<P>, class R = less<P>>
ostream &operator<<(ostream &out, priority_queue<P, Q, R> const &M)
{
    priority_queue<P, Q, R> U = M;
    out << "{ ";
    while (!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template <typename CharT, typename Traits, template <typename, typename...> class TT, typename... Args>
ostream &operator<<(basic_ostream<CharT, Traits> &out, TT<Args...> const &cont)
{
    out << "[ ";
    for (auto &&elem : cont)
        _containerprint(out, elem);
    return (out << "]");
}
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...) 6
#endif
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x)
{
    bool first = true;
    cerr << '{';
    for (const auto &i : x)
    {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p)
{
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t)
{
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args)
          { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s)
{
    vector<T> debugVector;
    while (!s.empty())
    {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T, size_t N>
void _print(const T (&arr)[N]) {
    cerr << "[";
    for (size_t i = 0; i < N; ++i) {
        cerr << arr[i];
        if (i != N - 1) cerr << ", ";
    }
    cerr << "]";
}
template <typename T>
void __print(queue<T> q)
{
    vector<T> debugVector;
    while (!q.empty())
    {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q)
{
    vector<T> debugVector;
    while (!q.empty())
    {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T)
{
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...)                                                  \
    cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define debug(...)
#endif
