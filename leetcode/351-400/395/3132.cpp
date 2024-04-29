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
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
		sort(ALL(nums1));
		sort(ALL(nums2));
		int mi=1<<30;
		int x,y,k;
		FOR(y,nums1.size()) {
			FOR(x,y) {
				int cur=0;
				int hoge=1<<30;
				FOR(k,nums2.size()) {
					while(cur==x||cur==y) cur++;
					if(hoge==1<<30) hoge=nums2[k]-nums1[cur];
					if(hoge!=nums2[k]-nums1[cur]) break;
					
					cur++;
				}
				if(k==nums2.size()) mi=min(mi,hoge);
				
			}
		}
        return mi;
    }
};
