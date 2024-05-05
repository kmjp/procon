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
    bool isValid(string word) {
        if(word.size()<3) return 0;
        int ok=0;
        int i;
        FORR(c,word) {
			int ng=1;
			FOR(i,26) if(c=='a'+i||c=='A'+i) {
				ng=0;
				if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') ok|=1;
				else if(c=='A'||c=='I'||c=='U'||c=='E'||c=='O') ok|=1;
				else ok|=2;
			}
			FOR(i,10) if(c=='0'+i) ng=0;
			if(ng) return 0;
		}
		return ok==3;
        
    }
};
