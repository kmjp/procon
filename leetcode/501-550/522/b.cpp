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

int L[202020];
int R[202020];

class Solution {
public:
    int minRotations(int n, string s) {
        int i;
        int cur=0;
        FOR(i,n) {
			int x=s[i]-'0';
			L[i+1]=L[i]+min(abs(x-cur),10-abs(x-cur));
			cur=x;
		}
		R[n]=0;
		cur=s.back()-'0';
		for(i=n-2;i>=0;i--) {
			int x=s[i]-'0';
			R[i+1]=R[i+2]+min(abs(x-cur),10-abs(x-cur));
			cur=x;
		}
		int ret=min(L[n],R[1]+min(abs('0'-s.back()),10-abs('0'-s.back())));
		FOR(i,n-1) {
			int tmp=L[i+1]+R[i+2]+min(abs(s[i]-s.back()),10-abs(s[i]-s.back()));
			ret=min(ret,tmp);
		}
		return ret;
		
    }
};
