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
    int minimumDeletions(string S, int k) {
		map<int,int> M;
		FORR(c,S) M[c]++;
		vector<int> V;
		FORR(m,M) V.push_back(m.second);
		sort(ALL(V));
		
		
		int mi=1<<30;
		int x,y;
		FOR(x,V.size()) {
			int co=0;
			FOR(y,V.size()) {
				if(V[y]<V[x]) co+=V[y];
				if(V[y]>V[x]+k) co+=V[y]-(V[x]+k);
			}
			mi=min(mi,co);
		}
		return mi;
		
        
    }
};
