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
    string findValidPair(string s) {
		int N=s.size();
		int i;
		FOR(i,N-1) if(s[i]!=s[i+1]) {
			int x=s[i]-'0';
			int y=s[i+1]-'0';
			FORR(c,s) {
				if(s[i]==c) x--;
				if(s[i+1]==c) y--;
			}
			if(x==0&&y==0) return s.substr(i,2);
		}
        return "";
    }
};


