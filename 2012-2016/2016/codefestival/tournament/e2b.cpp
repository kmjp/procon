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

int H,W;
vector<ll> A[2020];
ll G[2020],T[2020];

void dodo(vector<ll>& V) {
	int i;
	for(i=1;i<V.size();i++) V[i]+=V[i-1];
}

ll hoge(vector<ll> A,vector<ll> B,bool eq_ok) {
	if(A[0]<B[0]) {
		cout<<-1<<endl;
		exit(0);
	}
	if(A[0]>B[0]) return 0;
	
	ll t=(B[1]-A[1]+A[0]-1)/A[0];
	if(A[0]*t+A[1]>B[1]) return t;
	
	int mapos=B.size();
	ll ov=1LL<<30;
	int i,x,y;
	FOR(i,t) {
		if(mapos==2) {
			A[1]+=A[0]*(t-i);
			break;
		}
		for(x=1;x<mapos;x++) {
			A[x]+=A[x-1];
			if(A[x]>=ov) {
				mapos=x;
				break;
			}
		}
	}
	
	if(eq_ok && A>=B) return t;
	if(!eq_ok && A>B) return t;
	return t+1;
}
 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>i, A[y].push_back(i);
	
	if(W==1) {
		FOR(y,H-1) if(A[y][0]>=A[y+1][0]) return _P("-1\n");
		return _P("0\n");
	}
	
	FOR(y,H-1) {
		if(A[y][0]>A[y+1][0]) return _P("-1\n");
		if(A[y][0]<A[y+1][0]) {
			G[y+1]=-1LL<<30;
			continue;
		}
		
		if(A[y]<A[y+1]) {
			G[y+1]=-hoge(A[y],A[y+1],true)+1;
		}
		else {
			G[y+1]=hoge(A[y+1],A[y],false);
		}
	}
	
	ll ret=0;
	for(i=1;i<H;i++) {
		T[i]=max(0LL,T[i-1]+G[i]);
		ret+=T[i];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
