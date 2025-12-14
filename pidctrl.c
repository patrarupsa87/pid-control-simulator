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
    tau=0.3;
    setpoint =1.0;
    dt=0.5;
    output=0.0;
    ki=0.2;
    for(time=0; time<=10.0; time=time+dt){
        error=setpoint-output;
        integral=integral+error*dt;
        control=kp*error+ki*integral;
        output=output+(control-output)*dt/tau;
        printf("%lf  | ",time);
        printf("%lf  |",output);
        printf("%lf \n",control);
    }
    
}
