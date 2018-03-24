#pragma once


// CMyList

class CMyList : public CListCtrl
{
	DECLARE_DYNAMIC(CMyList)

public:
	CMyList();
	virtual ~CMyList();
	void CMyList::AddColumn(int nNum, ...);
	void CMyList::AddItem(int nItemNum, int nCount, ...);
	int m_nItem;
protected:
	DECLARE_MESSAGE_MAP()

public:
//	afx_msg void OnButton1();
//	afx_msg void OnButton1();
};


