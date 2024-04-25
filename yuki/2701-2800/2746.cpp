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

ll A,B;
int ok[295][86400];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	if(A>B) swap(A,B);
	if(A>=85344) {
		ll v=0;
		while((v+1000)*(v+1001)*(2*v+2001)/6<=A+B) v+=1000;
		while((v+1)*(v+2)*(2*v+3)/6<=A+B) v++;
		cout<<v<<endl;
	}
	else {
		ok[0][0]=1;
		int cand=0;
		ll v=0;
		FOR(i,293) {
			FOR(j,85400) {
				ok[i+1][j]|=ok[i][j];
				if(j>=(i+1)*(i+1)) ok[i+1][j]|=ok[i][j-(i+1)*(i+1)];
			}
			int num=0;
			FOR(j,85400) if(ok[i+1][j]&&j<=A) cand=max(cand,j);
			if(cand+B>=(i+1)*(i+2)*(2*v+3)/6) v=i+1;
		}
		A=min(A,(ll)cand);
		if(v==293) {
			while((v+1000)*(v+1001)*(2*v+2001)/6<=A+B) v+=1000;
			while((v+1)*(v+2)*(2*v+3)/6<=A+B) v++;
		}
		cout<<v<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
