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
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
		vector<pair<int,int>> P;
		int i;
		FOR(i,positions.size()) P.push_back({positions[i],i});
		sort(ALL(P));
		vector<int> V;
		FORR(p,P) {
			int cur=p.second;
			if(directions[cur]=='L') {
				while(V.size()) {
					int tar=V.back();
					if(healths[tar]<healths[cur]) {
						V.pop_back();
						healths[tar]=0;
						healths[cur]--;
					}
					else if(healths[tar]==healths[cur]) {
						V.pop_back();
						healths[tar]=0;
						healths[cur]=0;
						break;
					}
					else {
						healths[tar]--;
						healths[cur]=0;
						break;
					}
				}
			}
			else {
				V.push_back(cur);
			}
		}
		vector<int> ret;
		FORR(a,healths) if(a) ret.push_back(a);
		return ret;
        
    }
};
