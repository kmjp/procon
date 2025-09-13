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
	vector<vector<int>> hoge(int n,int d) {
		int g=__gcd(n,d);
		int s,i;
		vector<vector<int>> ret;
		if(g==1) {
			FOR(i,n) ret.push_back({(i*2*d)%n,((i*2+1)*d)%n});
		}
		else {
			FOR(i,n/g) {
				FOR(s,g) {
					ret.push_back({(s+i*d)%n,(s+(i+1)*d)%n});
				}
			}
		}
		s=ret.size()/2;
		FOR(i,s) if(ret[i]==ret[i+s]) swap(ret[i][0],ret[i][1]);
		return ret;
	}
	

    vector<vector<int>> generateSchedule(int n) {
		if(n<=4) return {};
		vector<vector<int>> ret;
		int i;
		for(i=1;i<n;i++) {
			vector<vector<int>> cand=hoge(n,i);
			if(ret.empty()) {
				ret=cand;
			}
			else {
				while(ret.back()[0]==cand[0][0]||ret.back()[1]==cand[0][0]||ret.back()[0]==cand[0][1]||ret.back()[1]==cand[0][1]) {
					rotate(cand.begin(),cand.begin()+1,cand.end());
				}
				FORR(v,cand) ret.push_back(v);
			}
		}
		
		
        return ret;
        
        
    }
};
