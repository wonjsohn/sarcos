%% generate hypothetical lut for spasticity 40x40

%% create a lookup table to export to robot. 
xinv = 0.001;% interval 
vinv = 0.001;
x = 0.3:xinv:2.3-xinv;  %2000 points
v = -5.0:vinv:5.0-vinv; % 10000 points

rowlen = 40;  % row length of table. higher = good resolution 3d map. 

rs_x = resample(x', 1, 2000/rowlen); %  points in lut
rs_v = resample(v', 1, 10000/rowlen); % points in lut

fake_lut=zeros(rowlen,rowlen);

% sudden spastic catch, velocity threshold
posSlope = 0.8;
velSlope = 1.1;
pos_reflex = @(x) posSlope*(-0.4 + 4*x)
vel_reflex = @(x) velSlope*x*((x>2.0) + (x<-2.0)) ;
%h=@(t) a*(t>5)+b*(t<=5)


for i=1:length(rs_x),
    for j=1:length(rs_v),
%       fake_lut(i,j)= -0.4 + 4*rs_x(i) + 0.4*rs_v(j) ;  % formula: f(x) = -0.3 + 3.0*x(i)  ; 3.0 is slope
      fake_lut(i,j)= pos_reflex(rs_x(i)) + vel_reflex(rs_v(j)) ;  % formula: f(x) = -0.3 + 3.0*x(i)  ; 3.0 is slope
    end
end




figure;
%% smoothing interpolation to reduce instability in robot. 
fname = 'fake_spasticity1';

% diff_load_lut_interp = interp2(diff_load_lut,2, 'cubic'); % interp spline to smooth out the surface (prevent jerky movement) 
h = 1/100*ones(5,5);
fake_lut_filtered = filter2(h,fake_lut);


surf( fake_lut_filtered);
title(fname);
xlabel('vel')
ylabel('pos')
zlabel('reflex')
zlim([-1 2.5])
caxis([-1, 2.5])

%% resample smooth curve to low res to export to C lookup table. 
fake_lut_filtered_resampled = imresize(fake_lut_filtered,[rowlen rowlen]);
% surf( diff_load_lut_interp_resampled);


mypath = 'lut_table/';
A = [fname, '_lut_table.txt'];    % trajectory recording phase
csvwrite(fullfile(mypath, A) ,fake_lut_filtered_resampled); % save selected variables

