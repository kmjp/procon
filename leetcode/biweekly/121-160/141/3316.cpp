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

int from[3030];
int to[3030];

class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int C[3030]={};
        FORR(a,targetIndices) C[a]=1;
        int N=source.size(),M=pattern.size();
        int i,j;
        FOR(i,M+1) from[i]=-1010;
        from[0]=0;
        FOR(i,N) {
			FOR(j,M+1) to[j]=from[j];
			FOR(j,M+1) if(from[j]>=0) {
				if(j<M&&pattern[j]==source[i]) {
					to[j+1]=max(to[j+1],from[j]);
				}
				if(C[i]) {
					to[j]=max(to[j],from[j]+1);
				}
			}
			FOR(j,M+1) from[j]=to[j];
		}
		return from[M];
    }
};
