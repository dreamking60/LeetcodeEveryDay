#include <iostream>

using namespace std;

double bSearch(double l, double h, double target) {
	if(l+0.0001 >= h) {
		return l;
	}
	double mid = ((h - l) / 2 + l) * 1000.0 / 1000.0;
	double dmid = mid * mid * 1000.0 / 1000.0;
	
    //cout << l << endl;
	if(dmid == target) {
		return mid;
	} else if(dmid < target){
		return bSearch(mid, h, target);
	} else {
		return bSearch(l, mid, target);
	}
	
}

int main() {
	double target;
	cin >> target;
	double res = bSearch(0, target, target);
	cout << res << endl;
    return 0;
}