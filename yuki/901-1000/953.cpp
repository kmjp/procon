#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K1,K2,M;
int order[101010];
ll X[101010],Y[101010];

set<pair<int,int>> A;
set<pair<int,int>> B;
map<ll,vector<int>> ev;
int ret[101010];

void fix(int x) {
	if(A.count({order[x],x})==0 && B.count({order[x],x})==0) return;
	int nei=0;
	if(x>1&&A.count({order[x-1],x-1})==0 && B.count({order[x-1],x-1})==0) nei++;
	if(x<N&&A.count({order[x+1],x+1})==0 && B.count({order[x+1],x+1})==0) nei++;
	
	if(nei==0) {
		B.erase({order[x],x});
		A.insert({order[x],x});
	}
	else {
		A.erase({order[x],x});
		B.insert({order[x],x});
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K1>>K2;
	x=0;
	if(K1<K2) {
		FOR(i,N) {
			if(K1-i>=1) order[K1-i]=x++;
			if(K2+i<=N) order[K2+i]=x++;
		}
	}
	else {
		FOR(i,N) {
			if(K1+i<=N) order[K1+i]=x++;
			if(K2-i>=1) order[K2-i]=x++;
		}
	}
	FOR(i,N) A.insert({order[i+1],i+1});
	
	cin>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		ev[X[i]].push_back(M+i);
	}
	assert(N<=100000&&M<=100000);
	
	queue<int> Q;
	while(ev.size()) {
		ll t=ev.begin()->first;
		auto V=ev.begin()->second;
		ev.erase(ev.begin());
		sort(ALL(V));
		
		FORR(x,V) {
			if(x<M) {
				B.insert({order[ret[x]],ret[x]});
				fix(ret[x]);
				fix(ret[x]-1);
				fix(ret[x]+1);
			}
			else {
				Q.push(x-M);
			}
		}
		
		while(Q.size() && (A.size()+B.size())) {
			x=Q.front();
			Q.pop();
			if(A.size()) {
				ret[x]=A.begin()->second;
				A.erase(A.begin());
			}
			else {
				ret[x]=B.begin()->second;
				B.erase(B.begin());
			}
			ev[t+Y[x]].push_back(x);
			fix(ret[x]-1);
			fix(ret[x]+1);
		}
	}
	
	
	FOR(i,M) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
