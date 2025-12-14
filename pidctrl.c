#include <stdio.h>
int main(){
    double setpoint;
    double output;
    double dt;
    double time;
    double tau;
    double control;
    double error;
    double kp=0.001;
    double ki;
    double integral=0;
    double integral_max=10;
    double integral_min=-10;
    double kd=0.001;
    double derivative;
    double previous_error=0;
    double u_max=-2;
    double u_min=+2;
    tau=0.3;
    setpoint =1.0;
    dt=0.5;
    output=0.0;
    ki=0.2;
    for(time=0; time<=10.0; time=time+dt){
        if(control>u_max){
            control=u_max;
        }
        if(control<u_min){
            control=u_min;
        }
        if (integral>integral_max){
            integral=integral_max;
        }
        if(integral<integral_min){
            integral=integral_min;
        }
        error=setpoint-output;
        derivative=(error-previous_error)/dt;
        integral=integral+error*dt;
        control=kp*error+ki*integral+kd*derivative;
        output=output+(control-output)*dt/tau;
        printf("%lf  | ",time);
        printf("%lf  |",output);
        printf("%lf \n",control);
        previous_error=error;
    }
    
}
