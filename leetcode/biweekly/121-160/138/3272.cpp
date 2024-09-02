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
	ll pat(int A[10]) {
		ll p=1;
		int i,j,nex=1;;
		FOR(i,10) FOR(j,A[i]) p*=nex++;
		FOR(i,10) FOR(j,A[i]) p/=(j+1);
		return p;
	}
    long long countGoodIntegers(int n, int k) {
		int i;
		set<string> S;
		
		for(i=1;i<=99999;i++) {
			string A=to_string(i);
			string B=A;
			reverse(ALL(B));
			string C=B.substr(1);
			B=A+B;
			C=A+C;
			if(B.size()==n&&atoll(B.c_str())%k==0) {
				sort(ALL(B));
				S.insert(B);
			}
			if(C.size()==n&&atoll(C.c_str())%k==0) {
				sort(ALL(C));
				S.insert(C);
			}
		}
		ll ret=0;
		FORR(s,S) if(s.size()==n) {
			int A[10]={};
			FORR(c,s) A[c-'0']++;
			ret+=pat(A);
			if(A[0]) {
				A[0]--;
				ret-=pat(A);
			}
		}
		
        return ret;
    }
};

