const int N=1e5;
int fact[N+1],ifact[N+1];


int binpow(int a,int n){
	if(n==0)return 1;

	int t=binpow(a,n/2);
	if(n%2==0) return (t*t)%mod;
	else{
		t=(t*t)%mod;
		return (t*a)%mod;
	}
}

int inverse(int a){
	return binpow(a,mod-2);
}

void compute_fact(){
	fact[0]=ifact[0]=1;
	for(int i=1;i<=N;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
	
	ifact[N]=inverse(fact[N]);
	for(int i=N-1;i>=0;i--){
		ifact[i]=(ifact[i+1]%mod*(i+1)%mod)%mod;
	}

}

int nCr(int n,int r){

	int num=fact[n];
	int den=(ifact[r]*ifact[n-r])%mod;
	return (num*den)%mod;
}