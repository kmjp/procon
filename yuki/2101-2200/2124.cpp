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

int S[5555];
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) S[N]+=i;
	
	int pre=S[N];
	for(i=1;i<=N-2;i++) {
		cout<<"? "<<i+1<<" "<<N<<endl;
		cin>>x;
		S[i]=pre-x;
		pre=x;
	}
	cout<<"? "<<N-2<<" "<<N-1<<endl;
	cin>>x;
	S[N-1]=x-S[N-2];
	for(i=1;i<=N-1;i++) S[N]-=S[i];
	
	cout<<"!";
	FOR(i,N) cout<<" "<<S[i+1];
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
