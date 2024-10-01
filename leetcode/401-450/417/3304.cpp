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
    char kthCharacter(int k) {
        string A="a";
        int i;
        FOR(i,k) {
			int j=A.size();
			int x;
			A+=A;
			FOR(x,j) {
				A[x+j]++;
				if(A[x+j]=='z'+1) A[x+j]='a';
			}
			if(A.size()>k) A.resize(k);
		}
		return A[k-1];
    }
};
