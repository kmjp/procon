#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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


const int DI=300;
ll V[101010];
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		int N=nums2.size();
		map<ll,int> M[200];
		ll D[200]={};
		int i;
		FOR(i,N) {
			V[i]=nums2[i];
			M[i/DI][V[i]]++;
		}
		
		vector<int> R;
		FORR(q,queries) {
			if(q[0]==1) {
				int L=q[1],R=q[2]+1;
				if(L/DI==(R-1)/DI) {
					int id=L/DI;
					M[id].clear();
					FOR(i,DI) if(id*DI+i<N) {
						V[id*DI+i]+=D[id];
						if(id*DI+i>=L&&id*DI+i<R) V[id*DI+i]+=q[3];
						M[id][V[id*DI+i]]++;
					}
					D[id]=0;
				}
				else {
					if(L%DI) {
						int id=L/DI;
						M[id].clear();
						FOR(i,DI) if(id*DI+i<N) {
							V[id*DI+i]+=D[id];
							if(id*DI+i>=L) V[id*DI+i]+=q[3];
							M[id][V[id*DI+i]]++;
						}
						D[id]=0;
						L=(id+1)*DI;
					}
					while(L+DI<=R) {
						D[L/DI]+=q[3];
						L+=DI;
					}
					if(L<R) {
						int id=L/DI;
						M[id].clear();
						FOR(i,DI) if(id*DI+i<N) {
							V[id*DI+i]+=D[id];
							if(id*DI+i<R) V[id*DI+i]+=q[3];
							M[id][V[id*DI+i]]++;
						}
						D[id]=0;
					}
				}
				
			}
			else {
				int ret=0;
				FOR(i,(N+DI-1)/DI) {
					FORR(a,nums1) ret+=M[i][q[1]-(a+D[i])];
				}
				R.push_back(ret);
			}
		}
        return R;
    }
};


