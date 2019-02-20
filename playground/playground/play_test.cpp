#include<iostream>

using namespace std;

class CMyString
{
public:
	CMyString(char * pData = nullptr) {};
	CMyString(const CMyString& str) {};
	~CMyString(void) {};
private:
	char * m_pData;


};


void main()
{
	char tmp[] = { "hello" };
	char *ptr = tmp;
	cout << *ptr << endl;
	cout << tmp << endl;

	int a = 5;
	int & a_ref = a;
	cout << a << endl;
	cout << ++a_ref << endl;
	cout << a << endl;


}

