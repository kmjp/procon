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
    int minTime(string s, vector<int>& order, int k) {
        ll sum=0;
        int N=s.size();
        set<int> S={-1,N};
        int i;
        FOR(i,N) {
			int x=order[i];
			S.insert(x);
			auto it=S.find(x);
			int a=*prev(it);
			int b=*next(it);
			sum+=1LL*(x-a)*(b-x);
			if(sum>=k) return i;
		}
		return -1;
    }
};
