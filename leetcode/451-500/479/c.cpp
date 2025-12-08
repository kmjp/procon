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
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        ll ret=0;
        ll sum=0;
        vector<ll> V={0};
        int N=damage.size();
        FORR(d,damage) V.push_back(V.back()+d);
        int i;
        FOR(i,N) {
			ll tmp=V[i+1]+requirement[i]-hp;
			int pos=lower_bound(ALL(V),tmp)-V.begin();
			if(pos<=i) ret+=i-pos+1;
		}
		return ret;
        
    }
};


