
// DemoHyperLPR-mfcDlg.h : ͷ�ļ�
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

// CPrjMfc2Dlg �Ի���
class CDemoHyperLPRmfcDlg : public CDialogEx
{
	// ����
public:
	CDemoHyperLPRmfcDlg(CWnd* pParent = nullptr);	// ��׼���캯��

											// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRJ_MFC2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


														// ʵ��
protected:
	HICON m_hIcon;

	//! ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	//! ͼƬ·��
	CString mcsFilePathImage;
	//! ��Ƶ·��
	CString mcsFilePathVideo;
	//! ʶ����
	CStatic tv_res;
	//! ��Ƶ������
	CProgressCtrl progress_vedio;
	long progress_pos = 0;
	bool is_progress_falg = false;

	afx_msg void OnBnClickedStart();
	//! ͼƬ��Ƶ
	CStatic image_view;
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	//! ��Ƶ����
	cv::VideoCapture capture;
	//! ��ǰ��Ƶ
	cv::VideoCapture capture_now;
	t_VIDEO tvideo_head;
	t_VIDEO *tvideo_now;
	int mfps = 1; //! ֡��
	long mTotalFrame; //! ��֡��
	int miImageW; //! ֡��
	int miImageH; //! ֡��
	bool isStat = false;
	bool isStop = false;
	bool isEnd = false;
	// ����Ƶ��
	int openVideoCapture(long bit);
	int miSpeed;//! �����ٶ�
	int miSpeedThink;//! ʶ���ٶ�
	int miRealValue;//! ���Ŷ�
	void soptPlayr();

	//! Matת��Image
	bool Mat2CImage(cv::Mat *mat, CImage &img);
	//! ��ʾ��Ƶ
	void showVideo(cv::Mat *matImg, CImage &image);
	void showVideo2(cv::Mat *matImg, CImage &image);
	//! ��ʾԤ��
	CImage showPreview(cv::Mat *matImg, CImage &image);
	//! ��ʾͼƬ
	bool showImage(CImage image1, CWnd *pWnd);
	//! ʶ��ͼƬ
	CString thinkCarId(cv::Mat image, CImage &image_preview);
	//! ��ͼƬʶ��
	CString thinkCarId2(cv::Mat image);
	//! ���ʶ������־
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
	//!  ��Ƶ�����ٶ�
	CSliderCtrl sl_vedio_speed;
	//!  �ٶ���ʾ
	CStatic mtv_speed;

	//!  ��ʱ��
	CStatic mtv_time_all;
	//! ��ǰʱ��
	CStatic tv_time;
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	//! �����ٶȵ���
	//CSpinButtonCtrl msp_speed;
	//! ��Ƶ���Ž�����
	CSliderCtrl msl_video_progress;
	//! ʶ�𵽳�����ͣ
	CButton cb_is_stop_when_get_car;
	afx_msg void OnBnClickedCheckIsStopWhenGetCar();
	afx_msg void OnBnClickedCheck1();
	//! �Ƿ���ʶ����Ԥ��
	CButton cb_is_preview_car;
	//! ����ʶ����Ԥ��
	CStatic miv_preview_car;
	afx_msg void OnEnChangeEtLog();
	//! �Ƿ񱣴泵��ͼƬ������
	CButton mcb_is_save_car_image;
	//! �Ƿ���ļ������ʱ��
	CButton cb_is_add_filename_time;
	//! ��֡��ƽ��ʶ���ʱ
	CStatic mtv_ave_time_all;
	//! ����֡ʶ��ƽ����ʱ
	CStatic mtv_ave_time_car;
	//! ����Ƶ��ʶ�����
	long mlThinkCount;
	//! ����Ƶ��ʶ���ʱ
	double mdAveTimeAll;
	//! ����Ƶ��ʶ�𵽳��ƴ���
	long mlThinkCarCount;
	//! ����Ƶʶ�𵽳����ܺ�ʱ
	double mdAveTimeCar;
	//! ʶ���߼�
	afx_msg void OnNMCustomdrawSliderVideo(NMHDR *pNMHDR, LRESULT *pResult);
	//! �Ƿ�ʶ����Ƶ
	CButton cb_is_think_video;

	afx_msg void OnBnClickedButton1();
	//! ��Ƶ�ļ�·��
	CEdit et_file_path_video;
	afx_msg void OnBnClickedButtonImagePathChoose();
	//! ͼƬ·��ѡ��
	CEdit et_file_path_image;
	//! ʶ��Ƶ��
	CSliderCtrl sl_think_speed;
	afx_msg void OnNMCustomdrawSliderSpeedThink(NMHDR *pNMHDR, LRESULT *pResult);
	//! ʶ��Ƶ��
	CStatic mtv_speed2;
	//! ���Ŷȵ���
	CSliderCtrl sl_real;
	//! ���Ŷ���ʾ
	CStatic tv_real;
	afx_msg void OnNMCustomdrawSliderReal(NMHDR *pNMHDR, LRESULT *pResult);
	//! �ֱ��ʵ���
	CSliderCtrl sl_dp;
	//! ��ʾ�ֱ��ʵ��ڲ���
	CStatic tv_dp;
	//! �ֱ���
	float miDp;
	//! �ֱ��ʵ���
	afx_msg void OnNMCustomdrawSliderDp(NMHDR *pNMHDR, LRESULT *pResult);
	//! ѭ��ѡ��
	CButton cb_loop;
	//! �Ƿ�ѭ��������Ƶ
	bool isLoopVideo;
	afx_msg void OnBnClickedCheckLoop();
	//! ��ʾ�ֱ��ʴ�С
	CStatic tv_dp_size;

	//! �ͷ���Ƶ
	void freeVideo();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	//! ������ʾ
	CStatic tv_speed_pos;
};
