#include <stdio.h>
#include "pid_config.h"
void clamp(double *point, double max, double min);
int main(){
    double setpoint=1;
    double output=0;
    double time=0;
    double control=0;
    double error=0;
    double integral=0;
    double derivative=0;
    double previous_error=0;
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
