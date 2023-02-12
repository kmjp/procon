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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
		map<int,pair<int,int>> V;
		int i,j;
		int N=s.size();
		FOR(i,N) {
			if(s[i]=='1') {
				int cur=0;
				for(j=0;j<30&&i+j<N;j++) {
					cur=cur*2+s[i+j]-'0';
					if(V.count(cur)==0) V[cur]={i,i+j};
				}
			}
			else {
				if(V.count(0)==0) V[0]={i,i};
			}
		}
		vector<vector<int>> R;
		FORR(a,queries) {
			i=a[0]^a[1];
			if(V.count(i)) {
				R.push_back({V[i].first,V[i].second});
			}
			else {
				R.push_back({-1,-1});
			}
		}
		return R;
        
    }
};
