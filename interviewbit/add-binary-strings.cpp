#include <string>
string Solution::addBinary(string A, string B) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int len_a = A.size();
	int len_b = B.size();
	string result;
	int a,b;
	int sum, carry=0;
	int i,j;
	i = A.size()-1;
	j = B.size()-1;
	while (i>=0 || j>=0) {
		if (i>=0)
			a = A[i] - '0';
		else
			a = 0;
		if (j>=0)
			b = B[j] - '0';
		else
			b = 0;
		sum = (a+b+carry)%2;
		carry = (a+b+carry)/2;
		result += to_string(sum);
		--i;
		--j;
	}
	if (carry)
		result += to_string(carry);
	reverse(result.begin(), result.end());
	return result;
}

