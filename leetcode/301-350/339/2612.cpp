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
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
		vector<int> D(n);
		FORR(b,banned) D[b]=-1;
		int i;
		set<int> S[2];
		FOR(i,n) if(D[i]==0&&i!=p) {
			D[i]=1<<20;
			S[i%2].insert(i);
		}
		queue<int> Q;
		
		
		
		Q.push(p);
		D[p]=0;
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			int L,R;
			L=cur-(k-1);
			if(L<0) L=k-1-cur;
			R=cur+(k-1);
			if(R>=n) R=n-(k+cur-n);
			int id=(cur%2) ^(k%2)^1;
			//cout<<id<<" "<<cur<<" "<<L<<" "<<R<<endl;
			while(L<=R) {
				auto it=S[id].lower_bound(L);
				if(it==S[id].end()||*it>R) break;
				L=*it;
				D[L]=D[cur]+1;
				Q.push(L);
				S[id].erase(L);
				
				L++;
			}
			
			
		}
		
		
		FORR(r,D) if(r==1<<20) r=-1;
		return D;
        
    }
};
