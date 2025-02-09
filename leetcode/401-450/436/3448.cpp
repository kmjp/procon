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

ll from[10][10];
ll to[10][10];

class Solution {
public:
    long long countSubstrings(string s) {
        ZERO(from);
        
        int x,y;
        ll ret=0;
        FORR(c,s) {
			c-='0';
			ZERO(to);
			
			for(x=1;x<=9;x++) {
				from[x][0]++;
				FOR(y,10) {
					to[x][(y*10+c)%x]+=from[x][y];
				}
			}
			swap(from,to);
			ret+=from[c][0];
			
			
			
		}
		return ret;
        
    }
};


