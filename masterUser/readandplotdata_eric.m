% clear all;
% close all; 
% clc

%% go to the directory
cd /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser

%% playback_data
% input = 'd00110_patient';  
% input = 'd00115';  
% input = 'd00116_Enrique';  
% input = 'd00117'; 
% input = 'd00118_sim_no_invdyn'; 
% input = 'd00119_sim_invdyn'; 

input_bl = 'd00120_nohuman'; % baseline
fname_bl = input_bl;
[D,vars,freq] = readSRCdata(fname_bl);
ind= find(D(:,1), 1, 'last'); % find index of last non-zero's.  

samples = ind% 13000;

st = 100;
time_pb_bl = D(st:samples,1);
pos_pb_bl = D(st:samples,2);
vel_pb_bl = D(st:samples,3);
acc_pb_bl = D(st:samples,4);
u_pb_bl = D(st:samples,5);
ufb_pb_bl = D(st:samples,6);
load_pb_bl = D(st:samples,7);
uff_pb_bl = D(st:samples,8);


%% patient simulation
% input_patient = 'd00123_ericStiff_patient';  % B
%input_patient = 'd00128_Sanger_spasticity';  % B
input_patient = 'd00135_newTrajectory';  % B

fname_patient = input_patient;
[D,vars,freq] = readSRCdata(fname_patient);
ind= find(D(:,1), 1, 'last'); % find index of last non-zero's.  

samples = ind% 13000;


time_pb_patient = D(st:samples,1);
pos_pb_patient = D(st:samples,2);
vel_pb_patient = D(st:samples,3);
acc_pb_patient = D(st:samples,4);
u_pb_patient = D(st:samples,5);
ufb_pb_patient = D(st:samples,6);
load_pb_patient = D(st:samples,7);
uff_pb_patient = D(st:samples,8);
%emg_Trig_patient = D(st:samples,13);


%% control subject
% input_control = 'd00122_eric_control';  % B
input_control = 'd00126_Sanger_control';  % B
fname_control = input_control;
[D,vars,freq] = readSRCdata(fname_control);
ind= find(D(:,1), 1, 'last'); % find index of last non-zero's.  
samples = ind% 13000;


time_pb_control = D(st:samples,1);
pos_pb_control = D(st:samples,2);
vel_pb_control = D(st:samples,3);
acc_pb_control = D(st:samples,4);
u_pb_control = D(st:samples,5);
ufb_pb_control = D(st:samples,6);
load_pb_control = D(st:samples,7);
uff_pb_control = D(st:samples,8);
%emg_Trig_control = D(st:samples,13);

%% plot diff

endinx = 26000; % get common end index from figure

figure(1)
plot(time_pb_control(1:endinx), load_pb_control(1:endinx),time_pb_control(1:endinx), load_pb_bl(1:endinx), time_pb_control(1:endinx), load_pb_control(1:endinx)-load_pb_bl(1:endinx))
legend('load human', 'load baseline', 'diff');
ylim([-20 20])

figure(2)
plot(time_pb_patient(1:endinx), load_pb_patient(1:endinx),time_pb_patient(1:endinx), load_pb_bl(1:endinx), time_pb_patient(1:endinx), load_pb_patient(1:endinx)-load_pb_bl(1:endinx))
legend('load patient', 'load baseline', 'diff');
ylim([-20 20])



%%  

% input = 'd00126_Sanger_control';   % A
% input = 'd00128_Sanger_spasticity';  % B
input = 'd00135_newTrajectory';  

% 
% 
%% EMG recording (yes or no)
emgYN = menu('Choose a mode','Yes EMG','No EMG'); % yes = 1, no = 2
% mode setting 


%% menu selection 
choice = menu('Choose a mode','view_recorded','get_selected_var', 'show_regression');

%% mode setting 
if choice==1,
    fname = input;   % wiggliing trajectory recording data
elseif choice==2,
    fname = input;    % (get_selected_var)
elseif choice==3,
    fname = input; %  (show regression)
else 
   error('Nonexistent mode');
end




[D,vars,freq] = readSRCdata(fname);

ind= find(D(:,1), 1, 'last'); % find index of last non-zero's.  

samples = ind% 13000;

st = 100;
time_pb = D(st:samples,1);
pos_pb = D(st:samples,2);
vel_pb = D(st:samples,3);
acc_pb = D(st:samples,4);
u_pb = D(st:samples,5);
ufb_pb = D(st:samples,6);
load_pb = D(st:samples,7);
uff_pb = D(st:samples,8);
%emg_Trig = D(st:samples,13);



diff_load = load_pb(1:endinx)-load_pb_bl(1:endinx);

playback_data = [ time_pb(1:endinx) pos_pb(1:endinx) vel_pb(1:endinx) ufb_pb(1:endinx) uff_pb(1:endinx) diff_load  u_pb(1:endinx) emg_Trig(1:endinx) ];% vel_pb acc_pb u_pb uff_pb load_pb ufb_pb];



%% mode setting 
A = [fname, '_selected_vars.txt'];    % trajectory recording phase
if choice==1,
elseif choice==2, 
    mypath = 'selected_vars/';
    csvwrite(fullfile(mypath, A) ,playback_data); % save selected variables
%     csvwrite(A,playback_data); % save selected variables
elseif choice==3,
    
else 
   error('Nonexistent mode');
end
 
% save('20141204_d00093_pos_vel_ufb','playback_data'); %save mat data



%% regression test
if choice==3,
    filename_read = ['regressionData/', fname, '_selected_vars', '_regressionCoeff.txt']
    M = dlmread(filename_read, ',')

    a0 = M(1)
    a1 = M(2)
    a2 = M(3)
    regressedF = a0 + a1* pos_pb + a2 * vel_pb;
end

%% plot
% close all

figure
subplot(2,1,1)
plot(time_pb,pos_pb, time_pb, vel_pb)
grid on
% title('Pos / vel - wo/subject')
title( ['Pos / vel ', input, ' ' ] )
legend('pos', 'vel')
ylim([-6 6])
subplot(2,1,2)


diff_load = load_pb(1:endinx)-load_pb_bl(1:endinx);
if choice==3,
    plot(time_pb,load_pb,time_pb,u_pb, '--', time_pb,uff_pb,time_pb,ufb_pb, time_pb, regressedF, time_pb(1:endinx), diff_load, time_pb(1:endinx), emg_Trig(1:endinx))
else
    plot(time_pb,load_pb,time_pb,u_pb, '--', time_pb,uff_pb,time_pb,ufb_pb)
end
grid on
legend('load','u','uff','fb', 'regF', 'diff load', 'emgTrig')
title([num2str(choice), ', regF= ', num2str(a0),'+(', num2str(a1), ')x + (', num2str(a2), ')xdot'])
ylim([-20 20])

%%
% figure
% subplot(2,1,1)
% plot(time_subject,pos_subject)
% grid on
% title('Position - subject')
% ylim([1 2.5])
% subplot(2,1,2)
% plot(time_subject,load_subject,time_subject,u_subject,time_subject,uff_subject,time_subject,ufb_subject)
% legend('load','u','uff','fb')
% title('Load - subject')
% ylim([2 22])





