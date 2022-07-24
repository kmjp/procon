#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int i;
        FOR(i,5) if(suits[i]!=suits[0]) break;
        if(i==5) return "Flush";
        sort(ALL(ranks));
        if(ranks[0]==ranks[1]&&ranks[1]==ranks[2]) return "Three of a Kind";
        if(ranks[1]==ranks[2]&&ranks[2]==ranks[3]) return "Three of a Kind";
        if(ranks[2]==ranks[3]&&ranks[3]==ranks[4]) return "Three of a Kind";
        if(ranks[0]==ranks[1]) return "Pair";
        if(ranks[1]==ranks[2]) return "Pair";
        if(ranks[2]==ranks[3]) return "Pair";
        if(ranks[3]==ranks[4]) return "Pair";
        return "High Card";
    }
};
