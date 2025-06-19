##include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bin_exp(ll a, ll b) {
    long long res = 1;
    ll mod=998244353;
    while (b > 0) {
        if (b & 1)
            res = ((res%mod)*(a%mod))%mod;
        a = ((a%mod)*(a%mod))%mod;
        b/=2;
    }
    return res;
}

ll hcf(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool is_prime(ll n){
    bool flag=true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    ll mod=998244353;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        ll c1=0;
        ll s=0;
        while(s<n-1){
            if(a[s]<=k){
                c1++;
            }
            ll b=(s+2)/2;
            //cout << b << endl;
            if(c1>=b && a[s+1]>k){
                s++;
            }
            if(c1>=b){
                break;
            }
            s++;
        }
        ll e=n-1;
        ll c2=0;
        while(e>0){
            if(a[e]<=k){
                c2++;
            }
            ll b=(n-e+1)/2;
            if(c2>=b && a[e-1]>k){
                e--;
            }
            if(c2>=b){
                break;
            }
            e--;
        }
        ll x=s;
        ll y=e;
        bool flag=false;
        // cout << s << " " << e << endl;
        if(s+1==e || s==e){
            s=0;
            e=n-1;
            c1=0;
            c2=0;
            while(s<n-1){
                if(a[s]<=k){
                    c1++;
                }
                ll b=(s+2)/2;
                if(c1>=b){
                    break;
                }
                s++;
            }
            while(e>0){
                if(a[e]<=k){
                    c2++;
                }
                ll b=(n-e+1)/2;
                if(c2>=b){
                    break;
                }
                e--;
            }
            if(s+1<e){
                flag=true;
            }
        }
        if(s+1<e){
            flag=true;
        }
        ll cnt1=0;
        for(int i=x+1;i<n-1;i++){
            ll b=(i-x+1)/2;
            if(a[i]<=k){
                cnt1++;
            }
            if(cnt1>=b){
                flag=true;
                break;
            }
        }
        ll cnt2=0;
        for(int i=y-1;i>0;i--){
            ll b=(y-i+1)/2;
            if(a[i]<=k){
                cnt2++;
            }
            if(cnt2>=b){
                flag=true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
