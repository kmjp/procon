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

vector<ll> cand;

class Solution {
public:
    long long specialPalindrome(long long n) {
		if(cand.empty()) {
			int mask,i;
			FOR(mask,1<<10) {
				if(mask&1) continue;
				vector<int> E[2],O;
				FOR(i,10) if(mask&(1<<i)) E[i%2].push_back(i);
				if(E[1].size()>1) continue;
				FORR(e,E[0]) {
					FOR(i,e/2) O.push_back(e);
				}
				if(E[1].size()) {
					FOR(i,E[1][0]/2) O.push_back(E[1][0]);
				}
				if(O.size()*2+E[1].size()>16) continue;
				sort(ALL(O));
				do {
					ll a=0;
					FORR(o,O) a=a*10+o;
					if(E[1].size()) a=a*10+E[1][0];
					reverse(ALL(O));
					FORR(o,O) a=a*10+o;
					reverse(ALL(O));
					cand.push_back(a);
				} while(next_permutation(ALL(O)));
				sort(ALL(cand));
			}
		}
		int i;
		FOR(i,100) cout<<cand[i]<<endl;
		return *lower_bound(ALL(cand),n+1);
        
    }
};
