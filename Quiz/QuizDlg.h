
// QuizDlg.h : header file
//

#pragma once
#include "QuizEngine.h"


// CQuizDlg dialog
class CQuizDlg : public CDialogEx
{
// Construction
public:
	CQuizDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUIZ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CString questionStaticText;
	CString answearAStaticText;
	CString answearBStaticText;
	CString answearCStaticText;
	CString answearDStaticText;
	CString scoreStaticText;

	CButton aButton;
	CButton bButton;
	CButton cButton;
	CButton dButton;

	std::uint16_t currentQuestion = 0;
	Question::ANSWEAR currentAnswear = Question::ANSWEAR::NONE;
	QuizEngine quizEngine;
	std::uint16_t score = 0;

	bool checkAnswear() const;
	void updateScore();
	void generateNewQuestion();
	void initializeFields();
	void handleAnswear(const Question::ANSWEAR &answear);

public:
	afx_msg void onButtonAClicked();
	afx_msg void onButtonBClicked();
	afx_msg void onButtonCClicked();
	afx_msg void onButtonDClicked();
};
