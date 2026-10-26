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
	int hoge(int v) {
		string s=to_string(v);
		sort(ALL(s));
		reverse(ALL(s));
		return atoi(s.c_str());
	}
    long long maximizeSum(vector<int>& nums, int k) {
		ll sum=0;
		vector<int> cand;
		FORR(a,nums) {
			sum+=a;
			cand.push_back(hoge(a)-a);
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		int i;
		FOR(i,k) sum+=cand[i];
		return sum;
        
    }
};


