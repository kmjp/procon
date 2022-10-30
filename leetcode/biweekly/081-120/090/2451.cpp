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
    string oddString(vector<string>& words) {
		vector<vector<int>> V;
			int i;
		FORR(s,words) {
			vector<int> A;
			FOR(i,s.size()-1) {
				int x=s[i]-'a';
				int y=s[i+1]-'a';
				x=(x-y+26)%26;
				A.push_back(x);
			}
			V.push_back(A);
		}
        if(V[0]==V[1]) {
			FOR(i,V.size()) if(V[i]!=V[0]) return words[i];
		}
		else {
			if(V[0]==V[2]) return words[1];
			else return words[0];
		}return "";
    }
};

