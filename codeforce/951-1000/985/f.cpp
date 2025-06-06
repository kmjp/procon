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
string C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C;
		//R2òAë±Ç∆B2òAë±Ç™óºï˚Ç†ÇÈÇ∆É_ÉÅ
		int ng=0;
		FOR(i,N) {
			if(C[i]=='R'&&C[(i+1)%N]=='R') ng|=1;
			if(C[i]=='B'&&C[(i+1)%N]=='B') ng|=2;
		}
		if(ng==0||ng==3) {
			cout<<"NO"<<endl;
			continue;
		}
		if(ng==2) {
			FOR(i,N) C[i]='R'+'B'-C[i];
		}
		FOR(x,N) if(C[x]=='B') break;
		if(x==N) {
			cout<<"YES"<<endl;
			continue;
		}
		vector<int> V={};
		FOR(i,N) {
			if(C[(x+i)%N]=='B') V.push_back(0);
			else V.back()^=1;
		}
		int D[2]={};
		FORR(v,V) D[v]++;
		
		if(D[0]==1||V.size()==1) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
