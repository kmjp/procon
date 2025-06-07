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
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
		map<int,int> M;
		int i;
		FOR(i,x.size()) M[x[i]]=max(M[x[i]],y[i]);
		vector<int> V;
		FORR(a,M) V.push_back(a.second);
		sort(ALL(V));
		reverse(ALL(V));
		if(V.size()<3) return -1;
		return V[0]+V[1]+V[2];
        
    }
};


