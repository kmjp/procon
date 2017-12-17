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

int N;
ll LL;
vector<string> S;
vector<string> V;
ll nim;
string T;

ll hoge(ll x) {
	ll y=1;
	while(x%2==0) {
		y<<=1;
		x>>=1;
	}
	return y;
}

void dfs(int x,int L,int R) {
	//cout<<T<<" "<<x<<" "<<L<<" "<<R<<endl;
	if(L>=R) {
		//cout<<"nim"<<T<<endl;
		nim^=hoge(LL-x+1);
	}
	else if(V[L].size()<=x) {
		return;
	}
	else {
		int M=L-1;
		for(int i=18;i>=0;i--) {
			M+=1<<i;
			if(M<R && V[M][x]=='0') continue;
			M-=1<<i;
		}
		//T.push_back('0');
		dfs(x+1,L,M+1);
		//T.pop_back();
		//T.push_back('1');
		dfs(x+1,M+1,R);
		//T.pop_back();
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>LL;
	FOR(i,N) {
		cin>>s;
		S.push_back(s);
	}
	sort(ALL(S));
	FORR(s,S) {
		while(s.size()&&V.size()) {
			string v=V.back();
			if(s.size()==v.size() && s.substr(0,s.size()-1)==v.substr(0,s.size()-1)) {
				V.pop_back();
				s.pop_back();
			}
			else {
				break;
			}
		}
		V.push_back(s);
	}
	
	if(V.size()==1 && V[0]=="") {
		cout<<"Bob"<<endl;
		return;
	}
	
	//FOR(i,V.size()) cout<<i<<" "<<V[i]<<endl;
	
	dfs(0,0,V.size());
	//cout<<"nim="<<nim<<endl;
	if(nim) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
