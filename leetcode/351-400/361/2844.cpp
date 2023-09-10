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
    int minimumOperations(string num) {
		int mi=num.size();
		
		vector<string> A={"00","05","52","57"};
		reverse(ALL(num));
		num+="00";
		FORR(a,A) {
			int cur=0;
			int step=0;
			FORR(c,num) {
				if(c==a[cur]) {
					cur++;
					if(cur==2) break;
				}
				else {
					step++;
				}
			}
			if(cur==2) mi=min(mi,step);
		}
		return mi;
		
        
    }
};
