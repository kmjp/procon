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
    int vowelStrings(vector<string>& words, int left, int right) {
		int ret=0;
		for(int i=left;i<=right;i++) {
			int ok=0;
			if(words[i][0]=='a')ok++;
			if(words[i][0]=='i')ok++;
			if(words[i][0]=='u')ok++;
			if(words[i][0]=='e')ok++;
			if(words[i][0]=='o')ok++;
			reverse(ALL(words[i]));
			if(words[i][0]=='a')ok++;
			if(words[i][0]=='i')ok++;
			if(words[i][0]=='u')ok++;
			if(words[i][0]=='e')ok++;
			if(words[i][0]=='o')ok++;
			if(ok==2) ret++;
		}
		return ret;
        
    }
};
