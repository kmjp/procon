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
string S[2];
int L[202020][4];
int R[202020][4];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S[0]>>S[1];
		while(S[0].back()=='.'&&S[1].back()=='.') {
			N--;
			S[0].pop_back();
			S[1].pop_back();
		}
		reverse(ALL(S[0]));
		reverse(ALL(S[1]));
		while(S[0].back()=='.'&&S[1].back()=='.') {
			N--;
			S[0].pop_back();
			S[1].pop_back();
		}
		if(S[0][0]=='*'&&S[1][0]=='.') {
			L[0][1]=0;
			L[0][2]=1;
			L[0][3]=1<<20;
		}
		if(S[0][0]=='.'&&S[1][0]=='*') {
			L[0][1]=1;
			L[0][2]=0;
			L[0][3]=1<<20;
		}
		if(S[0][0]=='*'&&S[1][0]=='*') {
			L[0][1]=L[0][2]=1;
			L[0][3]=0;
		}
		for(i=1;i<N;i++) {
			L[i][1]=L[i][2]=L[i][3]=1<<30;
			if(S[0][i]=='.'&&S[1][i]=='.') {
				L[i][1]=min(L[i][1],L[i-1][1]+1);
				L[i][1]=min(L[i][1],L[i-1][2]+2);
				L[i][1]=min(L[i][1],L[i-1][3]+2);
				L[i][2]=min(L[i][2],L[i-1][1]+2);
				L[i][2]=min(L[i][2],L[i-1][2]+1);
				L[i][2]=min(L[i][2],L[i-1][3]+2);
				L[i][3]=min(L[i][3],L[i-1][3]+2);
			}
			if(S[0][i]=='*'&&S[1][i]=='*') {
				L[i][1]=min(L[i][1],L[i-1][1]+2);
				L[i][1]=min(L[i][1],L[i-1][2]+2);
				L[i][1]=min(L[i][1],L[i-1][3]+3);
				L[i][2]=min(L[i][2],L[i-1][1]+2);
				L[i][2]=min(L[i][2],L[i-1][2]+2);
				L[i][2]=min(L[i][2],L[i-1][3]+3);
				L[i][3]=min(L[i][3],L[i-1][1]+1);
				L[i][3]=min(L[i][3],L[i-1][2]+1);
				L[i][3]=min(L[i][3],L[i-1][3]+2);
			}
			if(S[0][i]=='*'&&S[1][i]=='.') {
				L[i][1]=min(L[i][1],L[i-1][1]+1);
				L[i][1]=min(L[i][1],L[i-1][2]+2);
				L[i][1]=min(L[i][1],L[i-1][3]+2);
				L[i][2]=min(L[i][2],L[i-1][1]+2);
				L[i][2]=min(L[i][2],L[i-1][2]+2);
				L[i][2]=min(L[i][2],L[i-1][3]+3);
				L[i][3]=min(L[i][3],L[i-1][1]+2);
				L[i][3]=min(L[i][3],L[i-1][2]+1);
				L[i][3]=min(L[i][3],L[i-1][3]+2);
			}
			if(S[0][i]=='.'&&S[1][i]=='*') {
				L[i][1]=min(L[i][1],L[i-1][1]+2);
				L[i][1]=min(L[i][1],L[i-1][2]+2);
				L[i][1]=min(L[i][1],L[i-1][3]+3);
				L[i][2]=min(L[i][2],L[i-1][1]+2);
				L[i][2]=min(L[i][2],L[i-1][2]+1);
				L[i][2]=min(L[i][2],L[i-1][3]+2);
				L[i][3]=min(L[i][3],L[i-1][1]+1);
				L[i][3]=min(L[i][3],L[i-1][2]+2);
				L[i][3]=min(L[i][3],L[i-1][3]+2);
			}
		}
		if(S[0].back()=='*'&&S[1].back()=='.') {
			R[N-1][1]=0;
			R[N-1][2]=1;
			R[N-1][3]=1<<20;
		}
		if(S[0].back()=='.'&&S[1].back()=='*') {
			R[N-1][1]=1;
			R[N-1][2]=0;
			R[N-1][3]=1<<20;
		}
		if(S[0].back()=='*'&&S[1].back()=='*') {
			R[N-1][1]=R[N-1][2]=1;
			R[N-1][3]=0;
		}
		for(i=N-2;i>=0;i--) {
			R[i][1]=R[i][2]=R[i][3]=1<<30;
			if(S[0][i]=='.'&&S[1][i]=='.') {
				R[i][1]=min(R[i][1],R[i+1][1]+1);
				R[i][1]=min(R[i][1],R[i+1][2]+2);
				R[i][1]=min(R[i][1],R[i+1][3]+2);
				R[i][2]=min(R[i][2],R[i+1][1]+2);
				R[i][2]=min(R[i][2],R[i+1][2]+1);
				R[i][2]=min(R[i][2],R[i+1][3]+2);
				R[i][3]=min(R[i][3],R[i+1][3]+2);
			}
			if(S[0][i]=='*'&&S[1][i]=='*') {
				R[i][1]=min(R[i][1],R[i+1][1]+2);
				R[i][1]=min(R[i][1],R[i+1][2]+2);
				R[i][1]=min(R[i][1],R[i+1][3]+3);
				R[i][2]=min(R[i][2],R[i+1][1]+2);
				R[i][2]=min(R[i][2],R[i+1][2]+2);
				R[i][2]=min(R[i][2],R[i+1][3]+3);
				R[i][3]=min(R[i][3],R[i+1][1]+1);
				R[i][3]=min(R[i][3],R[i+1][2]+1);
				R[i][3]=min(R[i][3],R[i+1][3]+2);
			}
			if(S[0][i]=='*'&&S[1][i]=='.') {
				R[i][1]=min(R[i][1],R[i+1][1]+1);
				R[i][1]=min(R[i][1],R[i+1][2]+2);
				R[i][1]=min(R[i][1],R[i+1][3]+2);
				R[i][2]=min(R[i][2],R[i+1][1]+2);
				R[i][2]=min(R[i][2],R[i+1][2]+2);
				R[i][2]=min(R[i][2],R[i+1][3]+3);
				R[i][3]=min(R[i][3],R[i+1][1]+2);
				R[i][3]=min(R[i][3],R[i+1][2]+1);
				R[i][3]=min(R[i][3],R[i+1][3]+2);
			}
			if(S[0][i]=='.'&&S[1][i]=='*') {
				R[i][1]=min(R[i][1],R[i+1][1]+2);
				R[i][1]=min(R[i][1],R[i+1][2]+2);
				R[i][1]=min(R[i][1],R[i+1][3]+3);
				R[i][2]=min(R[i][2],R[i+1][1]+2);
				R[i][2]=min(R[i][2],R[i+1][2]+1);
				R[i][2]=min(R[i][2],R[i+1][3]+2);
				R[i][3]=min(R[i][3],R[i+1][1]+1);
				R[i][3]=min(R[i][3],R[i+1][2]+2);
				R[i][3]=min(R[i][3],R[i+1][3]+2);
			}
		}
		int ret=1<<30;
		if(N==1) {
			ret=min({L[0][1],L[0][2],L[0][3]+1});
		}
		else {
			FOR(i,N-1) {
				ret=min(ret,L[i][1]+R[i+1][1]+1);
				ret=min(ret,L[i][1]+R[i+1][2]+2);
				ret=min(ret,L[i][1]+R[i+1][3]+2);
				ret=min(ret,L[i][2]+R[i+1][1]+2);
				ret=min(ret,L[i][2]+R[i+1][2]+1);
				ret=min(ret,L[i][2]+R[i+1][3]+2);
				ret=min(ret,L[i][3]+R[i+1][1]+2);
				ret=min(ret,L[i][3]+R[i+1][2]+2);
				ret=min(ret,L[i][3]+R[i+1][3]+3);
			}
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
