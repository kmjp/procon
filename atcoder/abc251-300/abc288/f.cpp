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
string X;
ll F[202020];
const ll mo=998244353;
ll p2[202020];
ll S[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>X;
	
	ll p=0;
	p=F[1]=S[1]=X[0]-'0';
	for(i=2;i<=N;i++) {
		x=X[i-1]-'0';
		
		F[i]+=F[i-1]*x%mo;
		F[i]+=(F[i-1]+mo-p)*10%mo;
		(F[i]+=S[i-2]*x)%=mo;
		p=(p*10+x)%mo;
		(F[i]+=p)%=mo;
		S[i]=(S[i-1]+F[i])%mo;
	}
	cout<<F[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
