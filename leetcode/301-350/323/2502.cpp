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

class Allocator {
public:
	map<int,int> SM,SS;
	int N;
    Allocator(int n) {
        SM.clear();
        SS.clear();
        N=n;
        SM[-1]=SM[N]=-1;
        SS[-1]=SS[N]=100000;
        
        
    }
    
    int allocate(int size, int mID) {
        int cur=0;
        while(cur<N) {
			auto it=SS.lower_bound(cur);
			if(it->first-cur>=size) {
				SM[cur]=mID;
				SS[cur]=size;
				return cur;
			}
			cur=it->first+it->second;
		}
		return -1;
    }
    
    int free(int mID) {
		vector<int> V;
		int sum=0;
		FORR(a,SM) if(a.second==mID) {
			V.push_back(a.first);
			sum+=SS[a.first];
		}
		FORR(v,V) SM.erase(v),SS.erase(v);
		return sum;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
 