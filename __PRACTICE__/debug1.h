#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OS;

namespace Color {
    enum Code {
        FG_RED     = 31,
        FG_YELLOW  = 33,
        FG_BLUE    = 34,
        FG_GREEN   = 32,
        FG_DEFAULT = 39
    };
    class ColorDebugger {
        Code code;
        public:
        ColorDebugger(Code pCode) : code(pCode) {}
        template <class T>
        ColorDebugger& operator<<(const T &other) {
            cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
            return *this;
        }
        ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
            (*pManip)(cout);
            return *this;
        }
    };
}

using namespace Color;
// ColorDebugger ycout(FG_YELLOW);
// ColorDebugger ycout(FG_RED);
// ColorDebugger ycout(FG_BLUE);
ColorDebugger ycout(FG_GREEN);

#define print_OS(S) { for(auto i : S){cout << i << " ";} cout << endl;}

#define debug(x) ycout << #x <<" = "; _print(x); ycout << endl;

void _print(int t) {ycout << t;}
void _print(unsigned long long x) {ycout << x;}
void _print(float x) {ycout << x;}
void _print(double t) {ycout << t;}
void _print(long double t) {ycout << t;}

void _print(char x) {ycout << '\'' << x << '\'';}
void _print(const char *x) {ycout << '\"' << x << '\"';}
void _print(const string &x) {ycout << '\"' << x << '\"';}
void _print(bool x) {ycout << (x ? "true" : "false");}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(deque <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {ycout << "{"; _print(p.first); ycout << ","; _print(p.second); ycout << "}";}
template <class T> void _print(vector <T> v) {ycout << "[ "; for (T i : v) {_print(i); ycout << " ";} ycout << "]";}
template <class T> void _print(deque <T> v) {ycout << "[ "; for (T i : v) {_print(i); ycout << " ";} ycout << "]";}
template <class T> void _print(set <T> v) {ycout << "[ "; for (T i : v) {_print(i); ycout << " ";} ycout << "]";}
template <class T> void _print(multiset <T> v) {ycout << "[ "; for (T i : v) {_print(i); ycout << " ";} ycout << "]";}
template <class T, class V> void _print(map <T, V> v) {ycout << "[ "; for (auto i : v) {_print(i); ycout << " ";} ycout << "]";}
