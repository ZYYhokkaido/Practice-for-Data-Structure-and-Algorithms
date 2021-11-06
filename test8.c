#include <stdio.h>
#include <math.h>

long long gcd(long long a, long long b)
{
	long long temp;

	if (a < b)
	{
		temp = b;
		b = a;
		a = temp;
	}

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long gongbeishu(long long a, long long b)
{
	return a * b / gcd(a, b);
}

long long shuzugongbeishu(long long a[], int len)
{
	long long temp[len];
	int i;
	for (i = 0; i < len; i++)
	{
		temp[i] = a[i];
	}

	for (i = 1; i < len; i++)
	{
		temp[i] = gongbeishu(temp[i - 1], temp[i]);
		//printf("%d",temp[i]);
	}
	return temp[len - 1];
}

/*

28 42
28 = 2 x 2 x 7
42 = 2 x 3 x 7
lcm = (2 x 3) x (2 x 7)

28 = pow(2,2) x pow(3,0) x pow(7,1)
42 = pow(2,1) x pow(3,1) x pow(7,1)

lcm = pow(2,2) x pow(3,1) x pow(7,1) / pow(2,1) x pow(3,1) -> Bi

[[2,1],[3,1],[7,1]]
vector<int[2]>

AiBi = lcm
sum(Bi)
lcm/Ai 怎么算

lcm:

13

2 3 4 5 ... 13   sqrt(13)
魔数
math.h

*/

int main()
{
	int N, i;
	long long cnt = 0, gongbeishu;
	scanf("%d", &N);
	long long A[N];
	for (i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
	}

	gongbeishu = shuzugongbeishu(A, N);

	//printf("%ld\n",gongbeishu);

	for (i = 0; i < N; i++)
	{
		cnt += gongbeishu / A[i];
	}

	printf("%lld\n", cnt % (1000000000 + 7));

	return 0;
}


//------------------------------------------------


/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1E6+7;
const ll mod=1e9+7;
ll arr[N];
ll mp[N];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
int main()
{
    ios::sync_with_stdio(false );
    ll n;
    cin>>n;
    ll mx=0;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    ll pos=0;
    for(ll i=1;i<=n;i++){
        ll x=arr[i];
        ll y=sqrt(x);
        for(ll j=2;j<=y;j++){
            ll cnt=0;
            while(x%j==0){
                x/=j;
                cnt++;
            }
            mp[j]=max(mp[j],cnt);
        }
        if(x!=1) mp[x]=max(mp[x],(ll)1);
    }
    ll sum=1;
    for(ll i=1;i<=mx;i++)
        sum=(sum%mod*ksm(i,mp[i])%mod)%mod;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=sum*ksm(arr[i],mod-2)%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}




//------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[10010];
ll fac[1000010];
const ll mod = 1e9 + 7;
ll sqr(ll x)
{ //sqr(5)=2,sqr(10)=3
	ll lft = 0, rht = 1e5;
	while (rht - lft > 1)
	{
		ll mid = (rht + lft) >> 1;
		if (mid * mid <= x)
		{
			lft = mid;
		}
		else
		{
			rht = mid;
		}
	}
	return lft;
}
ll qp(ll a, ll b, ll mod)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
ll getInv(ll x, ll p)
{
	return qp(x, p - 2, p);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int tmp = a[i], bound = sqr(a[i]);
		for (int j = 2; j <= bound; j++)
		{
			if (tmp % j == 0)
			{
				ll save = 0;
				while (tmp % j == 0)
				{
					tmp /= j;
					save++;
				}
				fac[j] = max(fac[j], save);
				j = 1;
				bound = sqr(tmp);
			}
		}
		if (tmp != 1)
		{
			fac[tmp] = max(fac[tmp], 1ll);
		}
	}
	ll sum = 1;
	for (int i = 2; i <= 1000005; i++)
	{
		sum = sum * qp(i, fac[i], mod) % mod;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = ans + getInv(a[i], mod) * sum % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}







#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
 
const int MOD = 1000000007;
using bigint = boost::multiprecision::cpp_int;
 
int main(){
    int N; cin >> N;
    bigint ablcm = 1;
    bigint b = 0;
    for(int i=0; i<N; i++){
        int a; cin >> a;

		//auto t = gcd((ablcm%a),a)
        auto t = __gcd(boost::multiprecision::integer_modulus(ablcm, a), a);

        //(b *= (a/t)) += ablcm /= t;

		b *= a/t;
		ablcm /= t;
		b += ablcm;

        ablcm *= a;
    }
    b =  boost::multiprecision::integer_modulus(b, MOD);
    cout << b << endl;
}
*/