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

int H,W,Q;
int R[202020],C[202020];
string V[202020];
string S[202020];
int ma[202020];
int sw=0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	if(H>W) {
		sw=1;
		swap(H,W);
	}
	FOR(i,Q) {
		cin>>R[i]>>C[i]>>V[i];
		if(sw) swap(R[i],C[i]);
	}
	FOR(y,H) S[y]=string(W,'A');
	for(i=Q-1;i>=0;i--) {
		FOR(y,R[i]) {
			for(x=ma[y];x<C[i];x++) {
				S[y][x]=V[i][0];
			}
			ma[y]=max(ma[y],C[i]);
		}
	}
	if(sw==0) {
		FOR(y,H) {
			cout<<S[y]<<endl;
		}
	}
	else {
		FOR(x,W) {
			FOR(y,H) cout<<S[y][x];
			cout<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
