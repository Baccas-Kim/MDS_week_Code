#pragma once

class CMyString
{
public:
	CMyString();

	// 변환 생성자
	explicit CMyString(const char *pszParam);

	// 복사 생성자
	CMyString(const CMyString &rhs);

	// 이동 생성자
	CMyString(CMyString &&rhs);

	~CMyString();

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;

	// 저장된 문자열의 길이
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// 멤버 읽기만 수행하므로 메서드를 상수화한다.
	const char* GetString() const;

	void Release();
	CMyString& operator=(const CMyString &rhs);

	operator char*() const
	{
		return m_pszData;
	}

	int GetLength() const;
	int Append(const char * pszParam);
	CMyString operator+(const CMyString & rhs);
	CMyString& operator+=(const CMyString & rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString &rhs);
	virtual void OnSetString(char * pszData, int nLength);
	friend CMyString operator+(const char *pszParam, const CMyString &strParam);
};