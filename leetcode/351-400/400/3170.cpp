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
    string clearStars(string s) {
		set<int> S[26];
		int i,j;
		FOR(i,s.size()) {
			if(s[i]!='*') {
				S[s[i]-'a'].insert(i);
			}
			else {
				FOR(j,26) if(S[j].size()) {
					S[j].erase(*S[j].rbegin());
					break;
				}
			}
		}
        string T;
		FOR(i,s.size()) {
			if(s[i]!='*') if(S[s[i]-'a'].count(i)) T+=s[i];
		}
		return T;
        
    }
};
