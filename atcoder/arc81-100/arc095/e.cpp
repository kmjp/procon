#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int W,H;
string S[12];
string T[12],R[12];
int num=0;

void hoge() {
	int x,y;
	set<string> U;
	int left=0;
	
	FOR(x,W) {
		if(U.count(R[x])) {
			U.erase(R[x]);
		}
		else {
			U.insert(T[x]);
		}
	}
	
	if(U.empty()) {
		cout<<"YES"<<endl;
		exit(0);
	}
	if(U.size()==1) {
		string s=*U.begin();
		string t=s;
		reverse(ALL(s));
		if(t==s) {
			cout<<"YES"<<endl;
			exit(0);
		}
	}
}

void add(int l) {
	int x;
	FOR(x,W) {
		T[x].push_back(S[l][x]);
		R[x][H-T[x].size()]=S[l][x];
	}
}
void del() {
	int x;
	FOR(x,W) T[x].pop_back();
}

void dfs(int mask,int last) {
	int i;
	if(__builtin_popcount(mask)>=(H+1)/2) {
		int num=0;
		FOR(i,H) {
			if((mask&(1<<i))==0) {
				num++;
				add(i);
			}
		}
		hoge();
		FOR(i,num) del();
		return;
	}
	
	FOR(i,H) if((mask&(1<<i))==0) {
		add(i);
		dfs(mask^(1<<i),i);
		del();
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(x,W) R[x].resize(H);
	FOR(y,H) cin>>S[y];
	vector<int> V;
	dfs(0,-1);
	cout<<"NO"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
