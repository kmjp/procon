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
    vector<int> lastVisitedIntegers(vector<string>& words) {
		vector<int> V,R;
		int num=0;
		FORR(c,words) {
			if(c=="prev") {
				num++;
				if(num<=V.size()) R.push_back(V[V.size()-num]);
				else R.push_back(-1);
			}
			else {
				num=0;
				V.push_back(atoi(c.c_str()));
			}
		}
		return R;
        
    }
};
