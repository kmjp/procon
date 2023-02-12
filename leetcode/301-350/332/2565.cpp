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

int L[101010],R[101010];

class Solution {
public:
    int minimumScore(string s, string t) {
		
		int A=s.size(),B=t.size();
		L[0]=0;
		int i,cur=0;
		FOR(i,A) {
			L[i+1]=L[i];
			if(L[i]<B&&s[i]==t[L[i]]) L[i+1]++;
		}
		R[A]=0;
		for(i=A-1;i>=0;i--) {
			R[i]=R[i+1];
			if(R[i+1]<B&&s[i]==t[B-1-R[i]]) R[i]++;
		}
		int ma=0;
		FOR(i,A+1) ma=max(ma,L[i]+R[i]);
		ma=min(ma,B);
		return B-ma;
        
    }
};
