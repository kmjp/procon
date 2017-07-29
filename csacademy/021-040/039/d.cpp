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

ll K;
int S[10]={6,2,5,5,4,5,6,3,7,6};
string C;

string cand[70];

void dfs(string s,int left,int hoge) {
	sort(ALL(s));
	if(s.size()>1 && s[0]=='0') {
		int i;
		FOR(i,s.size()) if(s[i]!='0') {
			swap(s[i],s[0]);
			break;
		}
	}
	if(count(ALL(s),'0')!=s.size()) {
		if(cand[hoge]=="*" || s.size()<cand[hoge].size() || (s.size()==cand[hoge].size() && s<cand[hoge])) cand[hoge]=s;
	}
	
	if(left==0) return;
	for(int i=2;i<=7;i++) {
		dfs(s+C[i],left-1,hoge+i);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	C.resize(10);
	for(i=9;i>=0;i--) C[S[i]]='0'+i;
	
	FOR(i,70) cand[i]="*";
	dfs("",7,0);
	
	cin>>K;
	if(K==6) {
		cout<<0<<endl;
		return;
	}
	string R;
	for(i=2;i<70;i++) {
		if(cand[i]!="*" && K>=i && (K-i)%7==0) {
			string T=cand[i]+string((K-i)/7,'8');
			if(R.empty() || T.size()<R.size() || (T.size()==R.size() && T<R)) R=T;
		}
		
		if(i%6==0 && K>=i && (K-i)%7==0) {
			string T="6"+string(i/6-1,'0') + string((K-i)/7,'8');
			if(R.empty() || T.size()<R.size() || (T.size()==R.size() && T<R)) R=T;
		}
	}
	
	if(R.empty()) R="-1";
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
