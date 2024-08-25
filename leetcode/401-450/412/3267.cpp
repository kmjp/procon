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


map<int,int> M;
int p10[10];

class Solution {
public:
    int countPairs(vector<int>& nums) {
		int ret=0;
		int i,x,y;
		
		p10[0]=1;
		FOR(i,7) p10[i+1]=p10[i]*10;
		
		sort(ALL(nums));
		M.clear();
		FOR(i,nums.size()) {
			unordered_set<int> S;
			string a=to_string(nums[i]);
			int z,k;
			int v=nums[i];
			S.insert(v);
			FOR(y,a.size()) FOR(x,y) {
				int xa=v/p10[x]%10;
				int ya=v/p10[y]%10;
				int v2=v-xa*p10[x]-ya*p10[y]+xa*p10[y]+ya*p10[x];
				S.insert(v2);
				FOR(z,y+1) FOR(k,z) {
					int xb=v2/p10[z]%10;
					int yb=v2/p10[k]%10;
					int v3=v2-xb*p10[z]-yb*p10[k]+xb*p10[k]+yb*p10[z];
					S.insert(v3);
				}
			}
			FORR(s,S) if(M.count(s)) ret+=M[s];
			
			M[v]++;
		}
		
		
        return ret;
    }
};

