/***********************************************
/gen auto by zuitools
***********************************************/
#include "gcodeActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKButton* mHTTP_WS_BUTTONPtr;
static ZKTextView* mgcode_Button_textPtr;
static ZKButton* mForc_ButtonPtr;
static ZKButton* mgcode_Button_pinPtr;
static ZKListView* mGPIO_ListViewPtr;
static ZKListView* mHost_macros_listPtr;
static ZKButton* mButton45Ptr;
static ZKButton* mZoffset_Up_buttonPtr;
static ZKButton* mZoffset_Down_buttonPtr;
static ZKTextView* mFile_name_TextViewPtr;
static ZKButton* mButton58Ptr;
static ZKTextView* mTextView81Ptr;
static ZKTextView* mTextView80Ptr;
static ZKButton* mButton57Ptr;
static ZKButton* mtype_ButtonPtr;
static ZKButton* mgcode_ButtonPtr;
static ZKButton* mname_ButtonPtr;
static ZKWindow* mCustomize_WindowPtr;
static ZKButton* mCustomize_ButtonPtr;
static ZKTextView* mTextView79Ptr;
static ZKListView* mCustomize_ListViewPtr;
static ZKWindow* mDrop_down_menuPtr;
static ZKWindow* mCAM_BED_MESHPtr;
static ZKButton* mButton_print_Ptr;
static ZKButton* mButton_Ptr;
static ZKButton* mButton60Ptr;
static ZKButton* mButton54Ptr;
static ZKButton* mButton53Ptr;
static ZKButton* mButton52Ptr;
static ZKButton* mButton51Ptr;
static ZKButton* mButton49Ptr;
static ZKButton* mButton48Ptr;
static ZKButton* mButton47Ptr;
static ZKButton* mButton46Ptr;
static ZKButton* mButton_zPtr;
static ZKButton* mButton_yPtr;
static ZKButton* mButton_xPtr;
static ZKButton* mButton_wPtr;
static ZKButton* mButton_vPtr;
static ZKButton* mButton_uPtr;
static ZKButton* mButton_tPtr;
static ZKButton* mButton_sPtr;
static ZKButton* mButton_rPtr;
static ZKButton* mButton_qPtr;
static ZKButton* mButton_pPtr;
static ZKButton* mButton_oPtr;
static ZKButton* mButton_nPtr;
static ZKButton* mButton_mPtr;
static ZKButton* mButton_lPtr;
static ZKButton* mButton_kPtr;
static ZKButton* mButton_jPtr;
static ZKButton* mButton_iPtr;
static ZKButton* mButton_hPtr;
static ZKButton* mButton_gPtr;
static ZKButton* mButton_fPtr;
static ZKButton* mButton_ePtr;
static ZKButton* mButton_dPtr;
static ZKButton* mButton_cPtr;
static ZKButton* mButton_bPtr;
static ZKButton* mButton_aPtr;
static ZKButton* mButton_9Ptr;
static ZKButton* mButton_8Ptr;
static ZKButton* mButton_7Ptr;
static ZKButton* mButton_6Ptr;
static ZKButton* mButton_5Ptr;
static ZKButton* mButton_4Ptr;
static ZKButton* mButton_3Ptr;
static ZKButton* mButton_2Ptr;
static ZKButton* mButton_1Ptr;
static ZKButton* mButton_0Ptr;
static ZKButton* mstop_ButtonPtr;
static ZKButton* mButton62Ptr;
static ZKButton* mButton61Ptr;
static ZKListView* mListView1Ptr;
static ZKWindow* mspeed_windowPtr;
static ZKButton* mspeed_ButtonPtr;
static ZKButton* mzoffset005_ButtonPtr;
static ZKButton* mzoffset0025_ButtonPtr;
static ZKButton* mzoffset001_ButtonPtr;
static ZKButton* mZ_Offset_Reverse_ButtonPtr;
static ZKButton* mzoffset0005_ButtonPtr;
static ZKListView* mLanguage_ListViewPtr;
static ZKButton* mButton_moto_reversPtr;
static ZKButton* mButton_unlockPtr;
static ZKButton* mButton_homePtr;
static ZKButton* mButton_DelPtr;
static ZKButton* mButton_PreheatPtr;
static ZKButton* mButtonForgetPtr;
static ZKWindow* mHost_computer_wifiPtr;
static ZKButton* mButtonautoconnectPtr;
static ZKTextView* mTextConnectStatePtr;
static ZKTextView* mTextConnectSecTypePtr;
static ZKTextView* mTextConnectSsidPtr;
static ZKTextView* mTextview19Ptr;
static ZKTextView* mTextview17Ptr;
static ZKTextView* mTextview15Ptr;
static ZKButton* mButtonDisconnectPtr;
static ZKWindow* mWindowDisconnectPtr;
static ZKButton* mButtonShowPwdPtr;
static ZKTextView* mTextSecTypePtr;
static ZKTextView* mTextSsidPtr;
static ZKTextView* mTextview9Ptr;
static ZKTextView* mTextview7Ptr;
static ZKTextView* mTextview5Ptr;
static ZKEditText* mEdittextPwdPtr;
static ZKButton* mButtonConnectPtr;
static ZKWindow* mWindowSetPtr;
static ZKListView* mListViewWifiInfoPtr;
static ZKButton* mButton36Ptr;
static ZKTextView* mTextView78Ptr;
static ZKTextView* mTextView77Ptr;
static ZKTextView* mTextView65Ptr;
static ZKTextView* mTextView58Ptr;
static ZKTextView* mTextView76Ptr;
static ZKButton* mopen_notifyPtr;
static ZKButton* mBuzz_BUTTONPtr;
static ZKTextView* mTextView73Ptr;
static ZKButton* mms_file_buttonPtr;
static ZKButton* mSd_buttonPtr;
static ZKButton* mUdesk_buttonPtr;
static ZKListView* mdownload_listPtr;
static ZKButton* mUpdata_Slave_printingPtr;
static ZKButton* mUpdata_SlavePtr;
static ZKListView* mPrint_img_ListViewPtr;
static ZKListView* mPrint_ListView1Ptr;
static ZKWindow* mAnti_touchPtr;
static ZKTextView* mTextView41Ptr;
static ZKButton* mButton30Ptr;
static ZKButton* mButton29Ptr;
static ZKWindow* mrestart_layerPtr;
static ZKButton* mButton28Ptr;
static ZKButton* mButtonjpdPtr;
static ZKButton* mButtonjpLPtr;
static ZKButton* mButton96Ptr;
static ZKTextView* mTextView22Ptr;
static ZKButton* mButton84Ptr;
static ZKButton* mButton85Ptr;
static ZKButton* mButton86Ptr;
static ZKButton* mButton87Ptr;
static ZKButton* mButton88Ptr;
static ZKButton* mButton89Ptr;
static ZKButton* mButton90Ptr;
static ZKButton* mButton91Ptr;
static ZKButton* mButton92Ptr;
static ZKButton* mButton93Ptr;
static ZKButton* mButton94Ptr;
static ZKButton* mAJ_confirm_ButtonPtr;
static ZKWindow* mAJPtr;
static ZKButton* mButton168Ptr;
static ZKButton* mButton167Ptr;
static ZKButton* mButton166Ptr;
static ZKButton* mButton165Ptr;
static ZKButton* mButton138Ptr;
static ZKButton* mButton137Ptr;
static ZKButton* mButton125Ptr;
static ZKTextView* mTextView44Ptr;
static ZKTextView* mTextView46Ptr;
static ZKWindow* mAJ1Ptr;
static ZKButton* mButton18Ptr;
static ZKTextView* mTextview50Ptr;
static ZKWindow* mlockPtr;
static ZKTextView* mTextView18Ptr;
static ZKButton* mButton14Ptr;
static ZKButton* mButton12Ptr;
static ZKWindow* myes_no_WindowPtr;
static ZKTextView* mTextView30Ptr;
static ZKListView* mTime_out_listPtr;
static ZKWindow* mTime_out_winPtr;
static ZKTextView* mTextView26Ptr;
static ZKTextView* mTextView24Ptr;
static ZKTextView* mTextView23Ptr;
static ZKTextView* mTextView21Ptr;
static ZKButton* mButton17Ptr;
static ZKButton* mButton16Ptr;
static ZKButton* mButton15Ptr;
static ZKTextView* mTextView28Ptr;
static ZKTextView* mTextView27Ptr;
static ZKButton* mButton13Ptr;
static ZKTextView* mTextView29Ptr;
static ZKSeekBar* mbrightnes_SeekBarPtr;
static ZKTextView* mTextView20Ptr;
static ZKWindow* mScreen_set_winPtr;
static ZKListView* mNotify_ListViewPtr;
static ZKListView* mCOLOR_ListViewPtr;
static ZKTextView* mTextView72Ptr;
static ZKTextView* mTextView71Ptr;
static ZKTextView* mTextView75Ptr;
static ZKButton* mERCF_BOWDEN_CA_BUTTONPtr;
static ZKTextView* mTextView74Ptr;
static ZKButton* mERCF_BOWDEN_BACKPtr;
static ZKWindow* mERCF_BOWDEN_WindowPtr;
static ZKButton* mERCF_SENSOR_TRUE_BUTTONPtr;
static ZKTextView* mTextView70Ptr;
static ZKTextView* mTextView69Ptr;
static ZKButton* mERCF_SENSOR_BACKPtr;
static ZKTextView* mencode_viewPtr;
static ZKTextView* mTextView48Ptr;
static ZKTextView* mTextView47Ptr;
static ZKWindow* mERCF_SENSOR_WindowPtr;
static ZKTextView* mTextView68Ptr;
static ZKButton* mERCF_EX_TRUE_BUTTONPtr;
static ZKTextView* mTextView67Ptr;
static ZKButton* mERCF_EX_BUTTONPtr;
static ZKButton* mERCF_EX_BACKPtr;
static ZKTextView* mTextView66Ptr;
static ZKTextView* mTextView64Ptr;
static ZKTextView* mTextView63Ptr;
static ZKWindow* mERCF_EX_WindowPtr;
static ZKButton* mERCF_MOTOR_OFF1Ptr;
static ZKTextView* mTextView54Ptr;
static ZKTextView* mTextView53Ptr;
static ZKListView* mListView6Ptr;
static ZKListView* mERCF_CA_ListViewPtr;
static ZKTextView* mTextView52Ptr;
static ZKButton* mERCF_TOOOL_CAPtr;
static ZKButton* mERCF_TOOL_BACKPtr;
static ZKTextView* mTextView51Ptr;
static ZKTextView* mTextView50Ptr;
static ZKTextView* mTextView49Ptr;
static ZKButton* mERCF_MOTOR_OFF2Ptr;
static ZKWindow* mERCF_TOOL_WindowPtr;
static ZKTextView* mTextView62Ptr;
static ZKTextView* mTextView57Ptr;
static ZKButton* mERCF_SERVO_UP_ButtonPtr;
static ZKTextView* mTextView61Ptr;
static ZKButton* mERCF_SERVO_DOWN_ButtonPtr;
static ZKTextView* mTextView60Ptr;
static ZKTextView* mTextView59Ptr;
static ZKButton* mERCF_SERVO_BACKPtr;
static ZKTextView* mTextView56Ptr;
static ZKTextView* mTextView55Ptr;
static ZKWindow* mERCF_SERVO_WindowPtr;
static ZKButton* mERCF_CA_BACKPtr;
static ZKButton* mButton40Ptr;
static ZKButton* mButton39Ptr;
static ZKButton* mButton38Ptr;
static ZKButton* mButton37Ptr;
static ZKButton* mButton35Ptr;
static ZKButton* mButton34Ptr;
static ZKWindow* mERCF_CA_WindowPtr;
static ZKButton* mERCF_HOMEPtr;
static ZKButton* mERCF_MOTOR_OFFPtr;
static ZKButton* mERCF_EPtr;
static ZKButton* mERCF_E_ADDPtr;
static ZKButton* mERCF_CA_BUTTONPtr;
static ZKListView* mERCF_ListViewPtr;
static ZKWindow* mERCFPtr;
static ZKListView* mListView5Ptr;
static ZKWindow* mGcode_layerPtr;
static ZKButton* mPrint_set_buttonPtr;
static ZKButton* mButton44Ptr;
static ZKButton* mButton43Ptr;
static ZKButton* mButton42Ptr;
static ZKButton* mButton41Ptr;
static ZKButton* mButton22Ptr;
static ZKTextView* mTextView32Ptr;
static ZKButton* mButton21Ptr;
static ZKListView* mPrint_set_listPtr;
static ZKWindow* mConnect_WindowPtr;
static ZKButton* mButton19Ptr;
static ZKButton* mButton31Ptr;
static ZKButton* mButton20Ptr;
static ZKTextView* mTextView31Ptr;
static ZKWindow* mPrint_Set_WinPtr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKTextView* mTextView9Ptr;
static ZKButton* mButton7Ptr;
static ZKButton* mButton4Ptr;
static ZKTextView* mTextView8Ptr;
static ZKTextView* mTextView2Ptr;
static ZKWindow* mprint_surePtr;
static ZKListView* mFileListPtr;
static ZKButton* mFile_Refresh_buttonPtr;
static ZKTextView* mTextView14Ptr;
static ZKWindow* mfilePtr;
static ZKTextView* mTextView40Ptr;
static ZKListView* mListView3Ptr;
static ZKTextView* mTextView39Ptr;
static ZKButton* mButton27Ptr;
static ZKListView* mListView2Ptr;
static ZKWindow* mcur_jz_WinPtr;
static ZKButton* mButton26Ptr;
static ZKTextView* mTextView38Ptr;
static ZKTextView* mTextView33Ptr;
static ZKButton* mButton25Ptr;
static ZKButton* mButton24Ptr;
static ZKButton* mButton23Ptr;
static ZKButton* mButton6Ptr;
static ZKButton* mjz_win_close_buttonPtr;
static ZKButton* mButton80Ptr;
static ZKButton* mButton82Ptr;
static ZKButton* mButton81Ptr;
static ZKButton* mButton79Ptr;
static ZKButton* mButton77Ptr;
static ZKButton* mButton76Ptr;
static ZKButton* mButton75Ptr;
static ZKButton* mButton59Ptr;
static ZKTextView* mTextView5Ptr;
static ZKTextView* mTextView13Ptr;
static ZKWindow* mjz_WindowPtr;
static ZKButton* mtemp_move_ButtonPtr;
static ZKButton* mTool_ButtonPtr;
static ZKTextView* mTextView37Ptr;
static ZKButton* mhc_hg_ButtonPtr;
static ZKButton* mJZ_ButtonPtr;
static ZKWindow* mtoolPtr;
static ZKButton* mFAN3_DOWNPtr;
static ZKButton* mFAN3_UPPtr;
static ZKButton* mFAN2_DOWNPtr;
static ZKButton* mFAN2_UPPtr;
static ZKButton* mFAN1_DOWNPtr;
static ZKButton* mFAN1_UPPtr;
static ZKTextView* mFAN2_ViewPtr;
static ZKTextView* mFAN1_ViewPtr;
static ZKTextView* mFAN0_ViewPtr;
static ZKButton* mFAN3_ICONPtr;
static ZKButton* mFAN2_ICONPtr;
static ZKButton* mFAN1_ICONPtr;
static ZKButton* mFAN3_SW_ButtonPtr;
static ZKButton* mFAN2_SW_ButtonPtr;
static ZKButton* mFAN1_SW_ButtonPtr;
static ZKPointer* mFan2_PointerPtr;
static ZKPointer* mFan1_PointerPtr;
static ZKPointer* mFan0_PointerPtr;
static ZKWindow* mFAN_WindowPtr;
static ZKButton* mButton11Ptr;
static ZKButton* mButton10Ptr;
static ZKButton* mButton9Ptr;
static ZKButton* mButton8Ptr;
static ZKTextView* mTextView15Ptr;
static ZKWindow* mprint_speed_WindowPtr;
static ZKButton* mFan_layer_open_buttonPtr;
static ZKButton* mlayer2_speed_buttonPtr;
static ZKButton* mButton103Ptr;
static ZKButton* mlyayer2_bed_temp_buttonPtr;
static ZKButton* mlyayer2_nozzle_temp_buttonPtr;
static ZKButton* mY_D1_BUTTONPtr;
static ZKButton* mY_D10_BUTTONPtr;
static ZKButton* mY_U1_BUTTONPtr;
static ZKButton* mY_U10_BUTTONPtr;
static ZKButton* mX_D1_BUTTONPtr;
static ZKButton* mX_D10_BUTTONPtr;
static ZKButton* mX_U1_BUTTONPtr;
static ZKButton* mX_U10_BUTTONPtr;
static ZKButton* mButton3Ptr;
static ZKButton* mButton1Ptr;
static ZKButton* mButton68Ptr;
static ZKButton* mButton66Ptr;
static ZKTextView* mTextView36Ptr;
static ZKTextView* mTextView35Ptr;
static ZKTextView* mTextView34Ptr;
static ZKButton* mButton56Ptr;
static ZKButton* mButton2Ptr;
static ZKButton* mButton55Ptr;
static ZKTextView* mWarehouse_Temperature_ViewPtr;
static ZKTextView* mBed_Temp_ViewPtr;
static ZKTextView* mNozzle_Temp_ViewPtr;
static ZKTextView* mMove_button_backgroundPtr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView16Ptr;
static ZKWindow* mwhmovePtr;
static ZKWindow* mmovePtr;
static ZKTextView* mTextView19Ptr;
static ZKButton* mButton5Ptr;
static ZKSeekBar* mObj_SeekBarPtr;
static ZKButton* mobj_B30Ptr;
static ZKButton* mobj_B29Ptr;
static ZKButton* mobj_B28Ptr;
static ZKButton* mobj_B27Ptr;
static ZKButton* mobj_B26Ptr;
static ZKButton* mobj_B25Ptr;
static ZKButton* mobj_B24Ptr;
static ZKButton* mobj_B23Ptr;
static ZKButton* mobj_B22Ptr;
static ZKButton* mobj_B21Ptr;
static ZKButton* mobj_B20Ptr;
static ZKButton* mobj_B19Ptr;
static ZKButton* mobj_B18Ptr;
static ZKButton* mobj_B17Ptr;
static ZKButton* mobj_B16Ptr;
static ZKButton* mobj_B15Ptr;
static ZKButton* mobj_B14Ptr;
static ZKButton* mobj_B13Ptr;
static ZKButton* mobj_B12Ptr;
static ZKButton* mobj_B11Ptr;
static ZKButton* mobj_B10Ptr;
static ZKButton* mobj_B9Ptr;
static ZKButton* mobj_B8Ptr;
static ZKButton* mobj_B7Ptr;
static ZKButton* mobj_B6Ptr;
static ZKButton* mobj_B5Ptr;
static ZKButton* mobj_B4Ptr;
static ZKButton* mobj_B3Ptr;
static ZKButton* mobj_B2Ptr;
static ZKButton* mobj_B1Ptr;
static ZKButton* mobj_B0Ptr;
static ZKWindow* mExclude_Object_window2Ptr;
static ZKWindow* mExclude_Object_windowPtr;
static ZKButton* mButton101Ptr;
static ZKButton* mButton100Ptr;
static ZKButton* mButton98Ptr;
static ZKButton* mButton50Ptr;
static ZKButton* mbed_temp_buttonPtr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView45Ptr;
static ZKTextView* mTextView43Ptr;
static ZKTextView* mTextView42Ptr;
static ZKTextView* mTextView17Ptr;
static ZKButton* mStop_ButtonPtr;
static ZKButton* mPause_ButtonPtr;
static ZKButton* mSkip_it_ButtonPtr;
static ZKSeekBar* mPrint_SeekBarPtr;
static ZKTextView* mthumbnail_pngPtr;
static ZKTextView* mTextView4Ptr;
static ZKTextView* mTextView3Ptr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mprintPtr;
static ZKTextView* mTextView6Ptr;
static ZKWindow* mhomePtr;
static ZKButton* mMain_ButtonPtr;
static ZKButton* mLayer2_ButtonPtr;
static ZKButton* mFile_ButtonPtr;
static ZKButton* mButton73Ptr;
static ZKButton* mScreen_set_ButtonPtr;
static ZKTextView* mTextView25Ptr;
static gcodeActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(gcodeActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/gcodeLogic.cc"

/***********/
typedef struct {
    int id;
    const char *pApp;
} SAppInfo;

/**
 *点击跳转window
 */
static SAppInfo sAppInfoTab[] = {
//  { ID_MAIN_TEXT, "TextViewActivity" },
};

/***************/
typedef bool (*ButtonCallback)(ZKButton *pButton);
/**
 * button onclick表
 */
typedef struct {
    int id;
    ButtonCallback callback;
}S_ButtonCallback;

/*TAG:ButtonCallbackTab按键映射表*/
static S_ButtonCallback sButtonCallbackTab[] = {
    ID_GCODE_HTTP_WS_BUTTON, onButtonClick_HTTP_WS_BUTTON,
    ID_GCODE_Forc_Button, onButtonClick_Forc_Button,
    ID_GCODE_gcode_Button_pin, onButtonClick_gcode_Button_pin,
    ID_GCODE_Button45, onButtonClick_Button45,
    ID_GCODE_Zoffset_Up_button, onButtonClick_Zoffset_Up_button,
    ID_GCODE_Zoffset_Down_button, onButtonClick_Zoffset_Down_button,
    ID_GCODE_Button58, onButtonClick_Button58,
    ID_GCODE_Button57, onButtonClick_Button57,
    ID_GCODE_type_Button, onButtonClick_type_Button,
    ID_GCODE_gcode_Button, onButtonClick_gcode_Button,
    ID_GCODE_name_Button, onButtonClick_name_Button,
    ID_GCODE_Customize_Button, onButtonClick_Customize_Button,
    ID_GCODE_Button_print_, onButtonClick_Button_print_,
    ID_GCODE_Button_, onButtonClick_Button_,
    ID_GCODE_Button60, onButtonClick_Button60,
    ID_GCODE_Button54, onButtonClick_Button54,
    ID_GCODE_Button53, onButtonClick_Button53,
    ID_GCODE_Button52, onButtonClick_Button52,
    ID_GCODE_Button51, onButtonClick_Button51,
    ID_GCODE_Button49, onButtonClick_Button49,
    ID_GCODE_Button48, onButtonClick_Button48,
    ID_GCODE_Button47, onButtonClick_Button47,
    ID_GCODE_Button46, onButtonClick_Button46,
    ID_GCODE_Button_z, onButtonClick_Button_z,
    ID_GCODE_Button_y, onButtonClick_Button_y,
    ID_GCODE_Button_x, onButtonClick_Button_x,
    ID_GCODE_Button_w, onButtonClick_Button_w,
    ID_GCODE_Button_v, onButtonClick_Button_v,
    ID_GCODE_Button_u, onButtonClick_Button_u,
    ID_GCODE_Button_t, onButtonClick_Button_t,
    ID_GCODE_Button_s, onButtonClick_Button_s,
    ID_GCODE_Button_r, onButtonClick_Button_r,
    ID_GCODE_Button_q, onButtonClick_Button_q,
    ID_GCODE_Button_p, onButtonClick_Button_p,
    ID_GCODE_Button_o, onButtonClick_Button_o,
    ID_GCODE_Button_n, onButtonClick_Button_n,
    ID_GCODE_Button_m, onButtonClick_Button_m,
    ID_GCODE_Button_l, onButtonClick_Button_l,
    ID_GCODE_Button_k, onButtonClick_Button_k,
    ID_GCODE_Button_j, onButtonClick_Button_j,
    ID_GCODE_Button_i, onButtonClick_Button_i,
    ID_GCODE_Button_h, onButtonClick_Button_h,
    ID_GCODE_Button_g, onButtonClick_Button_g,
    ID_GCODE_Button_f, onButtonClick_Button_f,
    ID_GCODE_Button_e, onButtonClick_Button_e,
    ID_GCODE_Button_d, onButtonClick_Button_d,
    ID_GCODE_Button_c, onButtonClick_Button_c,
    ID_GCODE_Button_b, onButtonClick_Button_b,
    ID_GCODE_Button_a, onButtonClick_Button_a,
    ID_GCODE_Button_9, onButtonClick_Button_9,
    ID_GCODE_Button_8, onButtonClick_Button_8,
    ID_GCODE_Button_7, onButtonClick_Button_7,
    ID_GCODE_Button_6, onButtonClick_Button_6,
    ID_GCODE_Button_5, onButtonClick_Button_5,
    ID_GCODE_Button_4, onButtonClick_Button_4,
    ID_GCODE_Button_3, onButtonClick_Button_3,
    ID_GCODE_Button_2, onButtonClick_Button_2,
    ID_GCODE_Button_1, onButtonClick_Button_1,
    ID_GCODE_Button_0, onButtonClick_Button_0,
    ID_GCODE_stop_Button, onButtonClick_stop_Button,
    ID_GCODE_Button62, onButtonClick_Button62,
    ID_GCODE_Button61, onButtonClick_Button61,
    ID_GCODE_speed_Button, onButtonClick_speed_Button,
    ID_GCODE_zoffset005_Button, onButtonClick_zoffset005_Button,
    ID_GCODE_zoffset0025_Button, onButtonClick_zoffset0025_Button,
    ID_GCODE_zoffset001_Button, onButtonClick_zoffset001_Button,
    ID_GCODE_Z_Offset_Reverse_Button, onButtonClick_Z_Offset_Reverse_Button,
    ID_GCODE_zoffset0005_Button, onButtonClick_zoffset0005_Button,
    ID_GCODE_Button_moto_revers, onButtonClick_Button_moto_revers,
    ID_GCODE_Button_unlock, onButtonClick_Button_unlock,
    ID_GCODE_Button_home, onButtonClick_Button_home,
    ID_GCODE_Button_Del, onButtonClick_Button_Del,
    ID_GCODE_Button_Preheat, onButtonClick_Button_Preheat,
    ID_GCODE_ButtonForget, onButtonClick_ButtonForget,
    ID_GCODE_Buttonautoconnect, onButtonClick_Buttonautoconnect,
    ID_GCODE_ButtonDisconnect, onButtonClick_ButtonDisconnect,
    ID_GCODE_ButtonShowPwd, onButtonClick_ButtonShowPwd,
    ID_GCODE_ButtonConnect, onButtonClick_ButtonConnect,
    ID_GCODE_Button36, onButtonClick_Button36,
    ID_GCODE_open_notify, onButtonClick_open_notify,
    ID_GCODE_Buzz_BUTTON, onButtonClick_Buzz_BUTTON,
    ID_GCODE_ms_file_button, onButtonClick_ms_file_button,
    ID_GCODE_Sd_button, onButtonClick_Sd_button,
    ID_GCODE_Udesk_button, onButtonClick_Udesk_button,
    ID_GCODE_Updata_Slave_printing, onButtonClick_Updata_Slave_printing,
    ID_GCODE_Updata_Slave, onButtonClick_Updata_Slave,
    ID_GCODE_Button30, onButtonClick_Button30,
    ID_GCODE_Button29, onButtonClick_Button29,
    ID_GCODE_Button28, onButtonClick_Button28,
    ID_GCODE_Buttonjpd, onButtonClick_Buttonjpd,
    ID_GCODE_ButtonjpL, onButtonClick_ButtonjpL,
    ID_GCODE_Button96, onButtonClick_Button96,
    ID_GCODE_Button84, onButtonClick_Button84,
    ID_GCODE_Button85, onButtonClick_Button85,
    ID_GCODE_Button86, onButtonClick_Button86,
    ID_GCODE_Button87, onButtonClick_Button87,
    ID_GCODE_Button88, onButtonClick_Button88,
    ID_GCODE_Button89, onButtonClick_Button89,
    ID_GCODE_Button90, onButtonClick_Button90,
    ID_GCODE_Button91, onButtonClick_Button91,
    ID_GCODE_Button92, onButtonClick_Button92,
    ID_GCODE_Button93, onButtonClick_Button93,
    ID_GCODE_Button94, onButtonClick_Button94,
    ID_GCODE_AJ_confirm_Button, onButtonClick_AJ_confirm_Button,
    ID_GCODE_Button168, onButtonClick_Button168,
    ID_GCODE_Button167, onButtonClick_Button167,
    ID_GCODE_Button166, onButtonClick_Button166,
    ID_GCODE_Button165, onButtonClick_Button165,
    ID_GCODE_Button138, onButtonClick_Button138,
    ID_GCODE_Button137, onButtonClick_Button137,
    ID_GCODE_Button125, onButtonClick_Button125,
    ID_GCODE_Button18, onButtonClick_Button18,
    ID_GCODE_Button14, onButtonClick_Button14,
    ID_GCODE_Button12, onButtonClick_Button12,
    ID_GCODE_Button17, onButtonClick_Button17,
    ID_GCODE_Button16, onButtonClick_Button16,
    ID_GCODE_Button15, onButtonClick_Button15,
    ID_GCODE_Button13, onButtonClick_Button13,
    ID_GCODE_ERCF_BOWDEN_CA_BUTTON, onButtonClick_ERCF_BOWDEN_CA_BUTTON,
    ID_GCODE_ERCF_BOWDEN_BACK, onButtonClick_ERCF_BOWDEN_BACK,
    ID_GCODE_ERCF_SENSOR_TRUE_BUTTON, onButtonClick_ERCF_SENSOR_TRUE_BUTTON,
    ID_GCODE_ERCF_SENSOR_BACK, onButtonClick_ERCF_SENSOR_BACK,
    ID_GCODE_ERCF_EX_TRUE_BUTTON, onButtonClick_ERCF_EX_TRUE_BUTTON,
    ID_GCODE_ERCF_EX_BUTTON, onButtonClick_ERCF_EX_BUTTON,
    ID_GCODE_ERCF_EX_BACK, onButtonClick_ERCF_EX_BACK,
    ID_GCODE_ERCF_MOTOR_OFF1, onButtonClick_ERCF_MOTOR_OFF1,
    ID_GCODE_ERCF_TOOOL_CA, onButtonClick_ERCF_TOOOL_CA,
    ID_GCODE_ERCF_TOOL_BACK, onButtonClick_ERCF_TOOL_BACK,
    ID_GCODE_ERCF_MOTOR_OFF2, onButtonClick_ERCF_MOTOR_OFF2,
    ID_GCODE_ERCF_SERVO_UP_Button, onButtonClick_ERCF_SERVO_UP_Button,
    ID_GCODE_ERCF_SERVO_DOWN_Button, onButtonClick_ERCF_SERVO_DOWN_Button,
    ID_GCODE_ERCF_SERVO_BACK, onButtonClick_ERCF_SERVO_BACK,
    ID_GCODE_ERCF_CA_BACK, onButtonClick_ERCF_CA_BACK,
    ID_GCODE_Button40, onButtonClick_Button40,
    ID_GCODE_Button39, onButtonClick_Button39,
    ID_GCODE_Button38, onButtonClick_Button38,
    ID_GCODE_Button37, onButtonClick_Button37,
    ID_GCODE_Button35, onButtonClick_Button35,
    ID_GCODE_Button34, onButtonClick_Button34,
    ID_GCODE_ERCF_HOME, onButtonClick_ERCF_HOME,
    ID_GCODE_ERCF_MOTOR_OFF, onButtonClick_ERCF_MOTOR_OFF,
    ID_GCODE_ERCF_E, onButtonClick_ERCF_E,
    ID_GCODE_ERCF_E_ADD, onButtonClick_ERCF_E_ADD,
    ID_GCODE_ERCF_CA_BUTTON, onButtonClick_ERCF_CA_BUTTON,
    ID_GCODE_Print_set_button, onButtonClick_Print_set_button,
    ID_GCODE_Button44, onButtonClick_Button44,
    ID_GCODE_Button43, onButtonClick_Button43,
    ID_GCODE_Button42, onButtonClick_Button42,
    ID_GCODE_Button41, onButtonClick_Button41,
    ID_GCODE_Button22, onButtonClick_Button22,
    ID_GCODE_Button21, onButtonClick_Button21,
    ID_GCODE_Button19, onButtonClick_Button19,
    ID_GCODE_Button31, onButtonClick_Button31,
    ID_GCODE_Button20, onButtonClick_Button20,
    ID_GCODE_Button7, onButtonClick_Button7,
    ID_GCODE_Button4, onButtonClick_Button4,
    ID_GCODE_File_Refresh_button, onButtonClick_File_Refresh_button,
    ID_GCODE_Button27, onButtonClick_Button27,
    ID_GCODE_Button26, onButtonClick_Button26,
    ID_GCODE_Button25, onButtonClick_Button25,
    ID_GCODE_Button24, onButtonClick_Button24,
    ID_GCODE_Button23, onButtonClick_Button23,
    ID_GCODE_Button6, onButtonClick_Button6,
    ID_GCODE_jz_win_close_button, onButtonClick_jz_win_close_button,
    ID_GCODE_Button80, onButtonClick_Button80,
    ID_GCODE_Button82, onButtonClick_Button82,
    ID_GCODE_Button81, onButtonClick_Button81,
    ID_GCODE_Button79, onButtonClick_Button79,
    ID_GCODE_Button77, onButtonClick_Button77,
    ID_GCODE_Button76, onButtonClick_Button76,
    ID_GCODE_Button75, onButtonClick_Button75,
    ID_GCODE_Button59, onButtonClick_Button59,
    ID_GCODE_temp_move_Button, onButtonClick_temp_move_Button,
    ID_GCODE_Tool_Button, onButtonClick_Tool_Button,
    ID_GCODE_hc_hg_Button, onButtonClick_hc_hg_Button,
    ID_GCODE_JZ_Button, onButtonClick_JZ_Button,
    ID_GCODE_FAN3_DOWN, onButtonClick_FAN3_DOWN,
    ID_GCODE_FAN3_UP, onButtonClick_FAN3_UP,
    ID_GCODE_FAN2_DOWN, onButtonClick_FAN2_DOWN,
    ID_GCODE_FAN2_UP, onButtonClick_FAN2_UP,
    ID_GCODE_FAN1_DOWN, onButtonClick_FAN1_DOWN,
    ID_GCODE_FAN1_UP, onButtonClick_FAN1_UP,
    ID_GCODE_FAN3_ICON, onButtonClick_FAN3_ICON,
    ID_GCODE_FAN2_ICON, onButtonClick_FAN2_ICON,
    ID_GCODE_FAN1_ICON, onButtonClick_FAN1_ICON,
    ID_GCODE_FAN3_SW_Button, onButtonClick_FAN3_SW_Button,
    ID_GCODE_FAN2_SW_Button, onButtonClick_FAN2_SW_Button,
    ID_GCODE_FAN1_SW_Button, onButtonClick_FAN1_SW_Button,
    ID_GCODE_Button11, onButtonClick_Button11,
    ID_GCODE_Button10, onButtonClick_Button10,
    ID_GCODE_Button9, onButtonClick_Button9,
    ID_GCODE_Button8, onButtonClick_Button8,
    ID_GCODE_Fan_layer_open_button, onButtonClick_Fan_layer_open_button,
    ID_GCODE_layer2_speed_button, onButtonClick_layer2_speed_button,
    ID_GCODE_Button103, onButtonClick_Button103,
    ID_GCODE_lyayer2_bed_temp_button, onButtonClick_lyayer2_bed_temp_button,
    ID_GCODE_lyayer2_nozzle_temp_button, onButtonClick_lyayer2_nozzle_temp_button,
    ID_GCODE_Y_D1_BUTTON, onButtonClick_Y_D1_BUTTON,
    ID_GCODE_Y_D10_BUTTON, onButtonClick_Y_D10_BUTTON,
    ID_GCODE_Y_U1_BUTTON, onButtonClick_Y_U1_BUTTON,
    ID_GCODE_Y_U10_BUTTON, onButtonClick_Y_U10_BUTTON,
    ID_GCODE_X_D1_BUTTON, onButtonClick_X_D1_BUTTON,
    ID_GCODE_X_D10_BUTTON, onButtonClick_X_D10_BUTTON,
    ID_GCODE_X_U1_BUTTON, onButtonClick_X_U1_BUTTON,
    ID_GCODE_X_U10_BUTTON, onButtonClick_X_U10_BUTTON,
    ID_GCODE_Button3, onButtonClick_Button3,
    ID_GCODE_Button1, onButtonClick_Button1,
    ID_GCODE_Button68, onButtonClick_Button68,
    ID_GCODE_Button66, onButtonClick_Button66,
    ID_GCODE_Button56, onButtonClick_Button56,
    ID_GCODE_Button2, onButtonClick_Button2,
    ID_GCODE_Button55, onButtonClick_Button55,
    ID_GCODE_Button5, onButtonClick_Button5,
    ID_GCODE_obj_B30, onButtonClick_obj_B30,
    ID_GCODE_obj_B29, onButtonClick_obj_B29,
    ID_GCODE_obj_B28, onButtonClick_obj_B28,
    ID_GCODE_obj_B27, onButtonClick_obj_B27,
    ID_GCODE_obj_B26, onButtonClick_obj_B26,
    ID_GCODE_obj_B25, onButtonClick_obj_B25,
    ID_GCODE_obj_B24, onButtonClick_obj_B24,
    ID_GCODE_obj_B23, onButtonClick_obj_B23,
    ID_GCODE_obj_B22, onButtonClick_obj_B22,
    ID_GCODE_obj_B21, onButtonClick_obj_B21,
    ID_GCODE_obj_B20, onButtonClick_obj_B20,
    ID_GCODE_obj_B19, onButtonClick_obj_B19,
    ID_GCODE_obj_B18, onButtonClick_obj_B18,
    ID_GCODE_obj_B17, onButtonClick_obj_B17,
    ID_GCODE_obj_B16, onButtonClick_obj_B16,
    ID_GCODE_obj_B15, onButtonClick_obj_B15,
    ID_GCODE_obj_B14, onButtonClick_obj_B14,
    ID_GCODE_obj_B13, onButtonClick_obj_B13,
    ID_GCODE_obj_B12, onButtonClick_obj_B12,
    ID_GCODE_obj_B11, onButtonClick_obj_B11,
    ID_GCODE_obj_B10, onButtonClick_obj_B10,
    ID_GCODE_obj_B9, onButtonClick_obj_B9,
    ID_GCODE_obj_B8, onButtonClick_obj_B8,
    ID_GCODE_obj_B7, onButtonClick_obj_B7,
    ID_GCODE_obj_B6, onButtonClick_obj_B6,
    ID_GCODE_obj_B5, onButtonClick_obj_B5,
    ID_GCODE_obj_B4, onButtonClick_obj_B4,
    ID_GCODE_obj_B3, onButtonClick_obj_B3,
    ID_GCODE_obj_B2, onButtonClick_obj_B2,
    ID_GCODE_obj_B1, onButtonClick_obj_B1,
    ID_GCODE_obj_B0, onButtonClick_obj_B0,
    ID_GCODE_Button101, onButtonClick_Button101,
    ID_GCODE_Button100, onButtonClick_Button100,
    ID_GCODE_Button98, onButtonClick_Button98,
    ID_GCODE_Button50, onButtonClick_Button50,
    ID_GCODE_bed_temp_button, onButtonClick_bed_temp_button,
    ID_GCODE_Stop_Button, onButtonClick_Stop_Button,
    ID_GCODE_Pause_Button, onButtonClick_Pause_Button,
    ID_GCODE_Skip_it_Button, onButtonClick_Skip_it_Button,
    ID_GCODE_Main_Button, onButtonClick_Main_Button,
    ID_GCODE_Layer2_Button, onButtonClick_Layer2_Button,
    ID_GCODE_File_Button, onButtonClick_File_Button,
    ID_GCODE_Button73, onButtonClick_Button73,
    ID_GCODE_Screen_set_Button, onButtonClick_Screen_set_Button,
};
/***************/


typedef void (*SeekBarCallback)(ZKSeekBar *pSeekBar, int progress);
typedef struct {
    int id;
    SeekBarCallback callback;
}S_ZKSeekBarCallback;
/*TAG:SeekBarCallbackTab*/
static S_ZKSeekBarCallback SZKSeekBarCallbackTab[] = {
    ID_GCODE_brightnes_SeekBar, onProgressChanged_brightnes_SeekBar,
    ID_GCODE_Obj_SeekBar, onProgressChanged_Obj_SeekBar,
    ID_GCODE_Print_SeekBar, onProgressChanged_Print_SeekBar,
};


typedef int (*ListViewGetItemCountCallback)(const ZKListView *pListView);
typedef void (*ListViewobtainListItemDataCallback)(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index);
typedef void (*ListViewonItemClickCallback)(ZKListView *pListView, int index, int id);
typedef struct {
    int id;
    ListViewGetItemCountCallback getListItemCountCallback;
    ListViewobtainListItemDataCallback obtainListItemDataCallback;
    ListViewonItemClickCallback onItemClickCallback;
}S_ListViewFunctionsCallback;
/*TAG:ListViewFunctionsCallback*/
static S_ListViewFunctionsCallback SListViewFunctionsCallbackTab[] = {
    ID_GCODE_GPIO_ListView, getListItemCount_GPIO_ListView, obtainListItemData_GPIO_ListView, onListItemClick_GPIO_ListView,
    ID_GCODE_Host_macros_list, getListItemCount_Host_macros_list, obtainListItemData_Host_macros_list, onListItemClick_Host_macros_list,
    ID_GCODE_Customize_ListView, getListItemCount_Customize_ListView, obtainListItemData_Customize_ListView, onListItemClick_Customize_ListView,
    ID_GCODE_ListView1, getListItemCount_ListView1, obtainListItemData_ListView1, onListItemClick_ListView1,
    ID_GCODE_Language_ListView, getListItemCount_Language_ListView, obtainListItemData_Language_ListView, onListItemClick_Language_ListView,
    ID_GCODE_ListViewWifiInfo, getListItemCount_ListViewWifiInfo, obtainListItemData_ListViewWifiInfo, onListItemClick_ListViewWifiInfo,
    ID_GCODE_download_list, getListItemCount_download_list, obtainListItemData_download_list, onListItemClick_download_list,
    ID_GCODE_Print_img_ListView, getListItemCount_Print_img_ListView, obtainListItemData_Print_img_ListView, onListItemClick_Print_img_ListView,
    ID_GCODE_Print_ListView1, getListItemCount_Print_ListView1, obtainListItemData_Print_ListView1, onListItemClick_Print_ListView1,
    ID_GCODE_Time_out_list, getListItemCount_Time_out_list, obtainListItemData_Time_out_list, onListItemClick_Time_out_list,
    ID_GCODE_Notify_ListView, getListItemCount_Notify_ListView, obtainListItemData_Notify_ListView, onListItemClick_Notify_ListView,
    ID_GCODE_COLOR_ListView, getListItemCount_COLOR_ListView, obtainListItemData_COLOR_ListView, onListItemClick_COLOR_ListView,
    ID_GCODE_ListView6, getListItemCount_ListView6, obtainListItemData_ListView6, onListItemClick_ListView6,
    ID_GCODE_ERCF_CA_ListView, getListItemCount_ERCF_CA_ListView, obtainListItemData_ERCF_CA_ListView, onListItemClick_ERCF_CA_ListView,
    ID_GCODE_ERCF_ListView, getListItemCount_ERCF_ListView, obtainListItemData_ERCF_ListView, onListItemClick_ERCF_ListView,
    ID_GCODE_ListView5, getListItemCount_ListView5, obtainListItemData_ListView5, onListItemClick_ListView5,
    ID_GCODE_Print_set_list, getListItemCount_Print_set_list, obtainListItemData_Print_set_list, onListItemClick_Print_set_list,
    ID_GCODE_FileList, getListItemCount_FileList, obtainListItemData_FileList, onListItemClick_FileList,
    ID_GCODE_ListView3, getListItemCount_ListView3, obtainListItemData_ListView3, onListItemClick_ListView3,
    ID_GCODE_ListView2, getListItemCount_ListView2, obtainListItemData_ListView2, onListItemClick_ListView2,
};


typedef void (*SlideWindowItemClickCallback)(ZKSlideWindow *pSlideWindow, int index);
typedef struct {
    int id;
    SlideWindowItemClickCallback onSlideItemClickCallback;
}S_SlideWindowItemClickCallback;
/*TAG:SlideWindowFunctionsCallbackTab*/
static S_SlideWindowItemClickCallback SSlideWindowItemClickCallbackTab[] = {
};


typedef void (*EditTextInputCallback)(const std::string &text);
typedef struct {
    int id;
    EditTextInputCallback onEditTextChangedCallback;
}S_EditTextInputCallback;
/*TAG:EditTextInputCallback*/
static S_EditTextInputCallback SEditTextInputCallbackTab[] = {
    ID_GCODE_EdittextPwd, onEditTextChanged_EdittextPwd,
};

typedef void (*VideoViewCallback)(ZKVideoView *pVideoView, int msg);
typedef struct {
    int id; //VideoView ID
    bool loop; // 是否是轮播类型
    int defaultvolume;//轮播类型时,默认视频音量
    VideoViewCallback onVideoViewCallback;
}S_VideoViewCallback;
/*TAG:VideoViewCallback*/
static S_VideoViewCallback SVideoViewCallbackTab[] = {
};


gcodeActivity::gcodeActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

gcodeActivity::~gcodeActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
    onUI_quit();
    mActivityPtr = NULL;
    mHTTP_WS_BUTTONPtr = NULL;
    mgcode_Button_textPtr = NULL;
    mForc_ButtonPtr = NULL;
    mgcode_Button_pinPtr = NULL;
    mGPIO_ListViewPtr = NULL;
    mHost_macros_listPtr = NULL;
    mButton45Ptr = NULL;
    mZoffset_Up_buttonPtr = NULL;
    mZoffset_Down_buttonPtr = NULL;
    mFile_name_TextViewPtr = NULL;
    mButton58Ptr = NULL;
    mTextView81Ptr = NULL;
    mTextView80Ptr = NULL;
    mButton57Ptr = NULL;
    mtype_ButtonPtr = NULL;
    mgcode_ButtonPtr = NULL;
    mname_ButtonPtr = NULL;
    mCustomize_WindowPtr = NULL;
    mCustomize_ButtonPtr = NULL;
    mTextView79Ptr = NULL;
    mCustomize_ListViewPtr = NULL;
    mDrop_down_menuPtr = NULL;
    mCAM_BED_MESHPtr = NULL;
    mButton_print_Ptr = NULL;
    mButton_Ptr = NULL;
    mButton60Ptr = NULL;
    mButton54Ptr = NULL;
    mButton53Ptr = NULL;
    mButton52Ptr = NULL;
    mButton51Ptr = NULL;
    mButton49Ptr = NULL;
    mButton48Ptr = NULL;
    mButton47Ptr = NULL;
    mButton46Ptr = NULL;
    mButton_zPtr = NULL;
    mButton_yPtr = NULL;
    mButton_xPtr = NULL;
    mButton_wPtr = NULL;
    mButton_vPtr = NULL;
    mButton_uPtr = NULL;
    mButton_tPtr = NULL;
    mButton_sPtr = NULL;
    mButton_rPtr = NULL;
    mButton_qPtr = NULL;
    mButton_pPtr = NULL;
    mButton_oPtr = NULL;
    mButton_nPtr = NULL;
    mButton_mPtr = NULL;
    mButton_lPtr = NULL;
    mButton_kPtr = NULL;
    mButton_jPtr = NULL;
    mButton_iPtr = NULL;
    mButton_hPtr = NULL;
    mButton_gPtr = NULL;
    mButton_fPtr = NULL;
    mButton_ePtr = NULL;
    mButton_dPtr = NULL;
    mButton_cPtr = NULL;
    mButton_bPtr = NULL;
    mButton_aPtr = NULL;
    mButton_9Ptr = NULL;
    mButton_8Ptr = NULL;
    mButton_7Ptr = NULL;
    mButton_6Ptr = NULL;
    mButton_5Ptr = NULL;
    mButton_4Ptr = NULL;
    mButton_3Ptr = NULL;
    mButton_2Ptr = NULL;
    mButton_1Ptr = NULL;
    mButton_0Ptr = NULL;
    mstop_ButtonPtr = NULL;
    mButton62Ptr = NULL;
    mButton61Ptr = NULL;
    mListView1Ptr = NULL;
    mspeed_windowPtr = NULL;
    mspeed_ButtonPtr = NULL;
    mzoffset005_ButtonPtr = NULL;
    mzoffset0025_ButtonPtr = NULL;
    mzoffset001_ButtonPtr = NULL;
    mZ_Offset_Reverse_ButtonPtr = NULL;
    mzoffset0005_ButtonPtr = NULL;
    mLanguage_ListViewPtr = NULL;
    mButton_moto_reversPtr = NULL;
    mButton_unlockPtr = NULL;
    mButton_homePtr = NULL;
    mButton_DelPtr = NULL;
    mButton_PreheatPtr = NULL;
    mButtonForgetPtr = NULL;
    mHost_computer_wifiPtr = NULL;
    mButtonautoconnectPtr = NULL;
    mTextConnectStatePtr = NULL;
    mTextConnectSecTypePtr = NULL;
    mTextConnectSsidPtr = NULL;
    mTextview19Ptr = NULL;
    mTextview17Ptr = NULL;
    mTextview15Ptr = NULL;
    mButtonDisconnectPtr = NULL;
    mWindowDisconnectPtr = NULL;
    mButtonShowPwdPtr = NULL;
    mTextSecTypePtr = NULL;
    mTextSsidPtr = NULL;
    mTextview9Ptr = NULL;
    mTextview7Ptr = NULL;
    mTextview5Ptr = NULL;
    mEdittextPwdPtr = NULL;
    mButtonConnectPtr = NULL;
    mWindowSetPtr = NULL;
    mListViewWifiInfoPtr = NULL;
    mButton36Ptr = NULL;
    mTextView78Ptr = NULL;
    mTextView77Ptr = NULL;
    mTextView65Ptr = NULL;
    mTextView58Ptr = NULL;
    mTextView76Ptr = NULL;
    mopen_notifyPtr = NULL;
    mBuzz_BUTTONPtr = NULL;
    mTextView73Ptr = NULL;
    mms_file_buttonPtr = NULL;
    mSd_buttonPtr = NULL;
    mUdesk_buttonPtr = NULL;
    mdownload_listPtr = NULL;
    mUpdata_Slave_printingPtr = NULL;
    mUpdata_SlavePtr = NULL;
    mPrint_img_ListViewPtr = NULL;
    mPrint_ListView1Ptr = NULL;
    mAnti_touchPtr = NULL;
    mTextView41Ptr = NULL;
    mButton30Ptr = NULL;
    mButton29Ptr = NULL;
    mrestart_layerPtr = NULL;
    mButton28Ptr = NULL;
    mButtonjpdPtr = NULL;
    mButtonjpLPtr = NULL;
    mButton96Ptr = NULL;
    mTextView22Ptr = NULL;
    mButton84Ptr = NULL;
    mButton85Ptr = NULL;
    mButton86Ptr = NULL;
    mButton87Ptr = NULL;
    mButton88Ptr = NULL;
    mButton89Ptr = NULL;
    mButton90Ptr = NULL;
    mButton91Ptr = NULL;
    mButton92Ptr = NULL;
    mButton93Ptr = NULL;
    mButton94Ptr = NULL;
    mAJ_confirm_ButtonPtr = NULL;
    mAJPtr = NULL;
    mButton168Ptr = NULL;
    mButton167Ptr = NULL;
    mButton166Ptr = NULL;
    mButton165Ptr = NULL;
    mButton138Ptr = NULL;
    mButton137Ptr = NULL;
    mButton125Ptr = NULL;
    mTextView44Ptr = NULL;
    mTextView46Ptr = NULL;
    mAJ1Ptr = NULL;
    mButton18Ptr = NULL;
    mTextview50Ptr = NULL;
    mlockPtr = NULL;
    mTextView18Ptr = NULL;
    mButton14Ptr = NULL;
    mButton12Ptr = NULL;
    myes_no_WindowPtr = NULL;
    mTextView30Ptr = NULL;
    mTime_out_listPtr = NULL;
    mTime_out_winPtr = NULL;
    mTextView26Ptr = NULL;
    mTextView24Ptr = NULL;
    mTextView23Ptr = NULL;
    mTextView21Ptr = NULL;
    mButton17Ptr = NULL;
    mButton16Ptr = NULL;
    mButton15Ptr = NULL;
    mTextView28Ptr = NULL;
    mTextView27Ptr = NULL;
    mButton13Ptr = NULL;
    mTextView29Ptr = NULL;
    mbrightnes_SeekBarPtr = NULL;
    mTextView20Ptr = NULL;
    mScreen_set_winPtr = NULL;
    mNotify_ListViewPtr = NULL;
    mCOLOR_ListViewPtr = NULL;
    mTextView72Ptr = NULL;
    mTextView71Ptr = NULL;
    mTextView75Ptr = NULL;
    mERCF_BOWDEN_CA_BUTTONPtr = NULL;
    mTextView74Ptr = NULL;
    mERCF_BOWDEN_BACKPtr = NULL;
    mERCF_BOWDEN_WindowPtr = NULL;
    mERCF_SENSOR_TRUE_BUTTONPtr = NULL;
    mTextView70Ptr = NULL;
    mTextView69Ptr = NULL;
    mERCF_SENSOR_BACKPtr = NULL;
    mencode_viewPtr = NULL;
    mTextView48Ptr = NULL;
    mTextView47Ptr = NULL;
    mERCF_SENSOR_WindowPtr = NULL;
    mTextView68Ptr = NULL;
    mERCF_EX_TRUE_BUTTONPtr = NULL;
    mTextView67Ptr = NULL;
    mERCF_EX_BUTTONPtr = NULL;
    mERCF_EX_BACKPtr = NULL;
    mTextView66Ptr = NULL;
    mTextView64Ptr = NULL;
    mTextView63Ptr = NULL;
    mERCF_EX_WindowPtr = NULL;
    mERCF_MOTOR_OFF1Ptr = NULL;
    mTextView54Ptr = NULL;
    mTextView53Ptr = NULL;
    mListView6Ptr = NULL;
    mERCF_CA_ListViewPtr = NULL;
    mTextView52Ptr = NULL;
    mERCF_TOOOL_CAPtr = NULL;
    mERCF_TOOL_BACKPtr = NULL;
    mTextView51Ptr = NULL;
    mTextView50Ptr = NULL;
    mTextView49Ptr = NULL;
    mERCF_MOTOR_OFF2Ptr = NULL;
    mERCF_TOOL_WindowPtr = NULL;
    mTextView62Ptr = NULL;
    mTextView57Ptr = NULL;
    mERCF_SERVO_UP_ButtonPtr = NULL;
    mTextView61Ptr = NULL;
    mERCF_SERVO_DOWN_ButtonPtr = NULL;
    mTextView60Ptr = NULL;
    mTextView59Ptr = NULL;
    mERCF_SERVO_BACKPtr = NULL;
    mTextView56Ptr = NULL;
    mTextView55Ptr = NULL;
    mERCF_SERVO_WindowPtr = NULL;
    mERCF_CA_BACKPtr = NULL;
    mButton40Ptr = NULL;
    mButton39Ptr = NULL;
    mButton38Ptr = NULL;
    mButton37Ptr = NULL;
    mButton35Ptr = NULL;
    mButton34Ptr = NULL;
    mERCF_CA_WindowPtr = NULL;
    mERCF_HOMEPtr = NULL;
    mERCF_MOTOR_OFFPtr = NULL;
    mERCF_EPtr = NULL;
    mERCF_E_ADDPtr = NULL;
    mERCF_CA_BUTTONPtr = NULL;
    mERCF_ListViewPtr = NULL;
    mERCFPtr = NULL;
    mListView5Ptr = NULL;
    mGcode_layerPtr = NULL;
    mPrint_set_buttonPtr = NULL;
    mButton44Ptr = NULL;
    mButton43Ptr = NULL;
    mButton42Ptr = NULL;
    mButton41Ptr = NULL;
    mButton22Ptr = NULL;
    mTextView32Ptr = NULL;
    mButton21Ptr = NULL;
    mPrint_set_listPtr = NULL;
    mConnect_WindowPtr = NULL;
    mButton19Ptr = NULL;
    mButton31Ptr = NULL;
    mButton20Ptr = NULL;
    mTextView31Ptr = NULL;
    mPrint_Set_WinPtr = NULL;
    mTextView11Ptr = NULL;
    mTextView10Ptr = NULL;
    mTextView9Ptr = NULL;
    mButton7Ptr = NULL;
    mButton4Ptr = NULL;
    mTextView8Ptr = NULL;
    mTextView2Ptr = NULL;
    mprint_surePtr = NULL;
    mFileListPtr = NULL;
    mFile_Refresh_buttonPtr = NULL;
    mTextView14Ptr = NULL;
    mfilePtr = NULL;
    mTextView40Ptr = NULL;
    mListView3Ptr = NULL;
    mTextView39Ptr = NULL;
    mButton27Ptr = NULL;
    mListView2Ptr = NULL;
    mcur_jz_WinPtr = NULL;
    mButton26Ptr = NULL;
    mTextView38Ptr = NULL;
    mTextView33Ptr = NULL;
    mButton25Ptr = NULL;
    mButton24Ptr = NULL;
    mButton23Ptr = NULL;
    mButton6Ptr = NULL;
    mjz_win_close_buttonPtr = NULL;
    mButton80Ptr = NULL;
    mButton82Ptr = NULL;
    mButton81Ptr = NULL;
    mButton79Ptr = NULL;
    mButton77Ptr = NULL;
    mButton76Ptr = NULL;
    mButton75Ptr = NULL;
    mButton59Ptr = NULL;
    mTextView5Ptr = NULL;
    mTextView13Ptr = NULL;
    mjz_WindowPtr = NULL;
    mtemp_move_ButtonPtr = NULL;
    mTool_ButtonPtr = NULL;
    mTextView37Ptr = NULL;
    mhc_hg_ButtonPtr = NULL;
    mJZ_ButtonPtr = NULL;
    mtoolPtr = NULL;
    mFAN3_DOWNPtr = NULL;
    mFAN3_UPPtr = NULL;
    mFAN2_DOWNPtr = NULL;
    mFAN2_UPPtr = NULL;
    mFAN1_DOWNPtr = NULL;
    mFAN1_UPPtr = NULL;
    mFAN2_ViewPtr = NULL;
    mFAN1_ViewPtr = NULL;
    mFAN0_ViewPtr = NULL;
    mFAN3_ICONPtr = NULL;
    mFAN2_ICONPtr = NULL;
    mFAN1_ICONPtr = NULL;
    mFAN3_SW_ButtonPtr = NULL;
    mFAN2_SW_ButtonPtr = NULL;
    mFAN1_SW_ButtonPtr = NULL;
    mFan2_PointerPtr = NULL;
    mFan1_PointerPtr = NULL;
    mFan0_PointerPtr = NULL;
    mFAN_WindowPtr = NULL;
    mButton11Ptr = NULL;
    mButton10Ptr = NULL;
    mButton9Ptr = NULL;
    mButton8Ptr = NULL;
    mTextView15Ptr = NULL;
    mprint_speed_WindowPtr = NULL;
    mFan_layer_open_buttonPtr = NULL;
    mlayer2_speed_buttonPtr = NULL;
    mButton103Ptr = NULL;
    mlyayer2_bed_temp_buttonPtr = NULL;
    mlyayer2_nozzle_temp_buttonPtr = NULL;
    mY_D1_BUTTONPtr = NULL;
    mY_D10_BUTTONPtr = NULL;
    mY_U1_BUTTONPtr = NULL;
    mY_U10_BUTTONPtr = NULL;
    mX_D1_BUTTONPtr = NULL;
    mX_D10_BUTTONPtr = NULL;
    mX_U1_BUTTONPtr = NULL;
    mX_U10_BUTTONPtr = NULL;
    mButton3Ptr = NULL;
    mButton1Ptr = NULL;
    mButton68Ptr = NULL;
    mButton66Ptr = NULL;
    mTextView36Ptr = NULL;
    mTextView35Ptr = NULL;
    mTextView34Ptr = NULL;
    mButton56Ptr = NULL;
    mButton2Ptr = NULL;
    mButton55Ptr = NULL;
    mWarehouse_Temperature_ViewPtr = NULL;
    mBed_Temp_ViewPtr = NULL;
    mNozzle_Temp_ViewPtr = NULL;
    mMove_button_backgroundPtr = NULL;
    mTextView12Ptr = NULL;
    mTextView16Ptr = NULL;
    mwhmovePtr = NULL;
    mmovePtr = NULL;
    mTextView19Ptr = NULL;
    mButton5Ptr = NULL;
    mObj_SeekBarPtr = NULL;
    mobj_B30Ptr = NULL;
    mobj_B29Ptr = NULL;
    mobj_B28Ptr = NULL;
    mobj_B27Ptr = NULL;
    mobj_B26Ptr = NULL;
    mobj_B25Ptr = NULL;
    mobj_B24Ptr = NULL;
    mobj_B23Ptr = NULL;
    mobj_B22Ptr = NULL;
    mobj_B21Ptr = NULL;
    mobj_B20Ptr = NULL;
    mobj_B19Ptr = NULL;
    mobj_B18Ptr = NULL;
    mobj_B17Ptr = NULL;
    mobj_B16Ptr = NULL;
    mobj_B15Ptr = NULL;
    mobj_B14Ptr = NULL;
    mobj_B13Ptr = NULL;
    mobj_B12Ptr = NULL;
    mobj_B11Ptr = NULL;
    mobj_B10Ptr = NULL;
    mobj_B9Ptr = NULL;
    mobj_B8Ptr = NULL;
    mobj_B7Ptr = NULL;
    mobj_B6Ptr = NULL;
    mobj_B5Ptr = NULL;
    mobj_B4Ptr = NULL;
    mobj_B3Ptr = NULL;
    mobj_B2Ptr = NULL;
    mobj_B1Ptr = NULL;
    mobj_B0Ptr = NULL;
    mExclude_Object_window2Ptr = NULL;
    mExclude_Object_windowPtr = NULL;
    mButton101Ptr = NULL;
    mButton100Ptr = NULL;
    mButton98Ptr = NULL;
    mButton50Ptr = NULL;
    mbed_temp_buttonPtr = NULL;
    mTextView7Ptr = NULL;
    mTextView45Ptr = NULL;
    mTextView43Ptr = NULL;
    mTextView42Ptr = NULL;
    mTextView17Ptr = NULL;
    mStop_ButtonPtr = NULL;
    mPause_ButtonPtr = NULL;
    mSkip_it_ButtonPtr = NULL;
    mPrint_SeekBarPtr = NULL;
    mthumbnail_pngPtr = NULL;
    mTextView4Ptr = NULL;
    mTextView3Ptr = NULL;
    mTextView1Ptr = NULL;
    mprintPtr = NULL;
    mTextView6Ptr = NULL;
    mhomePtr = NULL;
    mMain_ButtonPtr = NULL;
    mLayer2_ButtonPtr = NULL;
    mFile_ButtonPtr = NULL;
    mButton73Ptr = NULL;
    mScreen_set_ButtonPtr = NULL;
    mTextView25Ptr = NULL;
}

