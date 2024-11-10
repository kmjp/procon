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


ll num[101010],sum[101010];
const ll mo=1000000007;

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
		ZERO(num);
		ZERO(sum);
		FORR(a,nums) {
			a++;
			(num[a]+=1+num[a-1]+num[a+1])%=mo;
			(sum[a]+=sum[a-1]+sum[a+1]+(1+num[a-1]+num[a+1])*(a-1))%=mo;
		}
		
        ll ret=0;
        int i;
        FOR(i,101000) ret+=sum[i];
        return ret%mo;
    }
};

