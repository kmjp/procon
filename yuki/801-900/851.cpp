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

string S[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	getline(cin,S[0]);
	getline(cin,S[1]);
	getline(cin,S[2]);
	getline(cin,S[3]);
	
	if(S[2].empty()) {
		cout<<"\"assert\""<<endl;
	}
	else {
		ll a=stoll(S[1].c_str());
		ll b=stoll(S[2].c_str());
		ll c=stoll(S[3].c_str());
		vector<ll> V={a+b,b+c,c+a};
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		reverse(ALL(V));
		cout<<V[1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
