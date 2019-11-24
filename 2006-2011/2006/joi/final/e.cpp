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

int N,P;
int X1[10101],Y1[10101],X2[10101],Y2[101010];
vector<int> add[10101];
vector<int> del[10101];

int pre[10101];
int cur[10101];
int sum[10101];
ll A,L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		X1[i]++;
		X2[i]++;
		add[Y1[i]+1].push_back(i);
		del[Y2[i]+1].push_back(i);
	}
	
	set<int> C;
	for(y=1;y<=10100;y++) {
		FORR(a,add[y]) C.insert(a);
		FORR(a,del[y]) C.erase(a);
		ZERO(sum);
		FORR(c,C) sum[X1[c]]++,sum[X2[c]]--;
		
		for(x=1;x<=10011;x++) {
			sum[x]+=sum[x-1];
			cur[x]=(sum[x]>0);
			if(cur[x]) A++;
			if(cur[x]!=cur[x-1]) L++;
			if(cur[x]!=pre[x]) L++;
		}
		
		swap(cur,pre);
	}
	
	cout<<A<<endl;
	if(P==2) cout<<L<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
