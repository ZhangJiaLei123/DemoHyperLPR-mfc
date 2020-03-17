
// DemoHyperLPR-mfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DemoHyperLPR-mfc.h"
#include "DemoHyperLPR-mfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



using namespace std;
using namespace cv;
cv::Mat cut(cv::Mat srcImage, int x, int y, int w, int h);
cv::Mat Drawing(cv::Mat matImg, int x, int y, int w, int h);

void setDp(CImage &image, int dp) {

	//CImage image_new = image;

	int image_pitch = image.GetPitch();
	int image_height = image.GetHeight();
	int image_width = image.GetWidth();

	byte* pSourceData;
	pSourceData = (byte*)image.GetBits();
	int image_bpp = image.GetBPP();

	int r = 0, g = 0, b = 0, alpha = 0;
	int gray = 0;
	for (int i = 0; i < image_width / 2; i++) {
		for (int j = 0; j < image_height / 2; j++) {
			//if (image_bpp == 8) {
			//	gray = *(pSourceData + j * image_pitch + i);

			//	//进行灰度值设置
			//	*(pSourceData + j * image_pitch + i) = 125;
			//}
			if (image_bpp == 24)
			{
				r = *(pSourceData + j * image_pitch + i * 3 * 2);
				g = *(pSourceData + j * image_pitch + i * 3 + 1 * 2);
				b = *(pSourceData + j * image_pitch + i * 3 + 2 * 2);

				//进行RGB设置
				*(pSourceData + j * image_pitch + i * 3) = r;//R
				*(pSourceData + j * image_pitch + i * 3 + 1) = g;//G
				*(pSourceData + j * image_pitch + i * 3 + 2) = b;//B
			}
			if (image_bpp == 32) {
				b = *(pSourceData + j * image_pitch + i * 4 * dp);
				g = *(pSourceData + j * image_pitch + i * 4 * dp + 1);
				r = *(pSourceData + j * image_pitch + i * 4 * dp + 2);
				alpha = *(pSourceData + j * image_pitch + i * dp * 4 + 3);

				//进行RGB设置
				*(pSourceData + j * image_pitch + i * 4) = b;//B
				*(pSourceData + j * image_pitch + i * 4 + 1) = g;//G
				*(pSourceData + j * image_pitch + i * 4 + 2) = r;//R
				*(pSourceData + j * image_pitch + i * 4 + 3) = 0;
			}
		}
	}

}

float baseX = 13;
float baseY = 20;
float baseW = 463;
float baseH = 283;

int iDraX = 0;
int iDraY = 0;
int iDraW = 0;
int iDraH = 0;

/**
* 压缩分辨率
*/
cv::Mat setDp2(cv::Mat matImg, float miDp, int miImageW, int miImageH) {


	cv::Mat matImg_new;
	cv::Size outSize;

	outSize.width = matImg.cols * miDp;
	outSize.height = matImg.rows * miDp;
	resize(matImg, matImg_new, outSize, 0, 0, cv::INTER_AREA);

	return matImg_new;
}

/**
* 画出方框
*/
cv::Mat Drawing(cv::Mat matImg, int x, int y, int w, int h) {
	cv::Mat image_new;
	cv::rectangle(matImg, cv::Point(x, y), cv::Point(x + w, y + h), cv::Scalar(155, 155, 100), 4);
	return matImg;
}


/**
* mat 图像裁剪
*/
cv::Mat cut(cv::Mat srcImage, int x, int y, int w, int h)
{
	cv::Rect m_select;
	m_select = Rect(x, y, w, h);
	Mat ROI = srcImage(m_select);
	return ROI;

}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

														// 实现
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


// CDemoHyperLPRmfcDlg 对话框



