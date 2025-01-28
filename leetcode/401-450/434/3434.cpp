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
    int maxFrequency(vector<int>& nums, int k) {
		int ma=0;
		int i;
		for(int d=-50;d<=50;d++) {
			int from[3]={};
			FORR(n,nums) {
				int to[3]={from[0],from[1],from[2]};
				if(n==k) {
					chmax(to[0],from[0]+1);
					chmax(to[2],from[1]+1);
					chmax(to[2],from[2]+1);
				}
				if(n+d==k) {
					chmax(to[1],from[0]+1);
					chmax(to[1],from[1]+1);
				}
				swap(from,to);
			}
			ma=max({ma,from[0],from[1],from[2]});
		}
        return ma;
    }
};


