% clear all;
% close all; 
% clc

%% go to the directory
cd /Volumes/SANDISK64G/sarcos/masterUser

%cd /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser

%% EMG recording (yes or no)
emgYN = menu('Choose a mode','Yes EMG','No EMG'); % yes = 1, no = 2
% mode setting 

%% playback_data
% input = 'd00110_patient';  
% input = 'd00115';  
% input = 'd00116_Enrique';  
% input = 'd00117'; 
% input = 'd00118_sim_no_invdyn'; 
% input = 'd00119_sim_invdyn'; 

% input_bl = 'd00120_zero_baseline'; % baseline
input_bl = 'd00139_alpha_baseline'; % baseline
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


%% patient 
% input_patient = 'd00123_ericStiff_patient';  % B
input_patient = 'd00156_alpha_CN_chair_2';  % B
% input_patient = 'd00127_Sanger_dystonia';  % B



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
if emgYN == 1, 
    emg_Trig_patient = D(st:samples,13);
end

%% control subject
% input_control = 'd00122_eric_control';  % B
input_control = 'd00148_alpha_Eric_control';  % B
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
if emgYN == 1, 
    emg_Trig_control = D(st:samples,13);
end
%% plot diff

endinx = 25000; % get common end index from figure


% 
% figure(1)
% plot(time_pb_control(1:endinx), load_pb_control(1:endinx),time_pb_control(1:endinx), load_pb_bl(1:endinx), time_pb_control(1:endinx), load_pb_control(1:endinx)-load_pb_bl(1:endinx))
% legend('load human', 'load baseline', 'diff');
% ylim([-20 20])
% 
% figure(2)
% plot(time_pb_patient(1:endinx), load_pb_patient(1:endinx),time_pb_patient(1:endinx), load_pb_bl(1:endinx), time_pb_patient(1:endinx), load_pb_patient(1:endinx)-load_pb_bl(1:endinx))
% legend('load patient', 'load baseline', 'diff');
% ylim([-20 20])



%%  

%input = 'd00139_alpha_baseline'; % 

%input = 'd00146_zero_Enrique_control';   % A
%input = 'd00147_zero_Enrique_control2';   % A
% input = 'd00140_alpha_Enrique_control';   % A
% input = 'd00148_alpha_Eric_control';   % A
% input = 'd00149_alpha_Eric_dystonia';   % A
% input = 'd00150_alpha_Eric_spasticity';   % A

% input = 'd00151_alpha_Eric_control_LH';   % A
% input = 'd00152_alpha_Eric_dystonia_LH';   % A
% input = 'd00153_alpha_Eric_spasticity_LH';   % A


% input = 'd00155_alpha_CN_chair_1';   % A

input = 'd00156_alpha_CN_chair_2';   % A
% input = 'd00157_zero_CN_chair_1';   % A
% input = 'd00158_alpha_JP_1';   % A
% input = 'd00159_zero_JP_1';   % A
% input = 'd00160_alpha_JP_2';   % A
% input = 'd00162_zero_JP_3';   % A



% input = 'd00141_alpha_Enrique_dystonia';  % B
% input = 'd00142_alpha_Enrique_spasticity';  % B
% input = 'd00139_alpha_baseline';
% input = 'd00138_trajectory_alpha';  
% input = 'd00145_alpha_AM_dystonia';
% input = 'd00144_alpha_AM_control';

% 
% 



%% menu selection 
choice = menu('Choose a mode','get traj 4 playback(1st time)','get_selected_var', 'plot only');

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
if emgYN == 1, 
    emg_Trig = D(st:samples,13);
end

ufb_pb_cut = ufb_pb(1:endinx);
uff_pb_cut = uff_pb(1:endinx);
load_pb_cut = load_pb(1:endinx);
pos_pb_cut = pos_pb(1:endinx);
vel_pb_cut = vel_pb(1:endinx);
acc_pb_cut = acc_pb(1:endinx);
diff_load_cut = load_pb(1:endinx)-load_pb_bl(1:endinx);

if emgYN == 1, 
    playback_data = [ time_pb(1:endinx) pos_pb(1:endinx) vel_pb(1:endinx) ufb_pb(1:endinx) uff_pb(1:endinx) diff_load_cut  u_pb(1:endinx) emg_Trig(1:endinx) ];% vel_pb acc_pb u_pb uff_pb load_pb ufb_pb];
else
    playback_data = [ time_pb(1:endinx) pos_pb(1:endinx) vel_pb(1:endinx) ufb_pb(1:endinx) uff_pb(1:endinx) diff_load_cut  u_pb(1:endinx) ];% vel_pb acc_pb u_pb uff_pb load_pb ufb_pb];
end


%% mode setting 
A = [fname, '_selected_vars.txt'];    % trajectory recording phase
if choice==1,
    mypath = 'selected_vars/trajectory/';
    csvwrite(fullfile(mypath, A) ,playback_data); % save selected variables
elseif choice==2, 
    mypath = 'selected_vars/';
    csvwrite(fullfile(mypath, A) ,playback_data); % save selected variables
%     csvwrite(A,playback_data); % save selected variables
elseif choice==3,
    
else 
   error('Nonexistent mode');
end
 
% save('20141204_d00093_pos_vel_ufb','playback_data'); %save mat data



% %% regression test
% if choice==3,
%     filename_read = ['regressionData/', fname, '_selected_vars', '_regressionCoeff.txt']
%     M = dlmread(filename_read, ',')
% 
%     a0 = M(1)
%     a1 = M(2)
%     a2 = M(3)
%     regressedF = a0 + a1* pos_pb + a2 * vel_pb;
% end

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

% refressedF_cut = regressedF(1:endinx);

%diff_load = load_pb(1:endinx)-load_pb_bl(1:endinx);
if choice==3,
    if emgYN == 1, 
        plot(time_pb(1:endinx),load_pb(1:endinx),time_pb(1:endinx),u_pb(1:endinx), '--', time_pb(1:endinx),uff_pb(1:endinx),time_pb(1:endinx),ufb_pb(1:endinx),  time_pb(1:endinx), diff_load_cut, time_pb(1:endinx), emg_Trig(1:endinx))
    else
        plot(time_pb(1:endinx),load_pb(1:endinx),time_pb(1:endinx),u_pb(1:endinx), '--', time_pb(1:endinx),uff_pb(1:endinx),time_pb(1:endinx),ufb_pb(1:endinx),  time_pb(1:endinx), diff_load_cut)
    end
else
    plot(time_pb(1:endinx),load_pb(1:endinx),time_pb(1:endinx),u_pb(1:endinx), '--', time_pb(1:endinx),uff_pb(1:endinx),time_pb(1:endinx),ufb_pb(1:endinx))
end
grid on
if emgYN == 1, 
    legend('load','u','uff','fb',  'diff load', 'emgTrig')
else
    legend('load','u','uff','fb',  'diff load')
end
% title([num2str(choice), ', regF= ', num2str(a0),'+(', num2str(a1), ')x + (', num2str(a2), ')xdot'])
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



