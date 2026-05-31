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

int C[202020];
int num[202020];

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
		int i,j,N=items.size();
		FOR(i,N+1) C[i]=num[i]=0;
		FORR(v,items) C[v[0]]++;
		
		for(i=1;i<=N;i++) {
			for(j=i;j<=N;j+=i) num[i]+=C[j];
		}
		vector<pair<int,int>> V;
		int mi=1<<30;
		FORR(v,items) {
			V.push_back({v[1],num[v[0]]-1});
			mi=min(mi,v[1]);
		}
		sort(ALL(V));
		ll ret=0;
		FORR2(a,b,V) if(a<=2*mi) {
			ll step=min(b,budget/a);
			ret+=step*2;
			budget-=a*step;
		}
		ret+=budget/mi;
		return ret;
		
		
        
    }
};

