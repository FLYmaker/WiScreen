/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __GCODEACTIVITY_H__
#define __GCODEACTIVITY_H__


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_GCODE_Board_SD_Button    20264
#define ID_GCODE_Print_again_Button    20263
#define ID_GCODE_Set_ListView    80019
#define ID_GCODE_Num_ListView    80020
#define ID_GCODE_Button_print_    20246
#define ID_GCODE_Button_    20245
#define ID_GCODE_Button60    20244
#define ID_GCODE_Button54    20241
#define ID_GCODE_Button53    20240
#define ID_GCODE_Button52    20239
#define ID_GCODE_Button51    20238
#define ID_GCODE_Button49    20237
#define ID_GCODE_Button48    20236
#define ID_GCODE_Button47    20235
#define ID_GCODE_Button46    20234
#define ID_GCODE_Button168    20125
#define ID_GCODE_Button167    20124
#define ID_GCODE_Button166    20175
#define ID_GCODE_Button165    20174
#define ID_GCODE_Button_z    20173
#define ID_GCODE_Button_y    20123
#define ID_GCODE_Button_x    20122
#define ID_GCODE_Button_w    20121
#define ID_GCODE_Button_v    20120
#define ID_GCODE_Button_u    20119
#define ID_GCODE_Button_t    20117
#define ID_GCODE_Button_s    20116
#define ID_GCODE_Button_r    20115
#define ID_GCODE_Button_q    20109
#define ID_GCODE_Button_p    20108
#define ID_GCODE_Button_o    20107
#define ID_GCODE_Button_n    20092
#define ID_GCODE_Button_m    20090
#define ID_GCODE_Button_l    20087
#define ID_GCODE_Button_k    20075
#define ID_GCODE_Button_j    20074
#define ID_GCODE_Button_i    20073
#define ID_GCODE_Button_h    20072
#define ID_GCODE_Button_g    20071
#define ID_GCODE_Button_f    20070
#define ID_GCODE_Button_e    20069
#define ID_GCODE_Button_d    20068
#define ID_GCODE_Button_c    20067
#define ID_GCODE_Button_b    20066
#define ID_GCODE_Button_a    20065
#define ID_GCODE_Button138    20064
#define ID_GCODE_Button137    20062
#define ID_GCODE_Button_9    20060
#define ID_GCODE_Button_8    20057
#define ID_GCODE_Button_7    20053
#define ID_GCODE_Button_6    20051
#define ID_GCODE_Button_5    20046
#define ID_GCODE_Button_4    20140
#define ID_GCODE_Button_3    20045
#define ID_GCODE_Button_2    20138
#define ID_GCODE_Button_1    20137
#define ID_GCODE_Button_0    20135
#define ID_GCODE_Button125    20134
#define ID_GCODE_TextView44    50101
#define ID_GCODE_TextView46    50103
#define ID_GCODE_AJ1    110027
#define ID_GCODE_Button45    20229
#define ID_GCODE_Button28    20039
#define ID_GCODE_Buttonjpd    20063
#define ID_GCODE_ButtonjpL    20059
#define ID_GCODE_Button96    20105
#define ID_GCODE_TextView22    50079
#define ID_GCODE_Button84    20093
#define ID_GCODE_Button85    20094
#define ID_GCODE_Button86    20095
#define ID_GCODE_Button87    20096
#define ID_GCODE_Button88    20097
#define ID_GCODE_Button89    20098
#define ID_GCODE_Button90    20099
#define ID_GCODE_Button91    20100
#define ID_GCODE_Button92    20101
#define ID_GCODE_Button93    20102
#define ID_GCODE_Button94    20103
#define ID_GCODE_AJ_confirm_Button    20104
#define ID_GCODE_AJ    110022
#define ID_GCODE_Button18    20025
#define ID_GCODE_Textview50    50052
#define ID_GCODE_lock    110013
#define ID_GCODE_Anti_touch    110012
#define ID_GCODE_Notify_ListView_del    24008
#define ID_GCODE_Notify_ListView    80012
#define ID_GCODE_open_notify    20218
#define ID_GCODE_Button58    20243
#define ID_GCODE_TextView81    50026
#define ID_GCODE_TextView80    50025
#define ID_GCODE_Button57    20242
#define ID_GCODE_type_Button    20233
#define ID_GCODE_gcode_Button    20232
#define ID_GCODE_name_Button    20231
#define ID_GCODE_Customize_Window    110033
#define ID_GCODE_Customize_Button    20230
#define ID_GCODE_TextView79    50021
#define ID_GCODE_smail_edit    24017
#define ID_GCODE_Customize_ListView    80016
#define ID_GCODE_Drop_down_menu    110032
#define ID_GCODE_Task_List_state    24025
#define ID_GCODE_Task_List_icon    24024
#define ID_GCODE_Task_List_up    24023
#define ID_GCODE_Task_List_down    24022
#define ID_GCODE_Task_List_del    24021
#define ID_GCODE_Task_List_dec    24020
#define ID_GCODE_Task_List_add    24019
#define ID_GCODE_Task_List_num    24016
#define ID_GCODE_Task_List    80018
#define ID_GCODE_Task_list_Window    110036
#define ID_GCODE_Button36    20061
#define ID_GCODE_TextView41    50049
#define ID_GCODE_Button30    20041
#define ID_GCODE_Button29    20040
#define ID_GCODE_restart_layer    110020
#define ID_GCODE_stop_Button    20228
#define ID_GCODE_ButtonForget    20219
#define ID_GCODE_TextConnectState    50105
#define ID_GCODE_TextConnectSecType    50104
#define ID_GCODE_TextConnectSsid    50102
#define ID_GCODE_Textview19    50100
#define ID_GCODE_Textview17    50099
#define ID_GCODE_Textview15    50098
#define ID_GCODE_ButtonDisconnect    20223
#define ID_GCODE_WindowDisconnect    100011
#define ID_GCODE_Buttonautoconnect    20226
#define ID_GCODE_ButtonShowPwd    20222
#define ID_GCODE_TextSecType    50097
#define ID_GCODE_TextSsid    50096
#define ID_GCODE_Textview9    50095
#define ID_GCODE_Textview7    50090
#define ID_GCODE_Textview5    50089
#define ID_GCODE_EdittextPwd    51000
#define ID_GCODE_ButtonConnect    20221
#define ID_GCODE_WindowSet    100010
#define ID_GCODE_WIFI_freq    24014
#define ID_GCODE_WIFI_IP    24012
#define ID_GCODE_SubItem2    24009
#define ID_GCODE_LISTSUBITEM_SUB    70002
#define ID_GCODE_LISTSUBITEM_NAME    70001
#define ID_GCODE_LISTSUBITEM_LEVEL    70000
#define ID_GCODE_ListViewWifiInfo    80000
#define ID_GCODE_Host_computer_wifi    100004
#define ID_GCODE_TextView18    50029
#define ID_GCODE_Button14    20021
#define ID_GCODE_Button12    20019
#define ID_GCODE_yes_no_Window    110007
#define ID_GCODE_SubItem4    24015
#define ID_GCODE_Language_ListView    80015
#define ID_GCODE_SubItem1    24001
#define ID_GCODE_Time_out_list    80001
#define ID_GCODE_Time_out_win    110011
#define ID_GCODE_TextView76    50084
#define ID_GCODE_Buzz_BUTTON    20217
#define ID_GCODE_TextView30    50042
#define ID_GCODE_TextView26    50036
#define ID_GCODE_TextView24    50035
#define ID_GCODE_TextView23    50034
#define ID_GCODE_TextView21    50033
#define ID_GCODE_Button17    20024
#define ID_GCODE_Button16    20023
#define ID_GCODE_Button15    20022
#define ID_GCODE_TextView28    50039
#define ID_GCODE_TextView27    50038
#define ID_GCODE_Button13    20020
#define ID_GCODE_TextView29    50040
#define ID_GCODE_brightnes_SeekBar    91003
#define ID_GCODE_TextView20    50032
#define ID_GCODE_Screen_set_win    110010
#define ID_GCODE_COLOR_ListView    80010
#define ID_GCODE_TextView72    50078
#define ID_GCODE_TextView71    50077
#define ID_GCODE_TextView75    50083
#define ID_GCODE_ERCF_BOWDEN_CA_BUTTON    20201
#define ID_GCODE_TextView74    50082
#define ID_GCODE_ERCF_BOWDEN_BACK    20200
#define ID_GCODE_ERCF_BOWDEN_Window    110031
#define ID_GCODE_ERCF_SENSOR_TRUE_BUTTON    20199
#define ID_GCODE_TextView70    50076
#define ID_GCODE_TextView69    50075
#define ID_GCODE_ERCF_SENSOR_BACK    20183
#define ID_GCODE_encode_view    50056
#define ID_GCODE_TextView48    50055
#define ID_GCODE_TextView47    50054
#define ID_GCODE_ERCF_SENSOR_Window    110026
#define ID_GCODE_TextView68    50074
#define ID_GCODE_ERCF_EX_TRUE_BUTTON    20198
#define ID_GCODE_TextView67    50073
#define ID_GCODE_ERCF_EX_BUTTON    20197
#define ID_GCODE_ERCF_EX_BACK    20196
#define ID_GCODE_TextView66    50072
#define ID_GCODE_TextView64    50071
#define ID_GCODE_TextView63    50070
#define ID_GCODE_ERCF_EX_Window    110030
#define ID_GCODE_ERCF_MOTOR_OFF1    20192
#define ID_GCODE_TextView54    50062
#define ID_GCODE_TextView53    50061
#define ID_GCODE_ListView6    80009
#define ID_GCODE_ERCF_CA_ListView    80008
#define ID_GCODE_TextView52    50060
#define ID_GCODE_ERCF_TOOOL_CA    20191
#define ID_GCODE_ERCF_TOOL_BACK    20190
#define ID_GCODE_TextView51    50059
#define ID_GCODE_TextView50    50058
#define ID_GCODE_TextView49    50057
#define ID_GCODE_ERCF_MOTOR_OFF2    20206
#define ID_GCODE_ERCF_TOOL_Window    110028
#define ID_GCODE_TextView62    50069
#define ID_GCODE_TextView57    50065
#define ID_GCODE_ERCF_SERVO_UP_Button    20195
#define ID_GCODE_TextView61    50068
#define ID_GCODE_ERCF_SERVO_DOWN_Button    20194
#define ID_GCODE_TextView60    50067
#define ID_GCODE_TextView59    50066
#define ID_GCODE_ERCF_SERVO_BACK    20193
#define ID_GCODE_TextView56    50064
#define ID_GCODE_TextView55    50063
#define ID_GCODE_ERCF_SERVO_Window    110029
#define ID_GCODE_ERCF_CA_BACK    20203
#define ID_GCODE_Button40    20182
#define ID_GCODE_Button39    20181
#define ID_GCODE_Button38    20180
#define ID_GCODE_Button37    20179
#define ID_GCODE_Button35    20136
#define ID_GCODE_Button34    20133
#define ID_GCODE_ERCF_CA_Window    110025
#define ID_GCODE_ERCF_HOME    20132
#define ID_GCODE_ERCF_MOTOR_OFF    20131
#define ID_GCODE_ERCF_E    20130
#define ID_GCODE_ERCF_E_ADD    20129
#define ID_GCODE_ERCF_CA_BUTTON    20128
#define ID_GCODE_T_NUM_sure    24005
#define ID_GCODE_ERCF_ListView    80006
#define ID_GCODE_ERCF    110017
#define ID_GCODE_ListView5    80007
#define ID_GCODE_Gcode_layer    110021
#define ID_GCODE_Print_img_ListView    80002
#define ID_GCODE_Print_set_button    20211
#define ID_GCODE_Button44    20210
#define ID_GCODE_Button43    20209
#define ID_GCODE_Button42    20208
#define ID_GCODE_Button41    20207
#define ID_GCODE_TextView32    50044
#define ID_GCODE_TextView77    50085
#define ID_GCODE_Print_set_list    80011
#define ID_GCODE_Print_state1    24013
#define ID_GCODE_Print_name1    24011
#define ID_GCODE_Print_mac1    24010
#define ID_GCODE_Print_img2    24006
#define ID_GCODE_Print_ListView1    80013
#define ID_GCODE_Button21    20028
#define ID_GCODE_Button22    20032
#define ID_GCODE_TextView78    50086
#define ID_GCODE_TextView58    50015
#define ID_GCODE_Connect_Window    110016
#define ID_GCODE_Button19    20026
#define ID_GCODE_Button31    20044
#define ID_GCODE_Button20    20027
#define ID_GCODE_TextView31    50043
#define ID_GCODE_Print_Set_Win    110014
#define ID_GCODE_TextView73    50081
#define ID_GCODE_ud_speed    24007
#define ID_GCODE_up_file_progress    24002
#define ID_GCODE_download_list    80014
#define ID_GCODE_Button_add_list    20262
#define ID_GCODE_Button_Del    20225
#define ID_GCODE_Button_Preheat    20224
#define ID_GCODE_Updata_Slave_printing    20213
#define ID_GCODE_Updata_Slave    20212
#define ID_GCODE_TextView11    50013
#define ID_GCODE_TextView10    50012
#define ID_GCODE_TextView9    50011
#define ID_GCODE_Button7    20002
#define ID_GCODE_Button4    20001
#define ID_GCODE_TextView8    50010
#define ID_GCODE_TextView2    50009
#define ID_GCODE_print_sure    110002
#define ID_GCODE_Udesk_button    20214
#define ID_GCODE_Sd_button    20215
#define ID_GCODE_ms_file_button    20216
#define ID_GCODE_FileList_icon    24003
#define ID_GCODE_FileList    80005
#define ID_GCODE_File_Refresh_button    20009
#define ID_GCODE_TextView14    50014
#define ID_GCODE_TextView65    50037
#define ID_GCODE_file    110001
#define ID_GCODE_CAM_BED_MESH    110034
#define ID_GCODE_TextView40    50048
#define ID_GCODE_ListView3    80004
#define ID_GCODE_TextView39    50047
#define ID_GCODE_Button27    20038
#define ID_GCODE_SubItem3    24004
#define ID_GCODE_ListView2    80003
#define ID_GCODE_cur_jz_Win    110015
#define ID_GCODE_Button26    20037
#define ID_GCODE_TextView38    50046
#define ID_GCODE_TextView33    50045
#define ID_GCODE_Button25    20036
#define ID_GCODE_Button24    20035
#define ID_GCODE_Button23    20034
#define ID_GCODE_Button6    20033
#define ID_GCODE_jz_win_close_button    20031
#define ID_GCODE_Button80    20049
#define ID_GCODE_Button82    20052
#define ID_GCODE_Button81    20050
#define ID_GCODE_Button79    20048
#define ID_GCODE_Button77    20047
#define ID_GCODE_Button76    20043
#define ID_GCODE_Button75    20042
#define ID_GCODE_Button59    20030
#define ID_GCODE_TextView5    50017
#define ID_GCODE_TextView13    50019
#define ID_GCODE_jz_Window    110006
#define ID_GCODE_temp_move_Button    20202
#define ID_GCODE_Button_cd    20259
#define ID_GCODE_Tool_Button    20189
#define ID_GCODE_TextView37    50094
#define ID_GCODE_Button62    20248
#define ID_GCODE_Button61    20247
#define ID_GCODE_hc_hg_Button    20029
#define ID_GCODE_JZ_Button    20017
#define ID_GCODE_tool    110024
#define ID_GCODE_FAN3_DOWN    20188
#define ID_GCODE_FAN3_UP    20187
#define ID_GCODE_FAN2_DOWN    20186
#define ID_GCODE_FAN2_UP    20185
#define ID_GCODE_FAN1_DOWN    20178
#define ID_GCODE_FAN1_UP    20184
#define ID_GCODE_FAN2_View    50041
#define ID_GCODE_FAN1_View    50030
#define ID_GCODE_FAN0_View    50018
#define ID_GCODE_FAN3_ICON    20177
#define ID_GCODE_FAN2_ICON    20176
#define ID_GCODE_FAN1_ICON    20142
#define ID_GCODE_FAN3_SW_Button    20141
#define ID_GCODE_FAN2_SW_Button    20114
#define ID_GCODE_FAN1_SW_Button    20113
#define ID_GCODE_Fan2_Pointer    90003
#define ID_GCODE_Fan1_Pointer    90002
#define ID_GCODE_Fan0_Pointer    90001
#define ID_GCODE_FAN_Window    110009
#define ID_GCODE_Button11    20008
#define ID_GCODE_Button10    20006
#define ID_GCODE_Button9    20005
#define ID_GCODE_Button8    20003
#define ID_GCODE_TextView15    50024
#define ID_GCODE_print_speed_Window    110004
#define ID_GCODE_move10_Button    20249
#define ID_GCODE_move01_Button    20256
#define ID_GCODE_move1_Button    20257
#define ID_GCODE_move100_Button    20258
#define ID_GCODE_Button_unlock    20220
#define ID_GCODE_Button_moto_revers    20227
#define ID_GCODE_Fan_layer_open_button    20112
#define ID_GCODE_layer2_speed_button    20111
#define ID_GCODE_Button103    20110
#define ID_GCODE_lyayer2_bed_temp_button    20106
#define ID_GCODE_lyayer2_nozzle_temp_button    20077
#define ID_GCODE_Y_D1_BUTTON    20089
#define ID_GCODE_Y_D10_BUTTON    20010
#define ID_GCODE_Y_U1_BUTTON    20088
#define ID_GCODE_Y_U10_BUTTON    20011
#define ID_GCODE_X_D1_BUTTON    20078
#define ID_GCODE_X_D10_BUTTON    20015
#define ID_GCODE_X_U1_BUTTON    20084
#define ID_GCODE_X_U10_BUTTON    20014
#define ID_GCODE_Button1    20205
#define ID_GCODE_Button68    20204
#define ID_GCODE_Button_home    20118
#define ID_GCODE_Button66    20091
#define ID_GCODE_TextView36    50093
#define ID_GCODE_TextView35    50092
#define ID_GCODE_TextView34    50091
#define ID_GCODE_Button56    20086
#define ID_GCODE_Button3    20004
#define ID_GCODE_Button2    20007
#define ID_GCODE_Button55    20085
#define ID_GCODE_Warehouse_Temperature_View    50023
#define ID_GCODE_Bed_Temp_View    50022
#define ID_GCODE_Nozzle_Temp_View    50020
#define ID_GCODE_Move_button_background    50003
#define ID_GCODE_TextView12    50016
#define ID_GCODE_TextView16    50028
#define ID_GCODE_whmove    110023
#define ID_GCODE_Button_cl    20260
#define ID_GCODE_Button_td    20261
#define ID_GCODE_move    110019
#define ID_GCODE_TextView19    50031
#define ID_GCODE_Button5    20018
#define ID_GCODE_Obj_SeekBar    91001
#define ID_GCODE_obj_B30    20172
#define ID_GCODE_obj_B29    20171
#define ID_GCODE_obj_B28    20170
#define ID_GCODE_obj_B27    20169
#define ID_GCODE_obj_B26    20168
#define ID_GCODE_obj_B25    20167
#define ID_GCODE_obj_B24    20166
#define ID_GCODE_obj_B23    20165
#define ID_GCODE_obj_B22    20164
#define ID_GCODE_obj_B21    20163
#define ID_GCODE_obj_B20    20162
#define ID_GCODE_obj_B19    20161
#define ID_GCODE_obj_B18    20160
#define ID_GCODE_obj_B17    20159
#define ID_GCODE_obj_B16    20158
#define ID_GCODE_obj_B15    20157
#define ID_GCODE_obj_B14    20156
#define ID_GCODE_obj_B13    20155
#define ID_GCODE_obj_B12    20154
#define ID_GCODE_obj_B11    20153
#define ID_GCODE_obj_B10    20152
#define ID_GCODE_obj_B9    20151
#define ID_GCODE_obj_B8    20150
#define ID_GCODE_obj_B7    20149
#define ID_GCODE_obj_B6    20148
#define ID_GCODE_obj_B5    20147
#define ID_GCODE_obj_B4    20146
#define ID_GCODE_obj_B3    20145
#define ID_GCODE_obj_B2    20144
#define ID_GCODE_obj_B1    20143
#define ID_GCODE_obj_B0    20139
#define ID_GCODE_Exclude_Object_window2    110008
#define ID_GCODE_Exclude_Object_window    110005
#define ID_GCODE_Button101    20056
#define ID_GCODE_Button100    20055
#define ID_GCODE_Button98    20054
#define ID_GCODE_Button50    20076
#define ID_GCODE_bed_temp_button    20058
#define ID_GCODE_TextView7    50007
#define ID_GCODE_File_name_TextView    50027
#define ID_GCODE_SubItem6    24018
#define ID_GCODE_ListView1    80017
#define ID_GCODE_speed_window    110035
#define ID_GCODE_speed_Button    20255
#define ID_GCODE_zoffset005_Button    20253
#define ID_GCODE_zoffset0025_Button    20252
#define ID_GCODE_zoffset001_Button    20251
#define ID_GCODE_Z_Offset_Reverse_Button    20254
#define ID_GCODE_zoffset0005_Button    20250
#define ID_GCODE_Zoffset_Up_button    20127
#define ID_GCODE_Zoffset_Down_button    20126
#define ID_GCODE_TextView45    50053
#define ID_GCODE_TextView43    50051
#define ID_GCODE_TextView42    50050
#define ID_GCODE_TextView17    50004
#define ID_GCODE_Stop_Button    20016
#define ID_GCODE_Pause_Button    20013
#define ID_GCODE_Skip_it_Button    20012
#define ID_GCODE_Print_SeekBar    91002
#define ID_GCODE_thumbnail_png    50008
#define ID_GCODE_TextView4    50005
#define ID_GCODE_TextView3    50002
#define ID_GCODE_TextView1    50001
#define ID_GCODE_print    110018
#define ID_GCODE_TextView6    50006
#define ID_GCODE_home    110003
#define ID_GCODE_Screen_set_Button    20083
#define ID_GCODE_Button73    20082
#define ID_GCODE_File_Button    20081
#define ID_GCODE_Layer2_Button    20080
#define ID_GCODE_Main_Button    20079
#define ID_GCODE_TextView25    50080
/*TAG:Macro宏ID END*/

class gcodeActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    gcodeActivity();
    virtual ~gcodeActivity();

    /**
     * 注册定时器
     */
	void registerUserTimer(int id, int time);
	/**
	 * 取消定时器
	 */
	void unregisterUserTimer(int id);
	/**
	 * 重置定时器
	 */
	void resetUserTimer(int id, int time);

protected:
    /*TAG:PROTECTED_FUNCTION*/
    virtual const char* getAppName() const;
    virtual void onCreate();
    virtual void onClick(ZKBase *pBase);
    virtual void onResume();
    virtual void onPause();
    virtual void onIntent(const Intent *intentPtr);
    virtual bool onTimer(int id);

    virtual void onProgressChanged(ZKSeekBar *pSeekBar, int progress);

    virtual int getListItemCount(const ZKListView *pListView) const;
    virtual void obtainListItemData(ZKListView *pListView, ZKListView::ZKListItem *pListItem, int index);
    virtual void onItemClick(ZKListView *pListView, int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);

    virtual void onTextChanged(ZKTextView *pTextView, const string &text);

    void rigesterActivityTimer();

    virtual void onVideoPlayerMessage(ZKVideoView *pVideoView, int msg);
    void videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex);
    void startVideoLoopPlayback();
    void stopVideoLoopPlayback();
    bool parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList);
    int removeCharFromString(string& nString, char c);


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;

};

#endif