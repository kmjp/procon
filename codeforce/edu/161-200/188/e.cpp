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

string V[1000000];
int nex[1000000];

int T;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=900000;i++) {
		x=i;
		V[i]=to_string(x);
		if(x>=10) {
			y=0;
			while(x) y+=x%10,x/=10;
			nex[i]=y;
			V[i]+=V[y];
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>S;
		int C[11]={};
		FORR(c,S) {
			C[c-'0']++;
			C[10]+=c-'0';
		}
		for(i=max(C[10]-100,1);i<=C[10];i++) {
			int ts=C[10];
			int ok=1;
			FORR(c,V[i]) {
				C[c-'0']--;
				ts-=c-'0';
				if(C[c-'0']<0) ok=0;
			}
			if(ok&&ts==i) {
				for(j=9;j>=0;j--) {
					FOR(x,C[j]) cout<<j;
				}
				cout<<V[i]<<endl;
				break;
			}
			if(count(C,C+10,0)==10) {
				cout<<V[i]<<endl;
				break;
			}
			FORR(c,V[i]) {
				C[c-'0']++;
			}
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
