#include <bits/stdc++.h>

#define _MAX_DIM 3
#define EPS 1e-9

using namespace std;


/** Double overloading 
bool operator == (const double& a, const double& b) {
    return (fabs(a - b) < EPS);
}

/** Double overloading **
bool operator != (const double& a, const double& b) {
    return !(a == b);
}*/

template<typename T>
struct vec {
    T comp[_MAX_DIM];

    vec() {}

    vec(T c[]) {
        for(int i = 0; i < _MAX_DIM; i++) {
            comp[i] = c[i];
        }
    }

    vec<T> add(vec<T> v) {
        vec<T> res;
        for(int i = 0; i < _MAX_DIM; i++) {
            res.comp[i] = comp[i] + v.comp[i];
        }

        return res;
    }

    vec<T> sub(vec<T> v) {
        vec<T> res;
        for(int i = 0; i < _MAX_DIM; i++) {
            res.comp[i] = comp[i] - v.comp[i];
        }

        return res;
    }

    vec<T> mul(T val) {
        vec<T> res;
        for(int i = 0; i < _MAX_DIM; i++) {
            res.comp[i] = val * comp[i];
        }

        return res;
    }

    double dot(vec<T> v) {
        double res = 0.0;
        for(int i = 0; i < _MAX_DIM; i++) {
            res += comp[i] * v.comp[i];
        }

        return res;
    }

    double length() {
        return sqrt( this->dot(*this) );
    }

    bool operator == (const vec<T> v) {
        for(int i = 0; i < _MAX_DIM; i++) {
            if(comp[i] != v.comp[i]) return false;
        }

        return true;
    }
};

vector< vec<double> > v;
bool done[30];

vec<double> visit(int node, double dleft, double& dist, bool& flag) {
    int nextNode;
    double td = 1e9;
    bool allvisited = true;
    done[node] = true;

    for(int i = 0; i < v.size(); i++) {
        if(!done[i]) {
            allvisited = false;
            double temp = v[i].sub(v[node]).length();
            if(temp < td) {
                td = temp;
                nextNode = i;
            }
        }
    }

    if(allvisited) return v[node];
    if(td > dleft) {
        flag = false;
        dist += dleft;
        return v[node].add( v[nextNode].sub(v[node]).mul(dleft/td) );
    }

    dist += td;
    return visit(nextNode, dleft-td, dist, flag);
}

bool cmp(vec<double> a, vec<double> b) {
    double xyz[] = {0, 0, 1};
    vec<double> myvec(xyz);
    return (myvec.sub(a).length()) > (myvec.sub(b).length());
}

int main() {
    //freopen("in", "r", stdin);
    int f, b, r, n, m = 0;

    while(scanf("%d %d %d %d", &f, &b, &r, &n) && f && b && r && n) {
        
        double xyz[] = {0, 0, 1};
        v.clear(); memset(done, 0, sizeof done);
        v.push_back( vec<double>(xyz) );

        for(int i = 0; i < n; i++) {
            scanf("%lf %lf %lf", &xyz[0], &xyz[1], &xyz[2]);
            v.push_back( vec<double>(xyz) );
        }

        double tim = (double)f / (double)b;
        double canTravel = tim * double(r);
        double dtarvelled = 0.0;
        bool flag = true;
        vec<double> last = visit(0, canTravel, dtarvelled, flag);
        sort(v.begin(), v.end(), cmp);

        printf("Mission %d: ", ++m);
        if(flag) {
            printf("SUCCESS!! Time: %.2lf  Traveled: %.2lf  Fuel Left: %.2lf\n", dtarvelled/r, dtarvelled, f - ((dtarvelled/r)*b));
        } else {
            printf("FAILURE!! Traveled: %.2lf  From Home: %.2lf\n", dtarvelled, last.sub(v[0]).length());
        }
    }

    return 0;
}