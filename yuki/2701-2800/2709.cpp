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
int P,Q;
ll mo;
int A[202];

ll po[4][2020202];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>P>>Q;
	mo=P;
	FOR(i,N) {
		cin>>A[i];
	}
	sort(A,A+N);
	po[0][0]=po[1][0]=po[2][0]=po[3][0]=1;
	FOR(i,2020101) {
		po[0][i+1]=po[0][i]*10%P;
		po[1][i+1]=po[1][i]*9%P;
		po[2][i+1]=po[2][i]*7%P;
		po[3][i+1]=po[3][i]*5%P;
	}
		
	
	ll ret=0;
	FOR(j,N) {
		for(i=j+1;i<N;i++) {
			for(x=i+1;x<N;x++) for(y=x+1;y<N;y++) {
				int v=po[0][A[j]]+po[1][A[i]]+po[2][A[x]]+po[3][A[y]];
				if(v%P==Q) ret++;
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
