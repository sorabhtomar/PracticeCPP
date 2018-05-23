class String {
private:

	int capacity;
	char* start;

public:
	//Constructors
	String();
	String(char _c);
	String(const char* _pc);
	String(const String& s); // Copy Constructor

							 //Info Methods
	int len() const;
	//int Index(char) const;

	//Operators
	char& operator[](int Index) const;

	//Destructor
	~String();
}; 
