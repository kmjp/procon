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

string N,M;
int NL,ML;
ll p10[1010101];
ll mo=1000000007;

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	return v;
}

ll dfs(int id,string& N,string& T,int nx) {
	if(id==N.size()) return 1;
	
	if(T[id]=='X') {
		return ((N[id]-'0')*p10[nx-1] + dfs(id+1,N,T,nx-1))%mo;
	}
	else {
		if(N[id]>T[id]) return p10[nx];
		if(N[id]<T[id]) return 0;
		return dfs(id+1,N,T,nx);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	NL=N.size();
	ML=M.size();
	
	p10[0]=1;
	FOR(i,1010000) p10[i+1]=p10[i]*10%mo;
	vector<int> Z=Zalgo(M);
	
	ll ret=0;
	for(int i=ML;i<NL;i++) {
		if(i<2*ML) {
			j=i-ML;
			if(Z[j]>=ML-j) ret++;
		}
		else {
			ret += p10[i-(2*ML)];
		}
	}
	
	
	if(NL>=ML) {
		string T(NL,'X');
		FOR(i,ML) T[i]=M[i];
		FOR(i,ML) {
			j=NL-ML+i;
			if(T[j]=='X') T[j]=M[i];
			if(T[j]!=M[i]) break;
		}
		if(i==ML) ret += dfs(0,N,T,count(T.begin(),T.end(),'X'));
	}
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
