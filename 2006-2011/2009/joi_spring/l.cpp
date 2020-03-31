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
int X[4040],Y[4040],Y2[4040],L[4040];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<short,1<<12> st;

vector<int> Ys,Ls;
vector<pair<int,int>> Xev;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	Ys.push_back(210000000);
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>L[i];
		Ys.push_back(Y[i]);
		Ls.push_back(L[i]);
	}
	sort(ALL(Ys));
	FOR(i,N) {
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
	}
	
	sort(ALL(Ls));
	int ma=0;
	FOR(i,N) {
		Xev.clear();
		int TL=L[i];
		
		FOR(j,N) if(L[j]>=TL && abs(X[j]-X[i])<=TL) {
			Xev.push_back({X[j]-TL,j});
			Xev.push_back({X[j],N+j});
			Y2[j]=lower_bound(ALL(Ys),Ys[Y[j]]+TL+1)-Ys.begin();
		}
		if(Xev.size()/2<=ma) continue;
		sort(ALL(Xev));
		FORR(e,Xev) {
			x=e.second%N;
			y=Y[x];
			r=Y2[x];
			if(e.second<N) {
				st.update(y,r,1);
				ma=max(ma,(int)st.ma[1]);
			}
			else {
				st.update(y,r,-1);
			}
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
