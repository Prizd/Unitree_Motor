#include "A1.h"


A1_motor::A1_motor(int id)
{
    cmd.motorType = MotorType::A1;
    data.motorType = MotorType::A1;
    cmd.mode = queryMotorMode(MotorType::A1,MotorMode::FOC);
    cmd.id   = id;
}
void A1_motor::send()
{
    serial.sendRecv(&cmd,&data);
}

void A1_motor::set_motor(float T,float Kp,float Pos,float Kd,float V)
{
    cmd.kp   = Kp;
    cmd.kd   = Kd;
    cmd.q    = Pos;
    cmd.dq   = -V*queryGearRatio(MotorType::A1);
    cmd.tau  = T;
    send();
}

const MotorData& A1_motor::get_data(){
    return data;
}


std::vector<A1_motor> A1::motor_list;
std::map<int,int> A1::motor_map;
void A1::insert(int id)
{
    motor_list.push_back(A1_motor(id));
    motor_map[id] = motor_list.size() - 1;
}
void A1::set_motor(int id, float T, float Kp, float Pos, float Kd, float V)
{
    if (motor_map.find(id) == motor_map.end())
        insert(id);
    motor_list[motor_map[id]].set_motor(T, Kp, Pos, Kd, V);
}

A1_motor &A1::operator[](int id)
{
    if (motor_map.find(id) == motor_map.end())
        insert(id);
    return motor_list[motor_map[id]];
}
