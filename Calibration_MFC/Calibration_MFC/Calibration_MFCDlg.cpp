
// Calibration_MFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calibration_MFC.h"
#include "Calibration_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CCalibrationMFCDlg 대화 상자



CCalibrationMFCDlg::CCalibrationMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALIBRATION_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalibrationMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalibrationMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CCalibrationMFCDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_DIST, &CCalibrationMFCDlg::OnBnClickedButtonDist)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CCalibrationMFCDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CALIB, &CCalibrationMFCDlg::OnBnClickedButtonCalib)
	ON_BN_CLICKED(IDC_BUTTON_UNDIST, &CCalibrationMFCDlg::OnBnClickedButtonUndist)
END_MESSAGE_MAP()


// CCalibrationMFCDlg 메시지 처리기

BOOL CCalibrationMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalibrationMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalibrationMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalibrationMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalibrationMFCDlg::OnBnClickedButtonLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str = _T("All files(*.*)|*.*|"); // 모든 파일 표시
	// _T("Excel 파일 (*.xls, *.xlsx) |*.xls; *.xlsx|"); 와 같이 확장자를 제한하여 표시할 수 있음
	CFileDialog dlg(TRUE, _T("*.dat"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, str, this);
	CString strC;
	if (dlg.DoModal() == IDOK)
	{
		strC = dlg.GetPathName();
		if (strC.GetBuffer() == NULL)
			return;
		CStringA strA(strC);
		m_strPath = strA;
		Mat mat;
		m_imgLoad = imread((string)strA);

		cout << strA << endl;
		if (m_imgLoad.data == NULL)
		{
			cout << "no data!!" << endl;
			CV_Assert(m_imgLoad.data);
		}		
		cvtColor(m_imgLoad, m_imgLoad, COLOR_BGR2GRAY);
		m_imgLoad.convertTo(m_imgLoad, CV_8UC1);
		CRect rect;
		GetDlgItem(IDC_PIC_LEFT)->GetClientRect(&rect);
		CDC* pDC;
		pDC = GetDlgItem(IDC_PIC_LEFT)->GetDC();
		DisplayImage(pDC, rect, m_imgLoad);
		cout << "불러온 이미지 데이터" << endl
			<< "cols: " << m_imgLoad.cols << endl
			<< "rows: " << m_imgLoad.rows << endl
			<< "type: " << m_imgLoad.type() << endl;
	}


}

void CCalibrationMFCDlg::OnBnClickedButtonDist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Mat outimg(m_imgLoad.rows, m_imgLoad.cols, CV_8UC1, Scalar(0));
	CString sK0, sK1, sK2, sK3;
	float fK0, fK1, fK2, fK3;
	GetDlgItemText(IDC_EDIT_K0, sK0);
	GetDlgItemText(IDC_EDIT_K1, sK1);
	GetDlgItemText(IDC_EDIT_K2, sK2);
	GetDlgItemText(IDC_EDIT_K3, sK3);
	CStringA aK0(sK0), aK1(sK1), aK2(sK2), aK3(sK3);
	fK0 = (float)atof(aK0);
	fK1 = (float)atof(aK1);
	fK2 = (float)atof(aK2);
	fK3 = (float)atof(aK3);
	DistortImg(fK0, fK1, fK2, fK3, m_imgLoad, outimg, m_imgLoad.cols, m_imgLoad.rows);

	//Mat img;
	//resize(outimg, img, Size(800, 800), 0, 0, INTER_CUBIC);
	//imshow("img", img);
	CRect rect;
	GetDlgItem(IDC_PIC_RIGHT)->GetClientRect(&rect);
	CDC* pDC;
	pDC = GetDlgItem(IDC_PIC_RIGHT)->GetDC();
	DisplayImage(pDC, rect, outimg);
	m_imgSave = outimg;
}

