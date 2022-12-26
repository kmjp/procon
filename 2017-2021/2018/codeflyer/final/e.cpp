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

int N,Q;
int A[202020];
string S;
int pos[202020], rpos[202020];
ll mo=1000000007;
vector<ll> pmul[202020];
vector<ll> pdiv[202020];
ll smul[202020];

struct node {
	int SL,SR;
	int L,R;
	ll V;
};

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<node> V;

int ptr;

int expr();
int value() {
	int node;
	if(S[ptr]=='a') {
		node=V.size();
		V.resize(node+1);
		V[node].SL=ptr++;
		V[node].SR=ptr;
		V[node].L=V[node].R=-1;
		V[node].V=A[rpos[V[node].SL]];
	}
	else {
		ptr++;
		node=expr();
		V[node].SL--;
		V[node].SR++;
		ptr++;
	}
	return node;
}

int term() {
	vector<int> child;
	child.push_back(value());
	while(ptr<N && S[ptr]=='*') {
		ptr++;
		child.push_back(value());
	}
	reverse(ALL(child));
	while(child.size()>1) {
		int node=V.size();
		V.resize(node+1);
		int lef=child.back();
		child.pop_back();
		int ri=child.back();
		child.pop_back();
		
		V[node].L=lef;
		V[node].R=ri;
		V[node].SL=V[lef].SL;
		V[node].SR=V[ri].SR;
		V[node].V=(V[lef].V*V[ri].V)%mo;
		pmul[V[lef].SL].push_back(V[ri].V);
		pdiv[V[lef].SR].push_back(V[ri].V);
		pmul[V[ri].SL].push_back(V[lef].V);
		pdiv[V[ri].SR].push_back(V[lef].V);
		child.push_back(node);
	}
	return child[0];
}

int expr() {
	vector<int> child;
	child.push_back(term());
	while(ptr<N && (S[ptr]=='+' || S[ptr]=='-')) {
		ptr++;
		child.push_back(term());
	}
	reverse(ALL(child));
	while(child.size()>1) {
		int node=V.size();
		V.resize(node+1);
		int lef=child.back();
		child.pop_back();
		int ri=child.back();
		child.pop_back();
		
		V[node].L=lef;
		V[node].R=ri;
		V[node].SL=V[lef].SL;
		V[node].SR=V[ri].SR;
		if(S[V[lef].SR]=='+') V[node].V=(V[lef].V+V[ri].V)%mo;
		if(S[V[lef].SR]=='-') {
			V[node].V=(V[lef].V-V[ri].V+mo)%mo;
			pmul[V[ri].SL].push_back(mo-1);
			pdiv[V[ri].SR].push_back(mo-1);
		}
		child.push_back(node);
	}
	return child[0];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	cin>>Q;
	N=S.size();
	x=0;
	FOR(i,N) if(S[i]=='a') {
		pos[x]=i;
		rpos[i]=x;
		x++;
	}
	FOR(i,x) cin>>A[i];
	expr();
	
	ll sm=1;
	int np=0;
	FOR(i,N) {
		FORR(v,pmul[i]) {
			if(v%mo==0) np++;
			else sm=sm*v%mo;
		}
		FORR(v,pdiv[i]) {
			if(v%mo==0) np--;
			else sm=sm*modpow(v)%mo;
		}
		if(np==0) smul[i]=sm;
	}
	
	ll ret=V.back().V;
	while(Q--) {
		cin>>x>>y;
		ll dif=y-A[x-1];
		ll tot=(ret+dif*smul[pos[x-1]])%mo+mo;
		cout<<tot%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
