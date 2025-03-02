#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    int minCost(vector<int>& nums) {
        int N=nums.size();
        if(N==1) return nums[0];
        if(N==2) return max(nums[0],nums[1]);
        map<int,int> F,T;
        F[nums[0]]=max(nums[1],nums[2]);
        F[nums[1]]=max(nums[0],nums[2]);
        F[nums[2]]=max(nums[0],nums[1]);
        int i;
        for(i=3;i<N;i+=2) {
			T.clear();
			if(i+1==N) {
				int ret=1<<30;
				FORR(a,F) ret=min(ret,a.second+max(a.first,nums[i]));
				return ret;
			}
			else {
				FORR(a,F) {
					int a1=a.first;
					int a2=nums[i];
					int a3=nums[i+1];
					
					if(T.count(a1)==0) T[a1]=1<<30;
					if(T.count(a2)==0) T[a2]=1<<30;
					if(T.count(a3)==0) T[a3]=1<<30;
					T[a1]=min(T[a1],a.second+max(a2,a3));
					T[a2]=min(T[a2],a.second+max(a1,a3));
					T[a3]=min(T[a3],a.second+max(a1,a2));
					
				}
			}
			swap(F,T);
			
		}
		int ret=1<<30;
		FORR(a,F) ret=min(ret,a.first+a.second);
		return ret;
        
        
			
    }
};

