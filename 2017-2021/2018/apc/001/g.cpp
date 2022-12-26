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
string S;
int ret[202020];

bool hoge() {
	int i,j,k,l,r,x,y; string s;
	
	if(count(ALL(S),'0')==0) {
		if(N%2) return false;
		FOR(i,N/2) {
			ret[i*4+0]=ret[i*4+2]=i*2+1;
			ret[i*4+1]=ret[i*4+3]=i*2+2;
		}
		return true;
	}
	
	S+='1';
	S+=S+S;
	FOR(i,S.size()) if(S[i]=='0') break;
	vector<vector<int>> V;
	vector<int> T;
	for(j=1;j<=2*N;j++) {
		if(S[i+j]=='1') {
			if(S[i+j-1]=='0') T.push_back((i+j)%(2*N));
			T.push_back((i+j+1)%(2*N));
		}
		else {
			if(T.size()) V.push_back(T);
			T.clear();
		}
	}
	
	int tot=0;
	vector<int> cand;
	int nex=1;
	FOR(i,V.size()) {
		tot+=V[i].size()-2;
		if(V[i].size()>=3) cand.push_back(i);
	}
	
	if(tot%2) return false;
	if(tot%4) {
		if(cand.size()<2) return false;
		x=cand[0];
		y=cand[1];
		ret[V[x][1]]=ret[V[y][1]]=nex++;
		swap(V[x][0],V[y][0]);
		V[x].erase(V[x].begin()+1);
		V[y].erase(V[y].begin()+1);
	}
	T.clear();
	FOR(i,V.size()) {
		ret[V[i].back()]=ret[V[(i+1)%V.size()][0]]=nex++;
		for(j=1;j<V[i].size()-1;j++) T.push_back(V[i][j]);
	}
	
	assert(T.size()%4==0);
	FOR(i,T.size()/4) {
		ret[T[i*4]]=ret[T[i*4+2]]=nex++;
		ret[T[i*4+1]]=ret[T[i*4+3]]=nex++;
	}
	T.clear();
	FOR(i,2*N) if(ret[i]==0) T.push_back(i);
	FOR(i,T.size()/2) ret[T[i*2]]=ret[T[i*2+1]]=nex++;
	
	return true;
}

void solve() {
	int i;
	
	cin>>N>>S;
	if(hoge()) {
		cout<<"Yes"<<endl;
		FOR(i,2*N) cout<<ret[i]<<" ";
		cout<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
