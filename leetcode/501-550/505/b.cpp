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
    vector<string> generateValidStrings(int n, int k) {
		vector<string> ret;
		int mask,i;
		FOR(mask,1<<n) if((mask&(mask>>1))==0) {
			string S;
			int sum=0;
			FOR(i,n) {
				if(mask&(1<<i)) {
					S+="1";
					sum+=i;
				}
				else {
					S+="0";
				}
			}
			if(sum<=k) ret.push_back(S);
			
		}
        return ret;
    }
};

