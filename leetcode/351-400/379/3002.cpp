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
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
		set<int> A,B,AB;
		int N=nums1.size();
		FORR(a,nums1) A.insert(a);
		FORR(a,nums2) {
			if(AB.count(a)) continue;
			if(A.count(a)) {
				A.erase(a);
				AB.insert(a);
			}
			else {
				B.insert(a);
			}
		}
		int ret=0;
		int a1=N/2,b1=N/2;
		int x=min(a1,(int)A.size());
		ret+=x;
		a1-=x;
		x=min(b1,(int)B.size());
		ret+=x;
		b1-=x;
		ret+=min((int)AB.size(),a1+b1);
		return ret;
        
    }
};