CDemoHyperLPRmfcDlg::CDemoHyperLPRmfcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRJ_MFC2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoHyperLPRmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT_RES, tv_res);
	DDX_Control(pDX, IDC_PROGRESS1, progress_vedio);
	DDX_Control(pDX, IDC_IMAGE_VIEW, image_view);
	DDX_Control(pDX, IDC_TV_TIME_NOW, tv_time);
	DDX_Control(pDX, IDC_CHECK2, cb_is_think_car_id);
	DDX_Control(pDX, IDC_ET_LOG, et_log);
	DDX_Control(pDX, IDC_SLIDER_SPEED, sl_vedio_speed);
	DDX_Control(pDX, IDC_TV_SPEED, mtv_speed);
	DDX_Control(pDX, IDC_TV_TIME_ALL, mtv_time_all);
	//DDX_Control(pDX, IDC_SPIN_SPEED, msp_speed);
	DDX_Control(pDX, IDC_SLIDER_VIDEO__PROESS, msl_video_progress);
	DDX_Control(pDX, IDC_CHECK_IS_STOP_WHEN_GET_CAR, cb_is_stop_when_get_car);
	DDX_Control(pDX, IDC_CB_IS_PREVIEW_CAR, cb_is_preview_car);
	DDX_Control(pDX, IDC_IMAGE_VIEW__GET_CAR, miv_preview_car);
	DDX_Control(pDX, IDC_CHECK_IS_SAVE_CAR_IMAGE, mcb_is_save_car_image);
	DDX_Control(pDX, IDC_CHECK_IS_ADD_FILE_TIME, cb_is_add_filename_time);
	DDX_Control(pDX, IDC_TV_AVE_TIME_ALL, mtv_ave_time_all);
	DDX_Control(pDX, IDC_TV_AVE_TIME_CAR, mtv_ave_time_car);
	DDX_Control(pDX, IDC_CHECK_IS_THINK_VIDEO, cb_is_think_video);
	DDX_Control(pDX, IDC_EDIT_FILE_PATH_VIDEO, et_file_path_video);
	DDX_Control(pDX, IDC_EDIT_FILE_PATH_IMAGE, et_file_path_image);
	DDX_Control(pDX, IDC_SLIDER_SPEED_THINK, sl_think_speed);
	DDX_Control(pDX, IDC_TV_SPEED2, mtv_speed2);
	DDX_Control(pDX, IDC_SLIDER_REAL, sl_real);
	DDX_Control(pDX, IDC_TV_SPEED3, tv_real);
	DDX_Control(pDX, IDC_SLIDER_DP, sl_dp);
	DDX_Control(pDX, IDC_STATIC_DP, tv_dp);
	DDX_Control(pDX, IDC_CHECK_LOOP, cb_loop);
	DDX_Control(pDX, IDC_STATIC_SIZT, tv_dp_size);
	DDX_Control(pDX, IDC_TV_POS, tv_speed_pos);
}

BEGIN_MESSAGE_MAP(CDemoHyperLPRmfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_START, &CDemoHyperLPRmfcDlg::OnBnClickedStart)
	ON_WM_TIMER()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CDemoHyperLPRmfcDlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_CHECK2, &CDemoHyperLPRmfcDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(ID_STOP, &CDemoHyperLPRmfcDlg::OnBnClickedStop)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_SPEED, &CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderSpeed)

	ON_BN_CLICKED(IDC_CHECK_IS_STOP_WHEN_GET_CAR, &CDemoHyperLPRmfcDlg::OnBnClickedCheckIsStopWhenGetCar)
	ON_BN_CLICKED(IDC_CHECK1, &CDemoHyperLPRmfcDlg::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_ET_LOG, &CDemoHyperLPRmfcDlg::OnEnChangeEtLog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_VIDEO__PROESS, &CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderVideo)
	ON_BN_CLICKED(IDC_BUTTON1, &CDemoHyperLPRmfcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_IMAGE_PATH_CHOOSE, &CDemoHyperLPRmfcDlg::OnBnClickedButtonImagePathChoose)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_SPEED_THINK, &CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderSpeedThink)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_REAL, &CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderReal)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_DP, &CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderDp)
	ON_BN_CLICKED(IDC_CHECK_LOOP, &CDemoHyperLPRmfcDlg::OnBnClickedCheckLoop)
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CDemoHyperLPRmfcDlg::OnNMThemeChangedScrollbar1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDemoHyperLPRmfcDlg 消息处理程序
BOOL CDemoHyperLPRmfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

									// TODO: 在此添加额外的初始化代码

									// 速度条
	sl_vedio_speed.SetRange(1, 10);//设置滑动范围为1到20
	sl_vedio_speed.SetTicFreq(1);//每1个单位画一刻度
	sl_vedio_speed.SetPos(1);//设置滑块初始位置为1 

	sl_think_speed.SetRange(1, 50);
	sl_think_speed.SetTicFreq(1);
	sl_think_speed.SetPos(1);

	msl_video_progress.SetRange(0, 100);
	sl_think_speed.SetTicFreq(10);
	msl_video_progress.SetPos(0);

	sl_real.SetRange(1, 99);
	sl_real.SetTicFreq(5);
	sl_real.SetPos(85);

	sl_dp.SetRange(1, 10);
	sl_dp.SetTicFreq(1);//每1个单位画一刻度
	sl_dp.SetPos(10);//设置滑块初始位置为1 


					 // 默认单选框
	cb_is_preview_car.SetCheck(true);
	cb_is_add_filename_time.SetCheck(true);

	// 默认路径
	et_file_path_video.SetWindowTextW(_T("E:/MyComputer/Desktop/test/demo.mp4"));
	et_file_path_image.SetWindowTextW(_T("E:/MyComputer/Desktop/test/demo3.jpg"));

	miImageW = 0;
	miImageH = 0;

	// 视频链表初始化
	tvideo_head.id = -1;
	tvideo_head.Mats = NULL;
	tvideo_head.last = NULL;
	tvideo_head.naxt = NULL;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDemoHyperLPRmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDemoHyperLPRmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDemoHyperLPRmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//定义模型文件
