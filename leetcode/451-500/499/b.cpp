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
    string sortVowels(string s) {
		int num[256]={},pos[256]={};
		int i;
		FOR(i,256) pos[i]=1<<20;
		FOR(i,s.size()) {
			char c=s[i];
			num[c]++;
			pos[c]=min(pos[c],i);
			int ok=0;
			if(c=='a') ok=1;
			if(c=='i') ok=1;
			if(c=='u') ok=1;
			if(c=='e') ok=1;
			if(c=='o') ok=1;
			if(ok) s[i]='_';
		}
		vector<vector<int>> V;
		V.push_back({-num['a'],pos['a'],'a'});
		V.push_back({-num['i'],pos['i'],'i'});
		V.push_back({-num['u'],pos['u'],'u'});
		V.push_back({-num['e'],pos['e'],'e'});
		V.push_back({-num['o'],pos['o'],'o'});
		sort(ALL(V));
		reverse(ALL(V));
		FORR(c,s) if(c=='_') {
			while(V.back()[0]==0) V.pop_back();
			V.back()[0]++;
			c=V.back()[2];
		}
		return s;
    }
};
