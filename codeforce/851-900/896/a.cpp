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

int T,H,W;

vector<int> A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int ret;
		FOR(y,H) {
			A[y].resize(W);
		}
		
		if(W>=H+1) {
			FOR(y,H) {
				FOR(x,H+1) {
					A[y][x]=(1+y+x)%(H+1);
				}
				for(x=H+1;x<W;x++) A[y][x]=x;
			}
		}
		else {
			FOR(y,H) {
				FOR(x,W) {
					if(y<W-1) {
						A[y][x]=(y+x)%W;
					}
					else {
						A[y][x]=(x)%W;
					}
				}
			}
		}
		
		set<int> X,Y;
		FOR(x,W) {
			set<int> Y;
			FOR(y,H) Y.insert(A[y][x]);
			i=0;
			while(Y.count(i)) i++;
			X.insert(i);
		}
		
		i=0;
		while(X.count(i)) i++;
		cout<<i<<endl;
		
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x]<<" ";
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
