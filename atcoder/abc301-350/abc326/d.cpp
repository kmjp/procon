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
string S[5];
string R,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>R>>C;
	vector<int> P[3];
	FOR(i,N) {
		P[0].push_back(i);
		P[1].push_back(i);
		P[2].push_back(i);
	}
	do {
		do {
			do {
				FOR(y,N) FOR(x,N) S[y]=string(N,'.');
				FOR(i,3) {
					FOR(y,N) {
						if(S[y][P[i][y]]!='.') break;
						S[y][P[i][y]]='A'+i;
					}
					if(y<N) break;
				}
				if(i==3) {
					string a,b;
					FOR(y,N) {
						FOR(x,N) if(S[y][x]!='.') {
							a+=S[y][x];
							break;
						}
						FOR(x,N) if(S[x][y]!='.') {
							b+=S[x][y];
							break;
						}
					}
					if(a==R&&b==C) {
						cout<<"Yes"<<endl;
						FOR(y,N) cout<<S[y]<<endl;
						return;
					}
					
				}
			} while(next_permutation(ALL(P[0])));
		}while(next_permutation(ALL(P[1])));
	}while(next_permutation(ALL(P[2])));
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
