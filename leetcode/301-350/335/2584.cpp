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

int ok[202020];

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int N=nums.size();
        int i;
        FOR(i,N+1) ok[i]=0;
        map<int,int> pre;
        FOR(i,N) {
			int v=nums[i];
			for(int j=2;j<=1000;j++) if(v%j==0) {
				while(v%j==0) v/=j;
				if(pre.count(j)==0) {
					pre[j]=i;
				}
				else {
					ok[pre[j]+1]++;
					ok[i+1]--;
				}
			}
			if(v>1) {
				if(pre.count(v)==0) {
					pre[v]=i;
				}
				else {
					ok[pre[v]+1]++;
					ok[i+1]--;
				}
			}
		}
		FOR(i,N-1) {
			ok[i+1]+=ok[i];
			if(ok[i+1]==0) return i;
		}
		return -1;
    }
};