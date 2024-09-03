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
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
		multiset<ll> V;
		int i;
		FOR(i,k) V.insert(1LL<<60);
		vector<int> R;
		FORR(q,queries) {
			int x=abs(q[0])+abs(q[1]);
			V.insert(x);
			V.erase(V.find(*V.rbegin()));
			if(*V.rbegin()==1LL<<60) R.push_back(-1);
			else R.push_back(*V.rbegin());
			
		}
        return R;
    }
};

