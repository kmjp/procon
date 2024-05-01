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
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	int dif=0;
	FOR(i,N) if(S[i]!=T[i]) dif++;
	if(dif%2) {
		cout<<-1<<endl;
		return;
	}
	int a=dif/2,b=dif/2;
	string U;
	FOR(i,N) {
		if(S[i]==T[i]) {
			U+="0";
		}
		else {
			if(S[i]=='0'&&a) {
				U+="0";
				a--;
			}
			else if(T[i]=='0'&&b) {
				U+="0";
				b--;
			}
			else {
				U+="1";
				if(S[i]=='1') a--;
				else b--;
			}
			
		}
	}
	cout<<U<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