using namespace pr;
pr::PipelinePR prc("./model/cascade.xml",
	"./model/HorizonalFinemapping.prototxt", "./model/HorizonalFinemapping.caffemodel",
	"./model/Segmentation.prototxt", "./model/Segmentation.caffemodel",
	"./model/CharacterRecognization.prototxt", "./model/CharacterRecognization.caffemodel"
);
long progress_pos_old = 0;
// 用户点击开始识别按钮响应
void CDemoHyperLPRmfcDlg::OnBnClickedStart()
{
	//SetTimer(1,100,NULL);

	// 只识别图片
	if (!cb_is_think_video.GetCheck()) {
		addLog("单图片识别");
		mlThinkCount = 0; // 总识别次数置0
		mdAveTimeAll = 0;
		mlThinkCarCount = 0;
		mdAveTimeCar = 0;
		// "E:/MyComputer/Desktop/test/demo3.jpg"
		// CT2CA()
		CString path;
		et_file_path_image.GetWindowTextW(path);
		string strPath;
		strPath = CW2A(path.GetString());
		cv::Mat image = cv::imread(strPath);

		thinkCarId2(image);

		return;
	}

	// 视频播放逻辑
	if (!isStat) { //  未开始
		addLog("正在读取");
		mlThinkCount = 0; // 总识别次数置0
		mdAveTimeAll = 0;
		mlThinkCarCount = 0;
		mdAveTimeCar = 0;
		openVideoCapture(0);
		isStat = true;
	}

	if (isEnd) { // 播放完毕
				 // 重新读取视频

		addLog("重新播放");
		mlThinkCount = 0; // 总识别次数置0
		mdAveTimeAll = 0;
		mlThinkCarCount = 0;
		mdAveTimeCar = 0;
		openVideoCapture(0);
		isEnd = false;

	}

	if (isStop) { // 继续播放
		addLog("继续播放");
		isStop = false;
		SetTimer(2, (unsigned int)(1000 * 1.0 / mfps) / 4, NULL);//按视频帧
	}

}

// 从指定帧打开视频流
int CDemoHyperLPRmfcDlg::openVideoCapture(long bit) {

	if (capture.isOpened()) {
		progress_pos = bit;
		msl_video_progress.SetRange(0, mTotalFrame);
		msl_video_progress.SetPos(progress_pos);
		capture_now = capture;
		capture_now.set(CV_CAP_PROP_POS_FRAMES, bit); // 从第bit帧开始
		return mTotalFrame;
	}

	try
	{
		CString path;
		et_file_path_video.GetWindowTextW(path);
		string strPath;
		strPath = CW2A(path.GetString());
		capture.open(strPath);
	}
	catch (const cv::Exception& ex)
	{
		MessageBox(_T("错误"), _T("没有找到文件"));
		return 0;
	}
	if (!capture.isOpened()) {
		addLog(_T("打开视频文件失败"));
		return 0;
	}

	mfps = capture.get(CV_CAP_PROP_FPS); // 帧率
	mTotalFrame = capture.get(CV_CAP_PROP_FRAME_COUNT); // 总帧数

	capture_now = capture;
	capture_now.set(CV_CAP_PROP_POS_FRAMES, bit); // 从第bit帧开始

	progress_pos = bit;
	is_progress_falg = true;
	progress_vedio.SetRange32(0, mTotalFrame);

	msl_video_progress.SetRange(0, mTotalFrame);
	msl_video_progress.SetPos(progress_pos);

	CString str;
	str = toCstring((unsigned int)(1000 * 1.0 / capture.get(CV_CAP_PROP_FPS)));
	CString str2;
	str2 = toCstring(mTotalFrame);


	miImageH = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	miImageW = capture.get(CV_CAP_PROP_FRAME_WIDTH);

	addLog(_T("帧率:") + str + _T("总帧数:") + str2 + _T("宽:") + toCstring(miImageW) + _T("高:") + toCstring(miImageH));
	tv_dp_size.SetWindowTextW(toCstring((int)(miImageW * miDp)) + _T("x") + toCstring((int)(miImageH * miDp)));
	SetTimer(2, (unsigned int)(1000 * 1.0 / mfps) / 1, NULL);//按视频帧

	int time_s = mTotalFrame / mfps; // 秒
	int time_m = time_s / 60; // 分钟
	time_s = time_s % 60; // 秒

	CString timeStrM = toCstring(time_m);
	CString timeStrS = toCstring(time_s);
	CString timeStr = _T("/") + timeStrM + _T(":") + timeStrS;
	mtv_time_all.SetWindowTextW(timeStr);

	return mTotalFrame;
}

