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

int L[303030],R[303030];

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
		int N=word1.size(),M=word2.size();
		int cur=0;
		int i;
		FOR(i,N) {
			if(cur<M&&word1[i]==word2[cur]) cur++;
			L[i+1]=cur;
		}
		cur=0;
		R[N]=0;
		for(i=N-1;i>=0;i--) {
			if(cur<M&&word1[i]==word2[M-1-cur]) cur++;
			R[i]=cur;
		}
		
		set<int> S[26];
		FOR(i,word1.size()) S[word1[i]-'a'].insert(i);
		int tar=-1;
		if(L[N]!=M) {
			FOR(i,N) {
				if(L[i]+R[i+1]==M-1) {
					tar=L[i];
					break;
				}
			}
		}
		if(tar==-1&&L[N]!=M) return {};
		vector<int> V;
		cur=0;
		cout<<tar<<endl;
		int did=0;
		FOR(i,word2.size()) {
			if(tar!=-1) {
				if(tar==i) {
					;
				}
				else {
					auto it=S[word2[i]-'a'].lower_bound(cur);
					cur=*it;
				}
			}
			else {
				auto it=S[word2[i]-'a'].lower_bound(cur);
				if(it==S[word2[i]-'a'].end()) {
					if(did) return {};
					did=1;
				}
				else {
					if(*it!=cur) {
						if(did==0) did=1;
						else cur=*it;
					}
					else {
						cur=*it;
					}
				}
			}
			V.push_back(cur);
			cur++;
		}
        return V;
    }
};
