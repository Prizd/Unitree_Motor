# README.md

If you have any questions or need assistance with usage, feel free to contact support@unitree.com.
 
### Notice

support motor: GO-M8010-6 motor、A1 motor、 B1 motor

gcc >= 5.4.0 (for x86 platform)

gcc >= 7.5.0 (for Arm platform) 

run gcc --version  command to check your gcc version

### Build
```bash
git clone https://github.com/Prizd/Unitree_Motor.git
cd Unitree_Motor
mkdir build
cd build
cmake ..
make
```

### Run
If the compilation is successful, many C++ example executable files will be generated in the build folder. Then run the examples with 'sudo', for example:
```bash
sudo ./example_a1_motor
```


### Tip

The code snippet below demonstrates an example of assigning values to the command structure `cmd` in `example_a1_motor.cpp`. It should be noted that the commands are all for the **rotor** side. However, the commands we usually compute are for the **output** side. Therefore, when assigning values, we need to consider the conversion between them.

```c++
Go1[id].set_motor(float T,float Kp,float Pos,float Kd,float V);
A1[id].set_motor(float T,float Kp,float Pos,float Kd,float V);
```

