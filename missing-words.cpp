vector < string > missingWords(string s, string t) {
	vector< string > ret;
	unordered_map<string,int> m;
	char *str = strdup(t.c_str());
	if(s.empty()) {
		return ret;
	}

	char *tok = strtok(str," ");
	while(tok != NULL){
		m.emplace(tok,1);
		tok = strtok(NULL, " ");
	}

	char *str2 = strdup(s.c_str());
	tok = strtok(str2, " ");
	while(tok!=NULL){
		if (m.count(tok) == 0)
			ret.push_back(string(tok));
		tok = strtok(NULL, " ");
	}

	return ret;
}
