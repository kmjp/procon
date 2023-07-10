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
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
		
		map<int,int> F;
		int ma=0,i;
		FOR(i,nums1.size()) {
			map<int,int> T;
			F[0]=0;
			FORR(m,F) {
				if(m.first<=nums1[i]) chmax(T[nums1[i]],m.second+1);
				if(m.first<=nums2[i]) chmax(T[nums2[i]],m.second+1);
			}
			FORR(m,T) ma=max(ma,m.second);
			F=T;
			
		}
		return ma;
        
    }
};
