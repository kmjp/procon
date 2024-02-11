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
    int maxPalindromesAfterOperations(vector<string>& words) {
		int C[256]={};
		vector<int> L;
		FORR(s,words) {
			L.push_back(s.size());
			FORR(c,s) C[c]++;
		}
		int ret=0,i;
		sort(ALL(L));
		FORR(l,L) {
			FOR(i,256) {
				if(l%2&&C[i]%2) {
					l--;
					C[i]--;
					break;
				}
			}
			if(l%2) {
				FOR(i,256) if(C[i]) {
					C[i]--;
					l--;
					break;
				}
			}
			if(l%2) return ret;
			FOR(i,256) {
				while(l&&C[i]>=2) {
					l-=2;
					C[i]-=2;
				}
			}
			if(l) return ret;
			ret++;
		}
        return ret;
    }
};
