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

int T,testcase;
int L,U,N;

string S[10]={
	"..********",
	".****.**..",
	"**********",
	"*****.*...",
	"****.*....",
	".**.*.....",
	".*.**.....",
	".......***",
	"......***.",
	"......***.",
};
	

int W[10],MW;
int ID[30][30];
vector<int> E[51];
vector<int> E2[51];
map<vector<int>,int> MP;
int ret[51];
int depth[51];


void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>U;
	MW=10;
	N=0;
	FOR(y,10) FOR(x,10) N+=S[y][x]=='*';
	int id=0;
	FOR(i,N) E[i].clear();
	MINUS(ID);
	FOR(y,10) FOR(x,10) if(S[y][x]=='*') ID[y][x]=id++;
	FOR(y,10) {
		int num=0;
		FOR(x,10) num+=S[y][x]=='*';
		if(num==1||num==2) return;
		num=0;
		FOR(x,10) num+=S[x][y]=='*';
		if(num==1||num==2) return;
	}
	
	FOR(y,10) {
		FOR(x,10) if(ID[y][x]>=0) {
			int cur;
			cur=(x+1)%10;
			while(ID[y][cur]<0) (cur+=1)%=10;
			E[ID[y][x]].push_back(ID[y][cur]);
			cur=(x+9)%10;
			while(ID[y][cur]<0) (cur+=9)%=10;
			E[ID[y][x]].push_back(ID[y][cur]);
			
			cur=(y+1)%10;
			while(ID[cur][x]<0) (cur+=1)%=10;
			E[ID[y][x]].push_back(ID[cur][x]);
			cur=(y+9)%10;
			while(ID[cur][x]<0) (cur+=9)%=10;
			E[ID[y][x]].push_back(ID[cur][x]);
		}
	}
	
	set<vector<int>> S;
	MP.clear();
	FOR(i,N) {
		FOR(j,N) depth[j]=100;
		depth[i]=0;
		queue<int> Q;
		Q.push(i);
		vector<int> D;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			D.push_back(depth[x]);
			FORR(e,E[x]) if(depth[e]>depth[x]+1) {
				depth[e]=depth[x]+1;
				Q.push(e);
			}
		}
		MP[D]=i;
		//FORR(d,D) cerr<<d;
		//cerr<<endl;
	}
	assert(MP.size()==N);
	//cout<<N<<" "<<S.size()<<endl;
	cout<<N<<endl;
	FOR(i,N) FORR(e,E[i]) if(i<e) cout<<i+1<<" "<<e+1<<endl;
	cin>>N;
	FOR(i,N) E2[i].clear();
	FOR(i,2*N) {
		cin>>x>>y;
		E2[x-1].push_back(y-1);
		E2[y-1].push_back(x-1);
	}
	FOR(i,N) {
		FOR(j,N) depth[j]=100;
		depth[i]=0;
		queue<int> Q;
		Q.push(i);
		vector<int> D;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			D.push_back(depth[x]);
			FORR(e,E2[x]) if(depth[e]>depth[x]+1) {
				depth[e]=depth[x]+1;
				Q.push(e);
			}
		}
		ret[MP[D]]=i+1;
	}
	
	FOR(i,N) {
		cout<<ret[i];
		if(i==N-1) cout<<endl;
		else cout<<" ";
	}
	
	
	//_P("Case #%d: IMPOSSIBLE\n",TC);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
