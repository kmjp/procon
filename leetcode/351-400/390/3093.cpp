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

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		int ret=V[cur][NUMC+1];
		FORR(c,s) {
			c-='a';
			if((cur=V[cur][c+1])==0) break;
			ret=V[cur][NUMC+1];
		}
		return ret;
	}
	void create(vector<string> S,vector<int> ids) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+2));
		V.back().back()=-1;
		int i;
		FOR(i,S.size()) {
			string s=S[i];
			int cur=0;
			V[cur][NUMC+1]=ids[i];
			FORR(c,s) {
				if(V[cur][c+1]==0) {
					V.push_back(vector<int>(NUMC+2));
					V[cur][c+1]=V.size()-1;
					V.back().back()=-1;
				}
				cur=V[cur][c+1];
				V[cur][NUMC+1]=ids[i];
			}
		}
	}
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
		vector<pair<int,int>> V;
		int i;
		int N=wordsContainer.size();
		FOR(i,N) {
			reverse(ALL(wordsContainer[i]));
			FORR(c,wordsContainer[i]) c-='a';
			V.push_back({wordsContainer[i].size(),i});
		}
		sort(ALL(V));
		reverse(ALL(V));
		vector<int> ids;
		vector<string> S;
		FORR(v,V) {
			ids.push_back(v.second);
			S.push_back(wordsContainer[v.second]);
		}
		Trie t;
		t.create(S,ids);
		vector<int> ret;
		FORR(w,wordsQuery) {
			reverse(ALL(w));
			ret.push_back(t.find(w));
		}
		return ret;
        
    }
};
