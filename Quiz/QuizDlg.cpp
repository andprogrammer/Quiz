
// QuizDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Quiz.h"
#include "QuizDlg.h"
#include "afxdialogex.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CQuizDlg dialog



CQuizDlg::CQuizDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_QUIZ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	initializeFields();
}

void CQuizDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_TEXT_QUESTION, questionStaticText);
	DDX_Text(pDX, IDC_STATIC_TEXT_ANSWEAR_A, answearAStaticText);
	DDX_Text(pDX, IDC_STATIC_TEXT_ANSWEAR_B, answearBStaticText);
	DDX_Text(pDX, IDC_STATIC_TEXT_ANSWEAR_C, answearCStaticText);
	DDX_Text(pDX, IDC_STATIC_TEXT_ANSWEAR_D, answearDStaticText);
	DDX_Text(pDX, IDC_STATIC_TEXT_SCORE, scoreStaticText);
	DDX_Control(pDX, IDC_BUTTON_A, aButton);
	DDX_Control(pDX, IDC_BUTTON_B, bButton);
	DDX_Control(pDX, IDC_BUTTON_C, cButton);
	DDX_Control(pDX, IDC_BUTTON_D, dButton);
	DDX_Control(pDX, IDC_BUTTON_NEW_QUIZ, newQuizButton);
}

BEGIN_MESSAGE_MAP(CQuizDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_A, &CQuizDlg::onButtonAClicked)
	ON_BN_CLICKED(IDC_BUTTON_B, &CQuizDlg::onButtonBClicked)
	ON_BN_CLICKED(IDC_BUTTON_C, &CQuizDlg::onButtonCClicked)
	ON_BN_CLICKED(IDC_BUTTON_D, &CQuizDlg::onButtonDClicked)
	ON_BN_CLICKED(IDC_BUTTON_NEW_QUIZ, &CQuizDlg::onButtonNewQuizClicked)
END_MESSAGE_MAP()


// CQuizDlg message handlers

BOOL CQuizDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	setFont();

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQuizDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQuizDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQuizDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CQuizDlg::setFont()
{
	font.CreateFont(16, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif"));
	aButton.SetFont(&font);
	bButton.SetFont(&font);
	cButton.SetFont(&font);
	dButton.SetFont(&font);
	newQuizButton.SetFont(&font);
}

bool CQuizDlg::checkAnswear() const
{
	if (currentQuestion >= quizEngine.getQuestions().size()) return false;
	return currentAnswear == quizEngine.getQuestions()[currentQuestion].getProperAnswear();
}

void CQuizDlg::updateScore()
{
	score += checkAnswear() ? 1 : 0;
	std::stringstream scoreText;
	scoreText << "SCORE : " << score << " / " << quizEngine.getQuestions().size();
	scoreStaticText = scoreText.str().c_str();
}

void CQuizDlg::generateNewQuestion()
{
	if (currentQuestion < quizEngine.getQuestions().size())
	{
		std::stringstream actualQuestion;
		actualQuestion << currentQuestion + 1 << ") " << quizEngine.getQuestions()[currentQuestion].getQuestion();
		questionStaticText = actualQuestion.str().c_str();

		answearAStaticText = quizEngine.getQuestions()[currentQuestion].getAnswear1().c_str();
		answearBStaticText = quizEngine.getQuestions()[currentQuestion].getAnswear2().c_str();
		answearCStaticText = quizEngine.getQuestions()[currentQuestion].getAnswear3().c_str();
		answearDStaticText = quizEngine.getQuestions()[currentQuestion].getAnswear4().c_str();
	}
}

void CQuizDlg::initializeFields()
{
	updateScore();
	generateNewQuestion();
}

void CQuizDlg::handleAnswear(const Question::ANSWEAR &answear)
{
	currentAnswear = answear;
	updateScore();
	++currentQuestion;
	generateNewQuestion();
	UpdateData(FALSE);
}

void CQuizDlg::onButtonAClicked()
{
	handleAnswear(Question::ANSWEAR::A);
}

void CQuizDlg::onButtonBClicked()
{
	handleAnswear(Question::ANSWEAR::B);
}

void CQuizDlg::onButtonCClicked()
{
	handleAnswear(Question::ANSWEAR::C);
}

void CQuizDlg::onButtonDClicked()
{
	handleAnswear(Question::ANSWEAR::D);
}

void CQuizDlg::onButtonNewQuizClicked()
{
	currentQuestion = 0;
	currentAnswear = Question::ANSWEAR::NONE;
	score = 0;
	updateScore();
	generateNewQuestion();
	UpdateData(FALSE);
}
