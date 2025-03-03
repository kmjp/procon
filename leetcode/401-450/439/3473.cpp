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

int from[4040];
int to[4040];

class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
		int N=nums.size();
		int i,x;
		FOR(i,2*N+2) from[i]=-1<<30;
		from[0]=0;
		FORR(c,nums) {
			FOR(i,2*N+2) to[i]=-1<<30;
			
			FOR(x,2*N+2) {
				if(x%(m+1)==0) {
					to[x]=max(to[x],from[x]);
					to[x+1]=max(to[x+1],from[x]+c);
				}
				else if(x%(m+1)==m) {
					to[x]=max(to[x],from[x]+c);
					to[x+1]=max(to[x+1],from[x]);
					to[x+2]=max(to[x+2],from[x]+c);
				}
				else {
					to[x+1]=max(to[x+1],from[x]+c);
				}
			}
			
			swap(from,to);
		}
		
		return max(from[(m+1)*k-1],from[(m+1)*k]);
        
    }
};
