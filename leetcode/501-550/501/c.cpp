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

vector<int> D[101010];
int C[101010];
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        
        if(D[4].empty()) {
			for(int i=1;i<=100000;i++) {
				for(int j=i;j<=100000;j+=i) D[j].push_back(i);
			}
		}
		
		FORR(a,nums) C[a]=1;
		ll ret=0;
		FORR(a,nums) {
			FORR(b,D[a]) if(C[b]) {
				ret+=b;
				break;
			}
		}
		FORR(a,nums) C[a]=0;
        return ret;
    }
};
