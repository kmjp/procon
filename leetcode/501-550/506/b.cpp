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
    int getLength(vector<int>& nums) {
		int ma=0;
		int N=nums.size();
		int x,y;
		FOR(x,N) {
			map<int,int> C;
			map<int,int> num;
			for(y=x;y<N;y++) {
				int v=nums[y];
				if(C[v]) {
					num[C[v]]--;
					if(num[C[v]]==0) num.erase(C[v]);
				}
				C[v]++;
				num[C[v]]++;
				
				if(num.size()==1&&C.size()==1) ma=max(ma,y-x+1);
				if(num.size()==2&&num.begin()->first*2==num.rbegin()->first) ma=max(ma,y-x+1);;
			}
		}
		return ma;
        
    }
};
