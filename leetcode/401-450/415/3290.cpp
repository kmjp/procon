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



ll from[5];
ll to[5];

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int i,j,N=b.size();
        FOR(i,5) from[i]=-1LL<<60;
        from[0]=0;
        FOR(i,N) {
			FOR(j,5) to[j]=from[j];
			FOR(j,4) to[j+1]=max(to[j+1],from[j]+1LL*a[j]*b[i]);
			swap(from,to);
		}
        return from[4];
    }
};
