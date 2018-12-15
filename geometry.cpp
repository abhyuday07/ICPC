//-----------|GEOMETRY|-----------------------//
struct point_i{
    int x,y;
    point_i(){ x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};
struct point{
    ld x,y;
    point(){ x = y = 0.0; }
    point(ld _x, ld _y): x(_x), y(_y) {}
    bool operator < (point other) const{
        if(fabs(x-other.x) > eps) return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const{
        return (fabs(x - other.x) < eps && fabs(y - other.y) < eps);
    }
};
double dist(point p1, point p2){ return hypot(p1.x-p2.x, p1.y-p2.y); }
point rotate(point p, ld theta){
    ld rad;
    ld rad = DEG_to_RAD(theta);
    return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
double area(const vector<point>& P){
    ld result = 0.0, x1, y1, x2, y2;
    rep(i,(int)P.size()-1){
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0 ;
}
//---------------------------------------------//