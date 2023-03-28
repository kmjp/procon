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


int N,M,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	string R;
	
	if(N==0) {
		if(K==0) R=string(M,'1');
		else R="-1";
	}
	else if(M==0) {
		if(K==0) R=string(N,'0');
		else R="-1";
	}
	else if(K==0) {
		R="-1";
	}
	else if(K%2==0) {
		K/=2;
		if(M>=K&&N>K) {
			R=string(N-K,'0');
			FOR(i,K) R+="10";
			M-=K;
			R.pop_back();
			R+=string(M,'1')+"0";
		}
		else if(N==K&&M>K) {
			FOR(i,K) R+="10";
			R+=string(M-K,'1');
		}
		else {
			R="-1";
		}
	}
	else {
		R="0";
		N--;
		FOR(i,K/2) {
			R+="10";
			N--,M--;
		}
		if(N<0||M<0) {
			R="-1";
		}
		else {
			R=string(N,'0')+R+string(M,'1');
		}
		
	}
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
