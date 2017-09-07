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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	string S="";
	while(S.size()<N) S+="001011";
	cout<<min(N,8)-(N==8)<<endl;
	cout<<S.substr(0,N)<<endl;
	return;
	
	vector<pair<int,string>> V;
	for(int mask=0;mask<1<<N;mask++) {
		if(mask>(1<<N)-mask) continue;
		string s;
		FOR(i,N) s+='0'+((mask&(1<<i))>0);
		string t=s;
		reverse(ALL(t));
		if(s>t) continue;
		set<string> S;
		for(int l=1;l<=N;l++) {
			for(x=0;x+l<=N;x++) S.insert(s.substr(x,l));
		}
		
		int ret=0;
		FORR(s,S) {
			string t=s;
			reverse(ALL(t));
			if(s==t) ret++;
		}
		V.push_back({ret,s});
	}
	sort(ALL(V));
	
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