// 定时器
void CDemoHyperLPRmfcDlg::OnTimer(UINT_PTR nIDEvent)
{
	cv::Mat matImg;
	cv::Mat matImg_new;
	CImage image;
	cv::Rect region;

	switch (nIDEvent) {
	case 1:
		break;
	case 2:
		capture_now >> matImg;//取出一帧图像

		if (!matImg.empty())
			//if(tvideo_now->naxt != NULL)
		{
			//matImg = tvideo_now->Mats;
			//tvideo_now = tvideo_now->naxt;
			//if (matImg.empty())
			//{
			//	addLog("播放出错");
			//	CDialogEx::OnTimer(nIDEvent);
			//	return;
			//}

			matImg_new = setDp2(matImg, miDp, miImageW, miImageH);
			///	matImg = ImageCropPadding(matImg_new, rect);

			progress_vedio.SetPos(progress_pos);
			msl_video_progress.SetPos(progress_pos);
			tv_speed_pos.SetWindowTextW(toCstring(progress_pos));

			int time_s = progress_pos / mfps; // 秒
			int time_m = time_s / 60; // 分钟
			time_s = time_s % 60; // 秒

			CString timeStrM = toCstring(time_m);
			CString timeStrS = toCstring(time_s);
			CString timeStr = timeStrM + _T(":") + timeStrS;
			tv_time.SetWindowTextW(timeStr);

			progress_pos++;

			// 按频率识别
			if (cb_is_think_car_id.GetCheck() && (progress_pos % miSpeedThink) == 0) {
				CImage image_pre;	// 预览缓存
				CString res = thinkCarId(matImg_new, image_pre);         // 识别
																		 // 识别到车牌
				if (res.GetLength() >= 20) {
					// 判断是否需要暂停
					if (cb_is_stop_when_get_car.GetCheck()) {
						soptPlayr();
						isStop = true;
					}
					addLog(res);
					// 是否预览结果
					if (cb_is_preview_car.GetCheck()) {
						//image_pre = showPreview(&matImg, image_pre);
						// 显示描绘车牌的图像图像
						showVideo(&matImg_new, image_pre);
					}
					else {
						showVideo(&matImg_new, image); // 显示图像
					}

					if (mlThinkCarCount > 0) {
						double aveTime2 = mdAveTimeCar / mlThinkCarCount;
						mtv_ave_time_car.SetWindowTextW(toCstring(aveTime2));
					}
				}
				else {
					showVideo(&matImg_new, image); // 显示图像
				}


				if (mlThinkCount > 0) {
					double aveTime1 = mdAveTimeAll / mlThinkCount;
					mtv_ave_time_all.SetWindowTextW(toCstring(aveTime1));
				}

			}
			else {
				showVideo(&matImg_new, image); // 显示图像
			}

		}
		else { // 播放完毕
			KillTimer(2);
			isEnd = true;
			addLog("播放完毕");

			// 循环播放
			if (isLoopVideo) {
				addLog("重新播放");
				mlThinkCount = 0; // 总识别次数置0
				mdAveTimeAll = 0;
				mlThinkCarCount = 0;
				mdAveTimeCar = 0;
				openVideoCapture(0);
				isEnd = false;
			}
		}
		break;

	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


// 暂停播放
void CDemoHyperLPRmfcDlg::soptPlayr() {
	KillTimer(2);
	//	addLog("播放暂停");
}

// 播放视频,返回当前帧视频
void CDemoHyperLPRmfcDlg::showVideo(cv::Mat *matImg, CImage &image) {
	if (matImg->empty())
	{
		KillTimer(2);
		addLog(_T("视频结束"));
		isEnd = true;
	}
	else
	{
		// 图片转换
		if (Mat2CImage(matImg, image)) {
			CWnd *pWnd = NULL;
			pWnd = GetDlgItem(IDC_IMAGE_VIEW);//获取控件句柄  
			showImage(image, pWnd);
		}
		else {
			addLog(_T("预览出错，空图片"));
		}
	}
	return;
}
// 播放视频,返回当前帧视频
void CDemoHyperLPRmfcDlg::showVideo2(cv::Mat *matImg, CImage &image) {
	CWnd *pWnd = NULL;
	pWnd = GetDlgItem(IDC_IMAGE_VIEW);//获取控件句柄  
	showImage(image, pWnd);
	return;
}

//! 显示预览
CImage CDemoHyperLPRmfcDlg::showPreview(cv::Mat *matImg, CImage &image) {
	if (matImg->empty())
	{
		addLog(_T("预览为空"));
	}
	else
	{
		// 图片转换
		if (Mat2CImage(matImg, image)) {
			CWnd *pWnd = NULL;
			pWnd = GetDlgItem(IDC_IMAGE_VIEW__GET_CAR);//获取控件句柄  
			showImage(image, pWnd);
		}
		else {
			addLog(_T("空图片"));
		}
	}
	return image;
}

// Mat转换Image
bool CDemoHyperLPRmfcDlg::Mat2CImage(cv::Mat *mat, CImage &img) {
	if (!mat || mat->empty())
		return -1;
	int nBPP = mat->channels() * 8;
	if (!img.Create(mat->cols, mat->rows, nBPP)) {
		return false;
	}
	if (nBPP == 8)
	{
		static RGBQUAD pRGB[256];
		for (int i = 0; i < 256; i++)
			pRGB[i].rgbBlue = pRGB[i].rgbGreen = pRGB[i].rgbRed = i;
		img.SetColorTable(0, 256, pRGB);
	}
	uchar* psrc = mat->data;
	uchar* pdst = (uchar*)img.GetBits();
	int imgPitch = img.GetPitch();
	for (int y = 0; y < mat->rows; y++)
	{
		memcpy(pdst, psrc, mat->cols*mat->channels());//mat->step is incorrect for those images created by roi (sub-images!)
		psrc += mat->step;
		pdst += imgPitch;
	}

	return true;
}


// 显示图片
bool CDemoHyperLPRmfcDlg::showImage(CImage image1, CWnd *pWnd)
{
	CRect rt;
	GetClientRect(&rt);
	CRect rectRes;
	//获取Picture Control控件的大小
	CDC *pDc = NULL;
	pWnd->GetClientRect(&rt);//获取句柄指向控件区域的大小  
	pDc = pWnd->GetDC();//获取picture的DC  
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	//if (image1.GetWidth() <= rt.Width() && image1.GetHeight() <= rt.Height()) //图片小于控件区域，不缩放
	//{
	//	rectRes = CRect(rt.TopLeft(), CSize(image1.GetWidth() , image1.GetHeight() ));
	//	image1.StretchBlt(pDc->m_hDC, rectRes, SRCCOPY); //将图片画到Picture控件表示的矩形区域 
	//}
	//else
	{
		float xScale = (float)rt.Width() / (float)image1.GetWidth();
		float yScale = (float)rt.Height() / (float)image1.GetHeight();
		float ScaleIndex = xScale;

		rectRes = CRect(rt.TopLeft(), CSize((int)image1.GetWidth()*ScaleIndex, (int)image1.GetHeight()*ScaleIndex));
		image1.StretchBlt(pDc->m_hDC, rectRes, SRCCOPY); //将图片画到Picture控件表示的矩形区域
		pWnd->SetWindowPos(NULL, 0, 0,
			(int)image1.GetWidth()*ScaleIndex, (int)image1.GetHeight()*ScaleIndex,
			SWP_NOZORDER | SWP_NOMOVE);
	}
	image1.Draw(pDc->m_hDC, rectRes);//将图片绘制到picture表示的区域内  

	return true;
}


//
//// [过时]保存Rect图片
//void writeCvRectToFile(cv::Rect &rect, const char *filename) {
//	CvFileStorage *fs = cvOpenFileStorage(filename, 0, CV_STORAGE_WRITE);
//	if (!fs) {
//		fprintf(stderr, "Could not open file ..\n");
//		return;
//	}
//	cvStartWriteStruct(fs, "rect", CV_NODE_SEQ | CV_NODE_FLOW);
//	cvWriteInt(fs, 0, rect.x);
//	cvWriteInt(fs, 0, rect.y);
//	cvWriteInt(fs, 0, rect.width);
//	cvWriteInt(fs, 0, rect.height);
//	cvEndWriteStruct(fs);
//	cvReleaseFileStorage(&fs);
//}

// 识别图片
CString CDemoHyperLPRmfcDlg::thinkCarId(cv::Mat image, CImage &image_preview) {
	// 识别次数+1
	mlThinkCount++;
	//使用端到端模型模型进行识别 识别结果将会保存在res里面
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时

										 // 只识别指定区域
										 //image = cut(image,200,200,300,300);

	if (iDraX > 0 && iDraY > 0 && iDraW > 0 && iDraH > 0) {
		float _bl_x = baseW / (miImageW * 1.0);
		float _bl_y = baseH / (miImageH * 1.0);

		image = Drawing(image, iDraX / _bl_x * miDp, iDraY / _bl_y * miDp
			, iDraW / _bl_x * miDp, iDraH / _bl_y * miDp);

		image = cut(image, iDraX / _bl_x * miDp, iDraY / _bl_y * miDp
			, iDraW / _bl_x * miDp, iDraH / _bl_y * miDp);
	}

	std::vector<pr::PlateInfo> res = prc.RunPiplineAsImage(image);

	QueryPerformanceCounter(&nEndTime);//停止计时

	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s
	mdAveTimeAll += time;

	addRes(_T("耗时:") + toCstring(time)); // 显示结果

	string resStr = "识别结果:";
	bool isAdd = false;
	for (auto st : res) {
		cv::Mat image_p = image;
		double dRealValue = miRealValue / 100.0;
		if (st.confidence > dRealValue) {



			//输出识别结果 、识别置信度
			resStr += st.getPlateName() + " -- 可信度:";
			resStr += to_string(st.confidence);
			//		addRes(resStr);

			cv::Rect region = st.getPlateRect();
			//画出车牌位置
			cv::rectangle(image_p, cv::Point(region.x + 1, region.y + 1), cv::Point(region.x + region.width - 1, region.y + region.height - 1), cv::Scalar(255, 255, 0), 1);
			//写上车牌
			cv::putText(image_p, st.getPlateName(), cv::Point(region.x - 1, region.y - 1), CV_FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(0, 0, 255), 1, 8, false);

			// 是否预览结果
			if (cb_is_preview_car.GetCheck()) {
				//image_pre = showPreview(&matImg, image_pre);
				// 显示描绘车牌的图像图像
				CImage image_pre;
				showPreview(&image_p, image_pre);
			}

			// 仅首次保存
			if (!isAdd) {
				// 是否保存到本地
				if (mcb_is_save_car_image.GetCheck()) {
					// 保存路径为 基础路径+车牌 + 可信度
					string filePath = "E:/MyComputer/Desktop/test/res/"
						+ st.getPlateName() + "_可信度"
						+ to_string(st.confidence) + "_耗时"
						+ to_string(time);
					// + 时间
					if (cb_is_add_filename_time.GetCheck()) {
						filePath += (double)nFreq.QuadPart;
					}
					// 加后缀
					filePath += ".jpg";
					//writeCvRectToFile(region, filePath.c_str());
					imwrite(filePath, image_p);
				}
			}


			// 仅记录一次
			if (!isAdd) {
				mlThinkCarCount++;
				mdAveTimeCar += time;
				isAdd = true;
			}
		}

	}

	string timeStr;
	timeStr = to_string(time);
	resStr += "耗时" + timeStr;

	CString strMfc;
	strMfc = resStr.c_str();
	//tv_res.SetWindowTextW(strMfc);

	return strMfc;
}
// 单图片识别
CString CDemoHyperLPRmfcDlg::thinkCarId2(cv::Mat image) {
	CImage image_pre;	// 预览缓存
	CString res = thinkCarId(image, image_pre);         // 识别

														// 识别到车牌
	if (res.GetLength() >= 20) {
		// 判断是否需要暂停
		if (cb_is_stop_when_get_car.GetCheck()) {
			soptPlayr();
			isStop = true;
		}
		addLog(res);
		// 显示描绘车牌的图像图像
		showVideo(&image, image_pre);
	}
	else {
		showVideo(&image, image_pre); // 显示图像
	}

	if (mlThinkCount > 0) {
		double aveTime1 = mdAveTimeAll / mlThinkCount;
		mtv_ave_time_all.SetWindowTextW(toCstring(aveTime1));
	}
	if (mlThinkCarCount > 0) {
		double aveTime2 = mdAveTimeCar / mlThinkCarCount;
		mtv_ave_time_car.SetWindowTextW(toCstring(aveTime2));
	}
	CString info;
	int xScale = image_pre.GetWidth();
	int yScale = image_pre.GetHeight();
	info = _T("宽:") + toCstring(xScale) + _T(" 高:") + toCstring(yScale);
	addLog(_T("图片信息：[") + info + _T("]"));
	return res;
}


// 添加日志
void CDemoHyperLPRmfcDlg::addLog(string msg) {
	if (sizeof(msg) > 0) {
		CString _msg;
		_msg = msg.c_str();
		addLog(_msg);
	}

}
// 添加日志
void CDemoHyperLPRmfcDlg::addLog(CString msg) {
	if (sizeof(msg) > 0) {
		CString cstr;
		et_log.GetWindowTextW(cstr);
		et_log.SetWindowTextW(cstr + "\r\n" + msg);
		int nLenth = et_log.GetWindowTextLength();
		et_log.SetSel(nLenth, nLenth, FALSE);
		et_log.SetFocus();
	}

}

// 添加识别结果日志
void CDemoHyperLPRmfcDlg::addRes(string msg) {
	if (sizeof(msg) > 0) {
		CString _msg;
		_msg = msg.c_str();
		addLog(_msg);
	}

}
// 添加识别结果日志
void CDemoHyperLPRmfcDlg::addRes(CString msg) {
	if (sizeof(msg) > 0) {
		tv_res.SetWindowTextW(msg);
	}

}



CString CDemoHyperLPRmfcDlg::toCstring(double number) {
	string sid = to_string(number);
	CString str;
	str = sid.c_str();

	return str;
}
CString CDemoHyperLPRmfcDlg::toCstring(unsigned int number) {
	string sid = to_string(number);
	CString str;
	str = sid.c_str();

	return str;
}
CString CDemoHyperLPRmfcDlg::toCstring(long number) {
	string sid = to_string(number);
	CString str;
	str = sid.c_str();

	return str;
}
CString CDemoHyperLPRmfcDlg::toCstring(int number) {
	string sid = to_string(number);
	CString str;
	str = sid.c_str();

	return str;
}


void CDemoHyperLPRmfcDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CDemoHyperLPRmfcDlg::OnBnClickedCheck2()
{
	if (cb_is_think_car_id.GetCheck()) {
		addLog("开启车牌识别");
	}
	else {
		addLog("关闭车牌识别");
	}

	// TODO: 在此添加控件通知处理程序代码
}

// 点击暂停识别响应
void CDemoHyperLPRmfcDlg::OnBnClickedStop()
{
	KillTimer(2);
	addLog("暂停播放");
	isStop = true;
}

int _miSpeed_old = 1;
// 播放速度条
void CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderSpeed(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	miSpeed = sl_vedio_speed.GetPos();
	if (_miSpeed_old == miSpeed) { // 速度未改变时，不做更新
		return;
	}
	_miSpeed_old = miSpeed;
	CString spStr;
	spStr = toCstring(miSpeed);
	//addLog(_T("更改播放速度:") + spStr);
	mtv_speed.SetWindowTextW(_T("x") + spStr);
	KillTimer(2);
	SetTimer(2, (unsigned int)(1000 * 1.0 / mfps) / miSpeed, NULL);//按视频帧
}


void CDemoHyperLPRmfcDlg::OnBnClickedCheckIsStopWhenGetCar()
{
	if (cb_is_stop_when_get_car.GetCheck()) {
		addLog(_T("开启识别到车牌暂停"));
	}
	else {
		addLog(_T("关闭识别到车牌暂停"));
	}
}


void CDemoHyperLPRmfcDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDemoHyperLPRmfcDlg::OnEnChangeEtLog()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

// 视频进度条控制响应
void CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderVideo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;


	// 用户选择的进度
	int speed = msl_video_progress.GetPos();
	// 过滤系统误差
	if (abs(progress_pos_old - speed) < 10) {
		progress_pos_old = speed;
		return;
	}
	progress_pos_old = speed;

	// 点击后暂停播放
	soptPlayr();

	tv_speed_pos.SetWindowTextW(toCstring(speed));
	// 当前进度大于选择的进度
	if (progress_pos < speed) {
		speed = speed - progress_pos;
		progress_pos = progress_pos + speed;
		for (int i = 0; i < speed; i++) {
			Mat matImg;
			capture_now >> matImg;
			//if (tvideo_now->naxt == NULL) {
			//	break;
			//}
			//tvideo_now = tvideo_now->naxt;
		}
		SetTimer(2, (unsigned int)(1000 * 1.0 / mfps) / 1, NULL);//按视频帧
	}
	else {
		//speed =  progress_pos - speed;
		//progress_pos = progress_pos - speed;
		//for (int i = 0; i < speed; i++) {
		//	if (tvideo_now->last == NULL) {
		//		break;
		//	}
		//	tvideo_now = tvideo_now->last;
		//}
		progress_pos = speed;
		openVideoCapture(speed);
		SetTimer(2, (unsigned int)(1000 * 1.0 / mfps) / 1, NULL);//按视频帧
	}

}

// 视频路径选择
void CDemoHyperLPRmfcDlg::OnBnClickedButton1()
{
	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.mp4)|*.mp4|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		mcsFilePathVideo = dlgFile.GetPathName();
		et_file_path_video.SetWindowTextW(mcsFilePathVideo);
	}
}

