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

int ok(string& S, int mask) {
	if(mask==0) return 1;
	
	int x,y,z;
	FOR(x,14) if(mask&(1<<x)) {
		for(y=x+1;y<14;y++) if((S[x]==S[y]||S[x]+1==S[y]) && (mask&(1<<y))) {
			for(z=y+1;z<14;z++) if(mask&(1<<z)) {
				if(S[x]==S[y] && S[y]==S[z] && ok(S,mask^(1<<x)^(1<<y)^(1<<z))) return 1;
				if(S[x]+1==S[y] && S[y]+1==S[z] && ok(S,mask^(1<<x)^(1<<y)^(1<<z))) return 1;
			}
		}
		
		break;
	}
	
	return 0;
	
}
int ok(string S) {
	sort(ALL(S));
	int i,j,x;
	FOR(j,S.size()) FOR(i,j) if(S[i]==S[j]) {
		int mask=(1<<14)-1-(1<<i)-(1<<j);
		if(ok(S,mask)) return 1;
	}
	
	int num=0;
	for(i=1;i<=9;i++) if(count(ALL(S),'0'+i)==2) num++;
	if(num==7) return 1;
	
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	for(char a='1';a<='9';a++) {
		S+=a;
		int ng=0;
		for(i=1;i<=9;i++) if(count(ALL(S),'0'+i)>4) ng++;
		if(!ng && ok(S)) cout<<a<<endl;
		S.pop_back();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
