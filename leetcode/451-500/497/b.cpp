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
    vector<double> internalAngles(vector<int>& sides) {
		sort(ALL(sides));
		if(sides[0]+sides[1]<=sides[2]) return {};
		double a=sides[0]*sides[0]+sides[1]*sides[1]-sides[2]*sides[2];
		double b=sides[0]*sides[0]+sides[2]*sides[2]-sides[1]*sides[1];
		double c=sides[2]*sides[2]+sides[1]*sides[1]-sides[0]*sides[0];
		vector<double> ret;
		ret.push_back(acos(a/(2*sides[0]*sides[1])));
		ret.push_back(acos(b/(2*sides[0]*sides[2])));
		ret.push_back(acos(c/(2*sides[2]*sides[1])));
		sort(ALL(ret));
		FORR(a,ret) a=a*180/(atan(1)*4);
		return ret;
        
    }
};
