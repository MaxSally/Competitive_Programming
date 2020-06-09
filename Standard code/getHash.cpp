void inithash(const string s){
    int n = s.size();
    for (int i = 1; i <= n; i++){
        hashs[i] = (hashs[i - 1] * base + s[n - i]) % MOD;
    }
    power[0] = 1;
    for (int i = 1; i <= n; i++){
        power[i] = (power[i - 1] * base) % MOD;
    }
}

long long gethashs(int l,int r){
    return (hashs[r] - (hashs[l - 1] * power[r - l + 1]) % MOD + MOD)%MOD;
}
