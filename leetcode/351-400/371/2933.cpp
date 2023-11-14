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
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
		map<string,vector<string>> M;
		FORR(a,access_times) {
			FORR(b,a[1]) b-='0';
			M[a[0]].push_back(a[1]);
		}
		vector<string> ret;
		FORR(a,M) {
			vector<string> V=a.second;
			sort(ALL(V));
			int i;
			for(i=2;i<V.size();i++) {
				int h1=V[i-2][0]*10*60+V[i-2][1]*60+V[i-2][2]*10+V[i-2][3];
				int h2=V[i][0]*10*60+V[i][1]*60+V[i][2]*10+V[i][3];
				if(h2-h1<60) {
					ret.push_back(a.first);
					break;
				}
			}
		}
		return ret;
        
    }
};
