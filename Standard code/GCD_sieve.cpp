vi prime;
bool isPrime[N];

void sieve(){
    fill(isPrime, isPrime + N, 1);
    isPrime[0] = isPrime[1] = 0;
    rep(i, 2, N - 1){
        if(isPrime[i]){
            prime.pb(i);
            for(int j = 2 * i; j < N; j += i){
                isPrime[j] = 0;
            }
        }
    }
}
