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
string S;
int E[28][28];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	E['w'-'a']['a'-'a']=1;
	E['w'-'a']['o'-'a']=1;
	E['a'-'a']['n'-'a']=1;
	E['o'-'a']['n'-'a']=1;
	E['n'-'a']['n'-'a']=1;
	E['a'-'a']['w'-'a']=1;
	E['o'-'a']['w'-'a']=1;
	E['n'-'a']['w'-'a']=1;
	E[26]['w'-'a']=1;
	E[26]['n'-'a']=1;
	
	
	cin>>N>>S;
	int mask=1<<26;
	FORR(c,S) {
		int nmask=0;
		FOR(i,27) if(mask&(1<<i)) {
			FOR(j,26) if((c=='a'+j||c=='?')&&E[i][j]) nmask|=1<<j;
		}
		mask=nmask;
	}
	
	if((mask&(1<<0))||(mask&(1<<('o'-'a')))||(mask&(1<<('n'-'a')))) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
