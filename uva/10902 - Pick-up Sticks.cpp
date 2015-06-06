#include <bits/stdc++.h>

#define _MAX_DIM 2
#define EPS 1e-9
#define PI acos(-1.0)

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

    vec<T> div(T val) {
        vec<T> res;
        for(int i = 0; i < _MAX_DIM; i++) {
            res.comp[i] = comp[i] / val;
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

    double cross2D(vec<T> v) {
        return comp[0]*v.comp[1] - comp[1]*v.comp[0];
    }

    double length() {
        return sqrt( this->dot(*this) );
    }

    vec<T> unitVec() {
        return this->div(this->length());
    }

    vec<T> perpendicularVec2D() {
        vec<T> res = (*this);
        swap( res.comp[0], res.comp[1] );
        res.comp[0] *= -1;
        return res;
    }

    double angle (vec<T> v) {
        double res = dot(v) / (length() * v.length());
        if(res > 1) res = 1; if(res < -1) res = -1;
        return acos(res);
    }

    double polarAngle2D() { //Angle from +ve x-axis
        double res = atan2(comp[1], comp[0]);
        if(res + EPS < 0) res += 2.0*PI;
        return res;
    }

    bool operator == (const vec<T> v) {
        for(int i = 0; i < _MAX_DIM; i++) {
            if(comp[i] != v.comp[i]) return false;
        }

        return true;
    }
};

template<typename T>
struct line {
    vec<T> disV, dirV;

    line(){}

    line(vec<T> _disV, vec<T> _dirV) {
        disV = _disV, dirV = _dirV;
    }

    // line from two points (v1 to v2 directed)
    line pointToLine (vec<T> v1, vec<T> v2) {
        disV = v1;
        dirV = v2.sub(v1);
        return *this;
    }

    // point on line, given t
    vec<T> atPos ( double t ) {
        return disV.add( dirV.mul(t) );
    }

    double segmentToPointDistance ( vec<T> p, double &t ) {
        p = p.sub(disV); // Take it to origin
        t = dirV.dot(p) / (dirV.length() * dirV.length());
        if(t+EPS < 0 || t > 1 + EPS) { //Not on segment
            return min(p.length(), p.sub(dirV).length());
        }
        vec<T> x = dirV.mul(t);
        return (p.sub(x).length());
    }

    bool overlapParallel (line l) {
        double p, q, r, s;
        if(dirV.comp[0] == 0) {
            p = disV.comp[1]; q = atPos(1).comp[1]; r = l.disV.comp[1]; s = l.atPos(1).comp[1];
            if(min(r,s) > max(p,q)) return false;
            if(max(r,s) < min(p,q)) return false;
            return true;
        } else {
            p = disV.comp[0]; q = atPos(1).comp[0]; r = l.disV.comp[0]; s = l.atPos(1).comp[0];
            if(min(r,s) > max(p,q)) return false;
            if(max(r,s) < min(p,q)) return false;
            return true;
        }
    }

    char lineAndLineIntersection2D( line l, double &t, double &s ) {
        if( dirV.cross2D(l.dirV) == 0 ) {
            if( l.disV.sub(disV).cross2D(l.dirV) == 0 ) {
                if ( overlapParallel(l) ) return 'o'; //overlaps
                else return 'p'; //parallel
            } else return 'd'; //disjoint and parallel
        }

        vec<T> w = disV.sub(l.disV);
        vec<T> p = l.dirV.perpendicularVec2D(), z = dirV.perpendicularVec2D();
        t = -(w.dot(p)) / p.dot(dirV); // for current line
        s = w.dot(z)/z.dot(l.dirV); // for line l
        return 'i';
    }

    double segmentAndSegmentDistance2D (line l) {
        double t, s;
        char r = lineAndLineIntersection2D(l, t, s);
        if(r == 'i' && t+EPS > 0 && t < 1+EPS && s+EPS > 0 && s < 1+EPS) {
            return 0; //Valid intersection
        }
        double res = segmentToPointDistance(l.disV, t);
        res = min(res, segmentToPointDistance(l.disV.add(l.dirV), t));
        res = min(res, l.segmentToPointDistance(disV, t));
        res = min(res, l.segmentToPointDistance(disV.add(dirV), t));
        return res;
    }
};

list< pair< int, line<double> > > in;

int main() {
    //freopen("in", "r", stdin);
    int n;
    double xy[2];
    vec<double> s, e;
    line<double> myLine;
    list< pair< int, line<double> > >::iterator it;

    while(scanf("%d", &n) && n) {
        
        in.clear();

        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &xy[0], &xy[1]);
            s = vec<double>(xy);
            scanf("%lf %lf", &xy[0], &xy[1]);
            e = vec<double>(xy);
            myLine = myLine.pointToLine(s, e);

            for(it = in.begin(); (in.size() > 0) && (it != in.end()); ) {
                //cerr << "HERE " << ++x << " " << (*it).first << "\n";
                if( fabs(myLine.segmentAndSegmentDistance2D( (*it).second )) < EPS ) {
                    it = in.erase(it);
                    //cout << "DEL " << (it == in.end()) << "\n";
                } else it++;
            }

            in.push_back( pair< int, line<double> >(i+1, myLine) );
        }

        printf("Top sticks: ");
        int x = 0;
        for(it = in.begin(); it != in.end(); it++) {
            if(x > 0) printf(", ");
            printf("%d", (*it).first);
            x++;
        }
        
        printf(".\n");
    }

    return 0;
}