String::String(const char* in_string){
	length = strlen(in_string);
	entries = new char[length+1];
	strcpy(entries, in_string);
}

String::String(List<char> &in_list){
	length = in_list.size();
	entries = new char[length+1];
	for(int i = 0; i < length; i++)
		in_list.retrieve(i, entries[i]);
	entries[length] = '\0';
}

const char* String::c_str() const{
	return (const char*) entries;
}

bool operator==(const String &first, const String &second){
	return strcmp(first.c_str(), second.c_str()) == 0;
}

bool operator> (const String &first, const String &second){
	return strcmp(first.c_str(), second.c_str()) > 0;
}

bool operator< (const String &first, const String &second){
	return strcmp(first.c_str(), second.c_str()) < 0;
}

bool operator>=(const String &first, const String &second){
	return strcmp(first.c_str(), second.c_str()) >= 0;
}

bool operator<=(const String &first, const String &second){
	return strcmp(first.c_str(), second.c_str()) <= 0;
}

bool operator!=(const String &first, const String &second){
	return strcmp(first.c_str(), second.c_str()) != 0;
}

void strcat(String &add_to, const String &add_on){
	const char* cfirst = add_to.c_str();
	const char* csecond = add_on.c_str();
	char* copy = new char[strlen(cfirst) + strlen(csecond) + 1]
	strcpy(copy, cfitst);
	strcat(copy, csecond);
	add_to = copy;
	delete []copy;
}

void strcpy(String &s, const String &t){
	s = t;
}

void strncpy(String &s, const String &t, int len){
	const char* temp = t.c_str();
	char* copy = new char[len + 1];
	strncpy(copy, temp, len);
	copy[len] = 0;
	s = copy;
	delete []copy;
}

int strstr(String s, String t){
	int answer;
	const char* content_s = s.c_str();
	char *p = strstr((char*)content_s, t.c_str);
	if(p == NULL) return -1;
	else answer = p - content_s;
	return answer;
}

String read_in(istream &input){
	List<char> temp;
	int size = 0;
	char c;
	while((c = input.peek()) != EOF && (c = input.get()) != '\n')
		temp.insert(size++, c);
	String answer(temp);
	return answer;
}

void write(String &s){
	cout << c.c_str() << endl;
}

String::String(){
	length = 0;
	entries = new char[length + 1];
	strcpy(entries, "");
}

String::~String(){
	delete []entries;
}

String::String(const String &copy){
	length = strlen(copy.entries);
	entries = new char[length + 1];
	strcpy(entries, copy.entries);
}

void String::operator= (const String &copy){
	if(strcmp(entries, copy.entries) != 0){
		delete []entries;
		length = strlen(copy.entries);
		entries = new char[length + 1];
		strcpy(entries, copy.entries);
	}
}