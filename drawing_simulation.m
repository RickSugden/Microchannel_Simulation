%drawing the confined microchannel
close all
clear

cd 'C:\Users\rickj\Desktop\specProj\shearclean\params\d0.7850\a0.50';
header = textread('params.1106','%s','delimiter','\n','whitespace','');%replace the ### after params with ic
header_length = length(header);
cd C:\Users\rickj\Desktop\specProj\shearclean;
data =load('data_output');
data_length = length(data);
%String[] splited = str.split("\\s+");
x= data(:,1);
y = data(:,2);
vx = data(:,3);
vy= data(:,4);
ax = data(:,5);
ay = data(:,6);
bx= data(:,7);
by = data(:,8);
cx = data(:,9);
cy= data(:,10);
lxwall_offset= data(:,11);
rxwall_offset = data(:,12);
r = data(:,13);
m = data(:,14);
invm = data(:,15);
axp =data(:,16);
ayp =data(:,17);
cell=data(:,18);
next=data(:,19);
numincell=data(:,20);
firstincell=data(:,21);

%find the smallest and largest radii and calculate the wall ball radius
%the ratio can later be made so its extracted from params
small_r = min(r(:));
big_r = max(r(:));
wall_ball_r = small_r*0.8;

LX = 50*small_r;
aspect_ratio = .5;
LY = aspect_ratio*LX;

figure
for i= 1:length(x)
    pos = [x(i) y(i) 2*r(i) 2*r(i)]; 
    rectangle('Position',pos,'Curvature',[1 1])
    
end  
frame_position = [0 0 LX LY];

rectangle('Position',frame_position);

for i= 0:(2.5*small_r):LY
   
    pos = [(-wall_ball_r) i 2*wall_ball_r 2*wall_ball_r]; 
    rectangle('Position',pos,'Curvature',[1 1])
    
    pos = [(LX-wall_ball_r) i 2*wall_ball_r 2*wall_ball_r]; 
    rectangle('Position',pos,'Curvature',[1 1])
    
end

title('Carbopol Microchannel Simulation restart file');
axis equal