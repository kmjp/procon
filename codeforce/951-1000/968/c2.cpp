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

int T,N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int C[26]={};
		FORR(c,S) C[c-'a']++;
		int ma=-1;
		FOR(i,26) if(C[i]>N-C[i]) ma=i;
		if(ma==-1) {
			int pre=-1;
			FOR(i,N) {
				int be=0;
				FOR(j,26) if(j!=pre&&C[j]>C[be]) be=j;
				cout<<(char)('a'+be);
				C[be]--;
				pre=be;
			}
			cout<<endl;
		}
		else {
			int oth=N-C[ma];
			FOR(i,oth) {
				FOR(j,26) if(C[j]&&j!=ma) {
					C[j]--;
					C[ma]--;
					cout<<(char)('a'+j);
					cout<<(char)('a'+ma);
					break;
				}
			}
			FOR(i,C[ma]) cout<<(char)('a'+ma);
			cout<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
