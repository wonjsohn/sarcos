%% fitting and gerenate look up table for pos, vel -> reflex force. 
% depending on the data points, 200x200 takes about 10 seconds. 

[fitresult, gof] = NNInterpFit(pos_pb_cut, vel_pb_cut, diff_load_cut)

%%

%% create a lookup table to export to robot. 
xinv = 0.001;% interval 
vinv = 0.001;
x = 0.3:xinv:2.3-xinv;  %2000 points
v = -5.0:vinv:5.0-vinv; % 10000 points

rowlen = 40;  % row length of table. higher = good resolution 3d map. 

rs_x = resample(x', 1, 2000/rowlen); %  points in lut
rs_v = resample(v', 1, 10000/rowlen); % points in lut

diff_load_lut=zeros(rowlen,rowlen);

for i=1:length(rs_x),
    for j=1:length(rs_v),
      diff_load_lut(i,j)= fitresult(rs_x(i), rs_v(j));
    end
end

figure;
%% smoothing interpolation to reduce instability in robot. 

% diff_load_lut_interp = interp2(diff_load_lut,2, 'cubic'); % interp spline to smooth out the surface (prevent jerky movement) 
h = 1/10*ones(5,5);
diff_load_lut_filtered = filter2(h,diff_load_lut, 'valid');


% surf( diff_load_lut_filtered);
title(fname);
xlabel('vel')
ylabel('pos')
zlabel('reflex')
zlim([-10 25])
caxis([-10, 25])

%% resample smooth curve to low res to export to C lookup table. 
diff_load_lut_filtered_resampled = imresize(diff_load_lut_filtered,[rowlen rowlen]);

surf( diff_load_lut_filtered_resampled);
title(fname);
xlabel('vel')
ylabel('pos')
zlabel('reflex')
zlim([-10 25])
caxis([-10, 25])


mypath = 'lut_table/';
A = [fname, '_lut_table.txt'];    % trajectory recording phase
csvwrite(fullfile(mypath, A) ,diff_load_lut_filtered_resampled); % save selected variables

