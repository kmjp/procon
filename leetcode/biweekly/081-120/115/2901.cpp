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


int len[1010];
int from[1010];

class Solution {
public:
	int dist(string a,string b) {
		if(a.size()!=b.size()) return 100;
		int i,r=0;
		FOR(i,a.size()) r+=a[i]!=b[i];
		return r;
	}
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int i,x,y;
        FOR(i,n) len[i]=-1;
        
        int ma=0;
        FOR(y,n) {
			len[y]=1;
			from[y]=-1;
			FOR(x,y) if(groups[x]!=groups[y]&&dist(words[x],words[y])==1) {
				if(len[y]<len[x]+1) {
					len[y]=len[x]+1;
					from[y]=x;
				}
			}
			ma=max(ma,len[y]);
		}
		vector<string> S;
		FOR(i,n) if(len[i]==ma) {
			int cur=i;
			while(cur>=0) {
				S.push_back(words[cur]);
				cur=from[cur];
			}
			break;
		}
		reverse(ALL(S));
		return S;
        
    }
};
