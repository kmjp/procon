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
    bool isItPossible(string word1, string word2) {
		int C[26][2]={};
		FORR(c,word1) C[c-'a'][0]++;
		FORR(c,word2) C[c-'a'][1]++;
		int a,b;
		FOR(a,26) FOR(b,26) if(C[a][0]&&C[b][1]) {
			C[a][0]--;
			C[b][0]++;
			C[b][1]--;
			C[a][1]++;
			int i,x=0;
			FOR(i,26) if(C[i][0]>0) x++;
			FOR(i,26) if(C[i][1]>0) x--;
			if(x==0) return 1;
			C[a][1]--;
			C[b][1]++;
			C[b][0]--;
			C[a][0]++;
		}
		return 0;
        
    }
};
