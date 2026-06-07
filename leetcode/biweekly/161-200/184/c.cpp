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
    long long maxTotal(vector<int>& nums, string s) {
		nums.insert(nums.begin(),0);
		nums.push_back(0);
		s='0'+s+'0';
        int N=s.size();
        ll ret=0;
        int cur=0;
        while(cur+1<N) {
			if(s[cur+1]=='0') continue;
			vector<int> V;
			V.push_back(nums[cur]);
			cur++;
			while(s[cur]=='1') {
				V.push_back(nums[cur]);
				cur++;
			}
			
			sort(ALL(V));
			FORR(a,V) ret+=a;
			ret-=V[0];
		}
        
		return ret;
    }
};
