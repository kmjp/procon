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

int H,W;
int N;
pair<int,int> P[303],Q[303];

int F[505050][4];
pair<int,int> PF[505050];
int G[303][4];
map<int,pair<int,int>> PG;
int PGG[505050][4];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>N;
	FOR(i,N) {
		cin>>y>>x;
		P[i]={y-1,x-1};
		Q[i]={x-1,y-1};
	}
	ll mi=1LL<<50;
	sort(P,P+N);
	sort(Q,Q+N);
	reverse(Q,Q+N);
	vector<int> cand;
	FOR(i,N) {
		if(i&&P[i-1].first==P[i].first) {
			cand.push_back(P[i].second-1-P[i-1].second);
		}
		else {
			cand.push_back(P[i].second);
		}
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	{
		vector<int> Xs;
		FOR(i,N) {
			if(i&&P[i-1].first==P[i].first) {
				if(P[i].second-1>P[i-1].second) Xs.push_back(P[i].second-1);
			}
			else {
				if(P[i].second-1>=0) Xs.push_back(P[i].second-1);
			}
		}
		Xs.push_back(W-1);
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		int sg=0;
		FORR(x,Xs) {
			int cg=1;
			PGG[sg+cg-1][0]=0;
			PGG[sg+cg-1][1]=1<<30;
			PGG[sg+cg-1][2]=1<<30;
			PGG[sg+cg-1][3]=1<<30;
			
			set<int> Ys;
			multiset<int> Ds;
			Ds.insert(0);
			FOR(i,N) if(Q[i].first<=x) {
				y=Q[i].second;
				int p=x-Q[i].first;
				if(Ys.size()) {
					if(y<*Ys.begin()) {
						Ds.insert(*Ys.begin()-y-1);
						Ys.insert(y);
					}
					else if(y>*Ys.rbegin()) {
						Ds.insert(y-*Ys.rbegin()-1);
						Ys.insert(y);
					}
					else {
						auto a=Ys.insert(y);
						if(!a.second) continue;
						auto it=a.first;
						auto it2=next(it);
						auto it3=prev(it);
						Ds.erase(Ds.find(*it2-*it3-1));
						Ds.insert(*it2-y-1);
						Ds.insert(y-*it3-1);
					}
				}
				else {
					Ys.insert(y);
				}
				if(PGG[sg+cg-1][0]!=p) cg++, PGG[sg+cg-1][0]=p;
				PGG[sg+cg-1][1]=*Ys.begin();
				PGG[sg+cg-1][2]=*Ds.rbegin();
				PGG[sg+cg-1][3]=H-1-*Ys.rbegin();
			}
			PG[x]={sg,cg};
			sg+=cg;
		}
	}
	
	
	FORR(w,cand) {
		vector<int> Xs;
		FOR(i,N) {
			if(i&&P[i-1].first==P[i].first) {
				if(P[i].second-w-1>P[i-1].second) Xs.push_back(P[i].second-w-1);
			}
			else {
				if(P[i].second-w-1>=0) Xs.push_back(P[i].second-w-1);
			}
		}
		Xs.push_back(W-1);
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		int nf=0,nf2=0;
		
		
		multiset<int> A,AB,B;
		//cout<<"###"<<endl;
		
		FORR(x,Xs) {
			int ng=1;
			G[0][0]=0;
			G[0][1]=G[0][2]=G[0][3]=1<<30;
			int tx=min(W-1,x+w);
			FOR(i,PG[tx].second) {
				r=PG[tx].first+i;
				int p=max(0,PGG[r][0]-w);
				if(x==W-1) p=PGG[r][0];
				if(G[ng-1][0]!=p) {
					G[ng++][0]=p;
				}
				G[ng-1][1]=PGG[r][1];
				G[ng-1][2]=PGG[r][2];
				G[ng-1][3]=PGG[r][3];
			}
			
			A.insert(G[0][1]);
			AB.insert(G[0][2]);
			B.insert(G[0][3]);
			FOR(i,ng) {
				F[nf][0]=G[i][0];
				F[nf][1]=G[i][1];
				F[nf][2]=G[i][2];
				F[nf][3]=G[i][3];
				if(G[i][0]>0) PF[nf2++]={G[i][0],nf};
				nf++;
			}
		}
		if(*A.rbegin()<1<<30 && *B.rbegin()<1<<30 && *AB.rbegin()<1<<30) {
			mi=min(mi,(ll)w+max(*A.rbegin()+*B.rbegin(),*AB.rbegin()));
		}
		sort(PF,PF+nf2);
		FOR(i,nf2) {
			x=PF[i].second;
			if(F[x-1][1]!=F[x][1]) {
				A.erase(A.find(F[x-1][1]));
				A.insert(F[x][1]);
			}
			if(F[x-1][2]!=F[x][2]) {
				AB.erase(AB.find(F[x-1][2]));
				AB.insert(F[x][2]);
			}
			if(F[x-1][3]!=F[x][3]) {
				B.erase(B.find(F[x-1][3]));
				B.insert(F[x][3]);
			}
			if(*A.rbegin()<1<<30 && *B.rbegin()<1<<30 && *AB.rbegin()<1<<30) {
				mi=min(mi,(ll)w+F[x][0]+max(*A.rbegin()+*B.rbegin(),*AB.rbegin()));
			}
		}
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
