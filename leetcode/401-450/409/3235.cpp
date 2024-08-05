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

set<int> S;
map<int,int> M;
int N;

class Solution {
public:
	void update(int x) {
		if(x==0||x==2*N) return;
		if(S.count(x)) {
			auto it=S.lower_bound(x);
			int a=*(prev(it));
			int b=*(next(it));
			S.erase(x);
			if(x<N) {
				if(--M[x-a]==0) M.erase(x-a);
			}
			if(b<N) {
				if(--M[b-x]==0) M.erase(b-x);
			}
			if(b<N) M[b-a]++;
			
		}
		else {
			auto it=S.lower_bound(x);
			auto pre=prev(it);
			int a=*pre;
			int b=*it;
			if(b<N) {
				if(--M[b-a]==0) M.erase(b-a);
			}
			S.insert(x);
			if(x<N) M[x-a]++;
			if(b<N) M[b-x]++;
		}
		
	}
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        N=colors.size();
        int i;
        FOR(i,N) colors.push_back(colors[i]);
        S.clear();
        S.insert(0);
        S.insert(2*N);
        M.clear();
        FOR(i,2*N) {
			if(i%2) colors[i]^=1;
			if(i&&colors[i]!=colors[i-1]) update(i);
		}
		
		vector<int> ret;
		FORR(q,queries) {
			if(q[0]==1) {
				int sum=0;
				if(*next(S.begin())>N) {
					sum=N;
				}
				else {
					FORR(a,M) if(a.first>=q[1]) sum+=1LL*(a.first-q[1]+1)*a.second;
					auto it=S.lower_bound(N);
					int b=*it;
					int a=*prev(it);
					sum+=max(0,min(b-a-q[1]+1,N-a));
				}
				ret.push_back(sum);
				
			}
			else {
				if(colors[q[1]]!=(q[2]^(q[1]%2))) {
					colors[q[1]]^=1;
					update(q[1]);
					update(q[1]+1);
					update(q[1]+N);
					update(q[1]+1+N);
					
				}
			}
		}
		return ret;
        
    }
};
