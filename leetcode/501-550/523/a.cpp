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
    bool threeFibonacciSum(int n) {
		ll F[100];
		F[0]=0;
		F[1]=1;
		int i;
		for(i=2;i<=99;i++) {
			F[i]=F[i-1]+F[i-2];
			if(F[i]>n) return 0;
			cout<<F[i]<<endl;
			if(2*F[i]==n) return 1;
		}
		return 0;
		
        
    }
};


