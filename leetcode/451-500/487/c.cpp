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


class RideSharingSystem {
public:
	queue<int> A,B;
	set<int> ok;
    RideSharingSystem() {
		while(A.size()) A.pop();
		while(B.size()) B.pop();
        ok.clear();
    }
    
    void addRider(int riderId) {
        A.push(riderId);
        ok.insert(riderId);
    }
    
    void addDriver(int driverId) {
        B.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(A.size()&&ok.count(A.front())==0) A.pop();
        int a=-1,b=-1;
        if(A.size()&&B.size()) {
			a=A.front();
			b=B.front();
			A.pop();
			B.pop();
		}
		return {b,a};
    }
    
    void cancelRider(int riderId) {
        ok.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
 
 
 