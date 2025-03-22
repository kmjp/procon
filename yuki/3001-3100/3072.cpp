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

int N,KA,KB;
vector<int> A,B;
int DA[303030],DB[303030];
int Q;
int S,T;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>KA>>KB;
	FOR(i,KA) {
		cin>>x;
		A.push_back(x-1);
	}
	FOR(i,KB) {
		cin>>x;
		B.push_back(x-1);
	}
	int dif=1<<20;
	FOR(i,N) {
		x=lower_bound(ALL(A),i)-A.begin();
		if(x==0) DA[i]=A[0]-i;
		else if(x==A.size()) DA[i]=i-A.back();
		else DA[i]=min(A[x]-i,i-A[x-1]);
		x=lower_bound(ALL(B),i)-B.begin();
		if(x==0) DB[i]=B[0]-i;
		else if(x==B.size()) DB[i]=i-B.back();
		else DB[i]=min(B[x]-i,i-B[x-1]);
		dif=min(dif,DA[i]+DB[i]);
	}
	cin>>Q;
	while(Q--) {
		cin>>S>>T;
		S--,T--;
		int ret=abs(S-T);
		ret=min(ret,DA[S]+DA[T]);
		ret=min(ret,DB[S]+DB[T]);
		ret=min(ret,DA[S]+dif+DB[T]);
		ret=min(ret,DB[S]+dif+DA[T]);
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
