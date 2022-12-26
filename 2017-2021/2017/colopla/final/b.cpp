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

string S;
vector<string> V;
int cur;

void dfs() {
	string sym=V[cur];
	if(V[cur][0]>='0' && V[cur][0]<='9') {
		cout<<sym;
		cur++;
		return;
	}
	
	// (
	cur++;
	cout<<V[cur];
	cur++;
	while(1) {
		dfs();
		cur++;
		if(V[cur-1]==")") {
			cout<<")";
			break;
		}
		cout<<sym;
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) {
		if(c>='0' && c<='9') {
			if(V.size() && (V.back()[0]>='0' && V.back()[0]<='9')) {
				V.back()+=c;
			}
			else {
				V.push_back(string()+c);
			}
		}
		else {
			V.push_back(string()+c);
		}
	}
	dfs();
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
