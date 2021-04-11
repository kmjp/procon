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


class MKAverage {
public:
	set<pair<int,int>> A,B,C;
	vector<int> E;
	vector<int> S;
	ll sum;
	int M,K;
    MKAverage(int m, int k) {
        A.clear();
        B.clear();
        C.clear();
        E.clear();
        S.clear();
        sum=0;
        M=m;
        K=k;
    }
    
    void addElement(int num) {
        E.push_back(num);
        int cur=E.size()-1;
        S.push_back(2);
        if(E.size()>M) {
			int x=cur-M;
			A.erase({E[x],x});
			B.erase({E[x],x});
			C.erase({E[x],x});
			if(S[x]==1) sum-=E[x];
		}
		
		if(A.size()<K) {
			A.insert({E[cur],cur});
			S[cur]=0;
		}
		else if(B.size()<M-2*K) {
			B.insert({E[cur],cur});
			S[cur]=1;
			sum+=E[cur];
		}
		else {
			C.insert({E[cur],cur});
			S[cur]=2;
		}
		
		if(A.size()&&B.size()&&*A.rbegin()>*B.begin()) {
			auto p=*A.rbegin();
			auto q=*B.begin();
			A.erase(p);
			B.erase(q);
			A.insert(q);
			B.insert(p);
			sum-=q.first;
			sum+=p.first;
			S[p.second]=1;
			S[q.second]=0;
		}
		if(B.size()&&C.size()&&*B.rbegin()>*C.begin()) {
			auto p=*B.rbegin();
			auto q=*C.begin();
			B.erase(p);
			C.erase(q);
			B.insert(q);
			C.insert(p);
			sum-=p.first;
			sum+=q.first;
			S[p.second]=2;
			S[q.second]=1;
		}
		if(A.size()&&B.size()&&*A.rbegin()>*B.begin()) {
			auto p=*A.rbegin();
			auto q=*B.begin();
			A.erase(p);
			B.erase(q);
			A.insert(q);
			B.insert(p);
			sum-=q.first;
			sum+=p.first;
			S[p.second]=1;
			S[q.second]=0;
		}
    }
    
    int calculateMKAverage() {
		if(E.size()<M) {
			return -1;
		}
		else {
			/*
			FORR(a,A) cout<<a.first<<"#";
			cout<<" ";
			FORR(a,B) cout<<a.first<<"#";
			cout<<" ";
			FORR(a,C) cout<<a.first<<"#";
			cout<<endl;
			*/
			return sum/(M-2*K);
		}
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */