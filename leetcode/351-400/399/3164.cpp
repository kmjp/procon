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

ll A[1<<20];
ll B[1<<20];

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		FORR(a,nums1) if(a%k==0) A[a/k]++;
		FORR(a,nums2) B[a]++;
        ll ret=0;
        int i,j;
        for(i=1;i<=1000000;i++) if(B[i]) {
			for(j=i;j<=1000000;j+=i) ret+=1LL*A[j]*B[i];
		}
        
		FORR(a,nums1) if(a%k==0) A[a/k]--;
		FORR(a,nums2) B[a]--;
        return ret;
    }
};
