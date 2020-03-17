
// DemoHyperLPR-mfcDlg.h : 头文件
//

#pragma once

#include "Pipeline.h"
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include <math.h>
#include <time.h>
//#include "MovableButton.h"
using namespace std;

typedef struct T_VIDEO
{
	int id;
	cv::Mat Mats;
	struct T_VIDEO *last;
	struct T_VIDEO *naxt;
}t_VIDEO;

// CPrjMfc2Dlg 对话框
class CDemoHyperLPRmfcDlg : public CDialogEx
{
	// 构造
public:
	CDemoHyperLPRmfcDlg(CWnd* pParent = nullptr);	// 标准构造函数

											// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRJ_MFC2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


														// 实现
protected:
	HICON m_hIcon;

	//! 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	//! 图片路径
	CString mcsFilePathImage;
	//! 视频路径
	CString mcsFilePathVideo;
	//! 识别结果
	CStatic tv_res;
	//! 视频进度条
	CProgressCtrl progress_vedio;
	long progress_pos = 0;
	bool is_progress_falg = false;

	afx_msg void OnBnClickedStart();
	//! 图片视频
	CStatic image_view;
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	//! 视频容器
	cv::VideoCapture capture;
	//! 当前视频
	cv::VideoCapture capture_now;
	t_VIDEO tvideo_head;
	t_VIDEO *tvideo_now;
	int mfps = 1; //! 帧率
	long mTotalFrame; //! 总帧数
	int miImageW; //! 帧宽
	int miImageH; //! 帧高
	bool isStat = false;
	bool isStop = false;
	bool isEnd = false;
	// 打开视频流
	int openVideoCapture(long bit);
	int miSpeed;//! 播放速度
	int miSpeedThink;//! 识别速度
	int miRealValue;//! 可信度
	void soptPlayr();

	//! Mat转换Image
	bool Mat2CImage(cv::Mat *mat, CImage &img);
	//! 显示视频
	void showVideo(cv::Mat *matImg, CImage &image);
	void showVideo2(cv::Mat *matImg, CImage &image);
	//! 显示预览
	CImage showPreview(cv::Mat *matImg, CImage &image);
	//! 显示图片
	bool showImage(CImage image1, CWnd *pWnd);
	//! 识别图片
	CString thinkCarId(cv::Mat image, CImage &image_preview);
	//! 单图片识别
	CString thinkCarId2(cv::Mat image);
	//! 添加识别结果日志
	void addLog(string msg);
	void addLog(CString msg);
	void addRes(string msg);
	void addRes(CString msg);


	CString toCstring(double number);
	CString toCstring(unsigned int number);
	CString toCstring(long number);
	CString toCstring(int number);

	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);

	CButton cb_is_think_car_id;
	afx_msg void OnBnClickedCheck2();
	CEdit et_log;
	afx_msg void OnBnClickedStop();
	afx_msg void OnNMCustomdrawSliderSpeed(NMHDR *pNMHDR, LRESULT *pResult);
	//!  视频播放速度
	CSliderCtrl sl_vedio_speed;
	//!  速度显示
	CStatic mtv_speed;

	//!  总时间
	CStatic mtv_time_all;
	//! 当前时间
	CStatic tv_time;
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	//! 播放速度调节
	//CSpinButtonCtrl msp_speed;
	//! 视频播放进度条
	CSliderCtrl msl_video_progress;
	//! 识别到车牌暂停
	CButton cb_is_stop_when_get_car;
	afx_msg void OnBnClickedCheckIsStopWhenGetCar();
	afx_msg void OnBnClickedCheck1();
	//! 是否开启识别结果预览
	CButton cb_is_preview_car;
	//! 车牌识别结果预览
	CStatic miv_preview_car;
	afx_msg void OnEnChangeEtLog();
	//! 是否保存车牌图片到本地
	CButton mcb_is_save_car_image;
	//! 是否给文件名添加时间
	CButton cb_is_add_filename_time;
	//! 总帧的平均识别耗时
	CStatic mtv_ave_time_all;
	//! 车牌帧识别平均耗时
	CStatic mtv_ave_time_car;
	//! 单视频总识别次数
	long mlThinkCount;
	//! 单视频总识别耗时
	double mdAveTimeAll;
	//! 单视频总识别到车牌次数
	long mlThinkCarCount;
	//! 单视频识别到车牌总耗时
	double mdAveTimeCar;
	//! 识别逻辑
	afx_msg void OnNMCustomdrawSliderVideo(NMHDR *pNMHDR, LRESULT *pResult);
	//! 是否识别视频
	CButton cb_is_think_video;

	afx_msg void OnBnClickedButton1();
	//! 视频文件路径
	CEdit et_file_path_video;
	afx_msg void OnBnClickedButtonImagePathChoose();
	//! 图片路径选择
	CEdit et_file_path_image;
	//! 识别频率
	CSliderCtrl sl_think_speed;
	afx_msg void OnNMCustomdrawSliderSpeedThink(NMHDR *pNMHDR, LRESULT *pResult);
	//! 识别频率
	CStatic mtv_speed2;
	//! 可信度调节
	CSliderCtrl sl_real;
	//! 可信度显示
	CStatic tv_real;
	afx_msg void OnNMCustomdrawSliderReal(NMHDR *pNMHDR, LRESULT *pResult);
	//! 分辨率调节
	CSliderCtrl sl_dp;
	//! 显示分辨率调节参数
	CStatic tv_dp;
	//! 分辨率
	float miDp;
	//! 分辨率调节
	afx_msg void OnNMCustomdrawSliderDp(NMHDR *pNMHDR, LRESULT *pResult);
	//! 循环选择
	CButton cb_loop;
	//! 是否循环播放视频
	bool isLoopVideo;
	afx_msg void OnBnClickedCheckLoop();
	//! 显示分辨率大小
	CStatic tv_dp_size;

	//! 释放视频
	void freeVideo();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	//! 进度显示
	CStatic tv_speed_pos;
};
