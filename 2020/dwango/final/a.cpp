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

int H,W;
string S[2525];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int sw=0;
	if(H>W) sw=1, swap(H,W);
	
	if(H==1) {
		FOR(i,W/7) S[0]+="2255555";
		if(W%7==2) {
			S[0]+="22";
		}
		else if (W%7==5) {
			S[0]="55555"+S[0];
		}
		else if(W%7) {
			return _P("No\n");
		}
	}
	else if(H==2) {
		FOR(i,W/7) {
			S[0]+="2552555";
			S[1]+="2555255";
		}
		if(W%7==1) {
			S[0]+="2";
			S[1]+="2";
		}
		else if (W%7==6) {
			S[0]="552555"+S[0];
			S[1]="555255"+S[1];
		}
		else if(W%7) {
			return _P("No\n");
		}
	}
	else if(H==3) {
		if(W==3) {
			cout<<"Yes"<<endl;
			cout<<"225"<<endl;
			cout<<"555"<<endl;
			cout<<"225"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		return;
	}
	else {
		cout<<"No"<<endl;
		return;
	}
	
	
	
	cout<<"Yes"<<endl;
	if(sw) {
		FOR(x,W) {
			FOR(y,H) cout<<S[y][x];
			cout<<endl;
		}
	}
	else {
		FOR(y,H) cout<<S[y]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
