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
    int sumImbalanceNumbers(vector<int>& nums) {
		ll ret=0;
		int a,b;
		FOR(a,nums.size()) {
			set<int> S={nums[a]};
			int sum=0;
			for(b=a+1;b<nums.size();b++) {
				int x=nums[b];
				if(S.count(x)==0) {
					sum++;
					if(x<*S.begin()) {
						if(x==*S.begin()-1) sum--;
					}
					else if(x>*S.rbegin()) {
						if(x==*S.rbegin()+1) sum--;
					}
					else {
						auto it=S.insert(x).first;
						if(x+1==*next(it)) sum--;
						if(x-1==*prev(it)) sum--;
						
					}
					S.insert(x);
				}
				ret+=sum;
			}
		}
		return ret;
        
    }
};