const char* gcodeActivity::getAppName() const{
	return "gcode.ftu";
}

//TAG:onCreate
void gcodeActivity::onCreate() {
	Activity::onCreate();
    mHTTP_WS_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_HTTP_WS_BUTTON);
    mgcode_Button_textPtr = (ZKTextView*)findControlByID(ID_GCODE_gcode_Button_text);
    mForc_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Forc_Button);
    mgcode_Button_pinPtr = (ZKButton*)findControlByID(ID_GCODE_gcode_Button_pin);
    mGPIO_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_GPIO_ListView);if(mGPIO_ListViewPtr!= NULL){mGPIO_ListViewPtr->setListAdapter(this);mGPIO_ListViewPtr->setItemClickListener(this);}
    mHost_macros_listPtr = (ZKListView*)findControlByID(ID_GCODE_Host_macros_list);if(mHost_macros_listPtr!= NULL){mHost_macros_listPtr->setListAdapter(this);mHost_macros_listPtr->setItemClickListener(this);}
    mButton45Ptr = (ZKButton*)findControlByID(ID_GCODE_Button45);
    mZoffset_Up_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_Zoffset_Up_button);
    mZoffset_Down_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_Zoffset_Down_button);
    mFile_name_TextViewPtr = (ZKTextView*)findControlByID(ID_GCODE_File_name_TextView);
    mButton58Ptr = (ZKButton*)findControlByID(ID_GCODE_Button58);
    mTextView81Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView81);
    mTextView80Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView80);
    mButton57Ptr = (ZKButton*)findControlByID(ID_GCODE_Button57);
    mtype_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_type_Button);
    mgcode_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_gcode_Button);
    mname_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_name_Button);
    mCustomize_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_Customize_Window);
    mCustomize_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Customize_Button);
    mTextView79Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView79);
    mCustomize_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_Customize_ListView);if(mCustomize_ListViewPtr!= NULL){mCustomize_ListViewPtr->setListAdapter(this);mCustomize_ListViewPtr->setItemClickListener(this);}
    mDrop_down_menuPtr = (ZKWindow*)findControlByID(ID_GCODE_Drop_down_menu);
    mCAM_BED_MESHPtr = (ZKWindow*)findControlByID(ID_GCODE_CAM_BED_MESH);
    mButton_print_Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_print_);
    mButton_Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_);
    mButton60Ptr = (ZKButton*)findControlByID(ID_GCODE_Button60);
    mButton54Ptr = (ZKButton*)findControlByID(ID_GCODE_Button54);
    mButton53Ptr = (ZKButton*)findControlByID(ID_GCODE_Button53);
    mButton52Ptr = (ZKButton*)findControlByID(ID_GCODE_Button52);
    mButton51Ptr = (ZKButton*)findControlByID(ID_GCODE_Button51);
    mButton49Ptr = (ZKButton*)findControlByID(ID_GCODE_Button49);
    mButton48Ptr = (ZKButton*)findControlByID(ID_GCODE_Button48);
    mButton47Ptr = (ZKButton*)findControlByID(ID_GCODE_Button47);
    mButton46Ptr = (ZKButton*)findControlByID(ID_GCODE_Button46);
    mButton_zPtr = (ZKButton*)findControlByID(ID_GCODE_Button_z);
    mButton_yPtr = (ZKButton*)findControlByID(ID_GCODE_Button_y);
    mButton_xPtr = (ZKButton*)findControlByID(ID_GCODE_Button_x);
    mButton_wPtr = (ZKButton*)findControlByID(ID_GCODE_Button_w);
    mButton_vPtr = (ZKButton*)findControlByID(ID_GCODE_Button_v);
    mButton_uPtr = (ZKButton*)findControlByID(ID_GCODE_Button_u);
    mButton_tPtr = (ZKButton*)findControlByID(ID_GCODE_Button_t);
    mButton_sPtr = (ZKButton*)findControlByID(ID_GCODE_Button_s);
    mButton_rPtr = (ZKButton*)findControlByID(ID_GCODE_Button_r);
    mButton_qPtr = (ZKButton*)findControlByID(ID_GCODE_Button_q);
    mButton_pPtr = (ZKButton*)findControlByID(ID_GCODE_Button_p);
    mButton_oPtr = (ZKButton*)findControlByID(ID_GCODE_Button_o);
    mButton_nPtr = (ZKButton*)findControlByID(ID_GCODE_Button_n);
    mButton_mPtr = (ZKButton*)findControlByID(ID_GCODE_Button_m);
    mButton_lPtr = (ZKButton*)findControlByID(ID_GCODE_Button_l);
    mButton_kPtr = (ZKButton*)findControlByID(ID_GCODE_Button_k);
    mButton_jPtr = (ZKButton*)findControlByID(ID_GCODE_Button_j);
    mButton_iPtr = (ZKButton*)findControlByID(ID_GCODE_Button_i);
    mButton_hPtr = (ZKButton*)findControlByID(ID_GCODE_Button_h);
    mButton_gPtr = (ZKButton*)findControlByID(ID_GCODE_Button_g);
    mButton_fPtr = (ZKButton*)findControlByID(ID_GCODE_Button_f);
    mButton_ePtr = (ZKButton*)findControlByID(ID_GCODE_Button_e);
    mButton_dPtr = (ZKButton*)findControlByID(ID_GCODE_Button_d);
    mButton_cPtr = (ZKButton*)findControlByID(ID_GCODE_Button_c);
    mButton_bPtr = (ZKButton*)findControlByID(ID_GCODE_Button_b);
    mButton_aPtr = (ZKButton*)findControlByID(ID_GCODE_Button_a);
    mButton_9Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_9);
    mButton_8Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_8);
    mButton_7Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_7);
    mButton_6Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_6);
    mButton_5Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_5);
    mButton_4Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_4);
    mButton_3Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_3);
    mButton_2Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_2);
    mButton_1Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_1);
    mButton_0Ptr = (ZKButton*)findControlByID(ID_GCODE_Button_0);
    mstop_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_stop_Button);
    mButton62Ptr = (ZKButton*)findControlByID(ID_GCODE_Button62);
    mButton61Ptr = (ZKButton*)findControlByID(ID_GCODE_Button61);
    mListView1Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView1);if(mListView1Ptr!= NULL){mListView1Ptr->setListAdapter(this);mListView1Ptr->setItemClickListener(this);}
    mspeed_windowPtr = (ZKWindow*)findControlByID(ID_GCODE_speed_window);
    mspeed_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_speed_Button);
    mzoffset005_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_zoffset005_Button);
    mzoffset0025_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_zoffset0025_Button);
    mzoffset001_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_zoffset001_Button);
    mZ_Offset_Reverse_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Z_Offset_Reverse_Button);
    mzoffset0005_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_zoffset0005_Button);
    mLanguage_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_Language_ListView);if(mLanguage_ListViewPtr!= NULL){mLanguage_ListViewPtr->setListAdapter(this);mLanguage_ListViewPtr->setItemClickListener(this);}
    mButton_moto_reversPtr = (ZKButton*)findControlByID(ID_GCODE_Button_moto_revers);
    mButton_unlockPtr = (ZKButton*)findControlByID(ID_GCODE_Button_unlock);
    mButton_homePtr = (ZKButton*)findControlByID(ID_GCODE_Button_home);
    mButton_DelPtr = (ZKButton*)findControlByID(ID_GCODE_Button_Del);
    mButton_PreheatPtr = (ZKButton*)findControlByID(ID_GCODE_Button_Preheat);
    mButtonForgetPtr = (ZKButton*)findControlByID(ID_GCODE_ButtonForget);
    mHost_computer_wifiPtr = (ZKWindow*)findControlByID(ID_GCODE_Host_computer_wifi);
    mButtonautoconnectPtr = (ZKButton*)findControlByID(ID_GCODE_Buttonautoconnect);
    mTextConnectStatePtr = (ZKTextView*)findControlByID(ID_GCODE_TextConnectState);
    mTextConnectSecTypePtr = (ZKTextView*)findControlByID(ID_GCODE_TextConnectSecType);
    mTextConnectSsidPtr = (ZKTextView*)findControlByID(ID_GCODE_TextConnectSsid);
    mTextview19Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview19);
    mTextview17Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview17);
    mTextview15Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview15);
    mButtonDisconnectPtr = (ZKButton*)findControlByID(ID_GCODE_ButtonDisconnect);
    mWindowDisconnectPtr = (ZKWindow*)findControlByID(ID_GCODE_WindowDisconnect);
    mButtonShowPwdPtr = (ZKButton*)findControlByID(ID_GCODE_ButtonShowPwd);
    mTextSecTypePtr = (ZKTextView*)findControlByID(ID_GCODE_TextSecType);
    mTextSsidPtr = (ZKTextView*)findControlByID(ID_GCODE_TextSsid);
    mTextview9Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview9);
    mTextview7Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview7);
    mTextview5Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview5);
    mEdittextPwdPtr = (ZKEditText*)findControlByID(ID_GCODE_EdittextPwd);if(mEdittextPwdPtr!= NULL){mEdittextPwdPtr->setTextChangeListener(this);}
    mButtonConnectPtr = (ZKButton*)findControlByID(ID_GCODE_ButtonConnect);
    mWindowSetPtr = (ZKWindow*)findControlByID(ID_GCODE_WindowSet);
    mListViewWifiInfoPtr = (ZKListView*)findControlByID(ID_GCODE_ListViewWifiInfo);if(mListViewWifiInfoPtr!= NULL){mListViewWifiInfoPtr->setListAdapter(this);mListViewWifiInfoPtr->setItemClickListener(this);}
    mButton36Ptr = (ZKButton*)findControlByID(ID_GCODE_Button36);
    mTextView78Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView78);
    mTextView77Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView77);
    mTextView65Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView65);
    mTextView58Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView58);
    mTextView76Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView76);
    mopen_notifyPtr = (ZKButton*)findControlByID(ID_GCODE_open_notify);
    mBuzz_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_Buzz_BUTTON);
    mTextView73Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView73);
    mms_file_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_ms_file_button);
    mSd_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_Sd_button);
    mUdesk_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_Udesk_button);
    mdownload_listPtr = (ZKListView*)findControlByID(ID_GCODE_download_list);if(mdownload_listPtr!= NULL){mdownload_listPtr->setListAdapter(this);mdownload_listPtr->setItemClickListener(this);}
    mUpdata_Slave_printingPtr = (ZKButton*)findControlByID(ID_GCODE_Updata_Slave_printing);
    mUpdata_SlavePtr = (ZKButton*)findControlByID(ID_GCODE_Updata_Slave);
    mPrint_img_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_Print_img_ListView);if(mPrint_img_ListViewPtr!= NULL){mPrint_img_ListViewPtr->setListAdapter(this);mPrint_img_ListViewPtr->setItemClickListener(this);}
    mPrint_ListView1Ptr = (ZKListView*)findControlByID(ID_GCODE_Print_ListView1);if(mPrint_ListView1Ptr!= NULL){mPrint_ListView1Ptr->setListAdapter(this);mPrint_ListView1Ptr->setItemClickListener(this);}
    mAnti_touchPtr = (ZKWindow*)findControlByID(ID_GCODE_Anti_touch);
    mTextView41Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView41);
    mButton30Ptr = (ZKButton*)findControlByID(ID_GCODE_Button30);
    mButton29Ptr = (ZKButton*)findControlByID(ID_GCODE_Button29);
    mrestart_layerPtr = (ZKWindow*)findControlByID(ID_GCODE_restart_layer);
    mButton28Ptr = (ZKButton*)findControlByID(ID_GCODE_Button28);
    mButtonjpdPtr = (ZKButton*)findControlByID(ID_GCODE_Buttonjpd);
    mButtonjpLPtr = (ZKButton*)findControlByID(ID_GCODE_ButtonjpL);
    mButton96Ptr = (ZKButton*)findControlByID(ID_GCODE_Button96);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView22);
    mButton84Ptr = (ZKButton*)findControlByID(ID_GCODE_Button84);
    mButton85Ptr = (ZKButton*)findControlByID(ID_GCODE_Button85);
    mButton86Ptr = (ZKButton*)findControlByID(ID_GCODE_Button86);
    mButton87Ptr = (ZKButton*)findControlByID(ID_GCODE_Button87);
    mButton88Ptr = (ZKButton*)findControlByID(ID_GCODE_Button88);
    mButton89Ptr = (ZKButton*)findControlByID(ID_GCODE_Button89);
    mButton90Ptr = (ZKButton*)findControlByID(ID_GCODE_Button90);
    mButton91Ptr = (ZKButton*)findControlByID(ID_GCODE_Button91);
    mButton92Ptr = (ZKButton*)findControlByID(ID_GCODE_Button92);
    mButton93Ptr = (ZKButton*)findControlByID(ID_GCODE_Button93);
    mButton94Ptr = (ZKButton*)findControlByID(ID_GCODE_Button94);
    mAJ_confirm_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_AJ_confirm_Button);
    mAJPtr = (ZKWindow*)findControlByID(ID_GCODE_AJ);
    mButton168Ptr = (ZKButton*)findControlByID(ID_GCODE_Button168);
    mButton167Ptr = (ZKButton*)findControlByID(ID_GCODE_Button167);
    mButton166Ptr = (ZKButton*)findControlByID(ID_GCODE_Button166);
    mButton165Ptr = (ZKButton*)findControlByID(ID_GCODE_Button165);
    mButton138Ptr = (ZKButton*)findControlByID(ID_GCODE_Button138);
    mButton137Ptr = (ZKButton*)findControlByID(ID_GCODE_Button137);
    mButton125Ptr = (ZKButton*)findControlByID(ID_GCODE_Button125);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView44);
    mTextView46Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView46);
    mAJ1Ptr = (ZKWindow*)findControlByID(ID_GCODE_AJ1);
    mButton18Ptr = (ZKButton*)findControlByID(ID_GCODE_Button18);
    mTextview50Ptr = (ZKTextView*)findControlByID(ID_GCODE_Textview50);
    mlockPtr = (ZKWindow*)findControlByID(ID_GCODE_lock);
    mTextView18Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView18);
    mButton14Ptr = (ZKButton*)findControlByID(ID_GCODE_Button14);
    mButton12Ptr = (ZKButton*)findControlByID(ID_GCODE_Button12);
    myes_no_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_yes_no_Window);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView30);
    mTime_out_listPtr = (ZKListView*)findControlByID(ID_GCODE_Time_out_list);if(mTime_out_listPtr!= NULL){mTime_out_listPtr->setListAdapter(this);mTime_out_listPtr->setItemClickListener(this);}
    mTime_out_winPtr = (ZKWindow*)findControlByID(ID_GCODE_Time_out_win);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView26);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView24);
    mTextView23Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView23);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView21);
    mButton17Ptr = (ZKButton*)findControlByID(ID_GCODE_Button17);
    mButton16Ptr = (ZKButton*)findControlByID(ID_GCODE_Button16);
    mButton15Ptr = (ZKButton*)findControlByID(ID_GCODE_Button15);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView28);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView27);
    mButton13Ptr = (ZKButton*)findControlByID(ID_GCODE_Button13);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView29);
    mbrightnes_SeekBarPtr = (ZKSeekBar*)findControlByID(ID_GCODE_brightnes_SeekBar);if(mbrightnes_SeekBarPtr!= NULL){mbrightnes_SeekBarPtr->setSeekBarChangeListener(this);}
    mTextView20Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView20);
    mScreen_set_winPtr = (ZKWindow*)findControlByID(ID_GCODE_Screen_set_win);
    mNotify_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_Notify_ListView);if(mNotify_ListViewPtr!= NULL){mNotify_ListViewPtr->setListAdapter(this);mNotify_ListViewPtr->setItemClickListener(this);}
    mCOLOR_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_COLOR_ListView);if(mCOLOR_ListViewPtr!= NULL){mCOLOR_ListViewPtr->setListAdapter(this);mCOLOR_ListViewPtr->setItemClickListener(this);}
    mTextView72Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView72);
    mTextView71Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView71);
    mTextView75Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView75);
    mERCF_BOWDEN_CA_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_BOWDEN_CA_BUTTON);
    mTextView74Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView74);
    mERCF_BOWDEN_BACKPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_BOWDEN_BACK);
    mERCF_BOWDEN_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF_BOWDEN_Window);
    mERCF_SENSOR_TRUE_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_SENSOR_TRUE_BUTTON);
    mTextView70Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView70);
    mTextView69Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView69);
    mERCF_SENSOR_BACKPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_SENSOR_BACK);
    mencode_viewPtr = (ZKTextView*)findControlByID(ID_GCODE_encode_view);
    mTextView48Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView48);
    mTextView47Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView47);
    mERCF_SENSOR_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF_SENSOR_Window);
    mTextView68Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView68);
    mERCF_EX_TRUE_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_EX_TRUE_BUTTON);
    mTextView67Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView67);
    mERCF_EX_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_EX_BUTTON);
    mERCF_EX_BACKPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_EX_BACK);
    mTextView66Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView66);
    mTextView64Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView64);
    mTextView63Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView63);
    mERCF_EX_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF_EX_Window);
    mERCF_MOTOR_OFF1Ptr = (ZKButton*)findControlByID(ID_GCODE_ERCF_MOTOR_OFF1);
    mTextView54Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView54);
    mTextView53Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView53);
    mListView6Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView6);if(mListView6Ptr!= NULL){mListView6Ptr->setListAdapter(this);mListView6Ptr->setItemClickListener(this);}
    mERCF_CA_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_ERCF_CA_ListView);if(mERCF_CA_ListViewPtr!= NULL){mERCF_CA_ListViewPtr->setListAdapter(this);mERCF_CA_ListViewPtr->setItemClickListener(this);}
    mTextView52Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView52);
    mERCF_TOOOL_CAPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_TOOOL_CA);
    mERCF_TOOL_BACKPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_TOOL_BACK);
    mTextView51Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView51);
    mTextView50Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView50);
    mTextView49Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView49);
    mERCF_MOTOR_OFF2Ptr = (ZKButton*)findControlByID(ID_GCODE_ERCF_MOTOR_OFF2);
    mERCF_TOOL_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF_TOOL_Window);
    mTextView62Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView62);
    mTextView57Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView57);
    mERCF_SERVO_UP_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_SERVO_UP_Button);
    mTextView61Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView61);
    mERCF_SERVO_DOWN_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_SERVO_DOWN_Button);
    mTextView60Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView60);
    mTextView59Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView59);
    mERCF_SERVO_BACKPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_SERVO_BACK);
    mTextView56Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView56);
    mTextView55Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView55);
    mERCF_SERVO_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF_SERVO_Window);
    mERCF_CA_BACKPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_CA_BACK);
    mButton40Ptr = (ZKButton*)findControlByID(ID_GCODE_Button40);
    mButton39Ptr = (ZKButton*)findControlByID(ID_GCODE_Button39);
    mButton38Ptr = (ZKButton*)findControlByID(ID_GCODE_Button38);
    mButton37Ptr = (ZKButton*)findControlByID(ID_GCODE_Button37);
    mButton35Ptr = (ZKButton*)findControlByID(ID_GCODE_Button35);
    mButton34Ptr = (ZKButton*)findControlByID(ID_GCODE_Button34);
    mERCF_CA_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF_CA_Window);
    mERCF_HOMEPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_HOME);
    mERCF_MOTOR_OFFPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_MOTOR_OFF);
    mERCF_EPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_E);
    mERCF_E_ADDPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_E_ADD);
    mERCF_CA_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_ERCF_CA_BUTTON);
    mERCF_ListViewPtr = (ZKListView*)findControlByID(ID_GCODE_ERCF_ListView);if(mERCF_ListViewPtr!= NULL){mERCF_ListViewPtr->setListAdapter(this);mERCF_ListViewPtr->setItemClickListener(this);}
    mERCFPtr = (ZKWindow*)findControlByID(ID_GCODE_ERCF);
    mListView5Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView5);if(mListView5Ptr!= NULL){mListView5Ptr->setListAdapter(this);mListView5Ptr->setItemClickListener(this);}
    mGcode_layerPtr = (ZKWindow*)findControlByID(ID_GCODE_Gcode_layer);
    mPrint_set_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_Print_set_button);
    mButton44Ptr = (ZKButton*)findControlByID(ID_GCODE_Button44);
    mButton43Ptr = (ZKButton*)findControlByID(ID_GCODE_Button43);
    mButton42Ptr = (ZKButton*)findControlByID(ID_GCODE_Button42);
    mButton41Ptr = (ZKButton*)findControlByID(ID_GCODE_Button41);
    mButton22Ptr = (ZKButton*)findControlByID(ID_GCODE_Button22);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView32);
    mButton21Ptr = (ZKButton*)findControlByID(ID_GCODE_Button21);
    mPrint_set_listPtr = (ZKListView*)findControlByID(ID_GCODE_Print_set_list);if(mPrint_set_listPtr!= NULL){mPrint_set_listPtr->setListAdapter(this);mPrint_set_listPtr->setItemClickListener(this);}
    mConnect_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_Connect_Window);
    mButton19Ptr = (ZKButton*)findControlByID(ID_GCODE_Button19);
    mButton31Ptr = (ZKButton*)findControlByID(ID_GCODE_Button31);
    mButton20Ptr = (ZKButton*)findControlByID(ID_GCODE_Button20);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView31);
    mPrint_Set_WinPtr = (ZKWindow*)findControlByID(ID_GCODE_Print_Set_Win);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView10);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView9);
    mButton7Ptr = (ZKButton*)findControlByID(ID_GCODE_Button7);
    mButton4Ptr = (ZKButton*)findControlByID(ID_GCODE_Button4);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView8);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView2);
    mprint_surePtr = (ZKWindow*)findControlByID(ID_GCODE_print_sure);
    mFileListPtr = (ZKListView*)findControlByID(ID_GCODE_FileList);if(mFileListPtr!= NULL){mFileListPtr->setListAdapter(this);mFileListPtr->setItemClickListener(this);}
    mFile_Refresh_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_File_Refresh_button);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView14);
    mfilePtr = (ZKWindow*)findControlByID(ID_GCODE_file);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView40);
    mListView3Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView3);if(mListView3Ptr!= NULL){mListView3Ptr->setListAdapter(this);mListView3Ptr->setItemClickListener(this);}
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView39);
    mButton27Ptr = (ZKButton*)findControlByID(ID_GCODE_Button27);
    mListView2Ptr = (ZKListView*)findControlByID(ID_GCODE_ListView2);if(mListView2Ptr!= NULL){mListView2Ptr->setListAdapter(this);mListView2Ptr->setItemClickListener(this);}
    mcur_jz_WinPtr = (ZKWindow*)findControlByID(ID_GCODE_cur_jz_Win);
    mButton26Ptr = (ZKButton*)findControlByID(ID_GCODE_Button26);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView38);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView33);
    mButton25Ptr = (ZKButton*)findControlByID(ID_GCODE_Button25);
    mButton24Ptr = (ZKButton*)findControlByID(ID_GCODE_Button24);
    mButton23Ptr = (ZKButton*)findControlByID(ID_GCODE_Button23);
    mButton6Ptr = (ZKButton*)findControlByID(ID_GCODE_Button6);
    mjz_win_close_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_jz_win_close_button);
    mButton80Ptr = (ZKButton*)findControlByID(ID_GCODE_Button80);
    mButton82Ptr = (ZKButton*)findControlByID(ID_GCODE_Button82);
    mButton81Ptr = (ZKButton*)findControlByID(ID_GCODE_Button81);
    mButton79Ptr = (ZKButton*)findControlByID(ID_GCODE_Button79);
    mButton77Ptr = (ZKButton*)findControlByID(ID_GCODE_Button77);
    mButton76Ptr = (ZKButton*)findControlByID(ID_GCODE_Button76);
    mButton75Ptr = (ZKButton*)findControlByID(ID_GCODE_Button75);
    mButton59Ptr = (ZKButton*)findControlByID(ID_GCODE_Button59);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView5);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView13);
    mjz_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_jz_Window);
    mtemp_move_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_temp_move_Button);
    mTool_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Tool_Button);
    mTextView37Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView37);
    mhc_hg_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_hc_hg_Button);
    mJZ_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_JZ_Button);
    mtoolPtr = (ZKWindow*)findControlByID(ID_GCODE_tool);
    mFAN3_DOWNPtr = (ZKButton*)findControlByID(ID_GCODE_FAN3_DOWN);
    mFAN3_UPPtr = (ZKButton*)findControlByID(ID_GCODE_FAN3_UP);
    mFAN2_DOWNPtr = (ZKButton*)findControlByID(ID_GCODE_FAN2_DOWN);
    mFAN2_UPPtr = (ZKButton*)findControlByID(ID_GCODE_FAN2_UP);
    mFAN1_DOWNPtr = (ZKButton*)findControlByID(ID_GCODE_FAN1_DOWN);
    mFAN1_UPPtr = (ZKButton*)findControlByID(ID_GCODE_FAN1_UP);
    mFAN2_ViewPtr = (ZKTextView*)findControlByID(ID_GCODE_FAN2_View);
    mFAN1_ViewPtr = (ZKTextView*)findControlByID(ID_GCODE_FAN1_View);
    mFAN0_ViewPtr = (ZKTextView*)findControlByID(ID_GCODE_FAN0_View);
    mFAN3_ICONPtr = (ZKButton*)findControlByID(ID_GCODE_FAN3_ICON);
    mFAN2_ICONPtr = (ZKButton*)findControlByID(ID_GCODE_FAN2_ICON);
    mFAN1_ICONPtr = (ZKButton*)findControlByID(ID_GCODE_FAN1_ICON);
    mFAN3_SW_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_FAN3_SW_Button);
    mFAN2_SW_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_FAN2_SW_Button);
    mFAN1_SW_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_FAN1_SW_Button);
    mFan2_PointerPtr = (ZKPointer*)findControlByID(ID_GCODE_Fan2_Pointer);
    mFan1_PointerPtr = (ZKPointer*)findControlByID(ID_GCODE_Fan1_Pointer);
    mFan0_PointerPtr = (ZKPointer*)findControlByID(ID_GCODE_Fan0_Pointer);
    mFAN_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_FAN_Window);
    mButton11Ptr = (ZKButton*)findControlByID(ID_GCODE_Button11);
    mButton10Ptr = (ZKButton*)findControlByID(ID_GCODE_Button10);
    mButton9Ptr = (ZKButton*)findControlByID(ID_GCODE_Button9);
    mButton8Ptr = (ZKButton*)findControlByID(ID_GCODE_Button8);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView15);
    mprint_speed_WindowPtr = (ZKWindow*)findControlByID(ID_GCODE_print_speed_Window);
    mFan_layer_open_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_Fan_layer_open_button);
    mlayer2_speed_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_layer2_speed_button);
    mButton103Ptr = (ZKButton*)findControlByID(ID_GCODE_Button103);
    mlyayer2_bed_temp_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_lyayer2_bed_temp_button);
    mlyayer2_nozzle_temp_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_lyayer2_nozzle_temp_button);
    mY_D1_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_Y_D1_BUTTON);
    mY_D10_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_Y_D10_BUTTON);
    mY_U1_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_Y_U1_BUTTON);
    mY_U10_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_Y_U10_BUTTON);
    mX_D1_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_X_D1_BUTTON);
    mX_D10_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_X_D10_BUTTON);
    mX_U1_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_X_U1_BUTTON);
    mX_U10_BUTTONPtr = (ZKButton*)findControlByID(ID_GCODE_X_U10_BUTTON);
    mButton3Ptr = (ZKButton*)findControlByID(ID_GCODE_Button3);
    mButton1Ptr = (ZKButton*)findControlByID(ID_GCODE_Button1);
    mButton68Ptr = (ZKButton*)findControlByID(ID_GCODE_Button68);
    mButton66Ptr = (ZKButton*)findControlByID(ID_GCODE_Button66);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView36);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView34);
    mButton56Ptr = (ZKButton*)findControlByID(ID_GCODE_Button56);
    mButton2Ptr = (ZKButton*)findControlByID(ID_GCODE_Button2);
    mButton55Ptr = (ZKButton*)findControlByID(ID_GCODE_Button55);
    mWarehouse_Temperature_ViewPtr = (ZKTextView*)findControlByID(ID_GCODE_Warehouse_Temperature_View);
    mBed_Temp_ViewPtr = (ZKTextView*)findControlByID(ID_GCODE_Bed_Temp_View);
    mNozzle_Temp_ViewPtr = (ZKTextView*)findControlByID(ID_GCODE_Nozzle_Temp_View);
    mMove_button_backgroundPtr = (ZKTextView*)findControlByID(ID_GCODE_Move_button_background);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView12);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView16);
    mwhmovePtr = (ZKWindow*)findControlByID(ID_GCODE_whmove);
    mmovePtr = (ZKWindow*)findControlByID(ID_GCODE_move);
    mTextView19Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView19);
    mButton5Ptr = (ZKButton*)findControlByID(ID_GCODE_Button5);
    mObj_SeekBarPtr = (ZKSeekBar*)findControlByID(ID_GCODE_Obj_SeekBar);if(mObj_SeekBarPtr!= NULL){mObj_SeekBarPtr->setSeekBarChangeListener(this);}
    mobj_B30Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B30);
    mobj_B29Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B29);
    mobj_B28Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B28);
    mobj_B27Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B27);
    mobj_B26Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B26);
    mobj_B25Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B25);
    mobj_B24Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B24);
    mobj_B23Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B23);
    mobj_B22Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B22);
    mobj_B21Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B21);
    mobj_B20Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B20);
    mobj_B19Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B19);
    mobj_B18Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B18);
    mobj_B17Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B17);
    mobj_B16Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B16);
    mobj_B15Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B15);
    mobj_B14Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B14);
    mobj_B13Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B13);
    mobj_B12Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B12);
    mobj_B11Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B11);
    mobj_B10Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B10);
    mobj_B9Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B9);
    mobj_B8Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B8);
    mobj_B7Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B7);
    mobj_B6Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B6);
    mobj_B5Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B5);
    mobj_B4Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B4);
    mobj_B3Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B3);
    mobj_B2Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B2);
    mobj_B1Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B1);
    mobj_B0Ptr = (ZKButton*)findControlByID(ID_GCODE_obj_B0);
    mExclude_Object_window2Ptr = (ZKWindow*)findControlByID(ID_GCODE_Exclude_Object_window2);
    mExclude_Object_windowPtr = (ZKWindow*)findControlByID(ID_GCODE_Exclude_Object_window);
    mButton101Ptr = (ZKButton*)findControlByID(ID_GCODE_Button101);
    mButton100Ptr = (ZKButton*)findControlByID(ID_GCODE_Button100);
    mButton98Ptr = (ZKButton*)findControlByID(ID_GCODE_Button98);
    mButton50Ptr = (ZKButton*)findControlByID(ID_GCODE_Button50);
    mbed_temp_buttonPtr = (ZKButton*)findControlByID(ID_GCODE_bed_temp_button);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView7);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView45);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView43);
    mTextView42Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView42);
    mTextView17Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView17);
    mStop_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Stop_Button);
    mPause_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Pause_Button);
    mSkip_it_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Skip_it_Button);
    mPrint_SeekBarPtr = (ZKSeekBar*)findControlByID(ID_GCODE_Print_SeekBar);if(mPrint_SeekBarPtr!= NULL){mPrint_SeekBarPtr->setSeekBarChangeListener(this);}
    mthumbnail_pngPtr = (ZKTextView*)findControlByID(ID_GCODE_thumbnail_png);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView4);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView3);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView1);
    mprintPtr = (ZKWindow*)findControlByID(ID_GCODE_print);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView6);
    mhomePtr = (ZKWindow*)findControlByID(ID_GCODE_home);
    mMain_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Main_Button);
    mLayer2_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Layer2_Button);
    mFile_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_File_Button);
    mButton73Ptr = (ZKButton*)findControlByID(ID_GCODE_Button73);
    mScreen_set_ButtonPtr = (ZKButton*)findControlByID(ID_GCODE_Screen_set_Button);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_GCODE_TextView25);
	mActivityPtr = this;
	onUI_init();
  registerProtocolDataUpdateListener(onProtocolDataUpdate);
  rigesterActivityTimer();
}

