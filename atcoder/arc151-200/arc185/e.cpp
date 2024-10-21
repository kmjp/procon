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

int N,A[505050];
const ll mo=998244353;

ll pat[505050];

vector<int> cand[505050];
ll p2[1505050];
ll sum[505050];
ll p[505050];
map<int,ll> M[105050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	p2[0]=1;
	FOR(i,1505040) p2[i+1]=p2[i]*2%mo;
	
	for(i=1;i<=100000;i++) {
		for(j=i;j<=100000;j+=i) cand[j].push_back(i);
		FORR(d,cand[i]) {
			M[i][d]=(M[i][d]%mo+d)%mo;
			FORR(d2,cand[i]) if(d2>d&&d2%d==0) M[i][d2]-=M[i][d];
		}
		FORR(d,cand[i]) M[i][d]%=mo;
		
	}
	
	cin>>N;
	ll CS=0;
	FOR(i,N) {
		cin>>A[i];
		CS*=2;
		
		FORR(d,cand[A[i]]) {
			p[d]=sum[d];
			(CS+=M[A[i]][d]*p[d])%=mo;
			(sum[d]+=p2[i])%=mo;
		}
		
		
		CS%=mo;
		cout<<CS<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
