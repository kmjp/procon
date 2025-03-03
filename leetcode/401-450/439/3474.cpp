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

int fix[202020];

class Solution {
public:
    string generateString(string str1, string str2) {
		int N=str1.size();
		int M=str2.size();
		
		string B(N+M-1,'?');
		int x,y;
		FOR(x,N+M+1) fix[x]=0;
		FOR(x,N) if(str1[x]=='T') {
			FOR(y,M) {
				if(B[x+y]=='?') {
					B[x+y]=str2[y];
					fix[x+y]=1;
				}
				if(B[x+y]!=str2[y]) return "";
			}
		}
		FOR(x,N+M-1) if(B[x]=='?') B[x]='a';
		FOR(x,N) if(str1[x]=='F') {
			FOR(y,M) if(B[x+y]!=str2[y]) break;
			if(y==M) {
				for(y=M-1;y>=0;y--) {
					if(fix[x+y]==0&&str2[y]=='a'&&B[x+y]=='a') {
						B[x+y]='b';
						break;
					}
				}
				if(y<0) return "";
			}
		}
        return B;
    }
};
