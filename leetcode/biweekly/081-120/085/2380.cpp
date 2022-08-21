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
    int secondsToRemoveOccurrences(string s) {
        int ma=0;
        int c=0;
        while(1) {
			int i;
			int step=0;
			FOR(i,s.size()-1) {
				if(s[i]=='0'&&s[i+1]=='1') {
					step=1;
					swap(s[i],s[i+1]);
					i++;
				}
			}
			if(step==0) break;
			ma++;
		}
		return ma;
    }
};
