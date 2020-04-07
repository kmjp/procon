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

int N,Q;
string S[1010];
int Y,X,L;

struct Node {
	char c;
	Node *P[2][2];
};

Node node[1010][1010];

Node* gonex(Node* cur, Node* pre) {
	if(cur->P[0][0]==pre) return cur->P[0][1];
	if(cur->P[0][1]==pre) return cur->P[0][0];
	if(cur->P[1][0]==pre) return cur->P[1][1];
	if(cur->P[1][1]==pre) return cur->P[1][0];
	cout<<cur->c<<" "<<pre->c<<endl;
	cout<<cur<<" "<<pre<<endl;
	cout<<cur->P[0][0]<<" "<<cur->P[0][1]<<" "<<cur->P[1][0]<<" "<<cur->P[1][1]<<endl;
	cout<<pre->P[0][0]<<" "<<pre->P[0][1]<<" "<<pre->P[1][0]<<" "<<pre->P[1][1]<<endl;
	assert(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(y,N+2) FOR(x,N+1) {
		node[y][x].P[0][1]=&node[y][x+1];
		node[y][x+1].P[0][0]=&node[y][x];
	}
	FOR(y,N+1) FOR(x,N+2) {
		node[y][x].P[1][1]=&node[y+1][x];
		node[y+1][x].P[1][0]=&node[y][x];
	}
	
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) node[y+1][x+1].c=S[y][x];
	}
	
	while(Q--) {
		cin>>Y>>X>>L;
		if(L==1) continue;
		vector<Node*> LR[4],UD[4];
		FOR(i,4) {
			if(i<=1) j=Y-1+i;
			else j=Y+L+i-3;
			Node* cur=&node[j][0];
			Node* nex=cur->P[0][1];
			LR[i].push_back(cur);
			LR[i].push_back(nex);
			for(x=2;x<=N+1;x++) {
				cur=gonex(nex,cur);
				swap(nex,cur);
				LR[i].push_back(nex);
			}
		}
		FOR(i,4) {
			if(i<=1) j=X-1+i;
			else j=X+L+i-3;
			
			Node* cur=&node[0][j];
			Node* nex=cur->P[1][1];
			UD[i].push_back(cur);
			UD[i].push_back(nex);
			for(x=2;x<=N+1;x++) {
				cur=gonex(nex,cur);
				swap(nex,cur);
				UD[i].push_back(nex);
			}
		}
		
		
		FOR(k,L) {
			FOR(i,2) FOR(j,2) {
				if(LR[0][X+k]->P[i][j]==LR[1][X+k]) LR[0][X+k]->P[i][j]=UD[2][Y+k];
				if(LR[1][X+k]->P[i][j]==LR[0][X+k]) LR[1][X+k]->P[i][j]=UD[0][Y+L-1-k];
				if(LR[2][X+k]->P[i][j]==LR[3][X+k]) LR[2][X+k]->P[i][j]=UD[3][Y+L-1-k];
				if(LR[3][X+k]->P[i][j]==LR[2][X+k]) LR[3][X+k]->P[i][j]=UD[1][Y+k];
				if(UD[0][Y+k]->P[i][j]==UD[1][Y+k]) UD[0][Y+k]->P[i][j]=LR[1][X+L-1-k];
				if(UD[1][Y+k]->P[i][j]==UD[0][Y+k]) UD[1][Y+k]->P[i][j]=LR[3][X+k];
				if(UD[2][Y+k]->P[i][j]==UD[3][Y+k]) UD[2][Y+k]->P[i][j]=LR[0][X+k];
				if(UD[3][Y+k]->P[i][j]==UD[2][Y+k]) UD[3][Y+k]->P[i][j]=LR[2][X+L-1-k];
			}
		}
	}
	
	for(y=1;y<=N;y++) {
		Node* cur=&node[y][0];
		Node* nex=cur->P[0][1];
		FOR(i,N) {
			cout<<nex->c;
			cur=gonex(nex,cur);
			swap(nex,cur);
		}
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
