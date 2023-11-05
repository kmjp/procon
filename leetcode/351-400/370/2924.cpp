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

int L[101];

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
		ZERO(L);
		FORR(e,edges) L[e[1]]++;
		vector<int> C;
		int i;
		FOR(i,n) if(L[i]==0) C.push_back(i);
		if(C.size()==1) return C[0];
		return -1;
		
        
    }
};

