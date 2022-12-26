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


template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return ma[k];
		return max({val[k],getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)});
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=max(val[k],v);
			ma[k]=max(ma[k],val[k]);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max({val[k],ma[k*2],ma[k*2+1]});
		}
	}
};
SegTree_3<int,1<<21> st;


int N,X;
int L[2020],R[2020];
vector<pair<int,int>> Ldp[2020],Rdp[2020];
pair<int,int> LP[2020],RP[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> P;
	vector<pair<int,int>> ev;
	P.push_back(-1);
	P.push_back(2000000000);
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		LP[i]={L[i],i};
		RP[i]={R[i],i};
		ev.push_back({R[i],i+N});
		ev.push_back({L[i],i});
	}
	sort(LP,LP+N);
	sort(RP,RP+N);
	reverse(RP,RP+N);
	int ma=2;
	FOR(i,N) {
		j=LP[i].second;
		vector<pair<int,int>> cand;
		cand.push_back({L[j]+1,1});
		FOR(x,N) if(L[x]<L[j]&&L[j]<R[x]&&R[x]<R[j]) {
			y=lower_bound(ALL(Ldp[x]),make_pair(L[j]+1,0))-Ldp[x].begin();
			if(y) cand.push_back({R[x]+1,Ldp[x][y-1].second+1});
		}
		sort(ALL(cand));
		FORR(c,cand) {
			if(c.first<R[j]) {
				if(Ldp[j].size() && Ldp[j].back().first==c.first) Ldp[j].pop_back();
				if(Ldp[j].empty() || Ldp[j].back().second<c.second) Ldp[j].push_back(c);
				ma=max(ma,c.second+1);
			}
			ma=max(ma,c.second);
		}
		
		FORR(c,Ldp[j]) P.push_back(max(R[j]+1,c.first+X-1));
		P.push_back(R[j]+X-1);
	}
	
	FOR(i,N) {
		j=RP[i].second;
		vector<pair<int,int>> cand;
		cand.push_back({R[j]-1,1});
		FOR(x,N) if(L[j]<L[x]&&L[x]<R[j]&&R[j]<R[x]) {
			y=lower_bound(ALL(Rdp[x]),make_pair(R[j],0))-Rdp[x].begin();
			if(y<Rdp[x].size()) cand.push_back({L[x]-1,Rdp[x][y].second+1});
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		FORR(c,cand) {
			if(L[j]<c.first) {
				if(Rdp[j].size() && Rdp[j].back().first==c.first) Rdp[j].pop_back();
				if(Rdp[j].empty() || Rdp[j].back().second<c.second) Rdp[j].push_back(c);
				ma=max(ma,c.second+1);
			}
			ma=max(ma,c.second);
		}
		FORR(c,Rdp[j]) P.push_back(min(c.first,L[j]-2+X)+1);
		P.push_back(L[j]+1);
		reverse(ALL(Rdp[j]));
		
	}
	sort(ALL(P));
	P.erase(unique(ALL(P)),P.end());
	sort(ALL(ev));
	FORR(e,ev) {
		//FOR(i,P.size()-1) cout<<i<<":"<<P[i]<<":"<<P[i+1]<<"="<<st.getval(i,i+1)<<" ";
		//cout<<endl;
		if(e.second<N) {
			i=e.second;
			FORR(c,Rdp[i]) {
				x=lower_bound(ALL(P),L[i]+1)-P.begin();
				y=lower_bound(ALL(P),min(c.first,L[i]-2+X)+1)-P.begin();
				//cout<<"!"<<i<<" "<<L[i]<<" "<<R[i]<<" $ "<<L[i]+1<<" "<<min(c.first,L[i]-2+X)+1<<" "<<c.second<<"+"<<st.getval(x,y)<<"  ["<<x<<":"<<y<<"]"<<endl;
				ma=max(ma,c.second+st.getval(x,y));
			}
		}
		else {
			i=e.second-N;
			FORR(c,Ldp[i]) {
				x=lower_bound(ALL(P),max(R[i]+1,c.first+X-1))-P.begin();
				y=lower_bound(ALL(P),R[i]+X-1)-P.begin();
				//cout<<"add"<<i<<" "<<L[i]<<" "<<R[i]<<" "<<c.first<<" "<<max(R[i]+1,c.first+X-1)<<" "<<R[i]+X-1<<" "<<c.second+1<<"  "<<x<<":"<<y<<endl;
				st.update(x,y,c.second+1);
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