void gcodeActivity::onClick(ZKBase *pBase) {
	//TODO: add widget onClik code 
    int buttonTablen = sizeof(sButtonCallbackTab) / sizeof(S_ButtonCallback);
    for (int i = 0; i < buttonTablen; ++i) {
        if (sButtonCallbackTab[i].id == pBase->getID()) {
            if (sButtonCallbackTab[i].callback((ZKButton*)pBase)) {
            	return;
            }
            break;
        }
    }


    int len = sizeof(sAppInfoTab) / sizeof(sAppInfoTab[0]);
    for (int i = 0; i < len; ++i) {
        if (sAppInfoTab[i].id == pBase->getID()) {
            EASYUICONTEXT->openActivity(sAppInfoTab[i].pApp);
            return;
        }
    }

	Activity::onClick(pBase);
}

void gcodeActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void gcodeActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void gcodeActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool gcodeActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void gcodeActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int gcodeActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void gcodeActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void gcodeActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void gcodeActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool gcodeActivity::onTouchEvent(const MotionEvent &ev) {
    return ongcodeActivityTouchEvent(ev);
}

void gcodeActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void gcodeActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void gcodeActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SVideoViewCallbackTab[i].id == pVideoView->getID()) {
        	if (SVideoViewCallbackTab[i].loop) {
                //循环播放
        		videoLoopPlayback(pVideoView, msg, i);
        	} else if (SVideoViewCallbackTab[i].onVideoViewCallback != NULL){
        	    SVideoViewCallbackTab[i].onVideoViewCallback(pVideoView, msg);
        	}
            break;
        }
    }
}

void gcodeActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

	switch (msg) {
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED\n");
    if (callbackTabIndex >= (sizeof(SVideoViewCallbackTab)/sizeof(S_VideoViewCallback))) {
      break;
    }
		pVideoView->setVolume(SVideoViewCallbackTab[callbackTabIndex].defaultvolume / 10.0);
		mVideoLoopErrorCount = 0;
		break;
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_ERROR:
		/**错误处理 */
		++mVideoLoopErrorCount;
		if (mVideoLoopErrorCount > 100) {
			LOGD("video loop error counts > 100, quit loop playback !");
            break;
		} //不用break, 继续尝试播放下一个
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED\n");
        std::vector<std::string> videolist;
        std::string fileName(getAppName());
        if (fileName.size() < 4) {
             LOGD("getAppName size < 4, ignore!");
             break;
        }
        fileName = fileName.substr(0, fileName.length() - 4) + "_video_list.txt";
        fileName = "/mnt/extsd/" + fileName;
        if (!parseVideoFileList(fileName.c_str(), videolist)) {
            LOGD("parseVideoFileList failed !");
		    break;
        }
		if (pVideoView && !videolist.empty()) {
			mVideoLoopIndex = (mVideoLoopIndex + 1) % videolist.size();
			pVideoView->play(videolist[mVideoLoopIndex].c_str());
		}
		break;
	}
}

