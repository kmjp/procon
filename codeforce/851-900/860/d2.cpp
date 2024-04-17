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

int T,N;
ll A[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> P,M;
		ll PS=0,MS=0;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]>0) {
				P.push_back(A[i]);
				PS+=A[i];
			}
			else if(A[i]<0) {
				M.push_back(-A[i]);
				MS+=-A[i];
			}
			A[i]=0;
		}
		if(P.empty()) {
			cout<<"No"<<endl;
			continue;
		}
		int nex=0;
		while(PS||MS) {
			if(PS>=MS) {
				A[nex++]=P.back();
				PS-=P.back();
				P.pop_back();
			}
			else {
				A[nex++]=-M.back();
				MS-=M.back();
				M.pop_back();
			}
		}
		cout<<"Yes"<<endl;
		FOR(i,N) cout<<A[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
