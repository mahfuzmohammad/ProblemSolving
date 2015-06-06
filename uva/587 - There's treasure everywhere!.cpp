#include <bits/stdc++.h>

using namespace std;

struct dir {
	double step;
	string d;
	dir(){}
	dir(double s, string _d) {
		step = s, d = _d;
	}
};

vector<dir> v;

dir processDir(string str) {
	double step = 0;
	string d = "";
	for(int i = 0; i < str.size(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			step = step * 10.0 + (str[i] - '0');
		} else {
			d += str[i];
		}
	}

	return dir(step, d);
}

struct Point {
	double x, y;
	Point(){}
	Point(double _x, double _y) {
		x = _x, y = _y;
	}

	void N(double d) {
		y += d;
	}

	void S(double d) {
		y -= d;
	}

	void E(double d) {
		x += d;
	}

	void W(double d) {
		x -= d;
	}
};

double dist(Point a, Point b) {
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int main() {
	string in;
	double step;
	int mapCnt = 0;

	while(cin >> in) {
		if(in == "END") break;
		v.clear();
		in = in.substr(0, (int)in.size() - 1);
		stringstream ss(in);
		string tmp;
		while(getline(ss, tmp, ',')) {
			v.push_back(processDir(tmp));
		}

		Point start(0.0, 0.0);
		for(int i = 0; i < v.size(); i++) {
			if(v[i].d == "N") {
				start.N(v[i].step);
			} else if(v[i].d == "S") {
				start.S(v[i].step);
			} else if(v[i].d == "E") {
				start.E(v[i].step);
			} else if(v[i].d == "W") {
				start.W(v[i].step);
			} else if(v[i].d == "NE") {
				step = v[i].step / sqrt(2.0);
				start.N(step); start.E(step);
			} else if(v[i].d == "NW") {
				step = v[i].step / sqrt(2.0);
				start.N(step); start.W(step);
			} else if(v[i].d == "SE") {
				step = v[i].step / sqrt(2.0);
				start.S(step); start.E(step);
			} else if(v[i].d == "SW") {
				step = v[i].step / sqrt(2.0);
				start.S(step); start.W(step);
			}
		}

		printf("Map #%d\n", ++mapCnt);
		printf("The treasure is located at (%.3f,%.3f).\n", start.x, start.y);
		printf("The distance to the treasure is %.3f.\n\n", dist(Point(0.0, 0.0), start));
	}

	return 0;
}