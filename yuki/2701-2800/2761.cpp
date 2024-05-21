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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,12> bt[1010][3];
ll mo[3]={998244353,1000000007,1000000009};
ll p[5050][3];

int N,L,Q;
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(j,3) {
		p[0][j]=1;
		p[1][j]=rand();
		for(i=1;i<=3010;i++) p[i+1][j]=p[i][j]*p[1][j]%mo[j];
	}
	
	
	cin>>N>>L>>Q;
	FOR(i,N) {
		cin>>S[i];
		FOR(j,L) {
			FOR(k,3) bt[i][k].add(j,S[i][j]*p[j][k]%mo[k]);
		}
	}
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			int k;
			char c,d;
			cin>>k>>c>>d;
			k--;
			FOR(i,N) if(S[i][k]==c) {
				FOR(j,3) {
					bt[i][j].add(k,-((ll)c*p[k][j]%mo[j]));
					bt[i][j].add(k,((ll)d*p[k][j]%mo[j]));
				}
				S[i][k]=d;
			}
		}
		else {
			cin>>s;
			ll ret[3]={};
			
			FOR(k,3) {
				FOR(i,s.size()) ret[k]+=(ll)s[i]*p[i][k]%mo[k];
			}
			int ok=0;
			FOR(i,N) {
				int nok=0;
				FOR(j,3) if(ret[j]==bt[i][j](s.size()-1)) nok++;
				if(nok==3) ok++;
			}
			cout<<ok<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
