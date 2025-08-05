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
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
		int ret=1<<30;
		int i,j,k;
		FOR(i,2) {
			int st=1<<30;
			FOR(j,landStartTime.size()) {
				st=min(st,landStartTime[j]+landDuration[j]);
			}
			FOR(j,waterStartTime.size()) {
				ret=min(ret,max(st,waterStartTime[j])+waterDuration[j]);
			}
			swap(landStartTime,waterStartTime);
			swap(landDuration,waterDuration);
			
		}
		return ret;
		
		
        
    }
};

