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
    long long maxTotal(vector<int>& value, vector<int>& limit) {
		map<int,vector<int>> V;
		int N=value.size();
		int i;
		FOR(i,N) V[limit[i]].push_back(value[i]);
		
		ll ret=0;
		FORR2(a,b,V) {
			sort(ALL(b));
			reverse(ALL(b));
			FOR(i,min(a,(int)b.size())) ret+=b[i];
		}
		return ret;
        
    }
};
