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
	int C[26];
	int L;
	string S,t;
	int odd,no;
	bool dfs(int cur,int gr) {
		if(cur==L) {
			string V=S;
			string RS=S;
			reverse(ALL(RS));
			if(no) V+=odd+'a';
			V+=RS;
			return V>t;
		}
		for(int i=(gr?0:t[cur]-'a');i<26;i++) if(C[i]) {
			S[cur]=i+'a';
			C[i]--;
			if(dfs(cur+1,gr|(i>t[cur]-'a'))) return 1;
			C[i]++;
		}
		return 0;
	}
    string lexPalindromicPermutation(string s, string target) {
		t=target;
        ZERO(C);
        FORR(a,s) C[a-'a']++;
        no=0;
        int i;
        FOR(i,26) {
			if(C[i]%2) {
				no++;
				odd=i;
			}
			C[i]/=2;
		}
		if(no>1) return "";
		L=s.size()/2;
		S=string(L,'-');
		
		if(dfs(0,0)) {
			string RS=S;
			reverse(ALL(RS));
			if(no) S+=odd+'a';
			S+=RS;
			return S;
		}
		return "";
				
    }
};
