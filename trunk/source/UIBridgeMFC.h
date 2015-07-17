#ifndef _UI_BRIDGE_MFC_
#define _UI_BRIDGE_MFC_

#include "UIBridgeBase.h"

#include <Windows.h>

#include "strhelper.h"
#include "OsUtils/OsThread.h"

class UIBridgeMFC: public UIBridgeBase
{
public:
	UIBridgeMFC(HWND hWnd, 
				sunjwbase::tstring *tstrUIAll,
				sunjwbase::OsMutex *mainMtx);
	virtual ~UIBridgeMFC();

	virtual void lockData();
	virtual void unlockData();

	virtual void preparingCalc();
	virtual void removePreparingCalc();
	virtual void calcStop();
	virtual void calcFinish();

	virtual void showFileName(const sunjwbase::tstring& tstrFileName);
	virtual void showFileMeta(const sunjwbase::tstring& tstrFileSize,
							const sunjwbase::tstring& tstrShortSize,
							const sunjwbase::tstring& tstrLastModifiedTime,
							const sunjwbase::tstring& tstrFileVersion);
	virtual void showFileHash(const sunjwbase::tstring& tstrFileMD5,
							const sunjwbase::tstring& tstrFileSHA1,
							const sunjwbase::tstring& tstrFileSHA256,
							const sunjwbase::tstring& tstrFileCRC32);
	virtual void showFileErr(const sunjwbase::tstring& tstrErr);

	virtual int getProgMax();
	virtual void updateProg(int value);
	virtual void updateProgWhole(int value);

	virtual void fileCalcFinish();
	virtual void fileFinish();

private:
	HWND m_hWnd;
	sunjwbase::tstring *m_uiTstrAll;
	sunjwbase::OsMutex *m_mainMtx;

	sunjwbase::tstring m_tstrNoPreparing;
};

#endif _UI_BRIDGE_MFC_