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

ll F(ll v) {
	int ret=0;
	if(v<0) {
		ret++;
		v=-v;
	}
	if(v==0) return 6;
	int S[10]={6,2,5,5,4,5,6,4,7,6};
	while(v) {
		ret+=S[v%10];
		v/=10;
	}
	return ret;
}

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}

string P,N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>N;
	if(N=="0") {
		cout<<P<<endl;
		return;
	}
	
	N=decdec(N);
	int cur=0;
	FORR(c,P) {
		int S[10]={6,2,5,5,4,5,6,4,7,6};
		if(c=='-') cur++;
		else cur+=S[c-'0'];
	}
	
	while(N!="0") {
		N=decdec(N);
		int nex=F(cur);
		if(nex==cur) break;
		cur=nex;
	}
	cout<<cur<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
