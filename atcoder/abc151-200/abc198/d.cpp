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

string S[3];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S[0]>>S[1]>>S[2];
	FOR(i,3) {
		FORR(c,S[i]) M[c]=0;
	}
	i=0;
	FORR(m,M) m.second=i++;
	
	if(M.size()>10) {
		cout<<"UNSOLVABLE"<<endl;
		return;
	}
	vector<int> V;
	FOR(i,10) V.push_back(i);
	do {
		string T[3];
		ll A[3];
		FOR(i,3) {
			T[i].clear();
			FORR(c,S[i]) T[i].push_back('0'+V[M[c]]);
			if(T[i][0]=='0') break;
			else A[i]=stoll(T[i]);
		}
		if(i!=3) continue;
		
		if(A[0]+A[1]==A[2]) {
			cout<<A[0]<<endl;
			cout<<A[1]<<endl;
			cout<<A[2]<<endl;
			return;
		}
		
		
		
	} while(next_permutation(ALL(V)));
	
	cout<<"UNSOLVABLE"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
