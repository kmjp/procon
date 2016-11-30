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

int H,W,D,K,Q,P;
vector<pair<pair<int,int>,char>> V;
int R[101010],C[101010];
vector<int> req[1010];

int TT[101010],DD[101010],ret[101010];

int dtop(int y,int t,char c) {
	if(c=='+') {
		y = (y+t%P+P)%P;
	}
	else {
		y = (y+P-t%P)%P;
	}
	if(y>P/2) y=P-y;
	return y;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>D>>K;
	FOR(i,K) {
		cin>>x>>y>>s;
		V.push_back({{y,x-1},s[0]});
	}
	sort(ALL(V));
	
	cin>>Q;
	if(D==H) {
		FOR(i,Q) _P("1\n");
		return;
	}
	P=2*(H-D);
	FOR(i,Q) {
		cin>>R[i]>>C[i];
		R[i]--;
		req[(P-C[i]%P)%P].push_back(i);
	}
	FOR(i,P) if(req[i].size()) {
		
		TT[K-1]=dtop(V[K-1].first.second,i+V[K-1].first.first,V[K-1].second);
		DD[K-1]=TT[K-1]+D-1;
		for(j=K-2;j>=0;j--) {
			if(TT[j+1]>DD[j+1]) {
				TT[j]=TT[j+1];
				DD[j]=DD[j+1];
				continue;
			}
			int d=V[j+1].first.first-V[j].first.first;
			TT[j]=dtop(V[j].first.second,i+V[j].first.first,V[j].second);
			DD[j]=TT[j]+D-1;
			
			TT[j]=max(TT[j],TT[j+1]-d);
			DD[j]=min(DD[j],DD[j+1]+d);
		}
		FORR(r,req[i]) {
			x=lower_bound(ALL(V),make_pair(make_pair(C[r],0),' '))-V.begin();
			if(x==V.size()) {
				ret[r]=1;
			}
			else {
				if(TT[x]>DD[x]) continue;
				int d=V[x].first.first-C[r];
				ret[r]=(TT[x]-d<=R[r]&&R[r]<=DD[x]+d);
			}
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
