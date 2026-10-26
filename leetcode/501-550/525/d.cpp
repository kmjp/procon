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


int id[101010];
vector<int> P[101010];

class Solution {
public:
    int countStaircase(vector<int>& nums) {
		int i,N=nums.size();
		map<int,int> F;
		FOR(i,N) {
			int x=nums[i];
			id[i]=P[x].size();
			P[x].push_back(i);
		}
		
		ll ret=0;
		FOR(i,N) {
			set<int> did;
			int cur=i;
			int R=N-1;
			for(int j=i;j<N;j++) {
				if(j>R) break;
				int v=nums[j];
				if(did.count(v)) {
					continue;
				}
				did.insert(v);
				//Š’è‚ÌŒÂ”‚ª‚È‚¢‚È‚çƒAƒEƒg
				if(id[j]+did.size()>P[v].size()) break;
				int nex1=P[v][id[j]+did.size()-1];
				int nex2=N-1;
				if(id[j]+did.size()<P[v].size()) nex2=P[v][id[j]+did.size()];
				cur=max(cur,nex1);
				R=min(R,nex2);
				if(cur>R) break;
				if(cur<=i+1LL*did.size()*(did.size()+1)/2-1&&i+1LL*did.size()*(did.size()+1)/2-1<=R) ret++;
			}
			
		}
		
		
		
		FORR(a,nums) P[a].clear();
		FOR(i,N) id[i]=0;
        return ret;
    }
};


