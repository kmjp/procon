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
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
		unordered_set<int> A;
		int ma=-1;
		hFences.push_back(1);
		hFences.push_back(m);
		vFences.push_back(1);
		vFences.push_back(n);
		FORR(a,hFences) FORR(b,hFences) if(b>a) A.insert(b-a);
		FORR(a,vFences) FORR(b,vFences) if(b>a&&A.count(b-a)) ma=max(ma,b-a);
		
		if(ma==-1) return -1;
		return 1LL*ma*ma%1000000007;
		
        
    }
};
