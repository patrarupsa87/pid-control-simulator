#include <stdio.h>
#include "pid_config.h"
void clamp(double *point, double max, double min);
int main(){
    double setpoint;
    double output;
    double time;
    double control;
    double error;
    double integral=0;
    double kd;
    double derivative;
    double previous_error=0;
    tau=1.0;
    setpoint =1.0;
    dt=0.1;
    output=0.0;
    kp=1.0;
    ki=0.7;
    kd=0.09;
    for(time=0; time<=10.0; time=time+dt){
        error=setpoint-output;
        derivative=(error-previous_error)/dt;
        integral=integral+error*dt;
        clamp(&integral,integral_max,integral_min);
        control=kp*error+ki*integral+kd*derivative;
        clamp(&control,u_max,u_min);
        output=output+(control-output)*dt/tau;
        printf("%.4lf,%.4lf,%.4lf,%.4lf\n",time, output, control,error);
        previous_error=error;
    }
    
}
void clamp(double *point, double max, double min){
    if(*point> max){
        *point=max;
    }
    if(*point<min){
        *point=min;
    }
    
}
