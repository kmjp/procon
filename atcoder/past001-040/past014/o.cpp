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

int N,Q;
set<pair<int,int>> S;

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
	int lower_bound(V val) { //’P’²‘‰Á‚ÌŽž‚Ì‚ÝŽg‚¦‚é
		V v0=0,v1=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) {
			if((ent+(1<<i)-1)*(v0+bit[0][ent+(1<<i)-1])+(v1+bit[1][ent+(1<<i)-1])<val) {
				v0+=bit[0][ent+(1<<i)-1];
				v1+=bit[1][ent+(1<<i)-1];
				ent+=(1<<i);
			}
		}
		return ent;
	}
};
BIT_r<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	S.insert({0,0});
	S.insert({N+1,0});
	FOR(i,N) {
		cin>>x;
		S.insert({i+1,x});
		bt.add(i+1,i+1,x);
	}
	while(Q--) {
		int C,L,R;
		cin>>C>>L>>R;
		if(C==3) {
			cout<<bt.total(R)-bt.total(L-1)<<endl;
		}
		else {
			R++;
			auto it=S.lower_bound({L+1,0});
			it--;
			S.insert({L,it->second});
			it=S.lower_bound({R+1,0});
			it--;
			S.insert({R,it->second});
			
			int NC[11]={};
			it=S.lower_bound({L,0});
			auto p=*it;
			it=S.erase(it);
			while(it->first<=R) {
				NC[p.second]+=it->first-p.first;
				bt.add(p.first,it->first-1,-p.second);
				if(it->first==R) break;
				p=*it;
				it=S.erase(it);
			}
			if(C==1) {
				FOR(i,11) if(NC[i]) {
					S.insert({L,i});
					bt.add(L,L+NC[i]-1,i);
					L+=NC[i];
				}
			}
			else {
				for(i=10;i>=0;i--) if(NC[i]) {
					S.insert({L,i});
					bt.add(L,L+NC[i]-1,i);
					L+=NC[i];
				}
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
