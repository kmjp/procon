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
    int minOperations(string s) {
		int mi=101010;
		int i,j;
		int N=s.size();
		FOR(i,N) {
			int sum=0;
			for(j=0;j<N-1-j;j++) sum+=min(abs(s[j]-s[N-1-j]),26-abs(s[j]-s[N-1-j]));
			mi=min(mi,sum+i);
			
			rotate(s.begin(),s.begin()+1,s.end());
		}
		return mi;
        
    }
};
