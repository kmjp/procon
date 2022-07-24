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


class NumberContainers {
public:
    map<int,int> C;
    set<pair<int,int>> A;
    NumberContainers() {
        C.clear();
        A.clear();
    }
    
    void change(int index, int number) {
        if(C[index]!=0) {
			A.erase({C[index],index});
		}
		C[index]=number;
		A.insert({number,index});
    }
    
    int find(int number) {
        auto it=A.lower_bound({number,0});
        if(it==A.end()) return -1;
        if(it->first!=number) return -1;
        return it->second;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
 