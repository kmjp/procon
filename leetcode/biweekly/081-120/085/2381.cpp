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


int S[50505];
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
		ZERO(S);
		FORR(a,shifts) {
			if(a[2]==1) {
				S[a[0]]++;
				S[a[1]+1]+=25;
			}
			else {
				S[a[0]]+=25;
				S[a[1]+1]++;
			}
		}
		int i;
		FOR(i,s.size()) {
			if(i) S[i]+=S[i-1];
			s[i]=(s[i]-'a'+S[i])%26+'a';
		}
		return s;
        
    }
};
