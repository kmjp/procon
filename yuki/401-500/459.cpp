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

int H,W,N;
string S;
int HH[10101];
int A[40100][3], C[40101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(y,H) {
		cin>>S;
		FOR(x,W) HH[x] += S[x]=='#';
	}
	vector<int> add[10101];
	FOR(i,N) {
		cin>>C[i];
		add[C[i]].push_back(i);
	}
	
	queue<int> Q[5];
	FOR(x,W) {
		for(i=2;i<=4;i++) {
			while(Q[i].size()) Q[1].push(Q[i].front()), Q[i].pop();
		}
		FORR(r,add[x]) Q[0].push(r);
		
		for(i=0;i<=3;i++) {
			while(HH[x] && Q[i].size()) {
				y=Q[i].front();
				Q[i].pop();
				if(x>=C[y]+3) continue;
				HH[x]--;
				A[y][x-C[y]]++;
				Q[i+1+(i==0)].push(y);
			}
		}
	}
	FOR(i,N) {
		string B[3]={"...","...","..."};
		FOR(y,3) {
			string B="...";
			FOR(x,3) if(A[i][x]>y) B[x]='#';
			cout<<B<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
