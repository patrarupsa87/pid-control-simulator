#include <stdio.h>
int main(){
    double setpoint;
    double output;
    double dt;
    double time;
    setpoint =1.0;
    dt=0.5;
    output=0.0;
    for(time=0; time<=10.0; time=time+dt){
        printf("%lf  | ",time);
        printf("%lf \n",output);
    }
}