void CCalibrationMFCDlg::UndistortImg(float k0, float k1, float k2, float k3, Mat& inImg, Mat& outImg, int width, int height)
{
	int xc = width / 2, yc = height / 2; // 중심좌표
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			// ------------------------------------------------------------
			// k1,k2,k3 적용하여 radial distortion을 구현한다.
			float r = sqrt((float)(y - yc)*(y - yc) / (2 * yc*yc) + (float)(x - xc)*(x - xc) / (2 * xc*xc));
			float dist = (k0 + k1 * r + k2 * r*r + k3 * r*r*r);
			float f_yu = (y - yc) * dist + yc; // 보정된 좌표 yu
			float f_xu = (x - xc) * dist + xc; // 보정된 좌표 xu

			// ------------------------------------------------------------
			// 양선형 보간법:  변환된 값을 구한다.
			int i_yu = (int)floor(f_yu); //예: floor(2.8)=2.0
			int i_xu = (int)floor(f_xu);
			float dy = f_yu - i_yu; // beta value
			float dx = f_xu - i_xu; // alpha value

			//원이미지의 범위를 벗어나는 경우 0값 할당 
			if (i_yu<0 || i_yu>height - 1 || i_xu<0 || i_xu>width - 1) {
				outImg.data[y*width + x] = 0;
			}
			//원 이미지의 범위 내에 존재할 경우 양선형 보간 수행 
			else {
				float I1, I2, I3, I4;
				BYTE newValue;
				I1 = (float)inImg.data[i_yu*width + i_xu]; // (x, y)
				I2 = (float)inImg.data[i_yu*width + (i_xu + 1)]; // (x, y+1)
				I3 = (float)inImg.data[(i_yu + 1)*width + i_xu]; // (x+1, y)
				I4 = (float)inImg.data[(i_yu + 1)*width + (i_xu + 1)]; // (x+1, y+1)
				//양선형 보간을 통한 새로운 밝기값 계산
				newValue = (BYTE)(I1*(1 - dx)*(1 - dy) + I2 * dx*(1 - dy) + I3 * (1 - dx)*dy + I4 * dx*dy);
				outImg.data[y*width + x] = newValue;
			}
		}
}

void CCalibrationMFCDlg::DistortImg(float k0, float k1, float k2, float k3, Mat& inImg, Mat& outImg, int width, int height)
{
	int xc = width / 2, yc = height / 2; // 중심좌표
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			// ------------------------------------------------------------
			// k1,k2,k3 적용하여 radial distortion을 구현한다.
			float r = sqrt((float)(y - yc)*(y - yc) / (2 * yc*yc) + (float)(x - xc)*(x - xc) / (2 * xc*xc));
			float dist = (k0 + k1 * r*r + k2 * r*r*r*r + k3 * r*r*r*r*r*r);
			float f_yu = (y - yc) * dist + yc; // 보정된 좌표 yu
			float f_xu = (x - xc) * dist + xc; // 보정된 좌표 xu

			// ------------------------------------------------------------
			// 양선형 보간법:  변환된 값을 구한다.
			int i_yu = (int)floor(f_yu); //예: floor(2.8)=2.0
			int i_xu = (int)floor(f_xu);
			float dy = f_yu - i_yu; // beta value
			float dx = f_xu - i_xu; // alpha value

			//원이미지의 범위를 벗어나는 경우 0값 할당 
			if (i_yu<0 || i_yu>height - 1 || i_xu<0 || i_xu>width - 1) {
				outImg.data[y*width + x] = 128;
				//cout << 1 << endl;
			}
			//원 이미지의 범위 내에 존재할 경우 양선형 보간 수행 
			else {
				//cout << 0 << endl;
				float I1, I2, I3, I4;
				BYTE newValue;
				I1 = (float)inImg.data[i_yu*width + i_xu]; // (x, y)
				I2 = (float)inImg.data[i_yu*width + (i_xu + 1)]; // (x, y+1)
				I3 = (float)inImg.data[(i_yu + 1)*width + i_xu]; // (x+1, y)
				I4 = (float)inImg.data[(i_yu + 1)*width + (i_xu + 1)]; // (x+1, y+1)
				//양선형 보간을 통한 새로운 밝기값 계산
				newValue = (BYTE)(I1*(1 - dx)*(1 - dy) + I2 * dx*(1 - dy) + I3 * (1 - dx)*dy + I4 * dx*dy);
				outImg.data[y*width + x] = newValue;
			}
		}
}
void  CCalibrationMFCDlg::FillBitmapInfo(BITMAPINFO* bmi, int width, int height, int bpp, int origin)
{
	assert(bmi&&width >= 0 && height >= 0 && (bpp == 8 || bpp == 24 || bpp == 32));
	BITMAPINFOHEADER *bmih = &(bmi->bmiHeader);
	memset(bmih, 0, sizeof(*bmih));
	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = width;
	bmih->biHeight = origin ? abs(height) : -abs(height);
	bmih->biPlanes = 1;
	bmih->biBitCount = (unsigned short)bpp;
	bmih->biCompression = BI_RGB;
	if (bpp == 8) {
		RGBQUAD *palette = bmi->bmiColors;
		for (int i = 0; i < 256; i++) {
			palette[i].rgbBlue = palette[i].rgbGreen = palette[i].rgbRed = (BYTE)i;
			palette[i].rgbReserved = 0;
		}
	}
}

