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

int closestPair(vector<int>& first, vector<int>& second) {
	int ret=1<<30;
	int i;
	sort(ALL(first));
	sort(ALL(second));
	FOR(i,2) {
	
		FORR(r,first) {
			auto it=lower_bound(ALL(second),r);
			if(it!=second.end()) ret=min(ret,abs(r-*it));
			if(it!=second.begin()) {
				it--;
				ret=min(ret,abs(r-*it));
			}
		}
		
		swap(first,second);
	}
	return ret;
    
}

int main() {
    int n; cin >> n;
    vector<int> first, second;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        second.push_back(val);
    }
    cout << closestPair(first, second) << "\n";
    return 0;
}
