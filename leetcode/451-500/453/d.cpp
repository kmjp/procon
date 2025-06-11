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

int dp[101][101][2];
int dp2[101];
class Solution {
public:
    int minOperations(string word1, string word2) {
		ZERO(dp);
		int N=word1.size();
		int L,R,i,x,rev;
		FOR(L,N) {
			for(R=L;R<N;R++) {
				FOR(rev,2) {
					int C[26][26]{};
					for(i=L;i<=R;i++) {
						int c1=word1[i]-'a';
						int c2=word2[rev?(R-(i-L)):i]-'a';
						
						if(c1==c2) continue;
						if(C[c1][c2]) {
							C[c1][c2]--;
						}
						else {
							C[c2][c1]++;
							dp[L][R][rev]++;
						}
					}
				}
			}
		}
		ZERO(dp2);
		for(i=N-1;i>=0;i--) {
			dp2[i]=1<<20;
			for(x=i;x<N;x++) dp2[i]=min({dp2[i],dp2[x+1]+dp[i][x][0],dp2[x+1]+dp[i][x][1]+1});
		}
		return dp2[0];
        
    }
};


