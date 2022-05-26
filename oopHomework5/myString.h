#pragma once
class myString {
private:
	size_t _length = 0;
	size_t _capacity = 16;
	char* _text = nullptr;
	void setText(const char* text);
public:
	myString(); // Default Constructor
	myString(const char* text); // Constructor with Param
	myString(const myString& other); // Copy Constructor
	// Constructor with Param
	myString(const size_t count, const char* text); 
	// Copy Assignment operator
	myString& operator=(const myString& other);
	myString(myString&& other) noexcept;
	myString& operator=(myString&& other) noexcept;
	char& front(); 
	char& back();
	char& at(size_t index);
	size_t capacity() const;
	size_t size() const;
	size_t find(char chr) const;
	size_t rfind(char chr) const;
	void clear();
	void resize(size_t newSize);
	void reserve(size_t newCapacity);
	void shrink_to_fit();
	bool empty() const;
	myString append(const char* text);
	int compare(const myString right);
	myString subString(int a, int b);
	void swap(myString string);////?????????
	myString erase(int a, int b);
	const char* print() const { 
		if (_text == nullptr)
			return "";
		return _text;
	}

	~myString();
};

myString::myString() {
	//_text = new char[_capacity];
}

myString::myString(const char* text)
	:myString()
{
	setText(text);
}

myString::myString(const size_t count, const char* text)
{
	_text = new char[count*strlen(text)+2]{};
	int a = 0;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; text[j]!='\0'; j++)
		{
			_text[a++] = text[j];
		}
	}
}


myString::myString(const myString& other) {
	_text = other._text;

}

myString& myString::operator=(const myString& other) {
	_text = other._text;
	return *this;
}


myString::myString(myString&& other) noexcept {
	// cout << "Move constructor\n";

	_text = other._text;
	other._text = nullptr;
}

myString& myString::operator=(myString&& other) noexcept {
	// cout << "Move Assigment operator\n";

	if (_text != nullptr)
		delete _text;

	_text = other._text;
	other._text = nullptr;

	return  *this;
}


void myString::setText(const char* text) {
	_length = strlen(text);
	while (_length >= _capacity)
		_capacity += 16;
	_text = new char[_capacity];
	strcpy_s(_text, _length + 1, text);
}

char& myString::front() {
	return _text[0];
}

char& myString::back() {
	return _text[_length - 1];
}

char& myString::at(size_t index) {
	return _text[index];
}

size_t myString::capacity() const {
	return _capacity - 1;
}
size_t myString::size() const { return _length; }

size_t myString::find(char chr) const {
	for (size_t i = 0; _text[i] != '\0'; i++)
	{
		if (_text[i] == chr)
			return i;
	}
	return -1;
}

size_t myString::rfind(char chr) const {
	for (size_t i = _length; i >= 0; i--)
	{
		if (_text[i] == chr)
			return i;
	}
	return -1;
}

void myString::clear() {
	delete[]_text;
	_text = nullptr;
	_length = 0;
}

void myString::resize(size_t newSize) {
	char* newString = new char[newSize+1]{};
	for (size_t i = 0; i < newSize; i++)
	{
		newString[i] = _text[i];
	}
	delete[]_text;
	_text = newString;
	_length = newSize;
}

void myString::reserve(size_t newCapacity) {
	_capacity = newCapacity+1;
}

void myString::shrink_to_fit()
{
	_capacity = _length+1;
}

bool myString::empty() const {
		return _text == nullptr;
	return false;
}
myString  myString::append(const char* text) {
	myString temp;
	size_t len = _length + strlen(text) + 1;
	temp._text = new char[len];
	for (size_t i = 0; i < _length; i++)
	{
		temp._text[i] = _text[i];
	}
	for (size_t i = _length, j=0; i < len; i++)
	{
		temp._text[i] = text[j++];
	}
	temp.setText(temp._text);
	return temp;

}

int  myString::compare(const myString right) {
	return strcmp(_text, right._text);
}

myString myString::subString(int a, int b) {
	myString temp;
	size_t len = b - a + 2;
	temp._text = new char[len] {};
	for (size_t i = a, j=0; i < b; i++)
	{
		temp._text[j++] = _text[i];
	}
	temp.setText(temp._text);
	return temp;
}

void myString::swap(myString string) {
	myString temp;
	temp.setText(_text);
	setText(string._text);
	string.setText(_text);
}

myString myString::erase(int idx, int count) {
	myString temp;
	temp._text = new char[_length] {};
	size_t a = 0;
	for (size_t i = 0; i < _length; i++)
	{
		for (size_t j = idx; j < idx+count; j++)
		{
			if (i == j)
				continue;

		}
		temp._text[a++] = _text[i];
	}
	temp.setText(temp._text);
	return temp;
}









myString::~myString(){
	//cout << "Destructor for -> " << (_text?_text:"null") << endl;
	delete _text;
}

/// default constructoru yaz
/// umumi check ele