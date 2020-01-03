%drawing the confined microchannel
close all

NUMBER_OF_FILES = 100;

compiled_left_shear = 0;
compiled_right_shear = 0;

%cd 'C:\Users\rickj\Desktop\specProj\shearclean\params\d0.7850\a0.50';
%header = textread('params.1106','%s','delimiter','\n','whitespace','');%replace the ### after params with ic
%header_length = length(header);


cd C:\Users\rickj\Desktop\specProj\shearclean\big_output_at_0.6;

frame = 1;
for i = 0:5:(NUMBER_OF_FILES-1)
    
    file_num = i;
    %file_num = 1102+i;
    file_num = num2str(file_num);
    filename = ['big_output 1229',' ',file_num];
    data =load(filename);
    data_length = length(data);

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
    stressxx=data(:,22);
    stressxy=data(:,23);%note this is possibly a resultant vector
    
    %stressyy = 
    
    %find the smallest and largest radii and calculate the wall ball radius
    %the ratio can later be made so its extracted from params
    small_r = min(r(:));
    big_r = max(r(:));
    wall_ball_r = small_r*0.8;

    LX = 50*small_r;
    aspect_ratio = 2;
    LY = aspect_ratio*LX;

    figure
    
    for j= 1:length(x)
        pos = [(x(j)-r(j)) (y(j)-r(j)) 2*r(j) 2*r(j)]; 
        rectangle('Position',pos,'Curvature',[1 1]);

    end  
    frame_position = [0 0 LX LY];
    rectangle('Position',frame_position);

    %this puts the wall balls on the frame
    for j= 0:(2.5*small_r):LY
        pos = [(-wall_ball_r) j 2*wall_ball_r 2*wall_ball_r]; 
        rectangle('Position',pos,'Curvature',[1 1]);

        pos = [(LX-wall_ball_r) j 2*wall_ball_r 2*wall_ball_r]; 
        rectangle('Position',pos,'Curvature',[1 1]);
    end

    title(strcat('Carbopol Microchannel Simulation restart file',file_num));
    axis ([0 100 0 100]);
    M(frame) = getframe;
    frame = frame+1;
end
figure
movie(M,10);

