
// DemoHyperLPR-mfcDlg.h : ͷ�ļ�
//

#pragma once


// CDemoHyperLPRmfcDlg �Ի���
class CDemoHyperLPRmfcDlg : public CDHtmlDialog
{
// ����
public:
	CDemoHyperLPRmfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMOHYPERLPRMFC_DIALOG, IDH = IDR_HTML_DEMOHYPERLPRMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
};
