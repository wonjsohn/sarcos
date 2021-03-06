function [fitresult, gof] = NNInterpFit(pos_pb_cut, vel_pb_cut, diff_load_cut)
%CREATEFIT(POS_PB_CUT,VEL_PB_CUT,DIFF_LOAD_CUT)
%  Create a fit.
%
%  Data for 'NNInterpFit1' fit:
%      X Input : pos_pb_cut
%      Y Input : vel_pb_cut
%      Z Output: diff_load_cut
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  See also FIT, CFIT, SFIT.

%  Auto-generated by MATLAB on 07-Aug-2015 13:31:32


%% Fit: 'NNInterpFit1'.
[xData, yData, zData] = prepareSurfaceData( pos_pb_cut, vel_pb_cut, diff_load_cut );

% Set up fittype and options.
ft = 'nearestinterp';

% Fit model to data.
[fitresult, gof] = fit( [xData, yData], zData, ft, 'Normalize', 'on' );


% Plot fit with data.
figure( 'Name', 'NNInterpFit' );
% h = plot( fitresult, [xData, yData], zData );
h = plot( fitresult);
legend( h, 'NNInterpFit', 'diff_load_cut vs. pos_pb_cut, vel_pb_cut', 'Location', 'NorthEast' );
% Label axes
xlabel( 'pos_pb_cut' );
ylabel( 'vel_pb_cut' );
zlabel( 'diff_load_cut' );
grid on


