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

string S="";

int ask(int K) {
	int x=0;
	if(S.size()) {
		int i;
		FOR(i,K) x+=S[i]-'0';
	}
	else {
		cout<<"? "<<K<<endl;
		cin>>x;
	}
	x=x-(K-x);
	return x;
}
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=ask(1);
	y=ask(N-1);
	
	if(x==y) {
		cout<<"! "<<2<<" "<<(N-1)<<endl;
		return;
	}
	
	int L=1,R=N-1;
	while(R>L+1) {
		int M=(L+R)/2;
		r=ask(M);
		
		if(r==0) {
			if(M>=N/2) {
				cout<<"! "<<1<<" "<<M<<endl;
				return;
			}
			else {
				cout<<"! "<<(M+1)<<" "<<N<<endl;
				return;
			}
		}
		
		if(r>0) {
			if(x>0) L=M;
			else R=M;
		}
		else {
			if(x<0) L=M;
			else R=M;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
