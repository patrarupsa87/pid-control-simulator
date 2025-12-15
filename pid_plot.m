data = readmatrix('pid_output.csv');

time    = data(:,1);
output  = data(:,2);
control = data(:,3);
error   = data(:,4);

% % -------- Output response --------
% figure;
% plot(time, output, 'LineWidth', 2);
% hold on;
% yline(1.0, '--r', 'Setpoint');
% xlabel('Time (s)');
% ylabel('Output');
% title('PID System Response');
% grid on;
% 
% % -------- Control effort --------
% figure;
% plot(time, control, 'LineWidth', 2);
% xlabel('Time (s)');
% ylabel('Control Signal');
% title('Control Effort');
% grid on;
% 
% % -------- Error --------
% figure;
% plot(time, error, 'LineWidth', 2);
% xlabel('Time (s)');
% ylabel('Error');
% title('Error vs Time');
% grid on;
figure;

yyaxis left
plot(time, output, 'b', 'LineWidth', 2);
hold on;
plot(time, error, 'k--', 'LineWidth', 1.5);
ylabel('Output / Error');

yyaxis right
plot(time, control, 'r', 'LineWidth', 2);
ylabel('Control Signal');

xlabel('Time (s)');
title('PID Controller Response (Dual Axis)');
legend('Output', 'Error', 'Control');
grid on;