void CCalibrationMFCDlg::DisplayImage(CDC* pDC, CRect rect, Mat& srcimg)
{
	Mat img;
	int step = ((int)(rect.Width() / 4)) * 4; // 4byte 단위조정해야 영상이 기울어지지 않는다.
	resize(srcimg, img, Size(step, rect.Height()));
	uchar buffer[sizeof(BITMAPINFOHEADER) * 1024];
	BITMAPINFO* bmi = (BITMAPINFO*)buffer;
	int bmp_w = img.cols;
	int bmp_h = img.rows;
	int depth = img.depth();
	int channels = img.channels();
	int bpp = 8 * channels;
	FillBitmapInfo(bmi, bmp_w, bmp_h, bpp, 0);
	int from_x = MIN(0, bmp_w - 1);
	int from_y = MIN(0, bmp_h - 1);
	int sw = MAX(MIN(bmp_w - from_x, rect.Width()), 0);
	int sh = MAX(MIN(bmp_h - from_y, rect.Height()), 0);
	SetDIBitsToDevice(pDC->m_hDC, rect.left, rect.top, sw, sh, from_x, from_y, 0, sh, img.data + from_y * img.step, bmi, 0);
	img.release();
}

void CCalibrationMFCDlg::OnBnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_imgSave.data == NULL) {
		AfxMessageBox(_T("no data!"), MB_OK);
		return;
	}
	CStringA strPath = m_strPath;
	strPath.Insert(strPath.GetLength() - 4, "1");
	cout << (string)strPath << endl;
	imwrite((string)strPath, m_imgSave);
}


