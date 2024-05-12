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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int ret=0;
        int i,j;
        int num=0;
        
        FOR(j,points.size()) if(points[j][0]==0&&points[j][1]==0) num++;
        
        for(i=30;i>=0;i--) {
			int mask=0;
			int sum=0;
			FOR(j,points.size()) {
				if(abs(points[j][0])<=ret+(1<<i)) {
					if(abs(points[j][1])<=ret+(1<<i)) {
						sum++;
						int x=s[j]-'a';
						if(mask&(1<<x)) break;
						mask |= 1<<x;
					}
				}
			}
			if(j==points.size()) {
				ret+=1<<i;
				num=sum;
			}
		}
		
		return num;
    }
};
