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

int T,N,K;
string S[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(y,N) S[y]=string(N,'.');
		
		if(N==2) {
			if(K==2) {
				cout<<"Yes"<<endl;
				cout<<"##"<<endl;
				cout<<".."<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
		else {
			if(K<=2||2*K>N*N) {
				cout<<"No"<<endl;
				continue;
			}
			
			if(K<=N) {
				FOR(x,K-1) S[0][x]='#';
				S[1][0]='#';
			}
			else {
				FOR(y,N) FOR(x,N) {
					if(y*N+x+1<=2*K-2*N) S[y][x]='?';
					else if(y*N+x+1<=2*K-N) S[y][x]='#';
				}
				int lef=K-N;
				FOR(y,N-1) FOR(x,N-1) {
					if(S[y][x]=='?'&&S[y+1][x]=='#'&&S[y][x+1]=='#') {
						S[y][x]='#';
						lef--;
					}
				}
				FOR(x,N) {
					if(x!=N-2&&x%3!=1) continue;
					FOR(y,N) {
						if(S[y][x]=='?'&&lef>0) {
							lef--;
							S[y][x]='#';
						}
						else {
							break;
						}
					}
				}
				FOR(y,N) FOR(x,N) if(S[y][x]=='?') {
					if(lef) {
						lef--, S[y][x]='#';
					}
					else {
						S[y][x]='.';
					}
				}
				
			}
			cout<<"Yes"<<endl;
			FOR(y,N) cout<<S[y]<<endl;

		}
		
	}
		
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
