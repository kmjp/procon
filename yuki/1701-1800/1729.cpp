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

string S;
int C[8];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int cur=0;
	while(S.size()) {
		string V=S.substr(max(0,(int)S.size()-3));
		x=0;
		FORR(c,V) x=x*16+(c-'A'+10);
		if(S.size()<=3) {
			while(x) {
				C[x%8]++;
				x/=8;
			}
		}
		else {
			FOR(i,4) {
				C[x%8]++;
				x/=8;
			}
		}
		
		if(S.size()<=3) break;
		S=S.substr(0,S.size()-3);
	}
	
	int ma=0;
	FOR(i,8) ma=max(ma,C[i]);
	FOR(i,8) if(C[i]==ma) cout<<i<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
