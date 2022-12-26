#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N,M;
vector<int> E[1010][2];
int ok[2020][2][2];
string S;
int id[1010][1010];
vector<int> R[1010];
int from[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(id);
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x][0].push_back(y);
		E[y][1].push_back(x);
		id[x][y]=i;
	}
	S=string(M,'R');
	ok[0][0][0]=ok[0][1][0]=1;
	queue<int> Q;
	Q.push(0);
	Q.push(2);
	while(Q.size()) {
		int cur=Q.front()/4;
		int id=Q.front()/2%2;
		int oe=Q.front()%2;
		Q.pop();
		FORR(e,E[cur][id]) if(ok[e][id][oe^1]==0) {
			ok[e][id][oe^1]=1;
			Q.push(e*4+id*2+(oe^1));
		}
	}
	FOR(i,N) if(ok[i][0][0]==0||ok[i][0][1]==0||ok[i][1][0]==0) return _P("-1\n");
	FOR(i,N) {
		MINUS(from);
		from[i]=i;
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x][0]) {
				if(e==i) {
					vector<int> T;
					y=x;
					while(y!=i) T.push_back(y),y=from[y];
					T.push_back(i);
					reverse(ALL(T));
					R[T.size()]=T;
					break;
				}
				else if(from[e]==-1) {
					from[e]=x;
					Q.push(e);
				}
			}
		}
		
		
	}
	for(x=2;x<N;x++) if(R[x].size()) {
		vector<pair<int,int>> V;
		FORR(r,R[x]) V.push_back({E[r][0].size(),r});
		int n=x/2+1;
		sort(ALL(V));
		reverse(ALL(V));
		ZERO(from);
		FOR(i,n) from[V[i].second]=1;
		
		FOR(i,x) if(from[R[x][i]]) S[id[R[x][i]][R[x][(i+1)%x]]]='G';
		cout<<S<<endl;
		return;
		
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
