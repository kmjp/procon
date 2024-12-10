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
    int maxRectangleArea(vector<vector<int>>& points) {
		vector<pair<int,int>> V;
		FORR(a,points) V.push_back({a[0],a[1]});
		sort(ALL(V));
		int ret=-1;
		int i;
		int a,b,c,d;
		int N=V.size();
		FOR(a,V.size()) for(b=a+1;b<N;b++) for(c=b+1;c<N;c++) for(d=c+1;d<N;d++) {
			if(V[a].first==V[b].first&&V[a].second==V[c].second&&V[a].first<=V[d].first) {
				if(V[d].first==V[c].first&&V[d].second==V[b].second&&V[a].second<=V[d].second)  {
					int sum=0;
					FOR(i,N) {
						if((V[i].first-V[a].first)*(V[i].first-V[d].first)<=0) {
							if((V[i].second-V[a].second)*(V[i].second-V[d].second)<=0) sum++;
						}
					}
					if(sum==4) ret=max(ret,(V[d].second-V[a].second)*(V[d].first-V[a].first));
				}
			}
		}
        return ret;
    }
};

