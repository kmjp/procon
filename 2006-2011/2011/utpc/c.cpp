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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int ma=0;
	for(int mask=0;mask<1<<N;mask++) {
		if(__builtin_popcount(mask)<max(3,ma)) continue;
		if(__builtin_popcount(mask)%2==0) continue;
		vector<int> V;
		FOR(i,N) if(mask&(1<<i)) V.push_back(i);
		
		if(S[V[V.size()/2]]!='w') continue;
		
		FOR(i,V.size()/2) {
			char a=S[V[i]];
			char b=S[V[V.size()-1-i]];
			
			if(i==V.size()/2-1) {
				if(a!='i' || b!='i') break;
			}
			else {
				if(a=='i' && b!='i') break;
				if(a=='w' && b!='w') break;
				if(a=='(' && b!=')') break;
				if(a==')' && b!='(') break;
				if(a=='[' && b!=']') break;
				if(a==']' && b!='[') break;
				if(a=='{' && b!='}') break;
				if(a=='}' && b!='{') break;
			}
		}
		if(i==V.size()/2) ma=__builtin_popcount(mask);
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
