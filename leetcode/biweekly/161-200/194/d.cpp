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

int nex[202020][26];
int pre[202020][26];
class Solution {
public:
    long long countMagicalPairs(string s) {
		int N=s.size();
		int i,j;
		FOR(i,26) {
			FOR(j,N) {
				if(j) pre[j][i]=pre[j-1][i];
				else pre[j][i]=-1;
				if(s[j]=='a'+i) pre[j][i]=j;
			}
			nex[N][i]=N;
			for(j=N-1;j>=0;j--) {
				nex[j][i]=nex[j+1][i];
				if(s[j]=='a'+i) nex[j][i]=j;
			}
		}
		ll ret=0;
		for(i=1;i<N;i++) {
			vector<int> A,B;
			A.push_back(0);
			B.push_back(0);
			FOR(j,26) {
				A.push_back(i-pre[i-1][j]);
				B.push_back(nex[i][j]-i);
			}
			A.push_back(i-(-1));
			B.push_back(N-i);
			sort(ALL(A));
			sort(ALL(B));
			FOR(j,26) {
				ll x=A[j+2]-A[j+1];
				ll y=B[j+2]-B[j+1];
				ret+=1LL*x*y;
			}
			
		}
		return ret;
        
    }
};

