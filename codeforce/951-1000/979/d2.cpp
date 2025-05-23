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

int T;
int N,Q;
int P[202020];
string S;

int NG[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) NG[i]=0;
		FOR(i,N) {
			cin>>x;
			x--;
			if(i<x) {
				NG[i]++;
				NG[x]--;
			}
			else {
				NG[x]++;
				NG[i]--;
			}
		}
		cin>>S;
		FOR(i,N) {
			NG[i+1]+=NG[i];
		}
		int num=0;
		FOR(i,N-1) if(NG[i]&&S[i]=='L'&&S[i+1]=='R') num++;
		while(Q--) {
			cin>>x;
			x--;
			if(x<N-1&&NG[x]&&S[x]=='L'&&S[x+1]=='R') num--;
			if(x>0&&NG[x-1]&&S[x-1]=='L'&&S[x]=='R') num--;
			
			if(S[x]=='L') {
				S[x]='R';
			}
			else {
				S[x]='L';
			}
			if(x<N-1&&NG[x]&&S[x]=='L'&&S[x+1]=='R') num++;
			if(x>0&&NG[x-1]&&S[x-1]=='L'&&S[x]=='R') num++;
			
			if(num==0) {
				cout<<"YES"<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
