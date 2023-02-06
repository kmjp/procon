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
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> A,B;
        ll mi=1<<30;
        FORR(b,basket1) A[b]++;
        FORR(b,basket2) {
			if(A[b]) {
				A[b]--;
				mi=min(mi,(ll)b);
			}
			else B[b]++;
		}
		vector<ll> C;
		int i;
		FORR(e,A) {
			if(e.second%2) return -1;
			FOR(i,e.second/2) C.push_back(e.first);
		}
		FORR(e,B) {
			if(e.second%2) return -1;
			FOR(i,e.second/2) C.push_back(e.first);
		}
		sort(ALL(C));
		ll ret=0;
		FORR(e,C) cout<<e<<endl;
		FOR(i,C.size()/2) {
			ret+=min(mi*2,C[i]);
			mi=min(mi,C[i]);
		}
		return ret;
		
		
    }
};
