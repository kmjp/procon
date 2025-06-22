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
int ask(int a,int b) {
	cout<<"? "<<a+1<<" "<<b<<endl;
	cin>>a;
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		x=ask(0,N);
		if(x==0) {
			cout<<"! IMPOSSIBLE"<<endl;
			continue;
		}
		S="";
		FOR(i,N) S+="0";
		int step=1;
		for(i=1;i<N-1;i++) {
			y=ask(i,N);
			step++;
			if(x==y) {
				S[i-1]='1';
			}
			else {
				S[i-1]='0';
				k=i-1;
				break;
			}
		}
		if(i==N-1) k=N;
		int pre=0;
		for(i=k+1;i<N-1;i++) {
			y=ask(k,i+1);
			if(pre!=y) {
				S[i]='1';
				pre=y;
			}
		}
		int sum=0;
		int cur=0;
		FOR(i,N) {
			if(S[i]=='0') cur++;
			else sum+=cur;
		}
		if(sum!=x) S[N-1]='1';
		
		
		cout<<"! "<<S<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}


