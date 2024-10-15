#pragma once
#include "unitreeMotor/unitreeMotor.h"
#include "serialPort/SerialPort.h"
#include <vector>
#include <map>
/**
*****************************************************************************
*  @brief   Go1_motor
*
*  @param   只有set_motor一个对外接口
*                   T+Kp*dert(Pos)+Kd*dert(V)
*                   Go1官方公式
*  @param   注意！！！只要改变电机数值，就会直接发送！！！！！！！！！！！！！！！！！
-------------------------------------------
*  @note 历史版本  修改人员      修改日期    修改内容
*  @note v1.0    lihaoyuan   2024.10.9   1.创建
*
*****************************************************************************
*/
class Go1_motor
{
private:
    MotorCmd    cmd;    
    MotorData   data;
    static SerialPort  serial;
    void send();
public:
    Go1_motor(int id);
    //改变即发送
    void set_motor(float T,float Kp,float Pos,float Kd,float V);
    const MotorData& get_data();
};
/**
*****************************************************************************
*  @brief   GO1对外接口
*
*  @param       insert(id)       
*                   加入电机并储存
*  @param       set_motor(int id,float T,float Kp,float Pos,float Kd,float V)
*                   T+Kp*dert(Pos)+Kd*dert(V)
*                   Go1官方公式
*  @param       operator[]          
*                   获取对应id的Go1_motor对象         
*----------------------------------------------------------------------------
*  @note 历史版本  修改人员      修改日期    修改内容
*  @note v1.0    lihaoyuan   2024.10.9   1.创建
*
*****************************************************************************
*/
class GO1
{
private:
    static void insert(int id);
    static std::vector<Go1_motor> motor_list;
    static std::map<int,int> motor_map;
public:
    static void set_motor(int id,float T,float Kp,float Pos,float Kd,float V);
    Go1_motor& operator[](int id);
};

