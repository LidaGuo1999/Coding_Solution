
class Solution {
public:
    #define EPS 1e-8
    double transform(double a) {
        //double pi = 3.14159265358979323;
        return a/(2*M_PI)*360.0;
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int len = points.size(), lap = 0;
        double an = (double)angle, start = 360.0-an/2.0, end = an/2.0;
        vector<double> ps;
        for (int i = 0; i < len; i++) {
            long long x = points[i][0], y = points[i][1], x0 = location[0], y0 = location[1];
            if (x == x0 && y == y0) {
                lap++;
                continue;
            }
            double a = asin((double)(y-y0)/(double)(sqrt((y-y0)*(y-y0)+(x-x0)*(x-x0))));
            a = transform(a);
            
            if (a == 0.0 && x > x0) {
                a = 0.0;
                //printf("way1:%d\n", i);
            }
            else if (a == 0.0 && x < x0) {
                a = 180.0;
                //printf("way2:%d a:%lf\n", i, a);
            }
            else if (a > 0 & x < x0) a = 180.0-a;
            else if (a < 0) {
                if (x < x0) a = -180.0-a;
                a += 360.0;
            }
            //printf("a:%lf\n", a);
            ps.push_back(a);
        }
        
        
        len = ps.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len-i-1; j++) {
                if (ps[j] > ps[j+1]) swap(ps[j], ps[j+1]);
            }
        }

        for (int i = 0; i < len; i++) ps.push_back(ps[i]+360);

        for (int i = 0; i < ps.size(); i++) printf("%.8lf ", ps[i]);
        printf("\n");
        
        int cur_max = 0;

        int p1 = 0, p2 = 0;
        for (p1 = 0; p1 < len; p1++) {
            while ((p2+1) < ps.size() && ((ps[p2] > ps[p1] && fabs(ps[p2]-ps[p1]) > EPS) || fabs(ps[p2]-ps[p1] <= EPS)))
                p2++;
            cur_max = max(cur_max, p2-p1+1);
        }

        /*int p1 = 0, p2 = 0, cnt = 0, move = 0;
        while (move < len) {
            double gap = 0.0;
            if (cnt >= len) break;
            if ((ps[p1] < ps[p2] && fabs(ps[p1]-ps[p2]) > EPS) || (fabs(ps[p1]-ps[p2]) <= EPS)) {
                gap = ps[p2]-ps[p1];
            } else {
                gap = 360.0-ps[p1]+ps[p2];
            }
            //printf("%d %d %lf\n", p1, p2, gap);
            if ((gap < an && fabs(gap-an) > EPS) || (fabs(gap-an) <= EPS)) {
                p2 = (p2+1)%len;
                cnt++;
            } else {
                p1 = (p1+1)%len;
                move++;
                cnt--;
            }
            cur_max = max(cur_max, cnt);
        }*/
        /*int r = 0, hi = 0, move = 0;
        for (int l = 0; l < len; ++l) {
            while ((r+1)%len != l && ps[(r + 1)%len] - ps[l] <= (double)angle + EPS)
                r = (r+1)%len;
            printf("%d %d\n", l, r);
            hi = max(hi, r - l + 1);
        }
        cur_max = hi;*/
        return cur_max+lap;
    }
};
