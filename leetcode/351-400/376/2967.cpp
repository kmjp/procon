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
    long long minimumCost(vector<int>& nums) {
		sort(ALL(nums));
		ll cur=1;
		ll co=1LL<<60;

		ll L=nums[nums.size()/2];
		ll R=L;
		if(nums.size()%2==0) R=nums[nums.size()/2-1];
		ll A=0,B=0,C=1000000001;
		for(int x=1;x<=99999;x++) {
			{
				ll ret=0;
				int y=x;
				ll p=x;
				while(y) {
					ret=ret*10+(y%10);
					p=p*10;
					y/=10;
				}
				ll c=p+ret;
				if(c<=L) A=max(A,c);
				if(c>=L&&c<=R) B=c;
				if(c>=R) C=min(C,c);
			}
			{
				ll ret=0;
				int y=x;
				ll p=x/10;
				while(y) {
					ret=ret*10+(y%10);
					p=p*10;
					y/=10;
				}
				ll c=p+ret;
				if(c<=L) A=max(A,c);
				if(c>=L&&c<=R) B=c;
				if(c>=R) C=min(C,c);
			}
			
			
			
		}
	
		cout<<A<<" "<<B<<" "<<C<<endl;
		ll ret1=0;
		ll ret2=0;
		ll ret3=0;
		FORR(a,nums) {
			ret1+=abs(A-a);
			ret2+=abs(B-a);
			ret3+=abs(C-a);
		}
		if(C>1000000000) ret3=1LL<<60;
		return min({ret1,ret2,ret3});
        
    }
};
