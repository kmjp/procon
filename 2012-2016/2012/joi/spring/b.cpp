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
vector<pair<int,int>> V;
int S[505050][3];

vector<pair<int,int>> ev[505050];

map<int,int> M;

ll now;

void add(int x,int y) {
	auto it=M.lower_bound(x);
	if(it->second>=y) return;
	int prey=it->second;
	M[x]=y;
	it--;
	int prex=x;
	while(1) {
		it=prev(M.find(x));
		
		now+=1LL*(prex-it->first)*(y-prey);
		
		if(it->second>=y) break;
		prex=it->first;
		prey=it->second;
		M.erase(it);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>s;
		if(s=="R") y=0;
		if(s=="G") y=1;
		if(s=="B") y=2;
		V.push_back({x,y});
	}
	sort(ALL(V));
	
	FOR(i,N) {
		FOR(j,3) S[i+1][j]=S[i][j];
		S[i+1][V[i].second]++;
	}
	FOR(i,N) {
		x=lower_bound(ALL(V),make_pair(V[i].first*2,0))-V.begin();
		ev[S[x][0]-S[i][0]].push_back({S[x][1]-S[i][1]+1,S[x][2]-S[i][2]+1});
	}
	
	M[0]=1<<20;
	M[1<<20]=0;
	ll ret=0;
	
	for(i=500000;i>=0;i--) {
		FORR(e,ev[i]) add(e.first,e.second);
		//if(now) cout<<i<<" "<<now<<endl;
		ret+=now;
	}
	
	cout<<ret-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
