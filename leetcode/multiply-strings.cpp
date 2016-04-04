string multiply(string num1, string num2) {
	string sum(num1.size() + num2.size(), '0');
	int carry = 0, val = 0;
	int i,j;
	for (i = num1.size() - 1; i>=0; i--) {
		carry = 0;
		for (j = num2.size() - 1; j>=0; j--) {
			val = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
			sum[i + j + 1] = (val % 10) + '0';
			carry = val / 10;
		}
		sum[i] += carry;
	}
	i=0;
	while(i<sum.size() && sum[i]=='0')
		i++;
	if (i!=sum.size())
		return sum.substr(i);
	return "0";
}
