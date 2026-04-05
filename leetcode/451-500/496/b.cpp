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
    vector<int> findGoodIntegers(int n) {
		vector<int> V;
		int x,y;
		map<int,int> M;
		for(x=1;x*x*x<=n;x++) {
			for(y=x;x*x*x+y*y*y<=n;y++) {
				M[x*x*x+y*y*y]++;
			}
		}
		FORR2(a,b,M) if(b>1) V.push_back(a);
		return V;
		
        
    }
};

