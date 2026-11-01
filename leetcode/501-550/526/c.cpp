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
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
		int N=nums.size();
		int unl=0;
		
		int i,x,y,j;
		FOR(i,N) nums[i]--;
		int sum=0;
		FOR(i,N) if(locked[i]) {
			cout<<"#"<<i<<endl;
			FOR(x,i) if(nums[x]>=i) break;
			if(x<i) {
				k--;
				sum++;
				continue;
			}
			for(x=i+1;x<N;x++) if(nums[x]<=i) break;
			if(x<N) {
				k--;
				sum++;
				continue;
			}
		}
		if(k<0) return -1;
		cout<<sum<<" "<<k<<endl;
		FOR(i,N) FOR(j,i) if(nums[j]>nums[i]) sum++;
		cout<<sum<<endl;
		return sum;
		
		
		
		
        
    }
};

 