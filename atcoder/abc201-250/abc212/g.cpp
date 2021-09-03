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


ll P;
const ll mo=998244353;
ll num[10101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	P--;
	vector<ll> A;
	for(ll a=1;a*a<=P;a++) if(P%a==0) {
		A.push_back(a);
		if(a*a!=P) A.push_back(P/a);
	}
	sort(ALL(A));
	
	ll ret=1;
	for(i=A.size()-1;i>=0;i--) {
		num[i]=P/A[i];
		for(j=i+1;j<A.size();j++) if(A[j]%A[i]==0) num[i]-=num[j];
		(ret+=num[i]%mo*(P/A[i]%mo))%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
