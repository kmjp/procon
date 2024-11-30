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

int T,N;
int ma,mi;
int S[2020];
int tcur=0;
int V[2020]={2,4,1,5,3};

int ask(int v) {
	string s;
	cout<<"? "<<v+1<<endl;
	if(tcur) {
		if(V[v]>tcur) {
			s=">";
			tcur++;
		}
		else if(V[v]<tcur) {
			s="<";
			tcur--;
		}
		else {
			s="=";
		}
	}
	else {
		cin>>s;
	}
	if(s==">") return 1;
	if(s=="<") return -1;
	return 0;
}
int dfs(int cur,int L,int R,vector<int> V) {
	if(L>R) return cur;
	int M=(L+R)/2;
	vector<int> A,B;
	while(cur<M) ask(ma), cur++;
	while(cur>M) ask(mi), cur--;
	FORR(v,V) {
		int ret=ask(v);
		if(ret==0) {
			S[v]=M;
		}
		else if(ret==1) {
			B.push_back(v);
			ask(mi);
		}
		else {
			A.push_back(v);
			ask(ma);
		}
	}
	cur=dfs(cur,L,M-1,A);
	cur=dfs(cur,M+1,R,B);
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ma=-1,mi=-1;
		FOR(i,N) {
			x=ask(i);
			if(x==-1) {
				if(ma!=-1) ask(ma);
			}
			else if(x==0) {
				if(ma==-1) ma=i;
			}
			else {
				while(1) {
					x=ask(i);
					if(x==0) break;
				}
				ma=i;
			}
		}
		FOR(i,N) {
			x=ask(i);
			if(x==1) {
				if(mi!=-1) ask(mi);
			}
			else if(x==0) {
				if(mi==-1) mi=i;
			}
			else {
				while(1) {
					x=ask(i);
					if(x==0) break;
				}
				mi=i;
			}
		}
		S[mi]=1;
		S[ma]=N;
		vector<int> V;
		FOR(i,N) ask(mi);
		FOR(i,N) if(i!=mi&&i!=ma) V.push_back(i);
		dfs(1,2,N-1,V);
		cout<<"!";
		FOR(i,N) cout<<" "<<S[i];
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
