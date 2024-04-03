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


multiset<int> XpY,XmY;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
		XpY.clear();
		XmY.clear();
		int i;
		int N=points.size();
		FOR(i,N) {
			XpY.insert(points[i][0]+points[i][1]);
			XmY.insert(points[i][0]-points[i][1]);
		}
		int ret=1<<30;
		FOR(i,N) {
			XpY.erase(XpY.find(points[i][0]+points[i][1]));
			XmY.erase(XmY.find(points[i][0]-points[i][1]));
			ret=min(ret,max(*XpY.rbegin()-*XpY.begin(),*XmY.rbegin()-*XmY.begin()));
			XpY.insert(points[i][0]+points[i][1]);
			XmY.insert(points[i][0]-points[i][1]);
		}
		return ret;
		
			
        
    }
};
