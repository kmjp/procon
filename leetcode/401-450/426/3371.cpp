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
    int getLargestOutlier(vector<int>& nums) {
		multiset<int> M;
		ll sum=0;
		FORR(n,nums) {
			M.insert(n);
			sum+=n;
		}
		int ret=-1<<30;
		FORR(n,nums) {
			M.erase(M.find(n));
			sum-=n;
			if(sum%2==0&&M.count(sum/2)) ret=max(ret,n);
			sum+=n;
			M.insert(n);
		}
        return ret;
    }
};

