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

int T,N,Y,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Y>>X;
		Y--;
		X--;
		if(N%2||(X+Y)%2==0) {
			cout<<"No"<<endl;
			continue;
		}
		
		string S;
		y=x=0;
		while(x<=X-2) {
			if(x%2==0) {
				FOR(i,N-1) S+="D";
				S+="R";
				y=N-1,x++;
			}
			else {
				FOR(i,N-1) S+="U";
				S+="R";
				y=0,x++;
			}
		}
		
		int step=0;
		if(y==0) {
			FOR(i,N) {
				if(Y!=y) {
					if(step==0) {
						S+="R";
						x++;
					}
					else {
						S+="L";
						x--;
					}
					step^=1;
				}
				else {
					assert(x!=X);
				}
				if(i!=N-1) {
					S+="D";
					y++;
				}
			}
		}
		else {
			FOR(i,N) {
				if(Y!=y) {
					if(step==0) {
						S+="R";
						x++;
					}
					else {
						S+="L";
						x--;
					}
					step^=1;
				}
				else {
					assert(x!=X);
				}
				if(i!=N-1) {
					S+="U";
					y--;
				}
			}
		}
		while(x!=N-1) {
			S+="R";
			x++;
			if(y==0) {
				FOR(i,N-1) S+="D";
				y=N-1;
			}
			else {
				FOR(i,N-1) S+="U";
				y=0;
			}
		}
		cout<<"Yes"<<endl;
		cout<<S<<endl;
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
