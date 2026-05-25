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
    int passwordStrength(string password) {
		int ret=0;
		int C[256]={};
		FORR(a,password) {
			if(C[a]) continue;
			C[a]++;
			if(a>='a'&&a<='z') ret+=1;
			else if(a>='A'&&a<='Z') ret+=2;
			else if(a>='0'&&a<='9') ret+=3;
			else if(a=='!') ret+=5;
			else if(a=='@') ret+=5;
			else if(a=='#') ret+=5;
			else if(a=='$') ret+=5;
		}
		return ret;
		
        
    }
};
