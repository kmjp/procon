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
	string hoge(int x) {
		string V;
		while(x) {
			V+=x%2;
			x/=2;
		}
		return V;
	}
	int hoge2(string A) {
		int ret=0;
		reverse(ALL(A));
		FORR(a,A) ret=ret*2+a;
		return ret;
	}
    int maxGoodNumber(vector<int>& nums) {
		string A[3];
		A[0]=hoge(nums[0]);
		A[1]=hoge(nums[1]);
		A[2]=hoge(nums[2]);
		int ret=0;
		ret=max(ret,hoge2(A[0]+A[1]+A[2]));
		ret=max(ret,hoge2(A[0]+A[2]+A[1]));
		ret=max(ret,hoge2(A[1]+A[0]+A[2]));
		ret=max(ret,hoge2(A[1]+A[2]+A[0]));
		ret=max(ret,hoge2(A[2]+A[0]+A[1]));
		ret=max(ret,hoge2(A[2]+A[1]+A[0]));
		
		
		return ret;
		
        
    }
};
