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
    bool canMakeEqual(vector<int>& nums, int k) {
		vector<int> A=nums,B=nums;
		int i;
		int a=k;
		for(i=1;i<nums.size()-1;i++) {
			if(A[i]!=A[0]) {
				A[i]*=-1;
				A[i+1]*=-1;
				a--;
			}
		}
		if(a>=0&&A.back()==A[0]) return 1;
		B[0]*=-1;
		B[1]*=-1;
		k--;
		for(i=1;i<nums.size()-1;i++) {
			if(B[i]!=B[0]) {
				B[i]*=-1;
				B[i+1]*=-1;
				k--;
			}
		}
		if(k>=0&&B.back()==B[0]) return 1;
		return 0;
        
    }
};


