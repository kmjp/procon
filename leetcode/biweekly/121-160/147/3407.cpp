#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    bool hasMatch(string s, string p) {
		string a,b;
		int i;
		FOR(i,p.size()) if(p[i]=='*') {
			a=p.substr(0,i);
			b=p.substr(i+1);
		}
		int x=-1,y=-1;
		FOR(i,s.size()-a.size()+1) {
			if(s.substr(i,a.size())==a) {
				x=i;
				break;
			}
		}
		FOR(i,s.size()-b.size()+1) {
			if(s.substr(i,b.size())==b) {
				y=i;
			}
		}
		if(x==-1||y==-1||y<x) return 0;
		return (y-x>=a.size());
        
    }
};
