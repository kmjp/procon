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
    int countMagicalPairs(string s) {
		ll ret=0;
		int x;
		int N=s.size();
		for(x=1;x<N;x++) {
			set<int> S;
			int y;
			map<int,int> M;
			for(y=x;y<N;y++) {
				S.insert(s[y]);
				M[S.size()]++;
			}
			S.clear();
			for(y=x-1;y>=0;y--) {
				S.insert(s[y]);
				ret+=M[S.size()];
			}
				
		}
		return ret;
        
    }
};
