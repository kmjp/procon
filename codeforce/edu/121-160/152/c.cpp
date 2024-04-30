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

int T,N,M;
string S;
const ll mo[2]={1000000007,1000000009};
ll A[2][202020];
ll B[2][202020];
ll p2[2][202020];
int num[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		p2[i][0]=1;
		FOR(j,201010) {
			p2[i][j+1]=p2[i][j]*2%mo[i];
			A[i][j+1]=(A[i][j]+p2[i][j])%mo[i];
		}
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>S;
		
		FOR(i,2) {
			FOR(j,N) {
				num[j+1]=num[j]+(S[j]-'0');
				B[i][j+1]=B[i][j];
				if(S[j]=='1') B[i][j+1]=(B[i][j]+p2[i][j])%mo[i];
			}
		}
		set<pair<ll,ll>> V;
		FOR(i,M) {
			int L,R;
			cin>>L>>R;
			ll a[2];
			FOR(j,2) {
				ll b=B[j][L-1]+B[j][N]-B[j][R]+mo[j];
				int n=num[R]-num[L-1];
				b+=A[j][n]*p2[j][R-n];
				a[j]=b%mo[j];
				
			}
			V.insert({a[0],a[1]});
		}
		cout<<V.size()<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
