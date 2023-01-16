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

int N;
string S,T;
int A,B,L;
ll F[202020],G[202020],num[202020];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	A=S.size();
	B=T.size();
	FOR(i,min(A,B)) {
		if(S[i]!=T[i]) break;
		L=i+1;
	}
	if(A>B) swap(A,B);
	
	FOR(i,202020) {
		F[i]=((i+3)*modpow(2,i)+(i-3)*modpow(2,2*i))%mo;
		G[i]=((i-2)*modpow(2,i)+2)%mo;
		num[i]=modpow(2,i)-1;
	}
	ll tot=F[N];
	if(A==B&&A==L) {
		cout<<tot<<endl;
		return;
	}
	//cout<<A<<" "<<B<<" "<<L<<endl;
	vector<ll> C,CS,CW;
	if(A==L) {
		C.push_back(num[N]-num[N-A]);
		for(i=A+1;i<B;i++) {
			C.push_back(num[N+1-i]-num[N-i]);
		}
		C.push_back(num[N+1-B]);
	}
	else {
		C.push_back(num[N+1-A]);
		for(i=A-1;i>L;i--) {
			C.push_back(num[N+1-i]-num[N-i]);
		}
		C.push_back(num[N]-num[N-L]*2);
		for(i=L+1;i<B;i++) {
			C.push_back(num[N+1-i]-num[N-i]);
		}
		C.push_back(num[N+1-B]);
	}
	CS={C[0]};
	CW={0};
	for(i=1;i<C.size();i++) {
		CS.push_back((CS.back()+C[i]+mo)%mo);
		CW.push_back((CW.back()+i*C[i]%mo+mo)%mo);
	}
	assert(CS.back()==num[N]);
	FOR(i,C.size()) {
		j=i+(C.size()+1)/2;
		if(j>=C.size()) break;
		(tot-=((CW.back()-CW[j-1])-i*(CS.back()-CS[j-1]))%mo*C[i]%mo)%=mo;
		(tot+=(((int)C.size()+i)*(CS.back()-CS[j-1])-(CW.back()-CW[j-1]))%mo*C[i]%mo)%=mo;
	}
	
	cout<<(tot%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
