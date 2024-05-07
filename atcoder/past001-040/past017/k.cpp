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
string S;
int from[202020][10];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	MINUS(from);
	from[0][0]=0;
	FOR(i,N) {
		FOR(x,10) if(S[i]=='?'||S[i]=='0'+x) {
			FOR(y,10) if(from[i][y]>=0) {
				from[i+1][(y+x*(i+1))%10]=x;
			}
		}
	}
	if(from[N][0]==-1) {
		cout<<"No"<<endl;
	}
	else {
		vector<int> V;
		x=N,y=0;
		while(x) {
			V.push_back(from[x][y]);
			y=(y-from[x][y]*x%10+10)%10;
			x--;
		}
		cout<<"Yes"<<endl;
		reverse(ALL(V));
		FORR(v,V) cout<<v;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
