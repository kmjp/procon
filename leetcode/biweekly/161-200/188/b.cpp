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
    int maximumWidth(vector<int>& planks) {
		map<int,int> C,tot;
		int x,y;
		int N=planks.size();
		FOR(x,N) {
			int v=planks[x];
			C[v]++;
			tot[v]++;
			
			if(C[v]%2==0) tot[v+v]++;
			FORR2(a,b,C) if(a!=v&&b>=C[v]) tot[a+v]++;
		}
		int ma=0;
		FORR2(a,b,tot) ma=max(ma,b);
		return ma;
		
        
    }
};
