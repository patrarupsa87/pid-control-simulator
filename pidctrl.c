#include <stdio.h>
void clamp(double *point, double max, double min);
int main(){
    double setpoint;
    double output;
    double dt;
    double time;
    double tau;
    double control;
    double error;
    double kp;
    double ki;
    double integral=0;
    double integral_max=10;
    double integral_min=-10;
    double kd;
    double derivative;
    double previous_error=0;
    double u_max=+2;
    double u_min=-2;
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
