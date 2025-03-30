#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    int maxActiveSectionsAfterTrade(string s) {
		int sum=count(ALL(s),'1');
		int i,N=s.size();
		int ma=0;
		vector<int> V;
		int x=0;
		FOR(i,N) {
			if(s[i]=='1') {
				if(x) {
					V.push_back(x);
					x=0;
				}
			}
			else {
				x++;
			}
		}
		if(x) V.push_back(x);
		if(sum&&V.size()>=2) {
			int ma=0;
			FOR(i,V.size()-1) ma=max(ma,V[i]+V[i+1]);
			return sum+ma;
		}
		else {
			return sum;
		}
    }
};
