#include <bits/stdc++.h>
using namespace std;


/*************************************************MACROS*************************************************************************/
#define int long long
#define endl "\n"
#define pii pair<int, int>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define inp(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define prr(v) for (const auto& elem : (v)) cout << elem << " "; cout << endl;
/********************************************************************************************************************************/

struct Data_dashBoard{

    int sum = 0;
    double cnt = 0;
    int sumq = 0;
    map<int,int>freq;
    multiset<pii>freq_order;
    multiset<int> low , high;
    
    void balance(){
        
        if( low.size() < high.size() ){
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        
        while( low.size() > high.size() + 1 ){
            int x = *low.begin();
            low.erase(low.find(x));
            high.insert(x);
        }
        
    }
    
    void insert(int x){
        cnt++;
        sum+=x;
        sumq+=x*x;
        
        // mode
         if (freq_order.find(make_pair(freq[x], x)) != freq_order.end()){
            freq_order.erase(freq_order.find(make_pair(freq[x], x)));
        }
        
        freq[x]++;
        freq_order.insert(make_pair(freq[x], x));
        
        // median 
        
        if(low.empty()) low.insert(x);
        else if( x <= *low.rbegin() ){
            low.insert(x);
        }else{
            high.insert(x);
        }
        
        balance();
    }
    
    void remove(int x){
        cnt--;
        sum-=x;
        sumq-=x*x;
        
         if (freq_order.find(make_pair(freq[x], x)) != freq_order.end()){
            freq_order.erase(freq_order.find(make_pair(freq[x], x)));
        }
        
        freq[x]--;
        if(freq[x])freq_order.insert(make_pair(freq[x], x));
        
        if(high.find(x)!=high.end()){
            high.erase(high.find(x));
        }else{
            low.erase(low.find(x));
        }
        
        balance();
    }
    
    
    double mean(){
        return static_cast<double>(sum)/cnt;
    }
    double variance(){
        return sumq/cnt - mean()*mean();
    }
    double mode(){
        return freq_order.rbegin()->second;
    }
    double median(){
        balance();
        if((low.size() + high.size()) %2){
            return *low.rbegin();
        }else{
            return( (*low.rbegin()) + (*high.begin()))/2.0;
        }
    }
};

void HELP_ME_(){
 
    
    
}



/*************************************************MAIN*************************************************************************/
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // int __runtTime_terror;
    // cin >> __runtTime_terror;
    // while(__runtTime_terror--) {
    //     HELP_ME_();
    // }
    
    Data_dashBoard db;
    
    db.insert(1);
    db.insert(2);
    db.insert(4);
    
    cout<<db.mean()<<endl;
    cout<<db.median()<<endl;
    cout<<db.mode()<<endl;
    cout<<db.variance()<<endl;

    return 0;
}


 // Number of Divisors till n  
 vector<int> sieve(int max_n) {
        vector<bool> is_prime(max_n + 1, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= max_n; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= max_n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    } 
    
    // Function to calculate LCM
    int lcm(int a, int b) {
        return (a * b) / __gcd(a, b); 
    }

