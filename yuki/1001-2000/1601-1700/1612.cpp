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
int C[201010];
vector<pair<int,int>> E[101010];
int from[101010][27];
int from2[101010][27];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(from);
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>s;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
		C[i]=s[0]-'a';
	}
	queue<int> Q;
	FORR2(e,x,E[0]) {
		from[e][C[x]]=-2;
		from2[e][C[x]]=x;
		Q.push(e*100+C[x]);
	}
	while(Q.size()) {
		int cur=Q.front()/100;
		int c=Q.front()%100;
		Q.pop();
		FORR2(e,x,E[cur]) {
			if(c==26||c!=C[x]) {
				if(from[e][26]==-1) {
					from[e][26]=cur*100+c;
					from2[e][26]=x;
					Q.push(e*100+26);
				}
			}
			else {
				if(from[e][c]==-1) {
					from[e][c]=cur*100+c;
					from2[e][c]=x;
					Q.push(e*100+c);
				}
			}
		}
	}
	
	if(from[N-1][26]>=0) {
		vector<int> V;
		int cur=N-1;
		int c=26;
		while(cur!=0||c!=0) {
			V.push_back(from2[cur][c]);
			x=from[cur][c];
			if(x==-2) break;
			cur=x/100;
			c=x%100;
		}
		
		V.push_back(E[0][0].second);
		V.push_back(E[0][0].second);
		
		reverse(ALL(V));
		cout<<V.size()<<endl;
		FORR(v,V) cout<<(v+1)<<endl;
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
