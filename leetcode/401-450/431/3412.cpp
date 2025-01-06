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
    long long calculateScore(string s) {
		vector<int> V[26];
		int i;
		ll ret=0;
		FOR(i,s.size()) {
			int a=s[i]-'a';
			int b=25-a;
			if(V[b].size()) {
				ret+=i-V[b].back();
				V[b].pop_back();
			}
			else {
				V[a].push_back(i);
			}
		}
		return ret;
        
    }
};


