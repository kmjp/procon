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


int V[101010];

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int,int> M;
        int i;
        FOR(i,k+1) V[i]=0;
        int N=nums.size();
        FOR(i,N/2) {
			int x=nums[i];
			int y=nums[N-1-i];
			
			if(x>y) swap(x,y);
			int ma=max(k-x,y);
			V[0]++;
			V[ma+1]++;
			V[y-x]--;
			V[y-x+1]++;
		}
		int mi=N;
		FOR(i,k+1) {
			if(i) V[i]+=V[i-1];
			mi=min(mi,V[i]);
		}
		
        return mi;
        
    }
};
