ll x, y, d;

void extendedEuclid(ll a, ll b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    x = x - (a/b) * y;
    swap(x, y);
}

ll cntSol(int a, int b, int c, ll x1, ll x2, ll y1, ll y2){
    //debug(a); debug(b); debug(c);
    extendedEuclid(a, b);
    if(!a && !b)
        if(c == 0) return 1LL*(1LL*x2 - x1 + 1) * (1LL*y2 - y1 + 1);
        else return 0;
    if(!a){
        if(c % b != 0) return 0;
        c = -c / b;
        if(y1 <= c && c <= y2) return x2 - x1 + 1;
        return 0;
    }else if(!b){
        if(c % a != 0) return 0;
        c = -c / a;
        if(x1 <= c && c <= x2) return y2 - y1 + 1;
        return 0;
    }

    if(c % d == 0){
        x *= (-c/d);
        y *= (-c/d);
        a /= d; b /= d;
        double p = (x1 - x)/(double)b, q = (x2 - x)/(double)b;
        //debug(p); debug(q);
        if(p > q) swap(p, q);
        x1 = (ll)ceil(p);
        x2 = (ll)floor(q);

        p = (y - y1)/(double)a;
        q = (y - y2)/(double)a;
        if(p > q) swap(p, q);
        y1 = (ll)ceil(p);
        y2 = (ll)floor(q);

        x1 = max(x1, y1);
        x2 = min(x2, y2);
        //debug(x1); debug(x2);
        return max(0LL, x2 - x1 + 1);
    }
    return 0;
}

