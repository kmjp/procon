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
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
		vector<int> dif;
		ll ret=0;
		int i,N=technique2.size();
		FOR(i,N) {
			ret+=technique1[i];
			dif.push_back(technique2[i]-technique1[i]);
		}
		sort(ALL(dif));
		reverse(ALL(dif));
		FOR(i,k) dif.pop_back();
		FORR(d,dif) if(d>=0) ret+=d;
		return ret;
		
        
    }
};
