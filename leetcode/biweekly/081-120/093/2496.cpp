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
    int maximumValue(vector<string>& strs) {
		ll ma=0;
		FORR(s,strs) {
			int a=0;
			FORR(c,s) {
				if(c>='a'&&c<='z') a++;
			}
			if(a) {
				ma=max(ma,(ll)s.size());
			}
			else {
				ma=max(ma,(ll)stoi(s.c_str()));
			}
		}
        return ma;
    }
};
