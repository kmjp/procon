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

int X;
string S,T,U;
int A,B,C;

int dpdp[5020][5020];

int lcs(string& AA,string& BB) {
	int x,y,ma=0;
	FOR(x,AA.size()+2) FOR(y,BB.size()+2) dpdp[x][y]=0;
	
	FOR(x,AA.size()) FOR(y,BB.size()) {
		if(AA[x]==BB[y]) dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y]+1);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y+1]);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x+1][y]);
		ma=max(ma,dpdp[x+1][y+1]);
	}
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	while(X--) {
		cin>>S>>T>>U;
		A=S.size();
		B=T.size();
		C=U.size();
		int org=A,add=0;
		FORR(c,U) {
			if(c=='A') add++;
			else {
				if(org) org--;
				else if(add) add--;
			}
		}
		if(org+add!=B) {
			cout<<"No"<<endl;
			continue;
		}
		if(lcs(S,T)>=org) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
