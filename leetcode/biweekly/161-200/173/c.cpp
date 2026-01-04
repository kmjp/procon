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
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
		vector<ll> A;
		int i,j;
		FOR(i,n) A.push_back(1LL<<60);
		FORR(r,restrictions) A[r[0]]=min(A[r[0]],(ll)r[1]);
		A[0]=0;
		FOR(j,3) {
			FOR(i,n-1) {
				A[i]=min(A[i],A[i+1]+diff[i]);
				A[i+1]=min(A[i+1],A[i]+diff[i]);
			}
			for(i=n-2;i>=0;i--) {
				A[i]=min(A[i],A[i+1]+diff[i]);
				A[i+1]=min(A[i+1],A[i]+diff[i]);
			}
		}
		FORR(a,A) cout<<a<<" ";
		cout<<endl;
		return *max_element(ALL(A));
		
		
        
    }
};
