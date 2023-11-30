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

vector<int> E[101010];

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
		vector<int> A=nums;
		sort(ALL(A));
		int pre=-(1<<30),id=-1;
		map<int,int> T;
		FORR(a,A) {
			if(a-pre>limit) {
				id++;
			}
			pre=a;
			T[a]=id;
			E[id].push_back(a);
		}
		int i;
		FOR(i,id+1) reverse(ALL(E[i]));
		FORR(a,nums) {
			i=T[a];
			a=E[i].back();
			E[i].pop_back();
		}
		return nums;
        
    }
};
