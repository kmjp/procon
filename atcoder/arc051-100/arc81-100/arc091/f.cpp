#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A,K;
int gr[101010];


int hoge(int A,int K) {
	if(A<K) return 0;
	if(A%K==0) return A/K;
	
	int dif=((A/K)+1);
	return hoge(A-max((A%K)/dif,1)*dif,K);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	/*
	for(i=0;i<=100;i++) {
		set<int> S;
		for(x=1;x<=i/N;x++) S.insert(gr[i-x]);
		while(S.count(gr[i])) gr[i]++;
		cout<<i<<" "<<gr[i]<<" "<<hoge(i,N)<<endl;
	}
	
	return;
	*/
	int nim=0;
	FOR(i,N) {
		cin>>A>>K;
		nim ^= hoge(A,K);
	}
	if(nim==0) cout<<"Aoki"<<endl;
	else cout<<"Takahashi"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
