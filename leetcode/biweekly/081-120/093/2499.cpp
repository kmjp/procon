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
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
		int N=nums1.size();
		map<int,int> A;
		FORR(v,nums1) A[v]++;
		FORR(v,nums2) A[v]++;
		FORR(v,A) if(v.second>N) return -1;
		
		map<int,int> B;
		int ma=-1;
		int i;
		vector<int> C;
		FOR(i,N) if(nums1[i]==nums2[i]) {
			C.push_back(i);
			B[nums1[i]]++;
			B[nums2[i]]++;
			if(B[ma]<B[nums1[i]]) ma=nums1[i];
			if(B[ma]<B[nums1[2]]) ma=nums2[i];
		}
		
		FOR(i,N) {
			if(B[ma]<=C.size()) break;
			if(nums1[i]==nums2[i]) continue;
			if(nums1[i]!=ma&&nums2[i]!=ma) {
				C.push_back(i);
				B[nums1[i]]++;
				B[nums2[i]]++;
				if(B[ma]<B[nums1[i]]) ma=nums1[i];
				if(B[ma]<B[nums1[2]]) ma=nums2[i];
			}
		}
		sort(ALL(C));
		if(C.size()%2==1) C.push_back(C[0]);
		ll ret=0;
		FORR(c,C) ret+=c;
		return ret;
        
    }
};
