int maxDifference(vector < int > a) {
	int start = a[1] - a[0];
	int cur = start;
	int max_dif = start;
	int i;

	for (i=1;i<a.size()-1;i++){
		start = a[i+1] - a[i];
		if(cur>0)
			cur += start;
		else
			cur = start;

		if(cur>max_dif)
			max_dif=cur;
	}
	return max_dif;
}
