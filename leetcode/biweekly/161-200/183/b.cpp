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

ll A[101],B[101];

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
		
		ZERO(A);
		ZERO(B);
		int i,j,N=nums.size();
		FOR(i,N) {
			int C[101];
			FOR(j,k) C[j]=1LL<<30;
			for(int a=-100;a<=100;a++) {
				int v=(nums[i]+100*k+a)%k;
				C[v]=min(C[v],abs(a));
			}
			
			FOR(j,k) {
				cout<<C[j];
				if(i%2==0) A[j]+=C[j];
				else B[j]+=C[j];
			}
			cout<<endl;
		}
		ll ret=1LL<<60;
		FOR(i,k) cout<<A[i]<<":"<<B[i]<<" ";
		cout<<endl;
		FOR(i,k) FOR(j,k) if(i!=j) ret=min(ret,A[i]+B[j]);
        return ret;
    }
};


