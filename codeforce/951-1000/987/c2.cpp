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

int from[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		if(N%2) {
			if(N<=26) {
				cout<<-1<<endl;
				continue;
			}
			ret[0]=ret[9]=ret[25]=1;
			ret[10]=ret[26]=2;
			int nex=3;
			for(i=1;i<9;i+=2) ret[i]=ret[i+1]=nex++;
			for(i=11;i<25;i+=2) ret[i]=ret[i+1]=nex++;
			for(i=27;i<N;i+=2) ret[i]=ret[i+1]=nex++;
			FOR(i,N) cout<<ret[i]<<" ";
			cout<<endl;
			
		}
		else {
			N/=2;
			FOR(i,N) cout<<i+1<<" "<<i+1<<" ";
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
