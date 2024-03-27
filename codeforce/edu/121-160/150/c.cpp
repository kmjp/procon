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

ll from[6][2];
ll to[6][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		reverse(ALL(S));
		
		FOR(i,6) from[i][0]=from[i][1]=-1LL<<60;
		from[0][0]=0;
		vector<int> C={1,10,100,1000,10000};
		FORR(c,S) {
			c-='A';
			FOR(i,5) to[i][0]=to[i][1]=-1LL<<60;
			
			FOR(x,5) {
				if(c>=x) {
					to[c][0]=max(to[c][0],from[x][0]+C[c]);
					to[c][1]=max(to[c][1],from[x][1]+C[c]);
				}
				else {
					to[x][0]=max(to[x][0],from[x][0]-C[c]);
					to[x][1]=max(to[x][1],from[x][1]-C[c]);
				}
				FOR(y,5) {
					if(y>=x) {
						to[y][1]=max(to[y][1],from[x][0]+C[y]);
					}
					else {
						to[x][1]=max(to[x][1],from[x][0]-C[y]);
					}
				}
				
			}
			
			
			swap(from,to);
		}
		
		ll ret=-1LL<<60;
		FOR(i,5) ret=max(ret,from[i][1]);
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
