/*
 * ZKWindow.h - Zkswe
 *
 * Copyright (C) 2017 Zkswe Technology Corp.
 *
 *  Created on: Jun 10, 2017
 *      Author: zkswe@zkswe.com
 */

#ifndef _WINDOW_ZKWINDOW_H_
#define _WINDOW_ZKWINDOW_H_

#include <vector>
#include "control/ZKBase.h"

class ZKWindowPrivate;

/**
 * @brief 窗口控件
 */
class ZKWindow : public ZKBase {
	ZK_DECLARE_PRIVATE(ZKWindow)

public:
	ZKWindow(ZKBase *pParent);
	virtual ~ZKWindow();

	bool isModalWindow() const;

	virtual ZKBase* findControlByID(int id);
	virtual void getAllControls(vector<ZKBase*> &controlsList);

	/**
	 * @brief 显示窗口
	 */
	void showWnd();

	/**
	 * @brief 隐藏窗口
	 */
	void hideWnd();

	/**
	 * @brief 窗口是否显示
	 */
	bool isWndShow() const;

	/**
	 * @brief 设置子控件层级位置 (非线程安全接口，只允许在UI线程中调用)
	 * @param pChild    子控件
	 * @param index     位置
	 */
	void setChildIndex(ZKBase *pChild, int index);

protected:
	ZKWindow(ZKBase *pParent, ZKBasePrivate *pBP);

	virtual void onBeforeCreateWindow(const Json::Value &json);
	virtual void onAfterCreateWindow(const Json::Value &json);
	virtual const char* getClassName() const { return ZK_WINDOW; }

	virtual bool onInterceptMessage(const struct _message_t *pMsg);
	virtual bool onTouchEvent(const MotionEvent &ev);
	virtual void onTimer(int id);

	bool isWindowClass(const char *pClassName) const;
	bool checkHideModalWindow(int x, int y);

private:
	void parseWindowAttributeFromJson(const Json::Value &json);
	void parseControlsFromJson(const Json::Value &json);
};

#endif /* _WINDOW_ZKWINDOW_H_ */
