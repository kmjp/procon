#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S2[21];
pair<string,int> S[21];
int T[21];
int good[21];
int rev[21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i].first;
		S[i].second=i;
	}
	sort(S,S+N);
	FOR(i,N) {
		S2[i]=S[i].first;
		rev[S[i].second]=i;
	}
	
	FOR(i,N) {
		cin>>s;
		FOR(x,N) if(s==S2[x]) T[rev[i]]=x;
		cin>>s;
		cin>>s;
		cin>>s;
		good[rev[i]]=s[0]=='g';
		cin>>s;
	}
	int best=-1;
	
	for(int mask=0;mask<1<<N;mask++) {
		int ng=0;
		
		FOR(i,N) {
			if(mask&(1<<i)) {
				if(good[i]) {
					if((mask&(1<<T[i]))==0) ng++;
				}
				else {
					if((mask&(1<<T[i]))!=0) ng++;
				}
			}
			else {
				if(good[i]==0) {
					if((mask&(1<<T[i]))==0) ng++;
				}
				else {
					if((mask&(1<<T[i]))!=0) ng++;
				}
			}
		}
		if(ng) continue;
		
		if(best==-1 || __builtin_popcount(mask)>__builtin_popcount(best)) best=mask;
	}
	if(best==-1) {
		cout<<"No answers"<<endl;
	}
	else {
		FOR(i,N) if(best&(1<<i)) cout<<S2[i]<<endl;;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
