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

string S,T;
int N;
int C[256];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	x=y=0;
	FORR(c,S) {
		if(c=='@') {
			x++;
		}
		else {
			C[c]++;
		}
	}
	FORR(c,T) {
		if(c=='@') {
			y++;
		}
		else {
			C[c]--;
		}
	}
	FOR(i,256) {
		if(i=='a'||i=='t'||i=='c'||i=='o'||i=='d'||i=='e'||i=='r') {
			while(C[i]>0) {
				C[i]--;
				y--;
			}
			while(C[i]<0) {
				C[i]++;
				x--;
			}
		}
		if(C[i]) {
			cout<<"No"<<endl;
			return;
		}
	}
	if(x>=0&&y>=0) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
