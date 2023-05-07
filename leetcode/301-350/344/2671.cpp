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

class FrequencyTracker {
public:
	map<int,int> A,B;
    FrequencyTracker() {
        A.clear();
        B.clear();
    }
    
    void add(int number) {
        B[A[number]]--;
        A[number]++;
        B[A[number]]++;
    }
    
    void deleteOne(int number) {
		if(A[number]>0) {
	        B[A[number]]--;
	        A[number]--;
	        B[A[number]]++;
	    }
        
    }
    
    bool hasFrequency(int frequency) {
        return B[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */