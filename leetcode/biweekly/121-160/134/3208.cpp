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

int S[202020];

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
		int N=colors.size();
		int i;
		FOR(i,N) colors.push_back(colors[i]);
		FOR(i,2*N) {
			colors[i]^=i%2;
			S[i+1]=S[i]+colors[i];
		}
		int ret=0;
		FOR(i,N) {
			if(S[i+k]-S[i]==0) ret++;
			if(S[i+k]-S[i]==k) ret++;
		}
		return ret;
		
		
        
    }
};

