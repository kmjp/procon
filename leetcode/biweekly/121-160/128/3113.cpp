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
    long long numberOfSubarrays(vector<int>& nums) {
		int N=nums.size();
		vector<pair<int,int>> stack={{1<<30,1}};
		ll ret=0;
		map<int,int> M;
		FORR(n,nums) {
			ret+=M[n]+1;
			while(stack.back().first<n) {
				M.erase(stack.back().first);
				stack.pop_back();
			}
			if(n==stack.back().first) {
				stack.back().second++;
			}
			else {
				stack.push_back({n,1});
			}
			M[n]++;
		}
		return ret;
		
        
    }
};