void CCalibrationMFCDlg::OnBnClickedButtonCalib()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str = _T("All files(*.*)|*.*|"); // 모든 파일 표시
// _T("Excel 파일 (*.xls, *.xlsx) |*.xls; *.xlsx|"); 와 같이 확장자를 제한하여 표시할 수 있음
	CFileDialog dlg(TRUE, _T("*.dat"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, str, this);
	CString strC;
	if (dlg.DoModal() == IDOK)
	{
		strC = dlg.GetPathName();
		CStringA strA(strC);

		m_strPath = strA;
		Mat mat;
		m_imgBoard = imread((string)strA, COLOR_BGR2GRAY);
		if (m_imgBoard.data == NULL)
		{
			cout << "no data!!" << endl;
			CV_Assert(m_imgBoard.data);
		}
		m_imgBoard.convertTo(m_imgBoard, CV_8U);
		CRect rect;
		GetDlgItem(IDC_PIC_RIGHT)->GetClientRect(&rect);
		CDC* pDC;
		pDC = GetDlgItem(IDC_PIC_RIGHT)->GetDC();
		DisplayImage(pDC, rect, m_imgBoard);
	}
	else
		return;
	//===중심점 찾기
	Mat th_imgD, th_imgB;
	threshold(m_imgLoad, th_imgD, 120, 255, THRESH_BINARY);
	threshold(m_imgBoard, th_imgB, 120, 255, THRESH_BINARY);
	//imshow("th_img", th_img);
	vector<vector<Point>> ptContoursD;
	vector<vector<Point>> ptContoursB;

	findContours(~th_imgD, ptContoursD, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	findContours(~th_imgB, ptContoursB, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	cvtColor(th_imgD, th_imgD, COLOR_GRAY2BGR);
	th_imgD.convertTo(th_imgD, CV_8UC3);
	cvtColor(th_imgB, th_imgB, COLOR_GRAY2BGR);
	th_imgB.convertTo(th_imgB, CV_8UC3);
	//cout << ptContours.size() << endl;

	vector<RotatedRect> rotRectArrD;
	vector<RotatedRect> rotRectArrB;
	for (int i = 0; i < (int)ptContoursD.size(); i++)
	{
		RotatedRect rot_rect = minAreaRect(ptContoursD[i]);
		if ((m_imgLoad.cols / 2 - 10) < rot_rect.center.x && rot_rect.center.x < (m_imgLoad.cols / 2 + 10) &&
			(m_imgLoad.rows / 2 - 10) < rot_rect.center.y && rot_rect.center.y < (m_imgLoad.rows / 2 + 10))
			continue;
		rotRectArrD.push_back(rot_rect);
	}cout << rotRectArrD.size() << endl;

	for (int i = 0; i < (int)ptContoursB.size(); i++)
	{
		RotatedRect rot_rect = minAreaRect(ptContoursB[i]);
		if ((m_imgBoard.cols / 2 - 10) < rot_rect.center.x && rot_rect.center.x < (m_imgBoard.cols / 2 + 10) &&
			(m_imgBoard.rows / 2 - 10) < rot_rect.center.y && rot_rect.center.y < (m_imgBoard.rows / 2 + 10))
			continue;
		rotRectArrB.push_back(rot_rect);
	}cout << rotRectArrB.size() << endl;

	int c = 0;
	for (int i = 0; i < (int)rotRectArrD.size(); i++)
	{
		c += (i * (255 / 64));
		circle(th_imgD, rotRectArrD[i].center, 2, Scalar(c, 0, 255 - i * (255 / 64)), 2);
	}
	c = 0;
	for (int i = 0; i < (int)rotRectArrB.size(); i++)
	{
		c += (i * (255 / 64));
		circle(th_imgB, rotRectArrB[i].center, 2, Scalar(c, 0, 255 - i * (255 / 64)), 2);
	}

	CRect rectD;
	GetDlgItem(IDC_PIC_LEFT)->GetClientRect(&rectD);
	CDC* pDCd;
	pDCd = GetDlgItem(IDC_PIC_LEFT)->GetDC();
	DisplayImage(pDCd, rectD, th_imgD);
	CRect rectB;
	GetDlgItem(IDC_PIC_RIGHT)->GetClientRect(&rectB);
	CDC* pDCb;
	pDCb = GetDlgItem(IDC_PIC_RIGHT)->GetDC();
	DisplayImage(pDCb, rectB, th_imgB);

	//==============
	//=============================
	double sumR6 = 0, sumR5 = 0, sumR4 = 0, sumR3 = 0, sumR2 = 0, sumR = 0;
	double sumR3L = 0, sumR2L = 0, sumRL = 0, sumL = 0;
	double sum = rotRectArrD.size();
	int xc = m_imgLoad.cols / 2;
	int yc = m_imgLoad.rows / 2;

	for (int i = 0; i < rotRectArrD.size(); i++)
	{
		float r = sqrt((float)(rotRectArrD[i].center.y - yc)*(rotRectArrD[i].center.y - yc) / (2 * yc*yc)
			+ (float)(rotRectArrD[i].center.x - xc)*(rotRectArrD[i].center.x - xc) / (2 * xc*xc));

		sumR6 += pow(r, 6);
		sumR5 += pow(r, 5);
		sumR4 += pow(r, 4);
		sumR3 += pow(r, 3);
		sumR2 += pow(r, 2);
		sumR += r;

		sumR3L += pow(r, 3)*((rotRectArrB[i].center.x - xc) / (rotRectArrD[i].center.x - xc));
		sumR2L += pow(r, 2)*((rotRectArrB[i].center.x - xc) / (rotRectArrD[i].center.x - xc));
		sumRL += r * ((rotRectArrB[i].center.x - xc) / (rotRectArrD[i].center.x - xc));
		sumL += ((rotRectArrB[i].center.x - xc) / (rotRectArrD[i].center.x - xc));
	}

	Mat A = (Mat_<float>(4, 4) <<
		sum, sumR, sumR2, sumR3,
		sumR, sumR2, sumR3, sumR4,
		sumR2, sumR3, sumR4, sumR5,
		sumR3, sumR4, sumR5, sumR6);

	Mat B = (Mat_<float>(4, 1) <<
		sumL,
		sumRL,
		sumR2L,
		sumR3L);

	// declare a vector for results
	Mat abc;
	// solve the linear system
	solve(A, B, abc); // (input Array, input Array, output Array)
	
//=============================
//=============================
	CString str0, str1, str2, str3;

	str0.Format(_T("%.2f"), abc.at<float>(0, 0));
	str1.Format(_T("%.2f"), abc.at<float>(1, 0));
	str2.Format(_T("%.2f"), abc.at<float>(2, 0));
	str3.Format(_T("%.2f"), abc.at<float>(3, 0));
	SetDlgItemText(IDC_EDIT_K0, str0);
	SetDlgItemText(IDC_EDIT_K1, str1);
	SetDlgItemText(IDC_EDIT_K2, str2);
	SetDlgItemText(IDC_EDIT_K3, str3);
	cout << abc << endl;
	cout <<"cols : "<<abc.cols << endl;
	cout <<"rows : "<<abc.rows << endl;
	cout <<"type : "<<abc.type() << endl;
}


void CCalibrationMFCDlg::OnBnClickedButtonUndist()
{
	Mat outimg(m_imgLoad.rows, m_imgLoad.cols, CV_8UC1, Scalar(0));
	CString sK0, sK1, sK2, sK3;
	float fK0, fK1, fK2, fK3;
	GetDlgItemText(IDC_EDIT_K0, sK0);
	GetDlgItemText(IDC_EDIT_K1, sK1);
	GetDlgItemText(IDC_EDIT_K2, sK2);
	GetDlgItemText(IDC_EDIT_K3, sK3);
	CStringA aK0(sK0), aK1(sK1), aK2(sK2), aK3(sK3);
	fK0 = (float)atof(aK0);
	fK1 = (float)atof(aK1);
	fK2 = (float)atof(aK2);
	fK3 = (float)atof(aK3);
	UndistortImg(fK0, fK1, fK2, fK3, m_imgLoad, outimg, m_imgLoad.cols, m_imgLoad.rows);
	CRect rect;
	GetDlgItem(IDC_PIC_RIGHT)->GetClientRect(&rect);
	CDC* pDC;
	pDC = GetDlgItem(IDC_PIC_RIGHT)->GetDC();
	DisplayImage(pDC, rect, outimg);
	m_imgSave = outimg;

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
