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
    string mergeCharacters(string s, int k) {
		while(1) {
			int N=s.size();
			int i,j;
			FOR(i,N) for(j=i+1;j<=i+k&&j<N;j++) {
				if(s[i]==s[j]) {
					s=s.substr(0,j)+s.substr(j+1);
					goto nex;
				}
			}
			nex:
			if(i==N) break;
		}
		return s;
			
			
        
    }
};
