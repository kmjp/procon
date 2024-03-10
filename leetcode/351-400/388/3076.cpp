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
	vector<string> hoge(string gen) {
		int x,y;
		vector<string> V;
		FOR(x,gen.size()) {
			string T;
			for(y=x;y<gen.size();y++) {
				T+=gen[y];
				V.push_back(T);
			}
		}
		return V;
	}
	
    vector<string> shortestSubstrings(vector<string>& arr) {
		map<string,int> M;
        
        vector<string> ret;
        FORR(a,arr) {
			auto v=hoge(a);
			FORR(b,v) M[b]++;
		}
        FORR(a,arr) {
			auto v=hoge(a);
			FORR(b,v) M[b]--;
			string r="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
			FORR(b,v) if(M[b]==0) {
				if(b.size()<r.size()) r=b;
				if(b.size()==r.size()) r=min(r,b);
			}
			if(r=="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") r="";
			ret.push_back(r);
			
			FORR(b,v) M[b]++;
		}
        return ret;
    }
};
