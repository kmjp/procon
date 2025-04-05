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

int T;
int H,W;
string S;

int from[5],to[5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,5) from[y]=-1<<20;
		from[0]=0;
		
		while(H--) {
			cin>>S;
			string V;
			FORR(c,S) {
				if(c=='n') V+=(char)0;
				else if(c=='a') V+=(char)1;
				else if(c=='r') V+=(char)2;
				else if(c=='e') V+=(char)3;
				else if(c=='k') V+=(char)4;
			}
			
			FOR(y,5) to[y]=from[y];
			FOR(y,5) {
				int cy=y,sc=from[y];
				string W=V;
				FORR(c,W) {
					if(c==cy) {
						sc++;
						c=5;
						cy=(cy+1)%5;
					}
					else {
						sc--;
					}
				}
				to[cy]=max(to[cy],sc);
			}
			swap(from,to);
		}
		int ma=0;
		FOR(x,5) ma=max(ma,from[x]-2*x);
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
