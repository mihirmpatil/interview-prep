#include <cmath>
int Solution::sqrt(int A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if (A<=0)
		return 0;
	if (A==1)
		return 1;
	double low = 0;
	double high = A;
	double mid;
	while(abs(low*high - A) > 0.0001) {
		mid = (low+high)/2;
		if(mid*mid > A)
			high = mid;
		else
			low = mid;
	}
	return floor(mid);
}
