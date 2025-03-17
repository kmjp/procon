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

vector<int> add[202020];
vector<int> del[202020];

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
		vector<pair<string,int>> V;
		int N=words.size(),i;
		V.push_back({"",N});
		FOR(i,N) V.push_back({words[i],i});
		sort(ALL(V));
		FOR(i,N+1) add[i].clear(),del[i].clear();
		vector<int> ret(N);
		
		FOR(i,N+1) {
			if(i+k-1<=N) {
				int x=0;
				while(x<V[i].first.size()&&x<V[i+k-1].first.size()&&V[i].first[x]==V[i+k-1].first[x]) x++;
				add[0].push_back(x);
				del[i].push_back(x);
				add[i+k].push_back(x);
			}
			if(i+k<=N) {
				int x=0;
				while(x<V[i].first.size()&&x<V[i+k].first.size()&&V[i].first[x]==V[i+k].first[x]) x++;
				add[i].push_back(x);
				del[i+k+1].push_back(x);
			}
		}
		multiset<int> M={0};
		FOR(i,N+1) {
			FORR(a,add[i]) M.insert(a);
			FORR(a,del[i]) M.erase(M.find(a));
			if(V[i].second<N) ret[V[i].second]=*M.rbegin();
		}
        return ret;
    }
};

