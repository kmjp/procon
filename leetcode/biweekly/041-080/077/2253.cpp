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
    int minimumAverageDifference(vector<int>& nums) {
		ll sum=0;
		
		if(nums.size()==1) return 0;
		
		FORR(n,nums) sum+=n;
		ll lef=0;
		int a=0,b=nums.size();
		ll mi=1<<30;
		int id=-1;
		FORR(n,nums) {
			a++;b--;
			sum-=n;
			lef+=n;
			ll c=abs((b?sum/b:0)-lef/a);
			if(c<mi) {
				mi=c;
				id=a-1;
			}
			
		}
        return id;
    }
};
