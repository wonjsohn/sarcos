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

%% Spasticity : sudden spastic catch, velocity threshold
posSlope = 12.0;
posOffset = -4.8;
velSlope = 8.0;
velThreshold = 1.5;
pos_reflex = @(x) posOffset + posSlope*(x)
vel_reflex = @(x) velSlope*x*((x>velThreshold) + (x<(-1*velThreshold)));
%h=@(t) a*(t>5)+b*(t<=5)


for i=1:length(rs_x),
    for j=1:length(rs_v),
%       fake_lut(i,j)= -0.4 + 4*rs_x(i) + 0.4*rs_v(j) ;  % formula: f(x) = -0.3 + 3.0*x(i)  ; 3.0 is slope
      fake_lut(i,j)= pos_reflex(rs_x(i)) + vel_reflex(rs_v(j)) ;  % formula: f(x) = -0.3 + 3.0*x(i)  ; 3.0 is slope
    end
end

%% Dystonia 

posSlope = 42.0;
posOffset = -50.0;
pos_reflex_dyst = @(x) posOffset + posSlope*(x)
for i=1:length(rs_x),
    for j=1:length(rs_v),
%       fake_lut(i,j)= -0.4 + 4*rs_x(i) + 0.4*rs_v(j) ;  % formula: f(x) = -0.3 + 3.0*x(i)  ; 3.0 is slope
      fake_lut(i,j)= pos_reflex_dyst(rs_x(i)) ;  % formula: f(x) = -0.3 + 3.0*x(i)  ; 3.0 is slope
    end
end


figure;
%% smoothing interpolation to reduce instability in robot. 
fname = 'fake_dystonia1';   %use ctp gain 1.5 (2.0: a bit unstable)

% diff_load_lut_interp = interp2(diff_load_lut,2, 'cubic'); % interp spline to smooth out the surface (prevent jerky movement) 
h = 1/100*ones(5,5);
fake_lut_filtered = filter2(h,fake_lut);


surf( fake_lut_filtered);
title(fname);
xlabel('vel')
ylabel('pos')
zlabel('reflex')
zlim([-8 12.5])
caxis([-8, 12.5])

%% resample smooth curve to low res to export to C lookup table. 
fake_lut_filtered_resampled = imresize(fake_lut_filtered,[rowlen rowlen]);
% surf( diff_load_lut_interp_resampled);


mypath = 'lut_table/';
A = [fname, '_lut_table.txt'];    % trajectory recording phase
csvwrite(fullfile(mypath, A) ,fake_lut_filtered_resampled); % save selected variables