void gcodeActivity::startVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		//循环播放
    		videoLoopPlayback(videoView, ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED, i);
    		return;
    	}
    }
}

void gcodeActivity::stopVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		if (videoView->isPlaying()) {
    		    videoView->stop();
    		}
    		return;
    	}
    }
}

bool gcodeActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
	mediaFileList.clear();
	if (NULL == pFileListPath || 0 == strlen(pFileListPath)) {
        LOGD("video file list is null!");
		return false;
	}

	ifstream is(pFileListPath, ios_base::in);
	if (!is.is_open()) {
		LOGD("cann't open file %s \n", pFileListPath);
		return false;
	}
	char tmp[1024] = {0};
	while (is.getline(tmp, sizeof(tmp))) {
		string str = tmp;
		removeCharFromString(str, '\"');
		removeCharFromString(str, '\r');
		removeCharFromString(str, '\n');
		if (str.size() > 1) {
     		mediaFileList.push_back(str.c_str());
		}
	}
  LOGD("(f:%s, l:%d) parse fileList[%s], get [%d]files", __FUNCTION__,
      __LINE__, pFileListPath, int(mediaFileList.size()));
  for (std::vector<string>::size_type i = 0; i < mediaFileList.size(); i++) {
    LOGD("file[%u]:[%s]", ::size_t(i), mediaFileList[i].c_str());
  }
	is.close();

	return true;
}

int gcodeActivity::removeCharFromString(string& nString, char c) {
    string::size_type   pos;
    while(1) {
        pos = nString.find(c);
        if(pos != string::npos) {
            nString.erase(pos, 1);
        } else {
            break;
        }
    }
    return (int)nString.size();
}

void gcodeActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void gcodeActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void gcodeActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}