%% fitting and gerenate look up table for pos, vel -> reflex force. 
% depending on the data points, 200x200 takes about 10 seconds. 

[fitresult, gof] = NNInterpFit(pos_pb_cut, vel_pb_cut, diff_load_cut)
%% create a lookup table to export to robot. 
xinv = 0.001;% interval 
vinv = 0.001;
x = 0.3:xinv:2.3-xinv;  %2000 points
v = -5.0:vinv:5.0-vinv; % 10000 points

rs_x = resample(x', 1, 100); % 20 points
rs_v = resample(v', 1, 500); % 20 points

diff_load_lut=zeros(20,20);
i=1;j=1;
for i=1:length(rs_x),
    for j=1:length(rs_v),
      diff_load_lut(i,j)= fitresult(rs_x(i), rs_v(j));
    end
end

mypath = 'lut_table/';
A = [fname, '_lut_table.txt'];    % trajectory recording phase
csvwrite(fullfile(mypath, A) ,diff_load_lut); % save selected variables

