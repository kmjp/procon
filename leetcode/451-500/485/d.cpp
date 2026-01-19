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
    string lexSmallestAfterDeletion(string s) {
		int C[256]={},D[256]={};
		FORR(c,s) C[c]++;
		string V;
		FORR(c,s) {
			C[c]--;
			while(V.size()) {
				char d=V.back();
				if(d>c&&(C[d]||D[d]>1)) {
					D[d]--;
					V.pop_back();
				}
				else {
					break;
				}
			}
			V+=c;
			D[c]++;
		}
		while(V.size()&&D[V.back()]>1) {
			D[V.back()]--;
			V.pop_back();
		}
		return V;
        
    }
};
