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
pair<int,int> P[252020],Q[252020];
int Y[252020];
const int D=450;

vector<int> BY[452];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
	}
	sort(P,P+N);
	FOR(i,N) Q[i]={P[i].second,i};
	sort(Q,Q+N);
	MINUS(Y);
	
	ll ret=0;
	FOR(i,N) {
		x=Q[i].second;
		int cur=x;
		int my=-1;
		while(cur>=0 && cur%D!=D-1) {
			if(Y[cur]>my) {
				ret++;
				my=Y[cur];
			}
			cur--;
		}
		if(cur<0) cur=-D;
		for(y=cur/D;y>=0;y--) if(BY[y].size()) {
			ret+=BY[y].end()-lower_bound(ALL(BY[y]),my);
			my=max(my,BY[y].back());
		}
		BY[x/D].clear();
		Y[x]=Q[i].first;
		my=-1;
		for(cur=x/D*D+(D-1);cur>=x/D*D;cur--) if(Y[cur]>my) {
			my=Y[cur];
			BY[cur/D].push_back(my);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
