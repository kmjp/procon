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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N>>S;
		x=0;
		vector<int> V;
		int step=0;
		for(i=0;i<2*N;i+=2) if(S[i]!=S[i+1]) {
			if(S[i]=='0'+step) V.push_back(i+1);
			else V.push_back(i+2);
			step^=1;
		}
		
		if(V.size()%2) {
			cout<<-1<<endl;
		}
		else {
			cout<<V.size();
			FORR(v,V) cout<<" "<<v;
			cout<<endl;
			FOR(i,N) cout<<(i*2+1)<<" ";
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
