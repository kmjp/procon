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

ll S[202020];

pair<vector<int>,pair<int,int> > manacher(vector<int> S) {
	int L=S.size(),i,j,k;
	assert(L);
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && S[(i-j)/2]==S[(i+j+1)/2]) j++;
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k&&i+k<rad.size(); k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
	i=max_element(rad.begin(),rad.end())-rad.begin();
	return make_pair(rad,make_pair((i-(rad[i]-1))/2,(i+(rad[i]-1))/2));
}


class Solution {
public:
    long long getSum(vector<int>& nums) {
		int i;
		int N=nums.size();
		FOR(i,N) S[i+1]=S[i]+nums[i];
		
		auto hoge=manacher(nums);
		vector<int> v=hoge.first;
		auto x=hoge.second.first;
		auto y=hoge.second.second;
		// [x,y]‚ª‰ñ•¶
		ll ret=-1;
		FOR(i,v.size()) {
			x=(i-(v[i]-1))/2;
			y=(i+(v[i]-1))/2;
			if(x<=y) ret=max(ret,S[y+1]-S[x]);
		}
		return ret;
        
    }
};
