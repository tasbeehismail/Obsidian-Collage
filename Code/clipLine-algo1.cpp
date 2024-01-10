#include <iostream>  
using namespace std;  

double xp1, yp1, xp2, yp2;  
double xw_min, xw_max, yw_min, yw_max;  

const int INSIDE = 0; // 0000  
const int LEFT = 1;   // 0001  
const int RIGHT = 2;  // 0010  
const int BOTTOM = 4; // 0100  
const int TOP = 8;    // 1000  

int bit(double x, double y) {  
	int code = INSIDE;  

	if (x < xw_min)  
	    code |= LEFT;  
	else if (x > xw_max)  
	    code |= RIGHT;  

	if (y < yw_min)  
	    code |= BOTTOM;  
	else if (y > yw_max)  
	    code |= TOP;  

	return code;  
}  

void clipLine() {  
	int bitP1 = bit(xp1, yp1);  
	int bitP2 = bit(xp2, yp2);  
	bool accept = false;  

	while (true) {  
	    if (!(bitP1 | bitP2)) {  
	        accept = true;  
	        break;  
	    } else if (bitP1 & bitP2) {  
	        break;  
	    } else {  
	        double x, y;  
	        int bitP = (bitP1) ? bitP1 : bitP2;  
	        double m = (yp2 - yp1) / (xp2 - xp1);  
	        if (bitP & TOP) {  
	            x = xp1 + (yw_max - yp1) / m;  
	            y = yw_max;  
	        } else if (bitP & BOTTOM) {  
	            x = xp1 + (yw_min - yp1) / m;  
	            y = yw_min;  
	        } else if (bitP & RIGHT) {  
	            y = yp1 + (xw_max - xp1) * m;  
	            x = xw_max;  
	        } else if (bitP & LEFT) {  
	            y = yp1 + (xw_min - xp1) * m;  
	            x = xw_min;  
	        }  

	        if (bitP == bitP1) {  
	            xp1 = x;  
	            yp1 = y;  
	            bitP1 = bit(xp1, yp1);  
	        } else {  
	            xp2 = x;  
	            yp2 = y;  
	            bitP2 = bit(xp2, yp2);  
	        }  
	    }  
	}  

	if (accept) {  
		cout << "Partially Inside! Clipped line: (" 
		<< xp1 << ", " << yp1 << ") to (" 
		<< xp2 << ", " << yp2 << ")\n";  
	} else {  
	    cout << "Completely Outside!\n";  
	}  
}  

int main() {  
	cin >> xp1 >> yp1 >> xp2 >> yp2;  
	cin >> xw_min >> xw_max >> yw_min >> yw_max;  

	clipLine();  

	return 0;  
}