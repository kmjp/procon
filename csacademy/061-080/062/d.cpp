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
int V[201010];
vector<int> C;

int L[201010],R[201010];
int LN[201010],RN[201010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int id=-1;
	FOR(i,N) {
		cin>>V[i];
		if(id==-1 || V[id]<V[i]) {
			L[i]=i;
			LN[i]=((id>=0)?LN[id]:0)+1;
			id=i;
		}
		else {
			L[i]=L[i-1];
			LN[i]=LN[i-1];
		}
	}
	vector<pair<int,int>> S;
	S.push_back({-1<<30,N});
	int ma=0;
	
	for(i=N-1;i>=0;i--) {
		x=lower_bound(ALL(S),make_pair((i)?-V[L[i-1]]:0,0))-S.begin()-1;
		
		int tmp=(i)?LN[i-1]:0;
		tmp+=RN[S[x].second];
		ma=max(ma,tmp);
		
		
		while(-S.back().first<=V[i]) S.pop_back();
		R[i]=S.back().second;
		RN[i]=RN[R[i]]+1;
		S.push_back({-V[i],i});
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

