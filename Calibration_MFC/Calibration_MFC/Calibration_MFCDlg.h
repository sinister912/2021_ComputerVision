
// Calibration_MFCDlg.h: 헤더 파일
//

#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// CCalibrationMFCDlg 대화 상자
class CCalibrationMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalibrationMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALIBRATION_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Mat m_imgLoad, m_imgSave;
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonDist();
	void CCalibrationMFCDlg::UndistortImg(float k1, float k2, float k3, Mat& inImg, Mat& outImg, int width, int height);
	void CCalibrationMFCDlg::FillBitmapInfo(BITMAPINFO* bmi, int width, int height, int bpp, int origin);
	void CCalibrationMFCDlg::DisplayImage(CDC* pDC, CRect rect, Mat& srcimg);
	afx_msg void OnBnClickedButtonSave();
};
