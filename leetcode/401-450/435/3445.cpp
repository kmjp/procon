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

int S[5][303030];

class Solution {
public:
    int maxDifference(string s, int k) {
		int N=s.size();
		int i,j,a,b;
		FOR(j,5) {
			FOR(i,N) {
				S[j][i+1]=S[j][i]+(s[i]-'0'==j);
			}
		}
		int ma=-1<<30;
		FOR(a,5) FOR(b,5) if(a!=b) {
			set<int> C[2][2];
			int pre=0;
			for(i=1;i<=N;i++) {
				while(pre+k<=i&&S[b][pre]<S[b][i]) {
					C[S[a][pre]%2][S[b][pre]%2].insert(S[a][pre]-S[b][pre]);
					pre++;
				}
				
				if(C[(S[a][i]%2)^1][S[b][i]%2].size()) {
					ma=max(ma,S[a][i]-S[b][i]-*C[(S[a][i]%2)^1][S[b][i]%2].begin());
				}
			}
			
		}
		return ma;
			
		
        
    }
};


