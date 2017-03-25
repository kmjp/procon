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
vector<vector<int>> V;

int num[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y>>j;
		vector<int> R = {x,y,j};
		sort(ALL(R));
		V.push_back(R);
		num[i]=1;
	}
	sort(ALL(V));
	
	int ma=1;
	FOR(i,N) {
		ma=max(ma,num[i]);
		for(j=i+1;j<N;j++) {
			if(V[i][0]<V[j][0] && V[i][1]<V[j][1] && V[i][2]<V[j][2]) {
				num[j]=max(num[j],num[i]+1);
			}
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
