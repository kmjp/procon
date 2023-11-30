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
    int beautifulSubstrings(string s, int k) {
		FORR(c,s) {
			if(c=='a'||c=='e'||c=='i'||c=='u'||c=='o') c=0;
			else c=1;
		}
		int t=0;
		for(t=1;t<=30303;t++) {
			if(t*t%k==0) break;
		}
		cout<<t<<endl;
		map<int,int> M[2*t];
		ll ret=0;
		int D=0;
		M[0][0]=1;
		int x;
		FOR(x,s.size()) {
			if(s[x]==0) D++;
			else D--;
			ret+=M[(x+1)%(2*t)][D]++;
		}
		return ret;
        
    }
};