// 图片路径选择
void CDemoHyperLPRmfcDlg::OnBnClickedButtonImagePathChoose()
{

	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		mcsFilePathImage = dlgFile.GetPathName();
		et_file_path_image.SetWindowTextW(mcsFilePathImage);

	}
}


int _sl_think_speed_old = 1;
// 识别频率
void CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderSpeedThink(NMHDR *pNMHDR, LRESULT *pResult)
{
	miSpeedThink = sl_think_speed.GetPos();
	if (_sl_think_speed_old == miSpeedThink) { // 速度未改变时，不做更新
		return;
	}
	_sl_think_speed_old = miSpeedThink;
	CString spStr;
	spStr = toCstring(miSpeedThink);
	//addLog(_T("更改播放速度:") + spStr);
	mtv_speed2.SetWindowTextW(_T("x") + spStr);

}

int _sl_miRealValue_old = 90;
// 可信度调节
void CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderReal(NMHDR *pNMHDR, LRESULT *pResult)
{
	miRealValue = sl_real.GetPos();
	if (_sl_miRealValue_old == miRealValue) { // 速度未改变时，不做更新
		return;
	}
	_sl_miRealValue_old = miRealValue;
	CString spStr;
	spStr = toCstring(miRealValue);
	//addLog(_T("更改播放速度:") + spStr);
	tv_real.SetWindowTextW(_T("x") + spStr);
}


