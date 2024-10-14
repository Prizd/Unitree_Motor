#include "Go1.h"


Go1_motor::Go1_motor(int id)
{
    cmd.motorType = MotorType::GO_M8010_6;
    data.motorType = MotorType::GO_M8010_6;
    cmd.mode = queryMotorMode(MotorType::GO_M8010_6,MotorMode::FOC);
    cmd.id   = id;
}
void Go1_motor::send()
{
    serial.sendRecv(&cmd,&data);
}

void Go1_motor::set_motor(float T,float Kp,float Pos,float Kd,float V)
{
    cmd.kp   = Kp;
    cmd.kd   = Kd;
    cmd.q    = Pos;
    cmd.dq   = -V*queryGearRatio(MotorType::GO_M8010_6);
    cmd.tau  = T;
    send();
}

const MotorData& Go1_motor::get_data(){
    return data;
}


std::vector<Go1_motor> GO1::motor_list;
std::map<int,int> GO1::motor_map;
void GO1::insert(int id)
{
    motor_list.push_back(Go1_motor(id));
    motor_map[id] = motor_list.size() - 1;
}
void GO1::set_motor(int id, float T, float Kp, float Pos, float Kd, float V)
{
    if (motor_map.find(id) == motor_map.end())
        insert(id);
    motor_list[motor_map[id]].set_motor(T, Kp, Pos, Kd, V);
}

Go1_motor &GO1::operator[](int id)
{
    if (motor_map.find(id) == motor_map.end())
        insert(id);
    return motor_list[motor_map[id]];
}
