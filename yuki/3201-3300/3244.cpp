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

int N,Q;
string S;
vector<int> P[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) {
		P[i].push_back(-3);
		P[i].push_back(-2);
		P[i].push_back(-1);
	}
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		P[S[i]-'0'].push_back(i);
	}
	
	vector<vector<int>> cand;
	FOR(i,1000) if(i%8==0) {
		vector<int> V={i%10,i/10%10,i/100%10};
		if(V[0]==0) continue;
		if(V[1]==0) continue;
		if(V[2]==0) continue;
		cand.push_back(V);
	}
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		if(R-L==1) {
			if(S[L]=='8') {
				cout<<0<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else if(R-L==2) {
			if(((S[L]-'0')*10+(S[L+1]-'0'))%8==0) {
				cout<<0<<endl;
			}
			else if(((S[L]-'0')+(S[L+1]-'0')*10)%8==0) {
				cout<<1<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else {
			int pos[10];
			int ret=1<<30;
			FOR(i,10) {
				pos[i]=lower_bound(ALL(P[i]),R)-P[i].begin();
			}
			
			FORR(v,cand) {
				int tp[10];
				FOR(i,10) tp[i]=pos[i];
				int p[3];
				p[0]=P[v[0]][--tp[v[0]]];
				p[1]=P[v[1]][--tp[v[1]]];
				p[2]=P[v[2]][--tp[v[2]]];
				if(p[0]<L) continue;
				if(p[1]<L) continue;
				if(p[2]<L) continue;
				int tmp=0;
				tmp=(R-1)-p[0];
				if(p[1]>p[0]) p[1]--;
				if(p[2]>p[0]) p[2]--;
				tmp+=(R-2)-p[1];
				if(p[2]>p[1]) p[2]--;
				tmp+=(R-3)-p[2];
				ret=min(ret,tmp);
				
			}
			
			
			if(ret>=1<<30) ret=-1;
			cout<<ret<<endl;
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
