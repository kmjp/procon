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
    int maxSelectedElements(vector<int>& nums) {
		sort(ALL(nums));
		int ma=0;
		map<int,int> M;
		FORR(a,nums) {
			M[a+1]=max(M[a+1],M[a]+1);
			M[a]=max(M[a],M[a-1]+1);
			ma=max(ma,M[a]);
			ma=max(ma,M[a+1]);
		}
        return ma;
    }
};

