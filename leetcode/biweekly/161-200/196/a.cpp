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
    vector<string> assignUmbrella(vector<int>& rain) {
		int C[2]={};
		int i;
		vector<string> R;
		FOR(i,rain.size()) {
			int a=(i+1<rain.size()&&rain[i]&&rain[i+1]);
			int b=(rain[i]);
			if(b==0) {
				R.push_back("None");
			}
			else if(a) {
				if(C[0]<=C[1]) {
					R.push_back("Alice");
					C[0]++;
				}
				else {
					R.push_back("Bob");
					C[1]++;
				}
					
			}
			else {
				R.push_back("Bob");
				C[1]++;
			}
			
		}
		return R;
        
    }
};