float _miDp_old = 0;
//! 分辨率调节
void CDemoHyperLPRmfcDlg::OnNMCustomdrawSliderDp(NMHDR *pNMHDR, LRESULT *pResult)
{
	miDp = sl_dp.GetPos() / 10.0;
	if (miDp == _miDp_old) { // 速度未改变时，不做更新
		return;
	}
	_miDp_old = miDp;
	CString spStr;
	spStr = toCstring(miDp);
	tv_dp.SetWindowTextW(_T("x") + spStr);

	if (miImageW > 0) {
		tv_dp_size.SetWindowTextW(toCstring((int)(miImageW * miDp)) + _T("x") + toCstring((int)(miImageH * miDp)));
	}
}

// 循环选择
void CDemoHyperLPRmfcDlg::OnBnClickedCheckLoop()
{
	// TODO: 在此添加控件通知处理程序代码
	isLoopVideo = cb_loop.GetCheck();
}



short iMoveCount = 0;
void CDemoHyperLPRmfcDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;

	if (baseX > point.x || point.x > baseX + baseW)
	{
		CDialogEx::OnLButtonDown(nFlags, point);
		return;
	}
	if (baseY > point.y || point.y > baseY + baseH)
	{
		CDialogEx::OnLButtonDown(nFlags, point);
		return;
	}

	switch (iMoveCount)
	{
	case 0:
		iDraX = point.x;
		iDraY = point.y;
		iMoveCount = 1;
		break;
	case 1:
		iDraW = point.x - iDraX;
		iDraH = point.y - iDraY;
		iMoveCount = 2;
		break;
	case 2:
		iDraX = 0;
		iDraY = 0;
		iDraW = 0;
		iDraH = 0;
		iMoveCount = 0;
		break;
	default:
		iMoveCount = 0;
		break;
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDemoHyperLPRmfcDlg::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CDemoHyperLPRmfcDlg::freeVideo() {

	if (tvideo_head.naxt == NULL) {
		return;
	}

	t_VIDEO *p = &tvideo_head;

	// 释放
	while (p->naxt != NULL) {
		p = p->naxt;
		free(p->last);
	}
}

/**
* 窗口关闭
*/
void CDemoHyperLPRmfcDlg::OnClose()
{

	// 释放
	freeVideo();

	CDialogEx::OnClose();
}
