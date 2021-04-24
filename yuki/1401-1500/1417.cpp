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
ll from[2][100],to[2][100];

const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>S;
	int first=1;
	FORR(c,S) {
		ZERO(to);
		from[first][1]++;
		first=0;
		
		FOR(x,100) {
			for(y=1;y<=9;y++) {
				(to[0][x*y%100]+=from[0][x])%=mo;
				if(y<c-'0') (to[0][x*y%100]+=from[1][x])%=mo;
				if(y==c-'0') (to[1][x*y%100]+=from[1][x])%=mo;
			}
		}
		
		
		swap(from,to);
	}
	
	cout<<(from[0][0]+from[1][0])%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
