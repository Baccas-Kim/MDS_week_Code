#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) { }
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// friend �Լ��� �����Ѵ�.
	friend void PrintData(const CMyData &);

private:
	int m_nData = 0;
};

void PrintData(const CMyData &rData)
{
	// ������ �Լ��̹Ƿ� ���� ���� �������� ������ ���� �ʰ�
	// private ����� ���� �����Ѵ�.
	cout << "PrintData(): " << rData.m_nData << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(5);
	PrintData(a);

	return 0;
}