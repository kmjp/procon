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

using VT = string;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
		string A,P;
		FORR(a,pattern) {
			P+='b'+a;
		}
		int i;
		int N=nums.size();
		FOR(i,N-1) {
			if(nums[i]<nums[i+1]) A+="c";
			if(nums[i]==nums[i+1]) A+="b";
			if(nums[i]>nums[i+1]) A+="a";
		}
		
		P+="z"+A;
		auto V=Zalgo(P);
		int ret=-1;
		FORR(a,V) if(a>=pattern.size()) ret++;
		return ret;
		
        
    }
};
