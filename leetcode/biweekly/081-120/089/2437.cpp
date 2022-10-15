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
    int countTime(string time) {
		int ok=0;
		for(int h=0;h<=23;h++) {
			for(int m=0;m<=59;m++) {
				string S="00:00";
				S[0]+=h/10;
				S[1]+=h%10;
				S[3]+=m/10;
				S[4]+=m%10;
				int i;
				FOR(i,5) if(time[i]!='?'&&time[i]!=S[i]) break;
				if(i==5) ok++;
			}
		}
        return ok;
    }
};
