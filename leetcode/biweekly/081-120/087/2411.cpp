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

int mi[101010][30];

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
		int i,j;
		int N=nums.size();
		FOR(i,30) mi[N][i]=N;
		vector<int> V;
		for(i=N-1;i>=0;i--) {
			int ma=i;
			FOR(j,30) {
				mi[i][j]=mi[i+1][j];
				if(nums[i]&(1<<j)) mi[i][j]=i;
				if(mi[i][j]<N) ma=max(ma,mi[i][j]);
			}
			V.push_back(ma-i+1);
			
		}
		reverse(ALL(V));
		return V;
    }
};
