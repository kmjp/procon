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

int N,S;
int A[2020202];
set<int> V[202020];

ll ret[202020];

ll front(ll p,int v) {
	p--;
	return (*V[v].lower_bound(p%N+1)-(p%N)+p+1);
}
ll bef(ll p,int v) {
	if(p==0) return 0;
	p--;
	return (p-((p%N)-*prev(V[v].lower_bound(p%N))))+1;
}

int dp(ll p) {
	if(p<0) return 0;
	return lower_bound(ret,ret+200001,p+1)-ret-1;
}

ll L,T[402020];
vector<int> cand[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	if(N==1) {
		cout<<1<<endl;
		return;
	}
	
	FOR(i,N) {
		cin>>A[i];
		V[A[i]].insert(i);
	}
	FOR(i,200001) ret[i]=1LL<<60;
	ret[0]=0;
	
	for(i=1;i<=S;i++) {
		x=*V[i].begin();
		y=*V[i].rbegin();
		V[i].insert(y-N);
		V[i].insert(x+N);
	}
	for(i=1;i<=S;i++) {
		T[i]=i-1;
		cand[T[i]].push_back(i);
	}
	for(i=0;i<S;i++) {
		FORR(x,cand[i]) {
			if(bef(L,x)<=0) {
				T[x]=x-1;
			}
			else {
				T[x]=dp(bef(L,x)-1)+x;
			}
			if(T[x]<=i) {
				L=front(L,x);
				T[x]=i+x;
			}
			cand[T[x]].push_back(x);
		}
		ret[i+1]=L;
	}
	cout<<L<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
