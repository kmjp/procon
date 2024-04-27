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
int O[505050];

void ri(int L,int R) ;
void lef(int L,int R) {
	if(L>R) return;
	if(S[R]==')') {
		ri(O[R]+1,R-1);
		lef(L,O[R]-1);
	}
	else {
		char c=S[R];
		if(c>='A'&&c<='Z') c+='a'-'A';
		else c+='A'-'a';
		cout<<c;
		lef(L,R-1);
	}
}

void ri(int L,int R) {
	if(L>R) return;
	if(S[L]=='(') {
		lef(L+1,O[L]-1);
		ri(O[L]+1,R);
	}
	else {
		cout<<S[L];
		ri(L+1,R);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	vector<int> V;
	FOR(i,N) {
		if(S[i]=='(') {
			V.push_back(i);
		}
		if(S[i]==')') {
			x=V.back();
			V.pop_back();
			O[i]=x;
			O[x]=i;
		}
	}
	ri(0,N-1);
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
