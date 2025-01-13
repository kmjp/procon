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

ll N,M,A,B;

ll L[20202],R[20202];

ll ok[505];

ll can(ll v) {
	if(v<0) return 0;
	if(v>=400) return 1;
	return ok[v];
}

int isok(ll v) {
	if(v<0) return 0;
	if(v<L[0]) return 1;
	if(v>=R[M-1]) return 1;
	int x=lower_bound(L,L+M,v+1)-L-1;
	return (v>=R[x]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>A>>B;
	N--;
	
	ok[0]=1;
	FOR(i,404) if(ok[i]) {
		for(j=A;j<=B;j++) {
			ok[i+j]=1;
		}
	}
	
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]--;
		if(i&&R[i-1]==L[i]) {
			R[i-1]=R[i];
			i--;
			M--;
		}
		if(L[i]-1+B<R[i]) {
			cout<<"No"<<endl;
			return;
		}
	}
	L[M]=N+1;
	R[M]=N+2;
	
	if(A==B) {
		if(N%A) {
			cout<<"No"<<endl;
			return;
		}
		FOR(i,M) if(L[i]%A==0||L[i]/A!=(R[i]-1)/A) {
			cout<<"No"<<endl;
			return;
		}
		cout<<"Yes"<<endl;
		return;
	}
	map<ll,int> C;
	C[0]=1;
	for(ll i=L[0]-20;i<L[0];i++) C[i]|=can(i)&isok(i);
	
	FOR(i,M) {
		for(ll x=L[i]-B;x<L[i];x++) if(C[x]) {
			for(ll y=A;y<=B;y++) {
				if(isok(x+y)) {
					C[x+y]=1;
				}
			}
		}
		for(ll x=R[i];x<=R[i]+20;x++) if(C[x]) {
			for(ll y=L[i+1]-20;y<L[i+1];y++) {
				if(isok(y)&&can(y-x)) {
					C[y]=1;
				}
			}
		}
	}
	
	if(C[N]) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
