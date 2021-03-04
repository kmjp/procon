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

int N,K;

int palin(string SS) {
	int i;
	FOR(i,SS.size()) if(SS[i]!=SS[SS.size()-1-i]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(N>=10) {
		if(K<=3) return _P("-1\n");
		string S="";
		FOR(i,K) S+='1';
		FOR(i,100000) S+="010011";
		cout<<S.substr(0,N)<<endl;
	}
	else {
		int mask;
		FOR(mask,1<<N) {
			string S;
			FOR(i,N) S.push_back('0'+(mask>>i)%2);
			int ma=0;
			for(int len=1;len<=N;len++) {
				for(x=0;x+len<=N;x++) if(palin(S.substr(x,len))) ma=len;
			}
			
			if(ma==K) {
				cout<<S<<endl;
				return;
			}
			
		}
		cout<<"-1"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
