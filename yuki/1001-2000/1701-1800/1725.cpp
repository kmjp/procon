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


string X,Y;
int A,B;
ll H[60],sum[60][26];

int S[101010][26];
int T[101010][26];
int Q;
int C;

ll hoge(int cur,ll num) {
	if(num==0) return 0;
	if(num>=H[cur]) {
		return sum[cur][C];
	}
	
	if(cur==1) {
		return S[num][C];
	}
	else if(num<=H[cur-1]){
		return hoge(cur-1,num);
	}
	else if(num<=H[cur-1]+B) {
		ll pat=sum[cur-1][C];
		num-=H[cur-1];
		pat+=T[num][C];
		return pat;
	}
	else {
		ll pat=sum[cur][C]-hoge(cur-1,H[cur]-num);
		return pat;
	}
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	A=X.size();
	B=Y.size();
	FOR(i,A) {
		FOR(j,26) S[i+1][j]=S[i][j];
		S[i+1][X[i]-'a']++;
	}
	FOR(i,B) {
		FOR(j,26) T[i+1][j]=T[i][j];
		T[i+1][Y[i]-'a']++;
	}
	H[1]=A;
	FOR(j,26) sum[1][j]=S[A][j];
	for(i=2;i<=40;i++) {
		H[i]=min(1LL<<60,H[i-1]*2+B);
		FOR(j,26) sum[i][j]=min(1LL<<60,sum[i-1][j]*2+T[B][j]);
	}
	
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>L>>R>>s;
		C=s[0]-'a';
		cout<<hoge(31,R)-hoge(31,L-1)<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
