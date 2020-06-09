vi extendedEuclidean(int b, int m){ //m is the mod
    vi res;
    int x1 = 0, y1 = 1;
    int x2 = 1, y2 = 0;
    int q, r;
    int x = 1, y = 0;
    while(m != 0){
        q = b / m;
        r = b % m;
        x = x2 - q * x1;
        y = y2 - q * y1;
        x2 = x1; y2 = y1; x1 = x; y1 = y;
        b = m; m = r;
    }
    res.pb(b); res.pb(x2); res.pb(y2);
    return res;
}

int modInverse(int b, int m){
    vi res = extendedEuclidean(b, m);
    int gcd = res[0];
    int x = res[1], y = res[2];
    if(gcd == 1) return (x + m) % m;
}

