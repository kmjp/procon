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

int N,Q;

int V[1<<22][28];
int P[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(V);
	cin>>N>>Q;
	int nex=1;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			P[x]=P[0];
		}
		else if(i==3) {
			cin>>x;
			P[0]=P[x];
		}
		else {
			cin>>x>>s;
			FORR(c,s) {
				c-='a';
				if(V[P[x]][c]==-1) {
					V[P[x]][c]=nex;
					V[nex][26]=P[x];
					V[nex][27]=c;
					nex++;
				}
				P[x]=V[P[x]][c];
			}
		}
	}
	s="";
	while(P[0]) {
		s+=(char)(V[P[0]][27]+'a');
		P[0]=V[P[0]][26];
	}
	reverse(ALL(s));
	cout<<s<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
