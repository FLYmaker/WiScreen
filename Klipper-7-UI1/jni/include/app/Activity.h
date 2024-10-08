/*
 * Activity.h - Zkswe
 *
 * Copyright (C) 2017 Zkswe Technology Corp.
 *
 *  Created on: Aug 21, 2017
 *      Author: zkswe@zkswe.com
 */

#ifndef _APP_ACTIVITY_H_
#define _APP_ACTIVITY_H_

#include <string>
#include <map>

#include "BaseApp.h"

class Intent;

class Activity : public BaseApp {
	friend class ActivityStack;
public:
	Activity();
	virtual ~Activity();

	int style() const { return mStyle; }
	bool needSwitchEffect() const { return mNeedSwitchEffect; }

protected:
	/**
	 * @brief 界面传递数据时回调
	 */
	virtual void onIntent(const Intent *intentPtr) { }

	/**
	 * @brief 界面显示时回调
	 */
	virtual void onResume() { }

	/**
	 * @brief 界面隐藏时回调
	 */
	virtual void onPause() { }

	/**
	 * @brief 执行返回时回调
	 * @return true 允许返回，false 禁止返回
	 */
	virtual bool onBack() { return true; }

	typedef enum {
		E_STYLE_PUSH = 0x01,
		E_STYLE_ZOOM,
		E_STYLE_ALPHA
	} EStyle;

protected:
	int mStyle;
	int mPushIndex;
	bool mNeedSwitchEffect;
};


class Intent {
public:
	typedef enum {
		E_INTENT_ACTION_MAIN,
		E_INTENT_ACTION_VIEW,
		E_INTENT_ACTION_EDIT
	} EIntentAction;

	Intent(int action = E_INTENT_ACTION_MAIN, std::string uri = "") :
		mAction(action), mUri(uri) { }
	virtual ~Intent() { }

public:
	int getAction() const { return mAction; }
	const std::string& getUri() const { return mUri; }

	/**
	 * @brief 设置键值数据
	 * @note 统一设置为string类型，如int类型需转为string类型，再存储，getExtra的时候再转一下
	 */
	void putExtra(const std::string &key, const std::string &value) {
		mExtras[key] = value;
	}

	/**
	 * @brief 获取key对应的数据
	 */
	const std::string& getExtra(const std::string &key) const {
		ExtraMap::const_iterator found = mExtras.find(key);
		static std::string empty("");

		if (found == mExtras.end()) {
			return empty;
		} else {
			return found->second;
		}
	}

protected:
	typedef std::map<std::string, std::string> ExtraMap;

	int mAction;
	std::string mUri;
	ExtraMap mExtras;
};


#include <vector>

class ActivityFactory {
public:
	static ActivityFactory *getInstance();

	bool registerActivity(const char *name, Activity* (*create)());
	Activity* create(const char *name);

	void dumpActivityInfos();

	void queryNames(std::vector<std::string> &names);

private:
	ActivityFactory() { }

private:
	typedef struct {
		std::string activityName;
		Activity* (*create)();
	} SActivityInfo;

	std::vector<SActivityInfo> mActivityInfos;
};

#define ACTIVITYFACTORY		ActivityFactory::getInstance()
#define REGISTER_ACTIVITY(_class) \
    static struct _ActivityFactory_##_class { \
        static Activity* create() { \
            return new _class(); \
        } \
        _ActivityFactory_##_class() { \
        	ACTIVITYFACTORY->registerActivity(#_class, create); \
        } \
    } _autoRegister_Activity_##_class

#endif /* _APP_ACTIVITY_H_ */
